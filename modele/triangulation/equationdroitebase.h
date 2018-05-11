#ifndef EQUATIONDROITEBASE_H
#define EQUATIONDROITEBASE_H

#include <iostream>
#include <string>
#include "modele/point.h"

using namespace std;

class EquationDroiteBase{
public:
    EquationDroiteBase();
    virtual operator string() const = 0;
    virtual EquationDroite * getEquationDroitePerpendiculairePassantParPoint(Point *)const=0;
};
inline ostream & operator <<(ostream & f, const EquationDroiteBase & edb) {
    return f << (string)edb;
}
#endif // EQUATIONDROITEBASE_H
