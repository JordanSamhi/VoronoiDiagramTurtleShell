#include "controleur.h"

Controleur::Controleur(){}

Controleur::Controleur(Carapace *c):carapace(c){}

vector<Vecteur2D> Controleur::generer3PointsDeControle() const{
    //TODO REDIGER LA METHODE
    return vector<Vecteur2D>();
}

void Controleur::genererCarapace(){
    Bezier bez;
    Vecteur2D pointDebut, pointMilieu, pointFin;

    //TODO rendre dynamique le point fin......
    unsigned int hauteurPointMilieu = (QRandomGenerator::global()->generate() % 7) + 4;
    pointDebut = Vecteur2D(0, 0);
    pointMilieu = Vecteur2D(5, hauteurPointMilieu);
    pointFin = Vecteur2D(10, 0);

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
}
