QT       += core gui sql multimedia multimediawidgets
QT       += core gui sql network printsupport charts
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    employe.cpp \
    gestion_medaille.cpp \
    gestionemploye.cpp \
    gestionmateriel.cpp \
    gestionsportif.cpp \
    gestionvolontaire.cpp \
    login.cpp \
    login_bd.cpp \
    main.cpp \
    mainwindow.cpp \
    materiel.cpp \
    medaille.cpp \
    sportifs.cpp \
    volontaire.cpp

HEADERS += \
    connection.h \
    employe.h \
    gestion_medaille.h \
    gestionemploye.h \
    gestionmateriel.h \
    gestionsportif.h \
    gestionvolontaire.h \
    login.h \
    login.h \
    login.h \
    login_bd.h \
    mainwindow.h \
    materiel.h \
    medaille.h \
    sportifs.h \
    volontaire.h

FORMS += \
    gestion_medaille.ui \
    gestionemploye.ui \
    gestionmateriel.ui \
    gestionsportif.ui \
    gestionvolontaire.ui \
    login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    tarduction.qrc
