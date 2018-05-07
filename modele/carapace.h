#ifndef CARAPACE_H
#define CARAPACE_H

#include <vector>
#include "modele/point.h"
#include "modele/triangulation/triangle.h"


class Application;

using namespace std;

class Carapace{
private:
    vector<Point *> contourHaut, contourBas, sites;
    vector<Triangle *> triangles;
    Application *application;
    //TODO Ajouter diagramme
public:
    Carapace();
    Carapace(Application *);
    //TODO Ajouter destructeur a la fin pour ne pas oublier de pointeurs
    const vector<Point *> & getContourHaut() const;
    const vector<Point *> & getContourBas() const;
    const vector<Point *> & getSites() const;
    void setContourHaut(const vector<Point *> &);
    void setContourBas(const vector<Point *> &);
    void setSites(const vector<Point *> &);
    const vector<Triangle *> & getTriangles()const;
    void setTriangles(const vector<Triangle *> &);
};

#endif // CARAPACE_H
