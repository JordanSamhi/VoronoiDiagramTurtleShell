#include "generateurcarapacealea.h"

GenerateurCarapaceAlea::GenerateurCarapaceAlea():GenerateurCarapace(){}

GenerateurCarapaceAlea::GenerateurCarapaceAlea(Carapace * c):GenerateurCarapace(c){}

vector<Point *> GenerateurCarapaceAlea::calculPositionSites(const Bezier * b) const{
    vector<Point *> pointsResultats;
    Point * point;

    for(double t = 0.1; t <= 0.9; t += 0.2){
        point = b->bezier(t);
        Outils::faireVarierStochastiquementLocalementUnPoint(point);
        pointsResultats.push_back(point);
        point = new Point(point->getX(), -point->getY());
        Outils::faireVarierStochastiquementLocalementUnPoint(point);
        pointsResultats.push_back(point);
        point = new Point(t*10, 0);
        Outils::faireVarierStochastiquementLocalementUnPoint(point);
        pointsResultats.push_back(point);
    }

    return pointsResultats;
}
