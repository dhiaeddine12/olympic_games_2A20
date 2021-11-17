#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "sportifs.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QPrinter>
#include <QPrintDialog>

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
    ui->tab_sportifs->setModel(s.afficher());
    msgBox.setText("echec d ajout");

}
else
    msgBox.setText("ajout avec succes.");

if(ui->le_id->text().isEmpty()||ui->le_nom->text().isEmpty()||ui->le_prenom->text().isEmpty()||ui->le_typesport->text().isEmpty()||ui->le_age->text().isEmpty())
          {
              QMessageBox::information(nullptr, QObject::tr("ERROR"),
              QObject::tr("Please Fill All Data"), QMessageBox::Ok);
          }
   msgBox.exec();

}

void MainWindow::on_pb_supprimer_clicked()
{
    sportifs s1; s1.setid(ui->le_id_supp->text().toInt());
    bool test=s1.supprimer(s1.getid());
    QMessageBox msgBox;
    if (test)
    {
        ui->tab_sportifs->setModel(s.afficher());
        msgBox.setText("suppression avec succes.");

    }
    else
        msgBox.setText("Echec de suppression");

    if(ui->le_id->text().isEmpty())
              {
                  QMessageBox::information(nullptr, QObject::tr("ERROR"),
                  QObject::tr("Please Fill All Data"), QMessageBox::Ok);
              }
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

       if(ui->le_id->text().isEmpty()||ui->le_nom->text().isEmpty()||ui->le_prenom->text().isEmpty()||ui->le_typesport->text().isEmpty()||ui->le_age->text().isEmpty())
                 {
                     QMessageBox::information(nullptr, QObject::tr("ERROR"),
                     QObject::tr("Please Fill All Data"), QMessageBox::Ok);
                 }
}

void MainWindow::on_pb_rechercher_clicked()
{
     sportifs s;
    QString nom= ui->le_nom_r->text();
     ui->tabler->setModel(s.afficher_nom(nom));



}




void MainWindow::on_pb_rechercher_id_clicked()
{
    sportifs s;
   int id= ui->le_id_r->text().toInt();;
    ui->tabler->setModel(s.afficher_id(id));

}

void MainWindow::on_pb_rechercher_type_sport_clicked()
{
    sportifs s;
   QString type_sport= ui->le_nom_r->text();
    ui->tabler->setModel(s.afficher_type_sport(type_sport));

}

void MainWindow::on_pb_trier_n_clicked()
{
    QMessageBox msgBox ;

      QSqlQueryModel *model = new QSqlQueryModel();
               model->setQuery("SELECT * FROM SPORTIF order by nom ASC");
               model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
               model->setHeaderData(3, Qt::Horizontal, QObject::tr("type_sport"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));


               ui->tabler->setModel(model);
               ui->tabler->show();
               msgBox.setText("Tri avec succès.");
               msgBox.exec();
}

void MainWindow::on_pb_trier_i_clicked()
{
    QMessageBox msgBox ;

      QSqlQueryModel *model = new QSqlQueryModel();
               model->setQuery("SELECT * FROM SPORTIF order by id ASC");
               model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
               model->setHeaderData(3, Qt::Horizontal, QObject::tr("type_sport"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));


               ui->tabler->setModel(model);
               ui->tabler->show();
               msgBox.setText("Tri avec succès.");
               msgBox.exec();
}

void MainWindow::on_pb_trier_a_clicked()
{
    QMessageBox msgBox ;

      QSqlQueryModel *model = new QSqlQueryModel();
               model->setQuery("SELECT * FROM SPORTIF order by age ASC");
               model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
               model->setHeaderData(3, Qt::Horizontal, QObject::tr("type_sport"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));


               ui->tabler->setModel(model);
               ui->tabler->show();
               msgBox.setText("Tri avec succès.");
               msgBox.exec();
}

void MainWindow::on_pb_update_clicked()
{
    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT* FROM SPORTIF");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("type_sport"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));

         ui->tab_sportifs->setModel(model);
         ui->tab_sportifs->show();

}



void MainWindow::on_pb_print_clicked()
{

    QPrinter printer;
    printer.setPrinterName("Canon LBP2900");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()== QDialog::Rejected) return;
 ui->textEdit->print(&printer);

}
