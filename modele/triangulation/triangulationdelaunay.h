#ifndef TRIANGULATIONDELAUNAY_H
#define TRIANGULATIONDELAUNAY_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <tuple>
#include "controleur/outils.h"
#include "Triangle.h"


using namespace std;

class TriangulationDelaunay {
private:
    //Encadrement (enveloppe convexe)
    Point * coinInferieurGauche, *coinInferieurDroit, *coinSuperieurGauche, *coinSuperieurDroit;
    vector<Triangle*> DT;
    vector<Point*> points;
public:
    TriangulationDelaunay(vector<Point *>);
    void calculerTriangulation(Point *);
    void determiner_DTL(const Point *, Triangle*, vector<Triangle*> *);
    vector<Triangle*> determiner_NTL(Point *, vector<Triangle*> *);
    Triangle * determinerTriangleContenantNouveauPoint(const Point *);
    void supprimerTriangles(vector<Triangle*> *);
    int indiceTriangleDansDT(Triangle *)const;
    vector<Triangle *> getTriangulation();
    tuple<Triangle *, Triangle*> genererTrianglesFictifs(vector<Point *>);
    const vector<Triangle *> & getDT()const;
    const vector<Point *> & getPoints()const;
};
#endif
