#include "outils.h"

void Outils::faireVarierStochastiquementLocalementUnPoint(Point * p) {
    p->setX(p->getX() + (Outils::getNombreAleatoireEntreDeuxNombres(-1, 1) * 0.1));
    p->setY(p->getY() + (Outils::getNombreAleatoireEntreDeuxNombres(-1, 1) * 0.1));
}

int Outils::getNombreAleatoireEntreDeuxNombres(const int a, const int b) {
    return (unsigned int)((QRandomGenerator::global()->generate() % (b+1-a)) + a);
}

Point Outils::calculerPointDeControleMilieu(const Point & pointDebut, const Point & pointFin){
    int limiteDroite = pointFin.getX() - pointDebut.getX(), xPointMilieu = limiteDroite/2, yPointMilieu;
    /*
     * Pour avoir des belles carapaces on limite la hauteur de la
     * hauteur du pointmilieu entre 40% et 90% de la limitedroite
     * Cela evite les carapaces en cloche et les carapaces plates
     */
    int limiteBasseYPointMilieu = limiteDroite * 0.4, limiteHauteYPointMilieu = limiteDroite * 0.9;
    yPointMilieu = Outils::getNombreAleatoireEntreDeuxNombres(limiteBasseYPointMilieu, limiteHauteYPointMilieu);
    return Point(xPointMilieu, yPointMilieu);
}
