#include "generateurcarapacealea.h"

GenerateurCarapaceAlea::GenerateurCarapaceAlea():GenerateurCarapace(){}

GenerateurCarapaceAlea::GenerateurCarapaceAlea(Carapace * c):GenerateurCarapace(c){}

vector<Point> GenerateurCarapaceAlea::calculPositionSites(const Bezier * b) const{
    vector<Point> pointsResultats;
    Point point;
    double pas = 0.1;

    for(double t = 0.1; t <= 0.9; t += pas){
        point = b->bezier(t);
        Outils::faireVarierStochastiquementLocalementUnPoint(&point);
        pointsResultats.push_back(point);
        point.setY(-point.getY());
        Outils::faireVarierStochastiquementLocalementUnPoint(&point);
        pointsResultats.push_back(point);
        point = Point(t/pas, 0);
        Outils::faireVarierStochastiquementLocalementUnPoint(&point);
        pointsResultats.push_back(point);
    }

    return pointsResultats;
}
