#include "application.h"

Application::Application() : QMainWindow(){
    this->carapace = Carapace(this);
    this->generateurCarapaceAlea = GenerateurCarapaceAlea(&this->carapace);
    this->generateurCarapaceParfaite = GenerateurCarapaceParfaite(&this->carapace);
    this->genererInterface();
    this->genererMenu();
    this->genererBarreOutils();
}

Application::~Application(){
    /*
     * Tous les widgets de la fenetre sont détruits
     * lorsqu'elle se ferme donc pas besoin de les
     * détruire ici
     */
}

void Application::genererInterface(){
    this->sizeAndCenterWindow();
    this->setWindowIcon(QIcon(":/icones/carapace"));
    //Fenetre centrale
    this->widgetFenetreCentral = new QWidget();
    //Layout de cette fenetre
    this->mainLayoutWidgetCentral = new QVBoxLayout();
    this->layoutBoutons = new QHBoxLayout();
    //Bouton de génération
    this->genererCarapaceBtn = new QPushButton("Générer carapace");
    this->genererCarapaceBtn->setIcon(QIcon(":/icones/carapaceRouge"));
    this->genererNouveauxSitesBtn = new QPushButton("Générer nouveaux sites");
    this->genererNouveauxSitesBtn->setIcon(QIcon(":/icones/sitesPasRanges"));
    this->genererNouveauxSitesParfaitsBtn = new QPushButton("Générer nouveaux sites parfaits");
    this->genererNouveauxSitesParfaitsBtn->setIcon(QIcon(":/icones/sitesRanges"));
    this->genererCarapaceParfaitBtn = new QPushButton("Générer carapace parfaite");
    this->genererCarapaceParfaitBtn->setIcon(QIcon(":/icones/carapaceVerte"));
    //Vue pour dessiner
    this->vueDessin = new QGraphicsView();
    //Scene pour vue
    this->sceneDessin = new QGraphicsScene();
    //On ajoute la scene à la vue
    this->vueDessin->setScene(this->sceneDessin);
    //On ajoute la vue et le bouton au layout
    this->mainLayoutWidgetCentral->addWidget(this->vueDessin);
    this->layoutBoutons->addWidget(this->genererCarapaceParfaitBtn);
    this->layoutBoutons->addWidget(this->genererCarapaceBtn);
    this->layoutBoutons->addWidget(this->genererNouveauxSitesBtn);
    this->layoutBoutons->addWidget(this->genererNouveauxSitesParfaitsBtn);
    this->mainLayoutWidgetCentral->addLayout(layoutBoutons);
    //On applique le layout au widget central
    this->widgetFenetreCentral->setLayout(this->mainLayoutWidgetCentral);
    //Enfin le widget centrale de la main widget devient celui que nous venons de créer
    this->setCentralWidget(this->widgetFenetreCentral);

    QObject::connect(this->genererCarapaceBtn, SIGNAL(clicked(bool)), this, SLOT(genererCarapace()));
    QObject::connect(this->genererNouveauxSitesBtn, SIGNAL(clicked(bool)), this, SLOT(genererNouveauxSites()));
    QObject::connect(this->genererNouveauxSitesParfaitsBtn, SIGNAL(clicked(bool)), this, SLOT(genererNouveauxSitesParfaits()));
    QObject::connect(this->genererCarapaceParfaitBtn, SIGNAL(clicked(bool)), this, SLOT(genererCarapaceParfaite()));
}

void Application::sizeAndCenterWindow(){
    int heightScreen, widthScreen, heightWindow, widthWindow, x, y;
    double percentage = 0.8;
    heightScreen = QApplication::desktop()->screenGeometry().height();
    widthScreen = QApplication::desktop()->screenGeometry().width();
    heightWindow = heightScreen * percentage;
    widthWindow = widthScreen * percentage;
    x = widthScreen - widthWindow - (widthScreen - widthWindow)/2;
    y = heightScreen - heightWindow - (heightScreen - heightWindow)/2;
    this->move(x, y);
    this->setFixedSize(widthWindow, heightWindow);

    this->unite = widthWindow/20;
}

