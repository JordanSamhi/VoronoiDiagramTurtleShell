#include "carapace.h"
#include "vue/application.h"

Carapace::Carapace(){}

Carapace::Carapace(Application *a):application(a){}

const vector<Vecteur2D> & Carapace::getContourHaut() const{
    return this->contourHaut;
}

const vector<Vecteur2D> & Carapace::getContourBas() const{
    return this->contourBas;
}

const vector<Vecteur2D> & Carapace::getSites() const{
    return this->sites;
}

void Carapace::setContourHaut(const vector<Vecteur2D> & cH){
    this->contourHaut.clear();
    for(size_t i = 0 ; i < cH.size() ; i++)
        this->contourHaut.push_back(cH[i]);
}

void Carapace::setContourBas(const vector<Vecteur2D> & cB){
    this->contourBas.clear();
    for(size_t i = 0 ; i < cB.size() ; i++)
        this->contourBas.push_back(cB[i]);
    //TODO NE PAS APPELER UPDATE ICI, CHANGER ULTERIEUREMENT, CEST JUSTE POUR LES TESTS
    this->application->update();
}

void Carapace::setSites(const vector<Vecteur2D> & s){
    this->sites.clear();
    for(size_t i = 0 ; i < s.size() ; i++)
        this->sites.push_back(s[i]);
}
