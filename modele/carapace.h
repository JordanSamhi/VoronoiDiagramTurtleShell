#ifndef CARAPACE_H
#define CARAPACE_H

#include <vector>
#include <modele/Point.h>

class Application;

using namespace std;

class Carapace{
private:
    vector<Point> contourHaut, contourBas, sites;
    Application *application;
    //TODO Ajouter diagramme
public:
    Carapace();
    Carapace(Application *);
    //TODO Ajouter destructeur a la fin pour ne pas oublier de pointeurs
    const vector<Point> & getContourHaut() const;
    const vector<Point> & getContourBas() const;
    const vector<Point> & getSites() const;
    void setContourHaut(const vector<Point> &);
    void setContourBas(const vector<Point> &);
    void setSites(const vector<Point> &);
    Point getSommetHaut()const;
};

#endif // CARAPACE_H
