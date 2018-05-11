#ifndef DIAGRAMMEVORONOI_H
#define DIAGRAMMEVORONOI_H

#include <vector>
#include "modele/carapace.h"
#include "graphe.h"
#include "modele/diagrammeVoronoi/segment.h"

using namespace std;

class DiagrammeVoronoi{
private:
    Graphe graphe;
    Carapace *carapace;
public:
    DiagrammeVoronoi(Carapace *carapace);
    const vector<Triangle *> getTrianglesParPoint(Point *, const vector<Triangle *> &)const;
    const Graphe & getGraphe()const;
    vector<Point*> getContourParRapportACoteArete(vector<Point *>) const;
    vector<Point*> getContourParRapportACotePoint(Point *) const;
};

#endif // DIAGRAMMEVORONOI_H
