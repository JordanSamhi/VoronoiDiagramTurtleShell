#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

class Point {
    double x, y;
public:
    Point(const double & x = 0, const double & y = 0);
    Point(const Point &);
    virtual ~Point();
    double getX() const;
    double getY() const;
    void setX(const double &);
    void setY(const double &);
    operator string() const;
    bool operator==(const Point &) const;
    bool operator != (const Point &) const;
    bool estDans(vector<Point *>) const;
    const Point & operator = (const Point &);
};
inline ostream & operator <<(ostream & f, const Point & p) {
    return f << (string)p;
}
#endif
