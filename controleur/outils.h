#ifndef OUTILS_H
#define OUTILS_H

#include <vector>
#include "modele/vecteur2d.h"

using namespace std;

class Outils{
public:
    /* pour generer 3 points de controle aléatoirement comme ça on aura pas lameme carapace de trotue à chaque fois*/
    static vector<Vecteur2D> generer3PointsDeControle();
};

#endif // OUTILS_H
