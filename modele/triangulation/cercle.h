#ifndef CERCLE_H
#define CERCLE_H

#include "modele/point.h"
#include <cmath>

using namespace std;

class Cercle {
private:
    Point centre;
    double rayon;
public:
    Cercle();
    Cercle(const Point &, const double &);
    Cercle(const Cercle &);
    virtual ~Cercle();
    const Cercle & operator = (const Cercle &);
    bool operator==(const Cercle &) const;
    bool operator != (const Cercle &)const;
    const Point & getCentre()const;
    double getRayon()const;
    void setCentre(const Point &);
    void setRayon(const double &);
};
#endif
