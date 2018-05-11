#ifndef LISTECIRCULAIRE_H
#define LISTECIRCULAIRE_H

#include <string>
#include <sstream>
#include "Element.h"

using namespace std;


//-------------------------------- conversion liste linéaire vers liste circulaire et vice-versa --------------------------------------------------------------------

/**
* lineaireToCirculaire
*
* DONNEES : l supposée non vide lineaire
* RESULTATS : l (modifiée) transformée en liste circulaire
* */
template <class T>
void lineaireToCirculaire(Element<T> * l)
{
    Element<T> * d = Element<T>::dernier(l);
    d->s = l;
}

/**
* circulaireToLineaire
*
* DONNEES : l supposée non vide circulaire
* RESULTATS : l (modifiée) transformée en liste linéaire
* */
template <class T>
void circulaireToLineaire(Element<T> * l)
{
    Element<T> * d;
    d = l;
    while (d->s != l) d = d->s;
    d->s = NULL;
}


//------------------------------------------------------------------------------------------------------

/**
* suppose que p est circulaire et non vide
*
*/
template <class T>
const string toStringCirculaire(const Element<T> * p, const char * debut = "(", const char * separateur = ", ", const char * fin = ")")
{
    circulaireToLineaire((Element<T> *)p);

    string s = Element<T>::toString(p, debut, separateur, fin);

    lineaireToCirculaire((Element<T> *) p);

    return s;
}

/**
* suppose que p est circulaire et non vide
*
*/
template <class T>
int tailleCirculaire(const Element<T> * p)
{
    int i;
    const Element<T> * r;
    i = 0; r = p;

    do
    {
        ++i; r = r->s;
    } while (r != p);

    return i;
}

template <class T>
Element<T> * creeTriangle(const T & A, const T & B, const T & C)
{
    Element<T> * p, *d;

    d = p = new Element<T>(C, NULL);
    p = new Element<T>(B, p);
    p = new Element<T>(A, p);
    d->s = p;
    return p;
}

#endif // LISTECIRCULAIRE_H
