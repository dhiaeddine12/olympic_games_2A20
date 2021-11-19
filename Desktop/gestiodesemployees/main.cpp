#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include <QtDebug>
#include <QtCharts/QChartView>
#include <QPieSlice>
#include <QPieSeries>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator t;
    QStringList langue;
    langue <<"French" <<"English";
    QString lang = QInputDialog::getItem(NULL,"SELECT LANGUAGE",
                                        "LANGAGUE",langue );

    if(lang == "English")
    {
        t.load(":/english.qm");
    }

    if(lang != "french")
    {
        a.installTranslator(&t);
    }
    Connection c;

    bool test =c.createconnect();
//
    MainWindow w;

    if(test)
{
    w.show();
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
