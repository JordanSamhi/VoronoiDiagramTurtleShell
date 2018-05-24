#ifndef CARAPACE_H
#define CARAPACE_H

#include <vector>
#include "modele/point.h"
#include "modele/triangulation/triangle.h"
#include "modele/diagrammeVoronoi/element.h"
#include "modele/diagrammeVoronoi/arete.h"

class Application;
class DiagrammeVoronoi;

using namespace std;

class Carapace{
private:
    vector<Point *> contourHaut, contourBas, sites;
    vector<Triangle *> triangles;
    Application *application;
    DiagrammeVoronoi *voronoi;
public:
    Carapace();
    Carapace(Application *);
    const vector<Point *> & getContourHaut() const;
    const vector<Point *> & getContourBas() const;
    const vector<Point *> & getSites() const;
    void setContourHaut(const vector<Point *> &);
    void setContourBas(const vector<Point *> &);
    void setSites(const vector<Point *> &);
    const vector<Triangle *> & getTriangles()const;
    void setTriangles(const vector<Triangle *> &);
    DiagrammeVoronoi * getVoronoi()const;
    void setVoronoi(DiagrammeVoronoi *);
    vector<Point *> getTousLesPointsDuContour()const;

    void updateVue()const;
};

#endif // CARAPACE_H
