#include "Arete.h"



Arete::Arete() :nom(""), extremite1(NULL), extremite2(NULL), clef(0) {}

Arete::Arete(const string & n, Sommet * extremiteA, Sommet * extremiteB, const int & c) :
    nom(n), extremite1(extremiteA), extremite2(extremiteB), clef(c)
{
    extremite1->setDegre(extremite1->getDegre() + 1);
    extremite2->setDegre(extremite2->getDegre() + 1);
}

Arete::Arete(const Arete & a) :nom(a.nom), extremite1(a.extremite1), extremite2(a.extremite2), clef(a.clef) {}


Arete::~Arete()
{
    extremite1->setDegre(extremite1->getDegre() - 1);
    extremite2->setDegre(extremite2->getDegre() - 1);
}

const string & Arete::getNom()const
{
    return nom;
}

const int & Arete::getClef()const
{
    return clef;
}

Sommet *  Arete::getExtremite1()const
{
    return extremite1;
}

Sommet *  Arete::getExtremite2()const
{
    return extremite2;
}

void Arete::setNom(const string & n)
{
    nom = n;
}

void Arete::setClef(const int & c)
{
    clef = c;
}

void Arete::setExtremite1(Sommet * s)
{
    extremite1 = s;
}

void Arete::setExtremite2(Sommet * s)
{
    extremite2 = s;
}

bool Arete::estEgal(const Sommet * s1, const Sommet * s2) const
{
    return (s1 == extremite1 && s2 == extremite2) || (s1 == extremite2 && s2 == extremite2);
}

bool Arete::positionsAreteSontEgales(Sommet *s1, Sommet *s2) const{
    return (s1->getPosition() == this->extremite1->getPosition() && s2->getPosition() == this->extremite2->getPosition()) ||
           (s1->getPosition() == this->extremite2->getPosition() && s2->getPosition() == this->extremite1->getPosition());
}

bool Arete::operator == (const Arete & objet) const
{
    return estEgal(objet.extremite1, objet.extremite2)
                && nom == objet.nom
                    && clef == objet.clef;

}
bool Arete::operator != (const Arete & a) const
{
    return !(*this == a);
}
const Arete & Arete::operator = (const Arete & a)
{
    if (*this != a)
    {
        nom = a.nom;
        clef = a.clef;
        extremite1 = a.extremite1;
        extremite2 = a.extremite2;
    }

    return *this;
}

Arete::operator string() const
{
    ostringstream oss;
    oss << "Arc[" << "Nom : " << nom << ", clef : " << clef << ", extremite 1 : " << extremite1->getNom() << ", extremite 2 : " << extremite2->getNom() << "]";
    return oss.str();
}

Arete * Arete::clone() const
{
    return new Arete(*this);
}

