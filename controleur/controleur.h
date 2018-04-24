#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <vector>
#include <modele/carapace.h>
#include <QRandomGenerator>
#include "modele/vecteur2d.h"
#include "modele/bezier.h"

using namespace std;

class Controleur{
private:
    Carapace *carapace;
public:
    //TODO Ajouter destructeur
    Controleur();
    Controleur(Carapace *);
    /* pour generer 3 points de controle aléatoirement comme ça on aura pas lameme carapace de trotue à chaque fois*/
    vector<Vecteur2D> generer3PointsDeControle() const;
    void genererCarapace();
};

#endif // CONTROLEUR_H
