#include "Point.h"

Point::Point(const double & x, const double & y): x(x), y(y){}

Point::Point(const Point & v) : x(v.x), y(v.y)
{}

Point::~Point(){}

double Point::getX() const{
    return this->x;
}

void Point::setX(const double & nouveauX){
    this->x = nouveauX;
}

double Point::getY() const{
    return this->y;
}

void Point::setY(const double &nouveauY){
    this->y = nouveauY;
}

Point Point::operator + (const Point & u) const{
    return Point(this->x + u.x, this->y + u.y);
}

Point Point::operator * (const double & a) const{
    return Point(this->x * a, this->y * a);
}

Point Point::operator - () const{
    return Point(-this->x, -this->y);
}

Point::operator string() const{
    ostringstream oss;
    oss << "(" << this->x << "," << this->y << ")";
    return oss.str();
}

bool Point::operator==(const Point& v) const{
    return (this->x == v.getX() && this->y == (v.getY()));
}

bool Point::operator != (const Point&  v) const{
    return !(*this == v);
}

Point Point::operator = (const Point & v){
    if (this != &v){
        this->x = v.getX();
        this->y = v.getY();
    }
    return *this;
}

bool Point::estDans(vector<Point> points) const{
    for (int i = 0; i < 3; i++)
        if (*this == points[i])
            return true;
    return false;
}

ostream & operator << (ostream & os, const Point & u){
    os << "(" << u.getX() << "," << u.getY() << ")";
    return os;
}
