#include "Face.h"

Face::Face():nom(""), clef(0), listeAretes(NULL){}

Face::Face(const string & n, const int & c): nom(n), clef(c), listeAretes(NULL){}

//A tester!!!!
Face::Face(const Face & f) : nom(f.nom), clef(f.clef), listeAretes(NULL)
{
    listeAretes = Element<Arete*>::copie(f.listeAretes);
}

Face::~Face()
{
    Element<Arete *>::effacer(listeAretes);
}

Arete * Face::getArete(const int & indice)const
{
    Element<Arete*> *l = listeAretes;
    for (int i = 0; i == indice; i++)
    {
        Element<Arete*>::depiler(l);
    }
    return l->v;
}

const string & Face::getNom()const
{
    return nom;
}
int Face::getClef()const
{
    return clef;
}
int Face::nombreAretes() const
{
    return tailleCirculaire(listeAretes);
}

int Face::getIndiceArete(Arete * a)const
{
    return Element<Arete *>::estDans(a, listeAretes);
}

void Face::ajouterArete(Arete * a){
    if (listeAretes == NULL){
        listeAretes = new Element<Arete*>(a, listeAretes);
        //lineaireToCirculaire(listeAretes);
    }
    else{
        //circulaireToLineaire(listeAretes);
        listeAretes = new Element<Arete*>(a, listeAretes);
        //lineaireToCirculaire(listeAretes);
    }
}

void Face::setNom(const string & n)
{
    nom = n;
}

void Face::setClef(const int & c)
{
    clef = c;
}

void Face::supprimerArete(Arete * a)
{
    Element<Arete*>::retirer(a, listeAretes);
}

Face::operator string() const
{
    ostringstream oss;
    oss << "Face" << endl;
    oss << "[" << endl;
    oss << "Nom : " << nom << ", Clef : " << clef <<  endl;
    oss << "Aretes : " << endl << toStringCirculaire(listeAretes, "", "\n", "");
    oss << "]";
    return oss.str();
}

// A TESTER!!!
bool Face::operator == (const Face & face) const
{
    bool egaux = (nom == face.nom )
                && (clef == face.clef);

    int taille = nombreAretes();

    Element<Arete *> * l = listeAretes;

    for (int i = 0; i < taille; i++)
    {
        if (l->v != face.listeAretes->v)
        {
            return false;
        }
        else
            l = l->s;
    }

        return egaux;
}

bool Face::operator != (const Face & face) const
{
    return !(*this == face);
}

const Face & Face::operator = (const Face & face)
{
    if (*this != face)
    {
        nom = face.nom;
        clef = face.clef;
        Element<Arete*> *l;
        for (l = face.listeAretes; l != NULL; l = l->s)
        {
            listeAretes = new Element<Arete*> (l->v, listeAretes);
        }
    }
    return *this;
}

Element<Arete*> * Face::getAretes()const{
    return this->listeAretes;
}
