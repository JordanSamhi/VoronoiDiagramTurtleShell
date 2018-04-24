#include "trianglepascal.h"

TrianglePascal::TrianglePascal(int taille) : taille(taille){
    creerTrianglePascal();
}

void TrianglePascal::creerTrianglePascal(){
    for (int i = 0; i <= this->taille; i++){
        /*LA diagonale est egale a 1*/
        this->trianglePascal[i][i] = 1;

        /*La premiere collonne est egale a 1*/
        this->trianglePascal[i][0] = 1;

        /*les autres cases du triangle suivent la formule suivante*/
        for (int j = 1; j < i; j++){
            this->trianglePascal[i][j] = this->trianglePascal[i - 1][j] + this->trianglePascal[i - 1][j - 1];
        }
    }
}

int TrianglePascal::get(const int & ligne, const int & colonne)const{
    if (ligne <= this->taille && colonne <= this->taille)
        return this->trianglePascal[ligne][colonne];
    return 0;
}
TrianglePascal::operator string() const{
    ostringstream oss;

    for (int i = 0; i <= taille; i++){
        for (int j = 0; j <= i; j++)
            if (this->trianglePascal[i][j])
                oss << this->trianglePascal[i][j] << " ";
        oss << endl;
    }
    return oss.str();
}
