#include "TriangulationDelaunay.h"

TriangulationDelaunay::TriangulationDelaunay(vector<Point *> points) {
    Triangle *triangleFictif1, *triangleFictif2;
    triangleFictif1 = NULL;
    triangleFictif2 = NULL;

    //Tie permet de manipuler des tuples
    std::tie(triangleFictif1, triangleFictif2) = this->genererTrianglesFictifs(points);
    DT.push_back(triangleFictif1);
    DT.push_back(triangleFictif2);

    for (int i = 0; i < 3; i++) {
        //On ajoute les points à la triangulation s'ils n'y sont pas déjà
        if (find(this->points.begin(), this->points.end(), triangleFictif1->getLesTroisPoints()[i]) == this->points.end())
            this->points.push_back(triangleFictif1->getLesTroisPoints()[i]);
        if (find(this->points.begin(), this->points.end(), triangleFictif2->getLesTroisPoints()[i]) == this->points.end())
            this->points.push_back(triangleFictif2->getLesTroisPoints()[i]);
    }

    for (Point * point : points)
        this->calculerTriangulation(point);
}

std::tuple<Triangle *, Triangle*> TriangulationDelaunay::genererTrianglesFictifs(vector<Point *> points) {
    //On récupère les coordonées des bords
    double xMin, xMax, yMin, yMax;
    xMin = Outils::getxMin(points);
    xMax = Outils::getxMax(points);
    yMin = Outils::getyMin(points);
    yMax = Outils::getyMax(points);

    //On crée les 4 points
    this->coinInferieurGauche = new Point(xMin, yMin);
    this->coinSuperieurGauche = new Point(xMin, yMax);
    this->coinInferieurDroit = new Point(xMax, yMin);
    this->coinSuperieurDroit = new Point(xMax, yMax);

    // On crée les deux triangles fictifs du rectangle de depart
    Triangle *triangleFictif1, *triangleFictif2;
    triangleFictif1 = new Triangle(coinInferieurGauche, coinSuperieurGauche, coinInferieurDroit);
    triangleFictif2 = new Triangle(coinSuperieurGauche, coinInferieurDroit, coinSuperieurDroit);

    //Création des points supplémentaires pour les voisins fictifs des triangles fictifs.
    Point *ptVoisin1TF1, *ptVoisin2TF1, *ptVoisin1TF2, *ptVoisin2TF2;
    ptVoisin1TF1 = new Point(xMin - 1, yMin);
    ptVoisin2TF1 = new Point(xMin, yMin - 1);
    ptVoisin1TF2 = new Point(xMin, yMax + 1);
    ptVoisin2TF2 = new Point(xMax + 1, yMin);

    //On créé les triangles voisins des triangles de départ.
    Triangle *voisin1TriangleFictif1, *voisin2TriangleFictif1, *voisin1TriangleFictif2, *voisin2TriangleFictif2;
    voisin1TriangleFictif1 = new Triangle(ptVoisin1TF1, coinInferieurGauche, coinSuperieurGauche, true);
    voisin2TriangleFictif1 = new Triangle(ptVoisin2TF1, coinInferieurGauche, coinInferieurDroit, true);
    voisin1TriangleFictif2 = new Triangle(ptVoisin1TF2, coinSuperieurGauche, coinSuperieurDroit, true);
    voisin2TriangleFictif2 = new Triangle(ptVoisin2TF2, coinInferieurDroit, coinSuperieurDroit, true);

    //Ajout des voisins entre les triangles.
    triangleFictif1->ajouterVoisin(voisin1TriangleFictif1);
    triangleFictif1->ajouterVoisin(voisin2TriangleFictif1);
    triangleFictif1->ajouterVoisin(triangleFictif2);
    triangleFictif2->ajouterVoisin(voisin1TriangleFictif2);
    triangleFictif2->ajouterVoisin(voisin2TriangleFictif2);
    triangleFictif2->ajouterVoisin(triangleFictif1);

    return std::make_tuple(triangleFictif1, triangleFictif2);
}

void TriangulationDelaunay::calculerTriangulation(Point * nouveauPoint){
    //étape 1
    Triangle * Ti = determinerTriangleContenantNouveauPoint(nouveauPoint);
    //étape 2
    vector<Triangle*> *DTL = new vector<Triangle*>();
    determiner_DTL(nouveauPoint, Ti, DTL);
    vector<Triangle*> NTL = determiner_NTL(nouveauPoint, DTL);
    supprimerTriangles(DTL);

    //étape 3
    for (size_t i = 0; i < NTL.size(); i++)
        DT.push_back(NTL[i]);
    points.push_back(nouveauPoint);
}

