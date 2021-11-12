#include "mainwindow.h"
#include "materiel.h"
#include <QtSql/QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QValidator>
#include <QIntValidator>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->table_materiel->setModel(m.afficher());

    ui->id->setValidator (new QIntValidator(0,99999999, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    int id=ui->id->text().toInt();
    QString nom=ui->nom->text();
    QString qualite=ui->qualite->text();
    QString date_achat=ui->date_achat->text();
    int prix=ui->prix->text().toInt();

    materiel m(id, prix, nom, qualite, date_achat);
    bool test=m.ajouter();
    QMessageBox msgBox;
    if(test)
  {
    msgBox.setText("ajout avec succée");
    ui->table_materiel->setModel(m.afficher());
    }

    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}


void MainWindow::on_pushButton_4_clicked()
{
    materiel m;
    QMessageBox msg;
    m.setid(ui->id->text().toInt());
    m.setprix(ui->prix->text().toInt());
    m.setnom(ui->nom->text());
    m.setqualite(ui->qualite->text());
    m.setdate_achat(ui->date_achat->text());

    bool test=m.modifier(m.getid());
    if(test)
    {
        msg.setText("modification avec succès");
        ui->table_materiel->setModel(m.afficher());
    }
    else
        msg.setText("echec de modification");

    msg.exec();

}

void MainWindow::on_pushButton_clicked()
{
    materiel m;
       QSqlQuery query;
       int id=ui->id->text().toInt();
       QString id_string=QString::number(id);
      if(m.recherche_id(id))
      {
          query.prepare("SELECT * FROM materiel WHERE id like :id");
          query.bindValue(0,id_string);
          query.exec();
          while(query.next())
      {
          ui->prix->setText(query.value(1).toString());
          ui->nom->setText(query.value(4).toString());
          ui->qualite->setText(query.value(2).toString());
          ui->date_achat->setText(query.value(3).toString());

       }
      }
}





void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox msgBox;
    materiel C1;
    C1.setid(ui->id->text().toInt());
    bool test=C1.supprimer(C1.getid());
    if (test){
        ui->id->clear();
        ui->table_materiel->setModel(m.afficher());
            msgBox.setText("clients supprimé");
            msgBox.exec();
           }
}

void MainWindow::on_pushButton_6_clicked()
{
    materiel m;
        if (ui->comboBox->currentText()=="Rechercher par ID")
        {
            int id=ui->lineEdit->text().toInt();
            if (m.recherche_id(id))
            {
                ui->table_materiel->setModel(m.afficher_id(id));
            }
        }
        else if(ui->comboBox->currentText()=="Rechercher par nom")
        {
            QString nom=ui->lineEdit->text();
            if (m.recherche_nom(nom))
            {
                ui->table_materiel->setModel(m.afficher_nom(nom));
            }

        }
        else if(ui->comboBox->currentText()=="Rechercher par prix")
        {
            int prix=ui->lineEdit->text().toInt();
            if(m.recherche_prix(prix))
            {
                ui->table_materiel->setModel(m.afficher_prix(prix));
            }
        }
}

void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox msgBox ;

  QSqlQueryModel *model = new QSqlQueryModel();
           model->setQuery("SELECT * FROM materiel order by id ASC");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("qualite"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_achat"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("nom"));

           ui->table_materiel->setModel(model);
           ui->table_materiel->show();
           msgBox.setText("Tri avec succès.");
           msgBox.exec();
}



void MainWindow::on_pushButton_10_clicked()
{
    QMessageBox msgBox ;

  QSqlQueryModel *model = new QSqlQueryModel();
           model->setQuery("SELECT * FROM materiel order by nom ASC");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("qualite"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_achat"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("nom"));

           ui->table_materiel->setModel(model);
           ui->table_materiel->show();
           msgBox.setText("Tri avec succès.");
           msgBox.exec();
}

void MainWindow::on_pushButton_11_clicked()
{
    QMessageBox msgBox ;

  QSqlQueryModel *model = new QSqlQueryModel();
           model->setQuery("SELECT * FROM materiel order by prix ASC");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("qualite"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_achat"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("nom"));

           ui->table_materiel->setModel(model);
           ui->table_materiel->show();
           msgBox.setText("Tri avec succès.");
           msgBox.exec();
}
