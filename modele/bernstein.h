#ifndef BERNSTEIN_H
#define BERNSTEIN_H

#include "modele/trianglepascal.h"
#include <cmath>

class Bernstein{
public:
    static double bernstein(const double &, const int &, const int &, const TrianglePascal &);
};

#endif // BERNSTEIN_H
