#include "bezier.h"

Bezier::Bezier(){}

Bezier::~Bezier(){}

void Bezier::ajouterPoint(const Point & point){
    this->pointsDeControle.push_back(point);
}

const vector<Point> & Bezier::getPointsControle()const{
    return this->pointsDeControle;
}

int Bezier::taille() const{
    return this->pointsDeControle.size();
}


Point* Bezier::bezier(const double & t) const{
    int m = taille() - 1;
    double resultatX = 0, resultatY = 0;
    TrianglePascal tp(m);
    double d;
    for (int i = 0; i <= m; i++){
        d = Bernstein::bernstein(t, i, m, tp);
        resultatX += (d * this->pointsDeControle[i].getX());
        resultatY += (d * this->pointsDeControle[i].getY());
    }
    return new Point(resultatX, resultatY);
}

