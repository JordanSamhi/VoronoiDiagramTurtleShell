#ifndef OUTILS_H
#define OUTILS_H

#include <QRandomGenerator>
#include <cmath>
#include <cfloat>
#include "modele/point.h"
#include "modele/triangulation/triangle.h"
#include "modele/triangulation/equationdroite.h"
#include "modele/triangulation/equationdroiteverticale.h"
#include "modele/triangulation/anglecapable.h"
#include "erreur.h"
#include "modele/triangulation/cercle.h"

class Triangle;

class Outils{
public:
    //Outils pour dessin
    static int getNombreAleatoireEntreDeuxNombres(const int, const int) ;
    static void faireVarierStochastiquementLocalementUnPoint(Point *);
    static Point *calculerPointDeControleMilieu(const Point *, const Point *) ;

    //Outils pour triangulation
    static bool pointEstDansTriangle(const Point *, const Triangle *);
    static bool appartientACercle(const Point *, const Cercle *);
    static const Point intersection2Droites(const EquationDroite &, const EquationDroite &);
    static const Point intersectionDroiteVerticaleEtAutre(const EquationDroiteVerticale &, const EquationDroite &);
    static const EquationDroiteVerticale equationMediatriceOrdonneesEgales(const Point *, const Point *);
    static const EquationDroite equationMediatriceOrdonneesPasEgales(const Point *, const Point *);
    static int indicePointLePlusAGauche(const vector<Point *> &);
    static double getxMin(const vector<Point *> &);
    static double getxMax(const vector<Point *> &);
    static double getyMax(const vector<Point *> &);
    static double getyMin(const vector<Point *> &);
};

#endif // OUTILS_H
