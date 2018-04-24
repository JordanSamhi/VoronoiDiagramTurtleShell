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
#include <QPushButton>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QGraphicsScene>
#include "modele/carapace.h"
#include "controleur/controleur.h"

class Application : public QMainWindow
{
    Q_OBJECT
public:
    Application();
    //TODO destructeur
    ~Application();
    const Carapace & getCarapace() const;
    void update();

signals:

public slots:
    void genererCarapace();
private:
    QWidget *widgetFenetreCentral;
    QVBoxLayout *mainLayoutWidgetCentral;
    QPushButton *genererCarapaceBtn;
    QGraphicsView *vueDessin;
    QGraphicsScene *sceneDessin;
    QMenu *menuFichier;
    QAction *actionQuitter;
    Carapace carapace;
    Controleur controleur;

    void genererInterface();
    void genererMenu();
};

#endif // APPLICATION_H
