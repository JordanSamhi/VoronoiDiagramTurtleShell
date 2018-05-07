QT += quick
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QT += widgets

SOURCES += \
        main.cpp \
    vue/application.cpp \
    modele/trianglepascal.cpp \
    modele/bernstein.cpp \
    modele/bezier.cpp \
    modele/carapace.cpp \
    controleur/outils.cpp \
    controleur/generateurCarapaces/generateurcarapacealea.cpp \
    controleur/generateurCarapaces/generateurcarapace.cpp \
    controleur/generateurCarapaces/generateurcarapaceparfaite.cpp \
    modele/triangulation/triangulationdelaunay.cpp \
    modele/triangulation/anglecapable.cpp \
    modele/triangulation/triangle.cpp \
    modele/triangulation/cercle.cpp \
    modele/triangulation/equationdroite.cpp \
    modele/triangulation/equationdroiteverticale.cpp \
    modele/point.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    vue/application.h \
    modele/trianglepascal.h \
    modele/bernstein.h \
    modele/bezier.h \
    modele/carapace.h \
    controleur/outils.h \
    controleur/generateurCarapaces/generateurcarapacealea.h \
    controleur/generateurCarapaces/generateurcarapace.h \
    controleur/generateurCarapaces/generateurcarapaceparfaite.h \
    modele/triangulation/triangulationdelaunay.h \
    modele/triangulation/anglecapable.h \
    modele/triangulation/triangle.h \
    modele/triangulation/cercle.h \
    modele/triangulation/equationdroite.h \
    modele/triangulation/equationdroiteverticale.h \
    controleur/erreur.h \
    modele/point.h \
    modele/vecteur2d.h