void Application::genererMenu(){
    this->menuFichier = this->menuBar()->addMenu("&Fichier");
    this->menuAffichage = this->menuBar()->addMenu("&Affichage");
    this->actionQuitter = new QAction("&Quitter", this);
    this->actionQuitter->setIcon(QIcon(":/icones/iconeQuitter"));
    this->actionQuitter->setToolTip("Quitter");
    this->actionCacherMontrerSites = new QAction("Afficher/Cacher sites", this);
    this->actionCacherMontrerSites->setCheckable(true);
    this->actionCacherMontrerSites->setIcon(QIcon(":/icones/site"));
    this->actionCacherMontrerSites->setToolTip("Afficher/Cacher sites");
    this->actionCacherMontrerTriangulation = new QAction("Afficher/Cacher triangulation", this);
    this->actionCacherMontrerTriangulation->setCheckable(true);
    this->actionCacherMontrerTriangulation->setIcon(QIcon(":/icones/triangle"));
    this->actionCacherMontrerTriangulation->setToolTip("Afficher/Cacher triangulation");
    this->menuFichier->addAction(this->actionQuitter);
    this->menuAffichage->addAction(this->actionCacherMontrerSites);
    this->menuAffichage->addAction(this->actionCacherMontrerTriangulation);
    QObject::connect(this->actionQuitter, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
    QObject::connect(this->actionCacherMontrerSites, SIGNAL(changed()), this, SLOT(afficherCacherSites()));
    QObject::connect(this->actionCacherMontrerTriangulation, SIGNAL(changed()), this, SLOT(afficherCacherTriangulation()));
}

void Application::genererBarreOutils(){
    this->barreOutils = this->addToolBar("Barre d'outils");
    this->barreOutils->setMovable(false);
    this->barreOutils->addAction(this->actionQuitter);
    this->barreOutils->addAction(this->actionCacherMontrerSites);
    this->barreOutils->addAction(this->actionCacherMontrerTriangulation);
}

const Carapace & Application::getCarapace() const{
    return this->carapace;
}

void Application::update(){
    //TODO diviser cette methode en plusieurs méthodes de dessin
    this->sceneDessin->clear();
    //Affichage contours
    this->dessinerContours();
    //Affichage sites
    this->afficherCacherSites();
    //Affichage Triangulation
    this->afficherCacherTriangulation();
}

void Application::dessinerContours(){
    //Listes de points
    QVector<QPointF> pointsHaut, pointsBas;
    //Assemblages des points dans des "paths"
    QPainterPath contourHaut, contourBas;
    for(size_t i = 0 ; i < this->carapace.getContourHaut().size() ; i++){
        pointsHaut.push_back(QPoint(this->carapace.getContourHaut()[i]->getX() * this->unite, this->carapace.getContourHaut()[i]->getY() * this->unite));
        pointsBas.push_back(QPoint(this->carapace.getContourBas()[i]->getX() * this->unite, this->carapace.getContourBas()[i]->getY() * this->unite));
    }
    if(!pointsHaut.isEmpty() && !pointsBas.isEmpty()){
        contourHaut = QPainterPath(pointsHaut.front());
        contourBas = QPainterPath(pointsBas.front());
    }
    for(int i = 1; i < pointsHaut.size(); ++i){
        contourHaut.lineTo(pointsHaut[i]);
        contourBas.lineTo(pointsBas[i]);
    }
    this->sceneDessin->addPath(contourHaut);
    this->sceneDessin->addPath(contourBas);
}

void Application::afficherCacherSites(){
    QPen pen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    QBrush brush(Qt::black);
    if(this->actionCacherMontrerSites->isChecked()){
        this->listeCercleSites.clear();
        for(size_t i = 0 ; i < this->carapace.getSites().size() ; i++)
            this->listeCercleSites.push_back(this->sceneDessin->addEllipse(this->carapace.getSites()[i]->getX() * this->unite, this->carapace.getSites()[i]->getY() * this->unite, 3, 3, pen, brush));
    }
    else{
        for(size_t i = 0 ; i < this->listeCercleSites.size() ; i++)
            this->sceneDessin->removeItem(this->listeCercleSites[i]);
        this->listeCercleSites.clear();
    }
}

void Application::afficherCacherTriangulation(){
    QPolygon poly;
    if(this->actionCacherMontrerTriangulation->isChecked()){
        this->listePolygonsDessin.clear();
        for(Triangle * triangle : this->carapace.getTriangles()){
            poly.clear();
            for(Point * p : triangle->getLesTroisPoints()){
                poly << QPoint(p->getX() * this->unite, p->getY() * this->unite);
            }
            this->listePolygonsDessin.push_back(this->sceneDessin->addPolygon(poly));
        }
    }
    else{
        for(size_t i = 0 ; i < this->listePolygonsDessin.size() ; i++)
            this->sceneDessin->removeItem(this->listePolygonsDessin[i]);
        this->listePolygonsDessin.clear();
    }
}

void Application::genererCarapace(){
    this->generateurCarapaceAlea.genererCarapace();
}

void Application::genererNouveauxSites(){
    this->generateurCarapaceAlea.genererNouveauxSites();
}

void Application::genererNouveauxSitesParfaits(){
    this->generateurCarapaceParfaite.genererNouveauxSites();
}

void Application::genererCarapaceParfaite(){
    this->generateurCarapaceParfaite.genererCarapace();
}
