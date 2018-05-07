#include <QApplication>
#include "vue/application.h"

#include "modele/point.h"
#include "modele/triangulation/triangulationdelaunay.h"

int main(int argc, char *argv[]){
    QApplication Qapp(argc, argv);
    Application app;
    app.show();
    return Qapp.exec();

    /*Point *p5, *p6, *p7, *p8, *p9, *p10, *p11, *p12, *p13;

    p5 = new Point(1, 1);
    p6 = new Point(2, 2);
    p7 = new Point(4, 3);
    p8 = new Point(5, 3);
    p9 = new Point(6, 2);
    p10 = new Point(7, 1);
    p11 = new Point(3, 1);
    p12 = new Point(4, 1);
    p13 = new Point(5, 1);

    vector<Point *> points;

    points.push_back(p5);
    points.push_back(p6);
    points.push_back(p7);
    points.push_back(p8);
    points.push_back(p9);
    points.push_back(p10);
    points.push_back(p11);
    points.push_back(p12);
    points.push_back(p13);

    TriangulationDelaunay triangulation(points);

    vector<Triangle *> triangles = triangulation.getTriangulation();
    for (Triangle * t : triangles)
        cout << *t << endl;
    return 0;*/
}
