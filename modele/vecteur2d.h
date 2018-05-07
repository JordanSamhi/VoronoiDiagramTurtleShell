#ifndef VECTEUR2D_H
#define VECTEUR2D_H


/**
* \file Vecteur2D.h
* \brief  point du plan = vecteur du plan = couple (x,y) de coordonnées  réelles..
* \details Cette classe servira à représenter un point dans une forme.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

/**
* \brief Définit l'operateur - binaire.
* \tparam T u.
* \tparam T v.
* \return u - v.
*/
template <class T>
const T operator - (const T & u, const T & v)
{
    return u + -v;
}
class Vecteur2D {
    double x, y;  /*! \a x , \a y coordonnées du vecteur dans le plan.*/
public:
    /**
    * \ brief Constructeur à partir des coordonnées x et y.
    * \details Les coordonnées x et y sont par défaut mis à zéro.
    * \param x.
    * \param y.
    */
    explicit Vecteur2D(const double & x = 0, const double & y = 0) : x(x), y(y) {}

    /**
    * \ brief Constructeur par copie à partir d'un vecteur.
    * \details Recopie les coordonnées du vecteur passé en paramètre dans \a x et \a y.
    * \param v.
    */
    Vecteur2D(const Vecteur2D & v) : x(v.x), y(v.y)
    {}

    /**
    * \ brief Destructeur.
    */
    virtual ~Vecteur2D() {}

    /**
    * \ brief getter du champ \a x.
    * \return \e double l'abcisse stockée dans le champ \a x.
    */
    double getX() const
    {
        return x;
    }

    /**
    * \ brief setter du champ \a x.
    * \details modifie la valeur du champ \a x.
    * \param x.
    */
    void setX(const double & nouveauX)
    {
        x = nouveauX;
    }

    /**
    * \ brief getter du champ \a y.
    * \return \e double l'ordonnée stockée dans le champ \a y.
    */
    double getY() const
    {
        return y;
    }

    /**
    * \ brief setter du champ \a y.
    * \details modifie la valeur du champ \a y.
    * \param y.
    */
    void setY(const double &nouveauY)
    {
        y = nouveauY;
    }

    /**
    * \ brief Opérateur d'addition entre deux vecteurs.
    * \param u.
    */
    const Vecteur2D operator + (const Vecteur2D & u) const
    {
        return Vecteur2D(x + u.x, y + u.y);
    }


    /**
    * \ brief Opérateur de multiplication parune facteur a.
    * \param a.
    */
    const Vecteur2D operator * (const double & a) const
    {
        return Vecteur2D(x * a, y * a);
    }
    /**
    * \brief - unaire (c'est-à- dire opposé d'un vecteur)
    **/
    const Vecteur2D operator - () const
    {
        return Vecteur2D(-x, -y);
    }

    bool operator ^ (const Vecteur2D & w)const
    {
        // selon la règle des trois doigts
        bool vecteurSortant;
        double composanteZ;
        composanteZ = this->getX() * w.getY() - this->getY() * w.getX();

        vecteurSortant = (composanteZ >= 0);
        return vecteurSortant;
    }
    /*
    const double & operator * (const Vecteur2D & w)
    {
    double scalaire = this->getX() * w.getX() + this->getY * w.getY();

    return scalaire;
    }
    */
    /**
    * \ brief Operateur de conversion Vecteur2D ===> string.
    * \details convertit les coordonnées du vecteur en des chaines de caractères.
    */
    operator string() const
    {
        ostringstream oss;
        oss << "(" << x << "," << y << ")";
        return oss.str();
    }

    /**
    * \ brief Test d'égalité avec un autre vecteur.
    * \details compare champ à champ les deux vecteurs.
    * \param objet.
    * \return \e bool true si égalité et false sinon.
    */
    bool operator==(const Vecteur2D& v) const
    {
        return (x == v.getX() && y == (v.getY()));
    }

    /**
    * \ brief Test de différence avec un autre vecteur.
    * \details Exploite l'opérateur d'égalité.
    * \param objet.
    * \return \e bool true si inégalité et false sinon.
    */
    bool operator != (const Vecteur2D&  v) const
    {
        return !(*this == v);
    }

    /**
    * \ brief Opérateur d'affectation.
    * \details Affecte les données du vecteur passé aux différents champs \a x et \a y.
    * \param objet.
    * \return \e Vecteur2D résultat de l'affectaion.
    */
    const Vecteur2D operator = (const Vecteur2D & v)
    {
        if (this != &v)
        {
            x = v.getX();
            y = v.getY();
        }
        return *this;
    }

    /**
    * \ brief Surcharge l'affichage dans un flux.
    * \param flux.
    * \param u.
    * \return \e ostream flux.
    */
    friend ostream & operator << (ostream & os, const Vecteur2D & u)
    {
        os << "(" << u.getX() << "," << u.getY() << ")";
        return os;
    }


    /**
    * \ brief Calcul du déterminant(u , v).
    *\param v.
    * \return \e double det(u, v).
    */
    double determinant(const Vecteur2D &) const;
};



#endif // VECTEUR2D_H
