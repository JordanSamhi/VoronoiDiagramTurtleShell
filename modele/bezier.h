#ifndef BEZIER_H
#define BEZIER_H

#include <vector>
#include "modele/vecteur2d.h"
#include "modele/bernstein.h"

using namespace std;

class Bezier{
private:
    vector<Vecteur2D> pointsDeControle;
public:
    //TODO Ajouter destructeur
    Bezier();
    void ajouterPoint(const Vecteur2D &);
    const vector<Vecteur2D>& getPointsControle()const;
    int taille() const;
    Vecteur2D bezier(const double &) const;
    vector<Vecteur2D> genererSitesSelonUneCourbeDeBezier(vector<Vecteur2D>);
};

#endif // BEZIER_H
