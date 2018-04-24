#ifndef TRIANGLEPASCAL_H
#define TRIANGLEPASCAL_H

#include <iostream>
#include <sstream>

using namespace std;

class TrianglePascal{
public:
    const int static TAILLE_MAX = 15;
    int taille;
    int trianglePascal[TAILLE_MAX][TAILLE_MAX];

    TrianglePascal(int);
    void creerTrianglePascal();
    int get(const int &, const int &)const;
    operator string() const;
};

#endif // TRIANGLEPASCAL_H
