#ifndef ERREUR_H
#define ERREUR_H

using namespace std;

#include <string>
#include <iostream>
#include <exception>

class Erreur : public exception
{
public:

    string message;

    Erreur() : message("Erreur !") {}

    Erreur(const string & messageErreur) : Erreur() { this->message += " " + messageErreur; }

    Erreur(const char * messageErreur) : Erreur((string)messageErreur) {}

    /**
    * vérifie que a == b
    * lance une exception si a != b
    *
    * */
    template <class T>
    inline static void testeEgalite(const T &  a, const T &  b, const char * message);

    /**
    * vérifie que a != b
    * lance une exception si a == b
    *
    * */
    template <class T>
    inline static void testeNonEgalite(const T &  a, const T &  b, const char * message);

    /**
    * vérifie que a <= b
    * lance une exception si a > b
    *
    * */
    template <class T>
    inline static void testePlusPetitOuEgal(const T & a, const T & b, const char * message);

    /**
    * lance une exception si x n'est pas dans [a,b]
    * */
    template <class T>
    inline static void testeAppartient(const T & a, const T & x, const T & b, const char * message);

    /**
    * lance une exception si d est vide
    * */
    inline static void testeNonVide(const void *d, const char * message);

    operator string() const { return this->message; }

    //virtual const char* what() const noexcept {return ((string)(*this)).c_str();}

};	//---------------------  classe Erreur -----------------------------------------

inline ostream & operator << (ostream & os, const Erreur & erreur)
{
    os << (string)erreur;
    return os;
}

/**
* vérifie que a == b
* lance une exception si a != b
*
* */
template <class T>
inline void Erreur::testeEgalite(const T & a, const T & b, const char * message)
{
#ifdef DEBUG
    if (a != b) throw Erreur(message);
#endif
}

/**
* vérifie que a != b
* lance une exception si a == b
*
* */
template <class T>
inline void Erreur::testeNonEgalite(const T & a, const T & b, const char * message)
{
#ifdef DEBUG
    if (a == b) throw Erreur(message);
#endif
}

/**
* vérifie que a <= b
* lance une exception si a > b
*
* */
template <class T>
inline /*static*/ void Erreur::testePlusPetitOuEgal(const T & a, const T & b, const char * message)
{
#ifdef DEBUG
    if (a > b) { throw Erreur(message); }
#endif
}

/**
* lance une exception si x n'est pas dans [a,b]
* */
template <class T>
inline /*static*/ void Erreur::testeAppartient(const T & a, const T & x, const T & b, const char * message)
{
    Erreur::testePlusPetitOuEgal<T>(a, x, message);
    Erreur::testePlusPetitOuEgal<T>(x, b, message);
}

/**
* lance une exception si d est vide
* */
inline /*static*/ void Erreur::testeNonVide(const void *d, const char * message)
{
    if (!d) throw Erreur(message);
}



#endif
