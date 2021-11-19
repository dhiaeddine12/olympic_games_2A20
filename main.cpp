#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <connection.h>
#include <QtDebug>
#include "login.h"
#include "login_bd.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;

    login l;
    login_bd b;
    bool test =b.createconnect1();



    if(test)
{
    l.show();
    QMessageBox::information(nullptr,QObject::tr("database is open"),
      QObject::tr("connection successful.\n"
                         "Click Cancel to exit "),QMessageBox::Cancel);
    }

    else
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                      QObject::tr("connection failed.\n"
                                  "Click Cancel to exit."),QMessageBox::Cancel);

    return a.exec();
}
