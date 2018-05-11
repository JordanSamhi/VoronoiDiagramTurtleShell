#ifndef GRAPHE_H
#define GRAPHE_H

#include "Face.h"

using namespace std;

class Graphe {
    Element<Sommet *> * listeSommets;
    Element<Arete  *> * listeAretes;
    Element<Face   *> * listeFaces;
    int prochaineClef;

public:
    Graphe();
    Graphe(const Graphe &);
    virtual ~Graphe();

    Sommet * creeSommet(const string & nom, Point *position);
    Arete  * creeArete(Sommet * debut, Sommet * fin, const string & nom);
    Face   * creeFace(const string & nom);

    int nombreSommets()const;
    int nombreAretes()const;
    int nombreFaces()const;
    int getProchaineClef()const;

    Sommet * getSommetParIndice(const int & indice)const;
    Arete* getAreteParSommets(const Sommet * s1, const Sommet * s2) const;
    Face * getFaceParSommets(Element<Sommet*> *lsommets)const;
    bool areteEntrePointsExiste(Sommet *, Sommet *)const;
    void ajouterSommets(Sommet *);

    Element<Sommet *> * getSommets()const;
    Element<Arete *> * getAretes()const;
    Element<Face *> *getFaces()const;

//	Element<pair<Sommet *, Arete*>> *adjacences(const Sommet * sommet)const; //TODO a faire

    operator string() const;
    const Graphe  & operator = (const Graphe  &);
};
inline ostream & operator <<(ostream & f, const Graphe & g) {
    return f << (string)g;
}

#endif // GRAPHE_H
