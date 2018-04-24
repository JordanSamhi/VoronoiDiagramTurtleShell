#include "vecteur2d.h"

Vecteur2D::Vecteur2D(const double & x, const double & y): x(x), y(y){}

Vecteur2D::Vecteur2D(const Vecteur2D & v) : x(v.x), y(v.y)
{}

Vecteur2D::~Vecteur2D(){}

double Vecteur2D::getX() const{
    return this->x;
}

void Vecteur2D::setX(const double & nouveauX){
    this->x = nouveauX;
}

double Vecteur2D::getY() const{
    return this->y;
}

void Vecteur2D::setY(const double &nouveauY){
    this->y = nouveauY;
}

Vecteur2D Vecteur2D::operator + (const Vecteur2D & u) const{
    return Vecteur2D(this->x + u.x, this->y + u.y);
}

Vecteur2D Vecteur2D::operator * (const double & a) const{
    return Vecteur2D(this->x * a, this->y * a);
}

Vecteur2D Vecteur2D::operator - () const{
    return Vecteur2D(-this->x, -this->y);
}

Vecteur2D::operator string() const{
    ostringstream oss;
    oss << "(" << this->x << "," << this->y << ")";
    return oss.str();
}

bool Vecteur2D::operator==(const Vecteur2D& v) const{
    return (this->x == v.getX() && this->y == (v.getY()));
}

bool Vecteur2D::operator != (const Vecteur2D&  v) const{
    return !(*this == v);
}

Vecteur2D Vecteur2D::operator = (const Vecteur2D & v){
    if (this != &v){
        this->x = v.getX();
        this->y = v.getY();
    }
    return *this;
}

ostream & operator << (ostream & os, const Vecteur2D & u){
    os << "(" << u.getX() << "," << u.getY() << ")";
    return os;
}
