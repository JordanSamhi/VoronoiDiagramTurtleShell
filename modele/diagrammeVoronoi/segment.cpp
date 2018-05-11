#include "segment.h"

Segment::Segment(){}

Segment::Segment(Point *a, Point*b):a(a), b(b){}

Point * Segment::getA()const{
    return this->a;
}

void Segment::setA(Point *p){
    this->a = p;
}

Point * Segment::getB()const{
    return this->b;
}

void Segment::setB(Point * p){
    this->b = p;
}

Segment::operator string()const{
    ostringstream oss;
    oss << "Segment[" << *this->a  << ", " << *this->b << "]";
    return oss.str();
}

double Segment::getLongueur()const{
    return sqrt(((this->b->getX() - this->a->getX()) * (this->b->getX() - this->a->getX())) + ((this->b->getY() - this->a->getY()) * (this->b->getY() - this->a->getY())));
}
