#include "bezier.h"

Bezier::Bezier(){}

void Bezier::ajouterPoint(const Vecteur2D & point){
    this->pointsDeControle.push_back(point);
}

const vector<Vecteur2D> & Bezier::getPointsControle()const{
    return this->pointsDeControle;
}

int Bezier::taille() const{
    return this->pointsDeControle.size();
}


Vecteur2D Bezier::bezier(const double & t) const{
    int m = taille() - 1;
    double resultatX = 0, resultatY = 0;
    TrianglePascal tp(m);
    double d;
    for (int i = 0; i <= m; i++){
        d = Bernstein::bernstein(t, i, m, tp);
        resultatX += (d * this->pointsDeControle[i].getX());
        resultatY += (d * this->pointsDeControle[i].getY());
    }
    return Vecteur2D(resultatX, resultatY);
}

vector<Vecteur2D> Bezier::genererSitesSelonUneCourbeDeBezier(vector<Vecteur2D> listePointsControle){
    vector<Vecteur2D> pointsResultats;
    Bezier bez;
    int taille = listePointsControle.size();
    for (int i = 0; i < taille; i++)
        bez.ajouterPoint(listePointsControle[i]);
    Vecteur2D res;
    for (double t = 0; t <= 1; t += 0.1){
        res = bez.bezier(t);
        pointsResultats.push_back(res);
        cout << res << endl;
    }
    return pointsResultats;
}
