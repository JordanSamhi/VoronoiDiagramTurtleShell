#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
#include <string>
#include <sstream>

#include "controleur/erreur.h"

using namespace std;

template <class T>
class Element
{
public:
    T v;
    Element<T> * s;

    Element(const T & v, Element<T> * s) : v(v), s(s) {}

    static int taille(const Element<T> * l);

    static const string toString(const Element<T> * p, const char * debut = "( ", const char * separateur = ", ", const char * fin = ")");

    static Element<T> * copie(const Element<T> * l);

    /**
    * recherche le 1er élément de l qui vérifie la condition
    *
    * renvoie un pointeur sur le 1er maillon de l vérifiant la condition
    * renvoie NULL si aucun élément de l ne vérifie la condition
    *
    * */
    template <class FONCTEUR>
    static  Element< T > * appartient(Element<T> * l, const FONCTEUR & condition);

    template<class FONCTEUR>
    static void insertionEnOrdre(const T & a, Element<T> * & l, const FONCTEUR & estPlusPetitOuEgal);


    static T depiler(Element<T> * & l);

    static void retirer(const T a, Element<T> * l);

    static void effacer(Element<T> * & l);

    static int estDans(const T v, const Element<T> * l);
    /**
    * renvoie un pointeur sur le dernier maillon de l.
    * lance une Erreur si l == NULL
    *
    * */
    static Element<T> * dernier(Element<T> * l);

    friend ostream & operator << (ostream & os, const Element<T> * p) { return os << Element<T>::toString(p); }

    //-------------------------- Element<T> ------------------------------
};

template<class T>
T Element<T>::depiler(Element<T> * & l)
{
    if (l == NULL)
        throw Erreur("Impossible de dépiler, la liste est vide");
    T temp = l->v;
    Element<T> * r = l;
    l = l->s;
    delete r;
    return temp;
}

template<class T>
void Element<T>::retirer(const T  a, Element<T> * l)
{
    if (l == NULL)
        throw Erreur("Impossible de dépiler, la liste est vide");
    //l contient au moins un maillon
    if (l->v == a) {
        Element<T> * r = l;
        l = l->s;
        delete r;
    }
    else
        Element::retirer(a, l->s);
}

template<class T>
void Element<T>::effacer(Element<T> * & l) {
    if (l != NULL) {
        Element::effacer(l->s);
        delete l->v; // A VOIR PEUT ETRE QU'IL FAUT PAS SUPPRIMER VU QUE C'EST PAS UN POINTEUR
        delete l;
        l = NULL;
    }
}

template <class T>
/* static */ int Element<T>::taille(const Element<T> * l)
{
    if (!l) return 0;
    else
        return 1 + Element<T>::taille(l->s);
}

/*template <class T>*/
/* static *//* int Element<T>::depiler(const Element<T> * l)
{
    if (!l) return 0;
    else
        return 1 + Element<T>::taille(l->s);
}*/

template <class T>
/*static*/ const string Element<T>::toString(const Element<T> * p, const char * debut, const char * separateur, const char * fin)
{
    ostringstream o;

    for (o << debut; p; p = p->s) o << *p->v << separateur;

    o << fin;

    return o.str();
}

template <class T>
/* static */ Element<T> * Element<T>::copie(const Element<T> * l)
{
    if (!l)
        return NULL;
    else
        return new Element<T>(l->v, Element<T>::copie(l->s));
}

template<class T>
 int Element<T>::estDans(const T  v, const Element<T> * l) {
    if (l == NULL)
        return -1;
    else if (v == l->v)
        return 0;
    return 1 + Element::estDans(v, l->s);
}
/**
* recherche le 1er élément de l qui vérifie la condition
*
* renvoie un pointeur sur le 1er maillon de l vérifiant la condition
* renvoie NULL si aucun élément de l ne vérifie la condition
*
* */
template <class T>
template <class FONCTEUR>
/*static*/  Element< T > * Element< T >::appartient(Element<T> * l, const FONCTEUR & condition)

{
    for (; l; l = l->s)
        if (condition(l->v))
            return l;

    return l;
}

/**
* Tâche : Insère  a dans l de telle sorte que l reste ordonnée par ordre croissant (l'élement en tête est le plus petit).
*
* Données : a (l'élément à insérer), l, estPlusPetitOuEgal qui est un foncteur de comparaison : au choix une fct dont la
* signature est : bool (*estPlusPetitOuEgal)(const T & a1, const T & a2)
*
* ou une instance d'une classe munie d'un opérateur dont la  signature est : bool operator () (const T & a1, const T & a2) const
* estPlusPetitOuEgal joue le rôle de fonction de comparaison
*
* Résultats : l modifiée par l'insertion
* Hypothèses : on suppose l ordonnée par ordre croissant à l'appel
*
* */
template <class T>
template <class FONCTEUR>
/* static */ void Element< T >::insertionEnOrdre(const T & a, Element<T> * & l, const FONCTEUR & estPlusPetitOuEgal)
{
    if (!l || estPlusPetitOuEgal(a, l->v)) l = new Element<T>(a, l);

    else insertionEnOrdre(a, l->s, estPlusPetitOuEgal);
}

/**
* renvoie un pointeur sur le dernier maillon de l.
* lance une Erreur si l == NULL
*
*
* */
template <class T>
/*static*/  Element<T> * Element<T> ::dernier(Element<T> * l)
{
    Element<T> * p;

    if(l == NULL)
        throw Erreur("le dernier élément d'une liste vide n'existe pas");

    // à présent l est non vide

    for (p = l; p->s; p = p->s);

    return p;
}

#endif // ELEMENT_H
