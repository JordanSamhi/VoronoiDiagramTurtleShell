#ifndef FACE_H
#define FACE_H

#include "Element.h"
#include "ListeCirculaire.h"
#include "Arete.h"

class Face {
    string nom;
    int clef;
    Element<Arete*> *listeAretes;

public:
    Face();
    Face(const string &, const int &);
    Face(const Face &);
    virtual ~Face();

    Arete * getArete(const int &)const;
    const string & getNom()const;
    int getClef()const;
    int  nombreAretes() const;
    int  getIndiceArete(Arete *)const;

    void ajouterArete(Arete *);
    void setNom(const string &);
    void setClef(const int &);
//	void supprimerArete1(const int &);
    void supprimerArete(Arete *);

    operator string() const;
    bool operator == (const Face &) const;
    bool operator != (const Face &) const;
    const Face & operator = (const Face &);

    Element<Arete*> * getAretes()const;
};
inline ostream & operator <<(ostream & f, const Face & face) {
    return f << (string)face;
}

#endif // FACE_H
