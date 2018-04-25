#include "controleur.h"

Controleur::Controleur(){}

Controleur::Controleur(Carapace *c):carapace(c){}

void Controleur::genererCarapace(const bool parfaite){
    Bezier bez;
    Vecteur2D pointDebut, pointMilieu, pointFin;
    //Détermination des points
    int origine = 0, limiteDroite = 10;
    pointDebut = Vecteur2D(origine, 0);
    pointFin = Vecteur2D(limiteDroite, 0);
    pointMilieu = this->calculerPointDeControleMilieu(pointDebut, pointFin);

    //Sauvegarde du milieu precedent dans la classe
    this->pointMilieuPrecedent = pointMilieu;

    bez.ajouterPoint(pointDebut);
    bez.ajouterPoint(pointMilieu);
    bez.ajouterPoint(pointFin);

    vector<Vecteur2D> contourHaut, contourBas;
    Vecteur2D pointResultat;
    for (double t = 0; t <= 1; t += 0.01){
        pointResultat = bez.bezier(t);
        contourHaut.push_back(pointResultat);
        pointResultat.setY(-pointResultat.getY());
        contourBas.push_back(pointResultat);
    }
    contourHaut.push_back(pointFin);
    contourBas.push_back(pointFin);

    this->carapace->setContourHaut(contourHaut);
    this->carapace->setContourBas(contourBas);
    this->carapace->setSites(this->genererSitesPourCarapace(pointDebut, pointMilieu, pointFin, parfaite));
}

void Controleur::genererCarapaceParfaite(){
    this->genererCarapace(true);
}

vector<Vecteur2D> Controleur::genererSitesPourCarapace(const Vecteur2D & pointDebut, const Vecteur2D & pointMilieu, const Vecteur2D & pointFin, const bool parfaite) const{
    vector<Vecteur2D> pointsResultats;
    Vecteur2D res;
    Bezier bez;
    int longueurCarapace, dixPourcentLongueurCarapace, quarantePourcentHauteurPointMilieu;
    longueurCarapace = pointFin.getX() - pointDebut.getX();
    dixPourcentLongueurCarapace = longueurCarapace * 0.1;
    quarantePourcentHauteurPointMilieu = pointMilieu.getY() * 0.4;

    bez.ajouterPoint(Vecteur2D(pointDebut.getX() + dixPourcentLongueurCarapace, pointDebut.getY()));
    bez.ajouterPoint(Vecteur2D(pointMilieu.getX(), pointMilieu.getY() - quarantePourcentHauteurPointMilieu));
    bez.ajouterPoint(Vecteur2D(pointFin.getX() - dixPourcentLongueurCarapace, pointFin.getY()));

    for(double t = 0.1; t <= 0.9; t += 0.1){
        res = bez.bezier(t);
        if(!parfaite) this->faireVarierStochastiquementLocalementUnPoint(&res);
        pointsResultats.push_back(res);
        res.setY(-res.getY());
        if(!parfaite) this->faireVarierStochastiquementLocalementUnPoint(&res);
        pointsResultats.push_back(res);
        res = Vecteur2D(t*10, 0);
        if(!parfaite) this->faireVarierStochastiquementLocalementUnPoint(&res);
        pointsResultats.push_back(res);
    }
    return pointsResultats;
}

Vecteur2D Controleur::calculerPointDeControleMilieu(const Vecteur2D & pointDebut, const Vecteur2D & pointFin) const{
    int limiteDroite = pointFin.getX() - pointDebut.getX(), xPointMilieu = limiteDroite/2, yPointMilieu;
    /*
     * Pour avoir des belles carapaces on limite la hauteur de la
     * hauteur du pointmilieu entre 40% et 90% de la limitedroite
     * Cela evite les carapaces en cloche et les carapaces plates
     */
    int limiteBasseYPointMilieu = limiteDroite * 0.4, limiteHauteYPointMilieu = limiteDroite * 0.9;
    yPointMilieu = this->getNombreAleatoireEntreDeuxNombres(limiteBasseYPointMilieu, limiteHauteYPointMilieu);
    return Vecteur2D(xPointMilieu, yPointMilieu);
}

void Controleur::genererNouveauxSites(const bool parfait)const{
    Vecteur2D pointDebut, pointFin, pointMilieu;
    if(!this->carapace->getContourHaut().empty()){
        pointDebut = this->carapace->getContourHaut()[0];
        pointFin = this->carapace->getContourHaut()[this->carapace->getContourHaut().size()-1];
        pointMilieu = this->pointMilieuPrecedent;
        this->carapace->setSites(this->genererSitesPourCarapace(pointDebut, pointMilieu, pointFin, parfait));
    }
}


void Controleur::faireVarierStochastiquementLocalementUnPoint(Vecteur2D * p) const{
    p->setX(p->getX() + (this->getNombreAleatoireEntreDeuxNombres(-1, 1) * 0.1));
    p->setY(p->getY() + (this->getNombreAleatoireEntreDeuxNombres(-1, 1) * 0.1));
}

int Controleur::getNombreAleatoireEntreDeuxNombres(const int a, const int b) const{
    return (unsigned int)((QRandomGenerator::global()->generate() % (b+1-a)) + a);
}
