#include "point.h"


Point::Point(const double & x, const double & y) : x(x), y(y) {}

Point::Point(const Point & p) : x(p.x), y(p.y) {}

Point::~Point() {}

double Point::getX() const{
    return x;
}

double Point::getY() const{
    return y;
}

void Point::setX(const double & nouveauX){
    x = nouveauX;
}

void Point::setY(const double & nouveauY){
    y = nouveauY;
}

Point::operator string() const{
    ostringstream oss;
    oss << "(" << x << "," << y << ")";
    return oss.str();
}

bool Point::operator==(const Point & p) const{
    return (fabs(x - p.getX()) < 0.0001 && fabs(y - p.getY()) < 0.0001);
}

bool Point::operator != (const Point &  p) const{
    return !(*this == p);
}

bool Point::estDans(vector<Point *> points) const{
    for(const Point * point : points)
        if (this == point)
            return true;
    return false;
}
const Point & Point::operator = (const Point & p){
    if (this != &p){
        x = p.getX();
        y = p.getY();
    }
    return *this;
}
