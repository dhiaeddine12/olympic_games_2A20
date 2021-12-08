#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"volontaire.h"
 #include<QSystemTrayIcon>
#include "arduino.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_annuler_clicked();
    void on_pushButton_ajouter_clicked();

    void on_pushButton_afficher_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_3_clicked();

 //   void on_recherche_clicked(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_lineEdit_textChanged(const QString &arg1);


    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    volontaire tmp;
      QSystemTrayIcon *mSystemTrayIcon ;

      QByteArray data; // variable contenant les données reçues

      Arduino A;
};

#endif // MAINWINDOW_H
