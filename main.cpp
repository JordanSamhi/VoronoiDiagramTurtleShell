#include <QApplication>
#include "vue/application.h"

int main(int argc, char *argv[])
{
    QApplication Qapp(argc, argv);
    Application app;
    app.show();
    return Qapp.exec();
}
