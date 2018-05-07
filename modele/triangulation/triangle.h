#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <vector>
#include "Cercle.h"
#include "EquationDroiteVerticale.h"
#include "controleur/outils.h"
#include "modele/vecteur2d.h"

using namespace std;

class Triangle {
private:
    vector<Triangle *> voisins; //les trois voisins du triangle
    vector<Point *> lesTroisPoints;
    Cercle cercleCirconscrit;
    bool null;
public:
    Triangle();
    Triangle(Point *, Point *, Point *);
    Triangle(Point *, Point *, Point *, bool);
    ~Triangle();
    int getNbVoisins()const;
    void ajouterVoisin(Triangle *);
    void supprimerVoisin(Triangle *);
    bool contientPoint(Point *)const;
    void setVoisin(int , Triangle *);
    Point * getPoint(int) const;
    vector<Point *> getAreteCommune(const Triangle *) const;
    bool ontUneAreteCommune(const Triangle *);
    bool appartient(vector<Triangle*> *) const;
    bool operator==(const Triangle &) const;
    operator string() const;
    vector<Point *> mettreDansSensTrigo(vector<Point *>);
    bool operator!=(const Triangle &) const;
    void calculerCercleCirconscrit();
    void seSupprimerDeSesVoisins();
    const vector<Triangle *> & getVoisins()const;
    const vector<Point *> & getLesTroisPoints()const;
    const Cercle & getCercle()const;
    bool isNull()const;//TODO TROUVER MIEUX QUE CA
    void setCercle(const Cercle &);
    void setNull(const bool &);
};
inline ostream & operator <<(ostream & f, const Triangle & t) {
    return f << (string)t;
}
#endif
