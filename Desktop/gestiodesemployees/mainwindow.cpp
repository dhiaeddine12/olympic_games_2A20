#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QMessageBox>
#include <QIntValidator>
//#include <QDebug>
//#include <QTableWidget>
//#include <QRegExpValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
        ui->setupUi(this);
        ui->le_id->setValidator( new QIntValidator(0, 99999999, this));
        ui->tab_employe->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
   int id=ui->le_id->text().toInt();
   QString nom=ui->le_nom->text();
   QString prenom=ui->le_prenom->text();
    QString fonction=ui->le_fonction->text();
   int age=ui->le_age->text().toInt();
      QString sexe=ui->le_sexe->text();
   int annee_recrutement=ui->le_annee_recrutement->text().toInt();
   int absence =ui->le_absence->text().toInt();
   int heure_de_travail=ui->le_heure_de_travail->text().toInt();

Employe E(id,nom,prenom,fonction,age,sexe,annee_recrutement,absence,heure_de_travail);
bool test=E.ajouter();
QMessageBox msgBox;
if(test)
{ msgBox.setText("Ajout avec suces.");
    ui->tab_employe->setModel(E.afficher());
}
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}






void MainWindow::on_pushButton_clicked()
{
    Employe E1;
    E1.setid(ui->le_id_supp->text().toInt());
  bool test=E1.Supprimer(E1.getid());
  QMessageBox msgBox;
  if(test)
  { msgBox.setText("Suppression avec succes.");
      ui->tab_employe->setModel(E.afficher());
  }
  else
       msgBox.setText("Echec de suppression");
  msgBox.exec();
}

void MainWindow::on_pb_modifier_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
     QString fonction=ui->le_fonction->text();
    int age=ui->le_age->text().toInt();
       QString sexe=ui->le_sexe->text();
    int annee_recrutement=ui->le_annee_recrutement->text().toInt();
    int absence =ui->le_absence->text().toInt();
    int heure_de_travail=ui->le_heure_de_travail->text().toInt();
Employe E(id,nom,prenom,fonction,age,sexe,annee_recrutement,absence,heure_de_travail);

    bool test=E.Modifier();
           QMessageBox msgbox;
           if(test)
               {msgbox.setText("Modification avec succes.");
                   ui->tab_employe->setModel(E.afficher());
                   ui->le_id_modifier->setText("");
                   ui->le_nom_modifier->setText("");
                   ui->le_prenom_modifier->setText("");
                   ui->le_fonction_modifier->setText("");
                   ui->le_age_modifier->setText("");
                   ui->le_sexe_modifier->setText("");
                   ui->le_annee_recrutement_modifier->setText("");
                   ui->le_absence_modifier->setText("");
                   ui->le_heure_de_travail_modifier->setText("");

               }
               else
                   msgbox.setText("Echec de modification");
               msgbox.exec();

}
