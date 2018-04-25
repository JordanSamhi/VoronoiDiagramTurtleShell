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
    Vecteur2D pointMilieuPrecedent;
    int getNombreAleatoireEntreDeuxNombres(const int, const int) const;
    vector<Vecteur2D> genererSitesPourCarapace(const Vecteur2D &, const Vecteur2D &, const Vecteur2D &, const bool) const;
    void faireVarierStochastiquementLocalementUnPoint(Vecteur2D *) const;
    Vecteur2D calculerPointDeControleMilieu(const Vecteur2D &, const Vecteur2D &) const;
public:
    //TODO Ajouter destructeur a la fin pour ne pas oublier de pointeurs
    Controleur();
    Controleur(Carapace *);
    void genererCarapace(const bool parfaite = false);
    void genererNouveauxSites(const bool)const;
    void genererCarapaceParfaite();
};

#endif // CONTROLEUR_H
