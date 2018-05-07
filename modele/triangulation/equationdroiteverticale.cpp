#include "equationdroiteverticale.h"

EquationDroiteVerticale::EquationDroiteVerticale(const double & c) : c(c) {}

EquationDroiteVerticale::EquationDroiteVerticale(const Point & p1) : c(){
    c = p1.getX();
}

EquationDroiteVerticale::EquationDroiteVerticale(const EquationDroiteVerticale & edv) : c(edv.c) {}

EquationDroiteVerticale::operator string() const{
    ostringstream oss;
    oss << "x = " << c;
    return oss.str();
}

const EquationDroiteVerticale & EquationDroiteVerticale::operator = (const EquationDroiteVerticale & edv){
    c = edv.c;
    return *this;
}

double EquationDroiteVerticale::getC()const{
    return this->c;
}

void EquationDroiteVerticale::setC(const double & c){
    this->c = c;
}
