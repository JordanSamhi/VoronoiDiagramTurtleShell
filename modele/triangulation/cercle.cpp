#include "cercle.h"

Cercle::Cercle() : centre(new Point(0, 0)), rayon(0){}

Cercle::Cercle(Point *centre, const double & rayon) : centre(centre), rayon(rayon) {}

Cercle::Cercle(const Cercle & c) : centre(c.centre), rayon(c.rayon) {}

Cercle::~Cercle() {}

const Cercle &Cercle::operator =(const Cercle & c){
    if (this != &c){
        centre = c.centre;
        rayon = c.rayon;
    }
    return *this;
}

bool Cercle::operator==(const Cercle & c) const{
    return (centre == c.centre && (fabs(rayon - c.rayon) < 0.0001));
}

bool Cercle::operator != (const Cercle & c) const{
    return !(*this == c);
}

Point *Cercle::getCentre()const{
    return this->centre;
}

double Cercle::getRayon()const{
    return this->rayon;
}

void Cercle::setCentre(Point *c){
    this->centre = c;
}

void Cercle::setRayon(const double & r){
    this->rayon = r;
}

void Cercle::setTriangle(Triangle * t){
    this->triangle = t;
}

Triangle * Cercle::getTriangle()const{
    return this->triangle;
}
