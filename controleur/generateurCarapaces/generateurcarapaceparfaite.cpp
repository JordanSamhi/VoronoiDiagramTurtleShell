#include "generateurcarapaceparfaite.h"

GenerateurCarapaceParfaite::GenerateurCarapaceParfaite():GenerateurCarapace(){}

GenerateurCarapaceParfaite::GenerateurCarapaceParfaite(Carapace * c):GenerateurCarapace(c){}

vector<Point *> GenerateurCarapaceParfaite::calculPositionSites(const Bezier * b) const{
    vector<Point *> pointsResultats;
    Point *point;

    for(double t = 0.1; t <= 0.9; t += 0.2){
        point = b->bezier(t);
        pointsResultats.push_back(point);
        point = new Point(point->getX(), -point->getY());
        pointsResultats.push_back(point);
        point = new Point(t*10, 0);
        pointsResultats.push_back(point);
    }

    return pointsResultats;
}
