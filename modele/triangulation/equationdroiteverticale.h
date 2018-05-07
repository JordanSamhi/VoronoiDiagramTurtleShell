#ifndef EQUATIONDROITEVERTICALE_H
#define EQUATIONDROITEVERTICALE_H

#include "modele/point.h"

using namespace std;
//	if (fabs(p2.getX() - p1.getX()) < 0.00001)
//equation du type x = c
class EquationDroiteVerticale {
private:
    double c; // pour les droites parallèles à l'axe des ordonnées x = c
public:
    EquationDroiteVerticale(const double &);
    EquationDroiteVerticale(const Point &);
    EquationDroiteVerticale(const EquationDroiteVerticale &);
    operator string() const;
    const EquationDroiteVerticale & operator = (const EquationDroiteVerticale &);
    double getC()const;
    void setC(const double &);
};
inline ostream & operator <<(ostream & f, const EquationDroiteVerticale & ed) {
    return f << (string)ed;
}
#endif