void TriangulationDelaunay::determiner_DTL(const Point * nouveauPoint, Triangle* Ti, vector<Triangle*> * DTL){
    //étape 1
    DTL->push_back(Ti);
    //étape 2
    for (Triangle * triangle : Ti->getVoisins()) {
        if (Ti->getVoisins().size() > 0 && triangle != NULL && triangle->getVoisins().size() > 0 && triangle->appartient(DTL) == false)
            if (Outils::appartientACercle(nouveauPoint, &triangle->getCercle()))
                determiner_DTL(nouveauPoint, triangle, DTL); /*Appel récursif*/
    }
}

vector<Triangle*> TriangulationDelaunay::determiner_NTL(Point * nouveauPoint, vector<Triangle*> * DTL){
    vector<Triangle*> NTL;

    for (Triangle * triangle : *DTL){
        for (Triangle * triangleVoisin : triangle->getVoisins()){
            if (triangleVoisin->isNull()){
                //Creer un nouveau triangle Tl de sommet nouveauPoint et d’arete kij (arete commune aux triangles Ti et Tij
                vector<Point *> areteCommune = triangle->getAreteCommune(triangleVoisin);
                Triangle * Tl = new Triangle(nouveauPoint, areteCommune[0], areteCommune[1]);
                Tl->ajouterVoisin(triangleVoisin);
                NTL.push_back(Tl);
            }
            else if (!triangleVoisin->appartient(DTL)){
                //Créer un triangle Tl de sommet nouveauPoint et d'arête kij
                vector<Point *> areteCommune = triangle->getAreteCommune(triangleVoisin);
                Triangle * Tl = new Triangle(nouveauPoint, areteCommune[0], areteCommune[1]);
                //établir l'adjacence entre Tl et Tij
                Tl->ajouterVoisin(triangleVoisin);
                triangleVoisin->supprimerVoisin(triangle);
                triangleVoisin->ajouterVoisin(Tl);
                //Rajouter Tl à la liste NTL
                NTL.push_back(Tl);
            }
        }

        vector<Point *> areteCommune;
        for (Triangle * Tk : NTL){
            for (Triangle * Tl : NTL){
                if (Tk != Tl){
                    //mettre à jour si il y a lieu l'adjacence entre Tl et Tk
                    if (Tk->ontUneAreteCommune(Tl)){
                        Tl->ajouterVoisin(Tk);
                        Tk->ajouterVoisin(Tl);
                    }
                }
            }
        }
    }
    return NTL;
}

Triangle * TriangulationDelaunay::determinerTriangleContenantNouveauPoint(const Point * point){
    bool TriangleTrouve = false;
    int taille = DT.size(), i = 0;
    while (!TriangleTrouve && i < taille){
        if (Outils::pointEstDansTriangle(point, DT[i]))
            TriangleTrouve = true;
        else i++;
    }
    return DT[i];
}

void TriangulationDelaunay::supprimerTriangles(vector<Triangle*> * DTL){
    int indice;
    for (size_t i = 0; i < DTL->size(); i++){
        if ((indice = indiceTriangleDansDT(DTL->at(i))) != -1){
            DT[indice]->seSupprimerDeSesVoisins();
            DT.erase(DT.begin() + indice);
        }
    }
}

int TriangulationDelaunay::indiceTriangleDansDT(Triangle * triangle)const{
    bool TriangleTrouver = false;
    int taille = DT.size(), i = 0;

    while (!TriangleTrouver && i < taille){
        if (DT[i] == triangle){
            TriangleTrouver = true;
            return i;
        }
        else i++;
    }
    return -1;
}

vector<Triangle *> TriangulationDelaunay::getTriangulation() {
    vector<Triangle*> trianglesFinaux;
    for (size_t i = 0; i < this->DT.size(); i++)
        if (!this->DT[i]->contientPoint(this->coinInferieurDroit)
        && !this->DT[i]->contientPoint(this->coinInferieurGauche)
        && !this->DT[i]->contientPoint(this->coinSuperieurDroit)
        && !this->DT[i]->contientPoint(this->coinSuperieurGauche))
            trianglesFinaux.push_back(this->DT[i]);
        else
            this->DT[i]->setNull(true);
    return trianglesFinaux;
}

const vector<Triangle *> & TriangulationDelaunay::getDT()const{
    return this->DT;
}

const vector<Point *> & TriangulationDelaunay::getPoints()const{
    return this->points;
}
