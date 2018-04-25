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
    Bezier();
    ~Bezier();
    void ajouterPoint(const Vecteur2D &);
    const vector<Vecteur2D>& getPointsControle()const;
    int taille() const;
    Vecteur2D bezier(const double &) const;
};

#endif // BEZIER_H
