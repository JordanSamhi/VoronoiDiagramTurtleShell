#include "bernstein.h"

double Bernstein::bernstein(const double & t, const int & i, const int & m, const TrianglePascal & tp){
    return tp.get(m, i) * pow((1 - t), (m - i)) * pow(t, i);
}
