#ifndef ARETE_H
#define ARETE_H

#include "Sommet.h"

using namespace std;

class Arete {
    string nom;
    int clef;
    Sommet * extremite1;
    Sommet * extremite2;

public:

    Arete();
    Arete(const string &, Sommet * extremiteA, Sommet * extremiteB, const int & clef);
    Arete(const Arete &);
    virtual ~Arete();

    const string & getNom()const;
    Sommet *  getExtremite1()const;
    Sommet *  getExtremite2()const;
    const int & getClef()const;

    void setNom(const string &);
    void setClef(const int &);
    void setExtremite1(Sommet *);
    void setExtremite2(Sommet *);

    bool operator == (const Arete &) const;
    bool operator != (const Arete &) const;
    const Arete & operator = (const Arete &);
    operator string() const;
    bool estEgal(const Sommet * s1, const Sommet * s2) const;
    bool positionsAreteSontEgales(Sommet * s1, Sommet *s2)const;
    Arete * clone() const;
};
inline ostream & operator <<(ostream & f, const Arete & a) {
    return f << (string)a;
}

#endif // ARETE_H
