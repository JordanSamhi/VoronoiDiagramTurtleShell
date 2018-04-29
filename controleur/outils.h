#ifndef OUTILS_H
#define OUTILS_H

#include "modele/point.h"
#include <QRandomGenerator>

class Outils{
public:
    static int getNombreAleatoireEntreDeuxNombres(const int, const int) ;
    static void faireVarierStochastiquementLocalementUnPoint(Point *);
    static Point calculerPointDeControleMilieu(const Point &, const Point &) ;

};

#endif // OUTILS_H
