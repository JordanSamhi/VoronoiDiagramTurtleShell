#ifndef ANGLECAPABLE_H
#define ANGLECAPABLE_H

#include "modele/point.h"
#include <cmath>
using namespace std;

class AngleCapable {
private:
    double alpha;
public:
    AngleCapable();
    AngleCapable(const Point *, const Point *, const Point *);
    operator string() const;
    bool operator==(const AngleCapable &) const;
    bool operator != (const AngleCapable &) const;
    const AngleCapable operator = (const AngleCapable &);
    const AngleCapable operator += (const AngleCapable &);
    double getAlpha()const;
    void setAlpha(const double &);
};
inline ostream & operator <<(ostream & f, const AngleCapable & ac) {
    return f << (string)ac;
}
#endif
