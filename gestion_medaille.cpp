#include "gestion_medaille.h"
#include "ui_gestion_medaille.h"
#include"medaille.h"
#include <QString>
#include<QDateEdit>
#include <QTabWidget>
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>

gestion_medaille::gestion_medaille(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_medaille)

{

    ui->setupUi(this);
    ui->tableView->setModel(mdl.afficher());
}

gestion_medaille::~gestion_medaille()
{
    delete ui;
}


void gestion_medaille::on_pushButton_ajouter_clicked()
{

    int ID_M=ui->lineEdit_ID_M->text().toInt();
  QString TYPE_MEDAILLE=ui->lineEdit_TYPE_MEDAILLE->text();
  int ANNEE_OBTENTION=ui->lineEdit_ANNEE_OBTENTION->text().toInt();
   QString PAYS=ui->lineEdit_PAYS->text();
  QString TYPE_S=ui->lineEdit_TYPE_S->text();
    medaille M(ID_M,TYPE_MEDAILLE,ANNEE_OBTENTION,PAYS,TYPE_S);
    bool test=M.ajouter();
            if (test)
            {
                // Refresh (Actualiser)
                ui->tableView->setModel(mdl.afficher());
                QMessageBox::information(nullptr,QObject::tr("ok"),
                                         QObject::tr("ajout effectué.\n"
                                                     "click Cancel to exit."),QMessageBox::Cancel);
            }
            else
                QMessageBox::critical(nullptr,QObject::tr("not ok"),
                           QObject::tr("ajout non effectué.\n"
                                       "click Cancel to exit."),QMessageBox::Cancel);
}


void gestion_medaille::on_pushButton_supprimer_clicked()
{
 int id=ui->lineEdit_sup->text().toInt();
 bool test=mdl.supprimer(id);
 if (test)
 {
     // Refresh (Actualiser)
      ui->tableView->setModel(mdl.afficher());
     QMessageBox::information(nullptr,QObject::tr("ok"),
                              QObject::tr("supression effectué.\n"
                                          "click Cancel to exit."),QMessageBox::Cancel);
 }
 else
     QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                QObject::tr("Supression non effectué.\n"
                            "Click Cancel to exit."),QMessageBox::Cancel);
}

void gestion_medaille::on_pushButton_Modifier_clicked()
{
    medaille m;
    int ID_M=ui->lineEdit_idM_3->text().toInt();
  QString TYPE_MEDAILLE=ui->lineEdit_type_m_3->text();
  int ANNEE_OBTENTION=ui->lineEdit_annee_3->text().toInt();
   QString PAYS=ui->lineEdit_pays_3->text();
  QString TYPE_S=ui->lineEdit_typeS_3->text();
   bool test=m.modifier(ID_M,TYPE_MEDAILLE,ANNEE_OBTENTION,PAYS,TYPE_S);

    if (test)
    {
        // Refresh (Actualiser)
         ui->tableView->setModel(mdl.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("modification effectué.\n"
                                             "click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                   QObject::tr("modification non effectué.\n"
                               "Click Cancel to exit."),QMessageBox::Cancel);
}
