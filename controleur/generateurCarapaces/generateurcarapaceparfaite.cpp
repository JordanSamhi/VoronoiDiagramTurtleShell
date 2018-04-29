#include "generateurcarapaceparfaite.h"

GenerateurCarapaceParfaite::GenerateurCarapaceParfaite():GenerateurCarapace(){}

GenerateurCarapaceParfaite::GenerateurCarapaceParfaite(Carapace * c):GenerateurCarapace(c){}

vector<Point> GenerateurCarapaceParfaite::calculPositionSites(const Bezier * b) const{
    vector<Point> pointsResultats;
    Point point;
    double pas = 0.1;

    for(double t = 0.1; t <= 0.9; t += pas){
        point = b->bezier(t);
        pointsResultats.push_back(point);
        point.setY(-point.getY());
        pointsResultats.push_back(point);
        point = Point(t/pas, 0);
        pointsResultats.push_back(point);
    }

    return pointsResultats;
}
