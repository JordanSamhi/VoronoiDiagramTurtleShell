#ifndef CERCLE_H
#define CERCLE_H

#include <cmath>
#include "modele/point.h"

class Triangle;

using namespace std;

class Cercle {
private:
    Point *centre;
    double rayon;
    Triangle * triangle;
public:
    Cercle();
    Cercle(Point *, const double &);
    Cercle(const Cercle &);
    virtual ~Cercle();
    const Cercle & operator = (const Cercle &);
    bool operator==(const Cercle &) const;
    bool operator != (const Cercle &)const;
    Point * getCentre()const;
    double getRayon()const;
    void setCentre(Point *);
    void setRayon(const double &);
    void setTriangle(Triangle *);
    Triangle * getTriangle()const;
};
#endif
