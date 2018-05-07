#include "AngleCapable.h"

AngleCapable::AngleCapable() :alpha(0) {}

AngleCapable::AngleCapable(const Point * p1, const Point * p, const Point * p2) : alpha(0){
    double sinus, cosinus;
    sinus = ((p2->getY() - p->getY())* (p1->getX() - p->getX())) - ((p1->getY() - p->getY())* (p2->getX() - p->getX()));
    cosinus = ((p2->getX() - p->getX())* (p1->getX() - p->getX())) + ((p2->getY() - p->getY())* (p1->getY() - p->getY()));
    alpha = atan2(sinus, cosinus);
}

AngleCapable::operator string() const{
    ostringstream oss;
    oss << alpha;
    return oss.str();
}

bool AngleCapable::operator==(const AngleCapable & ac) const{
    return (alpha == ac.alpha);
}

const AngleCapable AngleCapable::operator = (const AngleCapable & ac){
    if (this != &ac)
        alpha = ac.alpha;
    return *this;
}

bool AngleCapable::operator != (const AngleCapable & ac) const{
    return !(*this == ac);
}

const AngleCapable AngleCapable::operator += (const AngleCapable & ac){
    alpha += ac.alpha;
    return *this;
}

double AngleCapable::getAlpha()const{
    return this->alpha;
}

void AngleCapable::setAlpha(const double & a){
    this->alpha = a;
}
