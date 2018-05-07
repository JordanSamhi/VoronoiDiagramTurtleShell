#ifndef GENERATEURCARAPACE_H
#define GENERATEURCARAPACE_H

#include <vector>
#include "modele/point.h"
#include "modele/carapace.h"
#include "modele/bezier.h"
#include "controleur/outils.h"
#include "modele/triangulation/triangulationdelaunay.h"

class GenerateurCarapace{
private:
    Carapace *carapace;
protected:
    vector<Point *> genererSitesPourCarapace(const Point &, const Point &, const Point &) const;
public:
    static Point *pointMilieuPrecedent;
    //TODO destructeur
    GenerateurCarapace();
    GenerateurCarapace(Carapace *);
    void genererCarapace();
    void genererNouveauxSites()const;
    virtual vector<Point *> calculPositionSites(const Bezier *) const = 0;
};
#endif // GENERATEURCARAPACE_H
