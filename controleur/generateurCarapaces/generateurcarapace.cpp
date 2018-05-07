#include "generateurcarapace.h"

Point *GenerateurCarapace::pointMilieuPrecedent;

GenerateurCarapace::GenerateurCarapace(){}

GenerateurCarapace::GenerateurCarapace(Carapace *c):carapace(c){}

void GenerateurCarapace::genererCarapace(){
    Bezier bez;
    Point *pointDebut, *pointMilieu, *pointFin;
    //Détermination des points
    int origine = 0, limiteDroite = 10;
    pointDebut = new Point(origine, 0);
    pointFin = new Point(limiteDroite, 0);
    pointMilieu = Outils::calculerPointDeControleMilieu(pointDebut, pointFin);

    //Sauvegarde du milieu precedent dans la classe
    pointMilieuPrecedent = pointMilieu;

    //FIXME SI POSE PROBLEME VOIR POINTEURS
    bez.ajouterPoint(*pointDebut);
    bez.ajouterPoint(*pointMilieu);
    bez.ajouterPoint(*pointFin);

    vector<Point *> contourHaut, contourBas;
    Point * pointResultat;
    for (double t = 0; t <= 1; t += 0.01){
        pointResultat = bez.bezier(t);
        contourHaut.push_back(pointResultat);
        pointResultat = new Point(pointResultat->getX(), -pointResultat->getY());
        contourBas.push_back(pointResultat);
    }
    contourHaut.push_back(pointFin);
    contourBas.push_back(pointFin);

    this->carapace->setContourHaut(contourHaut);
    this->carapace->setContourBas(contourBas);
    this->carapace->setSites(this->genererSitesPourCarapace(*pointDebut, *pointMilieu, *pointFin));

    //Triangulation
    TriangulationDelaunay triangulation(this->carapace->getSites());
    this->carapace->setTriangles(triangulation.getTriangulation());
}
vector<Point *> GenerateurCarapace::genererSitesPourCarapace(const Point & pointDebut, const Point & pointMilieu, const Point & pointFin) const{
    Bezier bez;
    int longueurCarapace, dixPourcentLongueurCarapace, quarantePourcentHauteurPointMilieu;
    longueurCarapace = pointFin.getX() - pointDebut.getX();
    dixPourcentLongueurCarapace = longueurCarapace * 0.1;
    quarantePourcentHauteurPointMilieu = pointMilieu.getY() * 0.4;

    bez.ajouterPoint(Point(pointDebut.getX() + dixPourcentLongueurCarapace, pointDebut.getY()));
    bez.ajouterPoint(Point(pointMilieu.getX(), pointMilieu.getY() - quarantePourcentHauteurPointMilieu));
    bez.ajouterPoint(Point(pointFin.getX() - dixPourcentLongueurCarapace, pointFin.getY()));

    return this->calculPositionSites(&bez);
}

void GenerateurCarapace::genererNouveauxSites() const{
    Point *pointDebut, *pointFin, *pointMilieu;
    if(!this->carapace->getContourHaut().empty()){
        pointDebut = this->carapace->getContourHaut()[0];
        pointFin = this->carapace->getContourHaut()[this->carapace->getContourHaut().size()-1];
        pointMilieu = GenerateurCarapace::pointMilieuPrecedent;
        this->carapace->setSites(this->genererSitesPourCarapace(*pointDebut, *pointMilieu, *pointFin));
        //Triangulation
        TriangulationDelaunay triangulation(this->carapace->getSites());
        this->carapace->setTriangles(triangulation.getTriangulation());
    }
}
