#include "application.h"

Application::Application() : QMainWindow(){
    this->carapace = Carapace(this);
    this->controleur = Controleur(&this->carapace);
    this->genererInterface();
    this->genererMenu();
}

void Application::genererInterface(){
    //Fenetre centrale
    this->widgetFenetreCentral = new QWidget();
    //Layout de cette fenetre
    this->mainLayoutWidgetCentral = new QVBoxLayout();
    //Bouton de génération
    this->genererCarapaceBtn = new QPushButton("Générer carapace");
    //Vue pour dessiner
    this->vueDessin = new QGraphicsView();
    //Scene pour vue
    this->sceneDessin = new QGraphicsScene();
    //On ajoute la scene à la vue
    this->vueDessin->setScene(this->sceneDessin);
    //On ajoute la vue et le bouton au layout
    this->mainLayoutWidgetCentral->addWidget(this->vueDessin);
    this->mainLayoutWidgetCentral->addWidget(this->genererCarapaceBtn);
    //On applique le layout au widget central
    this->widgetFenetreCentral->setLayout(this->mainLayoutWidgetCentral);
    //Enfin le widget centrale de la main widget devient celui que nous venons de créer
    this->setCentralWidget(this->widgetFenetreCentral);

    QObject::connect(this->genererCarapaceBtn, SIGNAL(clicked(bool)), this, SLOT(genererCarapace()));
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

const Carapace & Application::getCarapace() const{
    return this->carapace;
}

void Application::update(){
//TODO METHODE DE MISE A JOUR DE DESSIN PAR RAPPORT A LA CARAPACE
//TODO Voir pour facteur
    //Dessins des contours
    this->sceneDessin->clear();
    QPolygon contourHaut, contourBas;
    int facteur = 70;
    for(size_t i = 0 ; i < this->carapace.getContourHaut().size() ; i++)
        contourHaut << QPoint(this->carapace.getContourHaut()[i].getX()*facteur, this->carapace.getContourHaut()[i].getY()*facteur);
    for(size_t i = 0 ; i < this->carapace.getContourBas().size() ; i++)
        contourBas << QPoint(this->carapace.getContourBas()[i].getX()*facteur, this->carapace.getContourBas()[i].getY()*facteur);
    this->sceneDessin->addPolygon(contourHaut);
    this->sceneDessin->addPolygon(contourBas);
}

void Application::genererCarapace(){
    this->controleur.genererCarapace();
}
