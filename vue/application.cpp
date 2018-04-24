#include "application.h"

Application::Application() : QMainWindow(){
    //Fenetre centrale
    this->widgetFenetreCentral = new QWidget();
    //Layout de cette fenetre
    this->mainLayoutWidgetCentral = new QVBoxLayout();
    //Bouton de génération
    this->genererCarapaceBtn = new QPushButton("Générer carapace");
    //Vue pour dessiner
    this->vueDessin = new QGraphicsView();

    this->genererInterface();
    this->genererMenu();
}

void Application::genererInterface(){
    //On ajoute la vue et le bouton au layout
    this->mainLayoutWidgetCentral->addWidget(this->vueDessin);
    this->mainLayoutWidgetCentral->addWidget(this->genererCarapaceBtn);
    //On applique le layout au widget central
    this->widgetFenetreCentral->setLayout(this->mainLayoutWidgetCentral);
    //Enfin le widget centrale de la main widget devient celui que nous venons de créer
    this->setCentralWidget(this->widgetFenetreCentral);
}

void Application::genererMenu(){
    this->menuFichier = this->menuBar()->addMenu("&Fichier");
    this->actionQuitter = new QAction("&Quitter", this);
    this->menuFichier->addAction(this->actionQuitter);
    QObject::connect(this->actionQuitter, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
}

Application::~Application(){
    /*
     * Tous les widgets de la fenetre sont détruits
     * lorsqu'elle se ferme donc pas besoin de les
     * détruire ici
     */
}
