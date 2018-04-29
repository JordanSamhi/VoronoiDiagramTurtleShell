#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPoint>
#include <QPolygon>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QGraphicsScene>
#include <QDesktopWidget>
#include <QVector>
#include <QPainterPath>
#include <QGraphicsItem>
#include <QToolBar>
#include <QResizeEvent>
#include "modele/carapace.h"
#include "controleur/generateurCarapaces/generateurcarapacealea.h"
#include "controleur/generateurCarapaces/generateurcarapaceparfaite.h"

class Application : public QMainWindow
{
    Q_OBJECT
public:
    Application();
    //TODO Ajouter destructeur a la fin pour ne pas oublier de pointeurs
    ~Application();
    const Carapace & getCarapace() const;
    void update();

signals:

public slots:
    void genererCarapace();
    void genererNouveauxSites();
    void afficherCacherSites();
    void genererCarapaceParfaite();
    void genererNouveauxSitesParfaits();
private:
    QWidget *widgetFenetreCentral;
    QVBoxLayout *mainLayoutWidgetCentral;
    QHBoxLayout *layoutBoutons;
    QPushButton *genererCarapaceBtn, *genererNouveauxSitesBtn, *genererCarapaceParfaitBtn, *genererNouveauxSitesParfaitsBtn;
    QGraphicsView *vueDessin;
    QGraphicsScene *sceneDessin;
    QMenu *menuFichier, *menuAffichage;
    QAction *actionQuitter, *actionCacherMontrerSites;
    vector<QGraphicsEllipseItem *> listeCercleSites;
    QToolBar * barreOutils;

    Carapace carapace;
    GenerateurCarapaceAlea generateurCarapaceAlea;
    GenerateurCarapaceParfaite generateurCarapaceParfaite;
    int unite;

    void genererInterface();
    void sizeAndCenterWindow();
    void genererMenu();
    void genererBarreOutils();
};

#endif // APPLICATION_H
