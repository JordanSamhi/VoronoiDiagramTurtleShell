#include "Graphe.h"

Graphe::Graphe() :listeSommets(NULL), listeAretes(NULL), listeFaces(NULL), prochaineClef() {}

Graphe::Graphe(const Graphe & g):prochaineClef(g.prochaineClef)
{
    //copie des sommets
    listeSommets = Element<Sommet*>::copie(g.listeSommets);
    //copie des aretes
    listeAretes = Element<Arete*>::copie(g.listeAretes);
    //copie des faces
    listeFaces = Element<Face*>::copie(g.listeFaces);

}

Graphe::~Graphe()
{
    //FIXME voir pourquoi ça bug quand on décommente ça
    //à la sortie de la création de l'objet diagrammeVoronoi
    //le destructeur est appelé, il devrait pas
//    Element<Sommet*>::effacer(listeSommets);
//    Element<Arete*>::effacer(listeAretes);
//    Element<Face*>::effacer(listeFaces);
}

Sommet * Graphe::creeSommet(const string & nom, Point * position)
{
    listeSommets = new Element<Sommet*>(new Sommet(nom, position, prochaineClef++), listeSommets);
    return listeSommets->v;
}

void Graphe::ajouterSommets(Sommet *s){
    listeSommets = new Element<Sommet*>(s, listeSommets);
}

Arete  * Graphe::creeArete(Sommet * debut, Sommet * fin, const string & nom)
{
    //on test d'abord si les sommets existent
    if (Element<Sommet*>::estDans(debut, this->listeSommets) == -1)
        throw Erreur("Le debut de l'arete n'existe pas dans la liste des sommets du graphe");
    if (Element<Sommet*>::estDans(fin, this->listeSommets) == -1)
        throw Erreur("La fin de l'arete n'existe pas dans la liste des sommets du graphe");

    listeAretes = new Element<Arete*>(new Arete(nom, debut, fin, prochaineClef++), listeAretes);
    return listeAretes->v;
}

Face   * Graphe::creeFace(const string & nom)
{
    listeFaces = new Element<Face*>(new Face(nom, prochaineClef++), listeFaces);
    return listeFaces->v;
}

int Graphe::nombreSommets()const
{
    return Element<Sommet*>::taille(listeSommets);
}

int Graphe::nombreAretes()const
{
    return Element<Arete*>::taille(listeAretes);
}
int Graphe::nombreFaces()const
{
    return Element<Face*>::taille(listeFaces);
}

int Graphe::getProchaineClef()const
{
    return prochaineClef;
}

Sommet * Graphe::getSommetParIndice(const int & indice)const
{
    if (indice < Element<Sommet*>::taille(listeSommets))
    {
        Element<Sommet*> * l = listeSommets;
        for (int i = 0; i <= indice; i++)
            l = l->s;
        return l->v;
    }
    return NULL;
}

/* A BESOIN DE ADAJCENCES
Face * Graphe::getFaceParSommets(Element<Sommet*> *lsommets)const
{
    Element<Arete*> *lAretes;
    //TO DO
}
*/
Arete * Graphe::getAreteParSommets(const Sommet * s1, const Sommet * s2) const {
    Element<Arete*> * l;
    for (l = this->listeAretes; l; l = l->s)
        if (l->v->estEgal(s1, s2))
            return l->v;
    return NULL;
}

bool Graphe::areteEntrePointsExiste(Sommet * s1, Sommet *s2)const{
    Element<Arete*> * l;
    for (l = this->listeAretes; l; l = l->s)
        if (l->v->positionsAreteSontEgales(s1, s2))
            return true;
    return false;
}

/* A REVOIR !!!!
Element<pair<Sommet *, Arete*>> *Graphe::adjacences(const Sommet * sommet)const
{
    Element< Arete* > * l;
    Element< pair< Sommet *, Arete* > > * r;
    for (l = listeAretes , r = NULL; l; l = l->s) {
        if (sommet == l->v->getExtremite1())
            r = new Element<pair<Sommet *, Arete *>>(new pair< Sommet *, Arete* >(l->v->getExtremite2(), l->v), r);
        else if (sommet == l->v->getExtremite2())
            r = new Element<pair<Sommet*, Arete *>>(new pair< Sommet *, Arete *>(l->v->getExtremite1(), l->v), r);
    }
    return r;
}
*/
Graphe::operator string() const
{
    ostringstream oss;
    oss << "Graphe : " << endl;
    oss << "Sommets : " << endl << Element<Sommet*>::toString(listeSommets, "", "\n", "") << endl;
    oss << "Aretes : " << endl << Element<Arete*>::toString(listeAretes, "", "\n", "") << endl;
    oss << "Faces : " << endl << Element<Face*>::toString(listeFaces, "", "\n", "") << endl;

    return oss.str();
}

const Graphe  & Graphe::operator = (const Graphe  &)
{
    Element<Sommet*>::effacer(listeSommets);
    Element<Arete*>::effacer(listeAretes);
    Element<Face*>::effacer(listeFaces);

    listeSommets = Element<Sommet*>::copie(listeSommets);
    listeAretes = Element<Arete*>::copie(listeAretes);
    listeFaces = Element<Face*>::copie(listeFaces);
    return *this;
}

Element<Sommet *> * Graphe::getSommets()const{
    return this->listeSommets;
}

Element<Arete *> * Graphe::getAretes()const{
    return this->listeAretes;
}

Element<Face *> * Graphe::getFaces()const{
    return this->listeFaces;
}
