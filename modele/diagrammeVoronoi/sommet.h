#ifndef SOMMET_H
#define SOMMET_H

#include "modele/point.h"

using namespace std;

class Sommet {
    int clef;
    string nom;
    Point *position;
    int degre;

public:
    Sommet();
    Sommet(const string & nom, Point * position, const int & clef);
    Sommet(const Sommet & s);
    virtual ~Sommet();

    const string & getNom()const;
    Point * getPosition()const;
    const int & getDegre()const;
    const int & getClef()const;

    void setNom(const string &);
    void setPosition(Point *);
    void setDegre(const int &);
    void setClef(const int & c);

    bool operator == (const Sommet & ) const;
    bool operator != (const Sommet &) const;
    const Sommet & operator = (const Sommet & );
    operator string() const;

    Sommet * clone() const;
};

inline ostream & operator <<(ostream & f, const Sommet & s) {
    return f << (string)s;
}

#endif // SOMMET_H
