#include "equationdroite.h"

EquationDroite::EquationDroite(const double & a, const double & b) : a(a), b(b) {}

EquationDroite::EquationDroite(const Point & p1, const Point & p2) : a(), b(){
    a = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
    b = p1.getY() - a * p1.getX();
}

EquationDroite::EquationDroite(const EquationDroite & ed) : a(ed.a), b(ed.b) {}

EquationDroite::operator string() const{
    ostringstream oss;
    oss << "y = " << a << "x + " << b;
    return oss.str();
}

double EquationDroite::getA()const{
    return this->a;
}

double EquationDroite::getB()const{
    return this->b;
}

void EquationDroite::setA(const double & a){
    this->a = a;
}

void EquationDroite::setB(const double & b){
    this->b = b;
}
