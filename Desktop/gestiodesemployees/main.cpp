 #include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    c.createconnect();
    MainWindow w;
    bool test;
    test=c.ouvrirConnexion();
    if (test ==true )
        QMessageBox::information(nullptr,"Data base","Connection succeful");
    else
        QMessageBox::warning(nullptr,"Data base","failed");
    w.show();

    return a.exec();
}
