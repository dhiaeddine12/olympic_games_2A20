#ifndef GESTIONVOLONTAIRE_H
#define GESTIONVOLONTAIRE_H

#include <QDialog>

#include"volontaire.h"
 #include<QSystemTrayIcon>
#include "arduino.h"


namespace Ui {
class Gestionvolontaire;
}

class Gestionvolontaire : public QDialog
{
    Q_OBJECT

public:
    explicit Gestionvolontaire(QWidget *parent = nullptr);
    ~Gestionvolontaire();
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
    Ui::Gestionvolontaire * ui;
    volontaire tmp;
      QSystemTrayIcon *mSystemTrayIcon ;
      QByteArray data; // variable contenant les données reçues

      Arduino A;
};


#endif // GESTIONVOLONTAIRE_H
