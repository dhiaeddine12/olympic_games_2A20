#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "sportifs.h"
#include <QMessageBox>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator( new QIntValidator(0, 9999999, this));
    ui->tab_sportifs->setModel(s.afficher());
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
QString type_sport=ui->le_typesport->text();
int age=ui->le_age->text().toInt();
sportifs s(id,nom,prenom,type_sport,age);

bool test=s.ajouter();
QMessageBox msgBox;
if (test)
{
    msgBox.setText("echec d ajout");
     ui->tab_sportifs->setModel(s.afficher());
}
else
    msgBox.setText("ajout avec succes.");
   msgBox.exec();

}

void MainWindow::on_pb_supprimer_clicked()
{
    sportifs s1; s1.setid(ui->le_id_supp->text().toInt());
    bool test=s1.supprimer(s1.getid());
    QMessageBox msgBox;
    if (test)
    {
        msgBox.setText("suppression avec succes.");
        ui->tab_sportifs->setModel(s.afficher());
    }
    else
        msgBox.setText("Echec de suppression");
       msgBox.exec();


}



void MainWindow::on_pb_modifier_clicked()
{
    int id=ui->le_id_2->text().toInt();
       QString nom=ui->le_nom_2->text();
       QString prenom=ui->le_prenom_2->text();
       QString type_sport=ui->le_typesport_2->text();
       int age=ui->le_age_2->text().toInt();

       sportifs s(id,nom,prenom,type_sport,age);
        bool test=s.modifier(id);
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("DONE"),
            QObject::tr("Modified Successfully !"), QMessageBox::Ok);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("ERROR"),
            QObject::tr("Modification Failed !"), QMessageBox::Ok);
        }

       ui->tab_sportifs->setModel(s.afficher());

}
