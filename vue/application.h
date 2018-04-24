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

class Application : public QMainWindow
{
    Q_OBJECT
public:
    Application();
    ~Application();

signals:

public slots:

private:
    QWidget *widgetFenetreCentral;
    QVBoxLayout *mainLayoutWidgetCentral;
    QPushButton *genererCarapaceBtn;
    QGraphicsView *vueDessin;
    QMenu *menuFichier;
    QAction *actionQuitter;

    void genererInterface();
    void genererMenu();
};

#endif // APPLICATION_H
