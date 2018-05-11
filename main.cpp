#include <QApplication>
#include "vue/application.h"

#include "modele/point.h"
#include "modele/triangulation/triangulationdelaunay.h"

int main(int argc, char *argv[]){
    QApplication Qapp(argc, argv);
    Application app;
    app.show();
    return Qapp.exec();
    //TODO GERER LES DESTRUCTION DE TOUS LES OBJETS SINON MEMOIRE SATURE
}
