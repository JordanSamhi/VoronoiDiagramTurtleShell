#include "carapace.h"
#include "vue/application.h"

Carapace::Carapace(){}

Carapace::Carapace(Application *a):application(a){}

const vector<Point> & Carapace::getContourHaut() const{
    return this->contourHaut;
}

const vector<Point> & Carapace::getContourBas() const{
    return this->contourBas;
}

const vector<Point> & Carapace::getSites() const{
    return this->sites;
}

void Carapace::setContourHaut(const vector<Point> & cH){
    this->contourHaut.clear();
    for(size_t i = 0 ; i < cH.size() ; i++)
        this->contourHaut.push_back(cH[i]);
}

void Carapace::setContourBas(const vector<Point> & cB){
    this->contourBas.clear();
    for(size_t i = 0 ; i < cB.size() ; i++)
        this->contourBas.push_back(cB[i]);
}

void Carapace::setSites(const vector<Point> & s){
    this->sites.clear();
    for(size_t i = 0 ; i < s.size() ; i++)
        this->sites.push_back(s[i]);
    //TODO NE PAS APPELER UPDATE ICI, CHANGER ULTERIEUREMENT, CEST JUSTE POUR LES TESTS
    this->application->update();
}

Point Carapace::getSommetHaut()const{
    Point max = Point(0, 0);
    for(size_t i = 0 ; i < this->contourHaut.size(); i++)
        if(contourHaut[i].getY() > max.getY())
            max = contourHaut[i];
    return max;
}
