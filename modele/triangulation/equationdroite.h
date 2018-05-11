#ifndef EQUATIONDROITE_H
#define EQUATIONDROITE_H

#include "modele/point.h"
#include "modele/triangulation/equationdroitebase.h"

using namespace std;

class EquationDroite : public EquationDroiteBase{
private:
    double a, b; // y = ax + b
public:
    EquationDroite(const double &, const double &);
    EquationDroite(const Point &, const Point &);
    EquationDroite(const EquationDroite &);
    operator string() const;
    double getA()const;
    double getB()const;
    void setA(const double &);
    void setB(const double &);
    EquationDroite * getEquationDroitePerpendiculairePassantParPoint(Point *)const;
};

#endif
