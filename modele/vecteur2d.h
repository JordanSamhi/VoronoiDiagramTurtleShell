#ifndef VECTEUR2D_H
#define VECTEUR2D_H

#include <iostream>
#include <sstream>

using namespace std;

template <class T>
const T operator - (const T & u, const T & v){
    return u + -v;
}

class Vecteur2D{
private:
    /*! \a x , \a y coordonnées du vecteur dans le plan.*/
    double x, y;
public:
    /**
    * \ brief Constructeur à partir des coordonnées x et y.
    * \details Les coordonnées x et y sont par défaut mis à zéro.
    * \param x.
    * \param y.
    */
    explicit Vecteur2D(const double & x = 0, const double & y = 0);

    /**
    * \ brief Constructeur par copie à partir d'un vecteur.
    * \details Recopie les coordonnées du vecteur passé en paramètre dans \a x et \a y.
    * \param v.
    */
    Vecteur2D(const Vecteur2D &);

    /**
    * \ brief Destructeur.
    */
    virtual ~Vecteur2D();

    /**
    * \ brief getter du champ \a x.
    * \return \e double l'abcisse stockée dans le champ \a x.
    */
    double getX() const;

    /**
    * \ brief setter du champ \a x.
    * \details modifie la valeur du champ \a x.
    * \param x.
    */
    void setX(const double &);

    /**
    * \ brief getter du champ \a y.
    * \return \e double l'ordonnée stockée dans le champ \a y.
    */
    double getY() const;

    /**
    * \ brief setter du champ \a y.
    * \details modifie la valeur du champ \a y.
    * \param y.
    */
    void setY(const double &);

    /**
    * \ brief Opérateur d'addition entre deux vecteurs.
    * \param u.
    */
    Vecteur2D operator + (const Vecteur2D &) const;


    /**
    * \ brief Opérateur de multiplication parune facteur a.
    * \param a.
    */
    Vecteur2D operator * (const double &) const;
    /**
    * \brief - unaire (c'est-à- dire opposé d'un vecteur)
    **/
    Vecteur2D operator - () const;

    /**
    * \ brief Operateur de conversion Vecteur2D ===> string.
    * \details convertit les coordonnées du vecteur en des chaines de caractères.
    */
    operator string() const;

    /**
    * \ brief Test d'égalité avec un autre vecteur.
    * \details compare champ à champ les deux vecteurs.
    * \param objet.
    * \return \e bool true si égalité et false sinon.
    */
    bool operator==(const Vecteur2D&) const;

    /**
    * \ brief Test de différence avec un autre vecteur.
    * \details Exploite l'opérateur d'égalité.
    * \param objet.
    * \return \e bool true si inégalité et false sinon.
    */
    bool operator != (const Vecteur2D&) const;

    /**
    * \ brief Opérateur d'affectation.
    * \details Affecte les données du vecteur passé aux différents champs \a x et \a y.
    * \param objet.
    * \return \e Vecteur2D résultat de l'affectaion.
    */
    Vecteur2D operator = (const Vecteur2D &);

    /**
    * \ brief Surcharge l'affichage dans un flux.
    * \param flux.
    * \param u.
    * \return \e ostream flux.
    */
    friend ostream & operator << (ostream &, const Vecteur2D &);

    /**
    * \ brief Calcul du déterminant(u , v).
    *\param v.
    * \return \e double det(u, v).
    */
    double determinant(const Vecteur2D &) const;

    /**
    * \ brief Opérateur de multiplication ordinaire d'un vecteur par un favetur réel a.
    * \param a, v.
    */
};

inline const Vecteur2D operator* (const double a, const Vecteur2D & v){
    return v * a;
}

#endif // VECTEUR2D_H
