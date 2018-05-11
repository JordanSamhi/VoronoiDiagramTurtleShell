#include "Sommet.h"

Sommet::Sommet() : nom(""), position(), degre(0), clef(0) {}

Sommet::Sommet(const string & nom, Point * position, const int & clef):
    nom(nom), position(position), degre(0), clef(clef){}

Sommet::Sommet(const Sommet & s): nom(s.nom), position(s.position), degre(s.degre),clef(s.clef){}

Sommet::~Sommet(){}

const string & Sommet::getNom()const
{
    return nom;
}

Point *Sommet::getPosition()const
{
    return position;
}

const int & Sommet::getDegre()const
{
    return degre;
}

const int & Sommet::getClef()const
{
    return clef;
}

void Sommet::setNom(const string & n)
{
    nom = n;
}

void Sommet::setPosition(Point *p)
{
    position = p;
}

void Sommet::setDegre(const int & d)
{
    degre = d;
}

void Sommet::setClef(const int & c)
{
    clef = c;
}

bool Sommet::operator == (const Sommet & s) const
{
    return nom == s.nom
                && clef == s.clef
                    && position == s.position
                        && degre == s.degre;
}

bool Sommet::operator != (const Sommet & s) const
{
    return !(*this == s);
}

const Sommet & Sommet::operator = (const Sommet & s)
{
    if (this != &s)
    {
        nom = s.nom;
        clef = s.clef;
        position = s.position;
        degre = s.degre;
    }
    return *this;
}

Sommet::operator string() const
{
    ostringstream oss;
    oss << "Sommet[" << "Nom : " << nom  << ", clef : " << clef << ", position : " << position << ", Degre : " << degre << "]";
    return oss.str();
}

Sommet * Sommet::clone() const
{
    return new Sommet(*this);
}
