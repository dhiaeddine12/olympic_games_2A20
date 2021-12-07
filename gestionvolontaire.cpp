#include "gestionvolontaire.h"
#include "ui_gestionvolontaire.h"
#include <QMessageBox>
#include "volontaire.h"
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include<QUrl>
#include <QSystemTrayIcon>
#include <QWidget>
#include <QObject>
#include<QtMessageHandler>
#include <QRegExpValidator>
#include <QFileDialog>
#include <QTranslator>
#include<QDialog>
#include "connection.h"

Gestionvolontaire::Gestionvolontaire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gestionvolontaire)
{
    Connection c;


        c.createconnect();


        bool test;
        test=c.ouvrirConnexion();
    ui->setupUi(this);
    mSystemTrayIcon = new QSystemTrayIcon(this);
      mSystemTrayIcon->setIcon(QIcon("C:\\Users\\dhia\\Desktop\\gestion_sportif2\\logo.png")); // app icon
       mSystemTrayIcon->setVisible(true);


}
Gestionvolontaire::~Gestionvolontaire()
{
    delete ui;
}



void Gestionvolontaire::on_pushButton_ajouter_clicked()
{
                   int id =ui->ID->text().toInt() ;
                   QString nom=ui->NOM->text();
                   QString prenom=ui->PRENOM->text();
                   int age=ui->AGE->text().toInt();
                   QString categorie=ui->CATEGORIE->text();
                   int disponibilite =0;

                   //affectation des donnees
                   volontaire V (id,nom,prenom,age,categorie,disponibilite);
                   bool test=true;
                   test=V.ajouter();
                           if(test)
                               {

                                  QMessageBox msgBox ;
                                  QMessageBox::information(this,"information","volontaire ajouté");
                                   ui->comboBox_id->setModel(tmp.afficher_id());
                                   mSystemTrayIcon->showMessage(tr("notification"),tr("ajout avec succes"));


                                  }
                                   else
                                   {
                                       QMessageBox msgBox ;
                                       QMessageBox::information(this,"information","volontaire non ajouté");
                                       mSystemTrayIcon->showMessage(tr("notification"),tr("ajout echoué"));
                                   }



}

void Gestionvolontaire::on_pushButton_annuler_clicked()
{
    close();
}



void Gestionvolontaire::on_pushButton_afficher_clicked()
{
    ui->tablea->setModel(tmp.afficher_dispo());
   // ui->tablea->setModel(tmp.trier());
}

void Gestionvolontaire::on_pushButton_clicked()
{
     ui->tablea->setModel(tmp.afficher_non_dispo());
    // ui->tablea->setModel(tmp.trier2());
}

void Gestionvolontaire::on_pushButton_2_clicked()
{
    int id=ui->comboBox_id->currentText().toInt();
            bool test=tmp.supprimer(id);
            QMessageBox msgBox;

             if(test)
             {  msgBox.setText("Suppression avec succes");
                ui->tablea->setModel(tmp.afficher_dispo());
                ui->tablea->setModel(tmp.afficher_non_dispo());
                ui->comboBox_id->setModel(tmp.afficher_id());

             }
            else
            msgBox.setText("Echec de suppression");
            msgBox.exec();
}

void Gestionvolontaire::on_checkBox_stateChanged(int disponibilite)
{if (ui->mod_dispo->isChecked())
    {
        disponibilite=  1;
    }
    else {
        disponibilite = 0;
    }


}

void Gestionvolontaire::on_pushButton_3_clicked()
{
    int id=ui->ID_3->text().toInt();
           QString prenom=ui->PRENOM_3->text();
           QString nom=ui->NOM_3->text();
           QString categorie=ui->CATEGORIE_3->text();
           int age=ui->AGE_3->text().toInt();
          int disponibilite=0;

           if (ui->mod_dispo->isChecked())
           {
               disponibilite = 1;
           }
           else {
               disponibilite = 0;
           }


           //affectation des donnees
           bool test=tmp.modifier(id,nom,prenom,age,categorie,disponibilite);
           if (test)
           {
               ui->tablea->setModel(tmp.afficher_dispo());//refresh
               QMessageBox msgBox ;
               QMessageBox::information(this,"information","disponibilite modifié");
           }
           else
           {
               QMessageBox::critical(nullptr, QObject::tr("modifier la disponibilte"),
                                     QObject::tr("Erreur !.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
           }
}

/*void MainWindow::on_recherche_clicked(const QString &arg1)
{

    if (!(ui->radioButton_categorie->isChecked())&&!(ui->radioButton_id->isChecked()))
    {
            QMessageBox::critical (nullptr, QObject::tr("chercher echouer"),
                                  QObject::tr("connection failed .\n"
                                               "click cancel to exit ."), QMessageBox::Cancel);

    }
    else if (ui->radioButton_categorie->isChecked())
            {
                QString categorie= ui->recherche->text();
                bool test= true;
                        if(test==(true))
                        {
                ui->tablea->setModel(tmp.chercher(arg1));
                        }
            }
       else if (ui->radioButton_id->isChecked())
            {
               int id= ui->recherche->text().toInt() ;
                ui->tablea->setModel(tmp.chercher(arg1));}


}*/

//******************* historique*********************************************************************************







void Gestionvolontaire::on_pushButton_4_clicked()
{
    QPdfWriter pdf("C:\\Users\\Administrateur\\Downloads\\Atelier_Connexion\\PDFs\\Pdf.pdf");
                QPainter painter(&pdf);
                int i = 4000;
                painter.setPen(Qt::blue);
                painter.setFont(QFont("Arial", 30));
                painter.drawText(1100,1200,"l'historique volontaire  ");
                painter.setPen(Qt::black);
                painter.setFont(QFont("Arial", 50));
                painter.drawRect(100,100,7300,2600);

                painter.drawRect(0,3000,9600,500);
                painter.setFont(QFont("Arial", 9));
                painter.drawText(200,3300,"ID");
                painter.drawText(1200,3300,"NOM");
                painter.drawText(2400,3300,"PRENOM");
                painter.drawText(4000,3300,"AGE");
                painter.drawText(5000,3300,"CATEGORIE");
                painter.drawText(5800,3300,"DISPONIBILITE ");


                QSqlQuery query;
                query.prepare("select * from VOLONTAIRE");
                query.exec();
                while (query.next())
                {
                    painter.drawText(200,i,query.value(0).toString());
                    painter.drawText(1200,i,query.value(1).toString());
                    painter.drawText(2400,i,query.value(2).toString());
                    painter.drawText(4000,i,query.value(3).toString());
                    painter.drawText(5000,i,query.value(4).toString());
                    painter.drawText(5800,i,query.value(5).toString());




                    i = i + 500;
                }
                int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                if (reponse == QMessageBox::Yes)
                {

                    QDesktopServices::openUrl(QUrl::fromLocalFile("C:\\Users\\dhia\\Desktop\\gestion_sportif2\\PDFs\\Pdf.pdf\\Pdf.pdf"));
                    painter.end();
                }
                if (reponse == QMessageBox::No)
                {
                    painter.end();

            }
}

void Gestionvolontaire::on_lineEdit_textChanged(const QString &arg1)
{
    ui->tablea->setModel(tmp.chercher(arg1));
}




void Gestionvolontaire::on_pushButton_5_clicked()
{
    ui->tablea->setModel(tmp.somme());
}
