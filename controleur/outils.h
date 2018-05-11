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
#include "modele/triangulation/triangle.h"
#include "modele/diagrammeVoronoi/segment.h"

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
    static Point *intersection2Droites(const EquationDroite &, const EquationDroite &);
    static Point *intersectionDroiteVerticaleEtAutre(const EquationDroiteVerticale &, const EquationDroite &);
    static const EquationDroiteVerticale equationMediatriceOrdonneesEgales(const Point *, const Point *);
    static const EquationDroite equationMediatriceOrdonneesPasEgales(const Point *, const Point *);
    static int indicePointLePlusAGauche(const vector<Point *> &);
    static double getxMin(const vector<Point *> &);
    static double getxMax(const vector<Point *> &);
    static double getyMax(const vector<Point *> &);
    static double getyMin(const vector<Point *> &);

    //Outils pour voronoi
    static Triangle * getTriangleParCentreCercleCirconscrit(Point *, const vector<Triangle *> &);
    static vector<Triangle *> getTrianglesAyantMoinsDeTroisVoisins(const vector<Triangle*> &);
    static bool pointEstSurSegment(Point *, Segment *);
    static double getDistanceEuclidienne(Point *, Point*);
    static Point * getPointDuContourLePlusProche(Point *inter, const vector<Point *> &);
    static Point * getPointMilieu(Point *, Point *);
    static vector<Point*> getAreteContenantPoint(const vector<vector<Point*>> &, Point *);
    static Point * getPointLePlusAGauche(const vector<Point*> &);
    static Point * getPointLePlusADroite(const vector<Point*> &);
};

#endif // OUTILS_H
