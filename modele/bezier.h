#ifndef BEZIER_H
#define BEZIER_H

#include <vector>
#include "modele/Point.h"
#include "modele/bernstein.h"

using namespace std;

class Bezier{
private:
    vector<Point> pointsDeControle;
public:
    Bezier();
    ~Bezier();
    void ajouterPoint(const Point &);
    const vector<Point>& getPointsControle()const;
    int taille() const;
    Point *bezier(const double &) const;
};

#endif // BEZIER_H
