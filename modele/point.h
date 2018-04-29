#ifndef Point_H
#define Point_H

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

template <class T>
const T operator - (const T & u, const T & v){
    return u + -v;
}

class Point{
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
    explicit Point(const double & x = 0, const double & y = 0);

    /**
    * \ brief Constructeur par copie à partir d'un vecteur.
    * \details Recopie les coordonnées du vecteur passé en paramètre dans \a x et \a y.
    * \param v.
    */
    Point(const Point &);

    /**
    * \ brief Destructeur.
    */
    virtual ~Point();

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
    Point operator + (const Point &) const;


    /**
    * \ brief Opérateur de multiplication parune facteur a.
    * \param a.
    */
    Point operator * (const double &) const;
    /**
    * \brief - unaire (c'est-à- dire opposé d'un vecteur)
    **/
    Point operator - () const;

    /**
    * \ brief Operateur de conversion Point ===> string.
    * \details convertit les coordonnées du vecteur en des chaines de caractères.
    */
    operator string() const;

    /**
    * \ brief Test d'égalité avec un autre vecteur.
    * \details compare champ à champ les deux vecteurs.
    * \param objet.
    * \return \e bool true si égalité et false sinon.
    */
    bool operator==(const Point&) const;

    /**
    * \ brief Test de différence avec un autre vecteur.
    * \details Exploite l'opérateur d'égalité.
    * \param objet.
    * \return \e bool true si inégalité et false sinon.
    */
    bool operator != (const Point&) const;

    /**
    * \ brief Opérateur d'affectation.
    * \details Affecte les données du vecteur passé aux différents champs \a x et \a y.
    * \param objet.
    * \return \e Point résultat de l'affectaion.
    */
    Point operator = (const Point &);

    /**
    * \ brief Surcharge l'affichage dans un flux.
    * \param flux.
    * \param u.
    * \return \e ostream flux.
    */
    friend ostream & operator << (ostream &, const Point &);

    /**
    * \ brief Calcul du déterminant(u , v).
    *\param v.
    * \return \e double det(u, v).
    */
    double determinant(const Point &) const;

    /**
    * \ brief Opérateur de multiplication ordinaire d'un vecteur par un favetur réel a.
    * \param a, v.
    */
    bool estDans(vector<Point>) const;
};

inline const Point operator* (const double a, const Point & v){
    return v * a;
}

#endif // Point_H
