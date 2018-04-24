#ifndef CARAPACE_H
#define CARAPACE_H

#include <vector>
#include <modele/vecteur2d.h>

class Application;

using namespace std;

class Carapace{
private:
    vector<Vecteur2D> contourHaut, contourBas, sites;
    Application *application;
    //TODO Ajouter diagramme
public:
    Carapace();
    Carapace(Application *);
    //TODO Destructeur
    const vector<Vecteur2D> & getContourHaut() const;
    const vector<Vecteur2D> & getContourBas() const;
    const vector<Vecteur2D> & getSites() const;
    void setContourHaut(const vector<Vecteur2D> &);
    void setContourBas(const vector<Vecteur2D> &);
    void setSites(const vector<Vecteur2D> &);
};

#endif // CARAPACE_H
