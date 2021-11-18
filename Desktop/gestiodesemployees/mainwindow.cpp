#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "connection.h"
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
{ msgBox.setText("Echec d'ajout");
    ui->tab_employe->setModel(E.afficher());
}
    else
        msgBox.setText("Ajout avec succes");
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
    int id=ui->le_id_modifier->text().toInt();
    QString nom=ui->le_nom_modifier->text();
    QString prenom=ui->le_prenom_modifier->text();
     QString fonction=ui->le_fonction_modifier->text();
    int age=ui->le_age_modifier->text().toInt();
       QString sexe=ui->le_sexe_modifier->text();
    int annee_recrutement=ui->le_annee_recrutement_modifier->text().toInt();
    int absence =ui->le_absence_modifier->text().toInt();
    int heure_de_travail=ui->le_heure_de_travail_modifier->text().toInt();
Employe E(id,nom,prenom,fonction,age,sexe,annee_recrutement,absence,heure_de_travail);

    bool test=E.Modifier(id);
           QMessageBox msgbox;
           if(test)
               {
               QMessageBox::information(nullptr, QObject::tr("DONE"),
               QObject::tr("Modified Successfully !"), QMessageBox::Ok);

               }
               else
           {
                  QMessageBox::information(nullptr, QObject::tr("ERROR"),
                  QObject::tr("Modification Failed !"), QMessageBox::Ok);
           }
           ui->tab_employe->setModel(E.afficher());

}

void MainWindow::on_Pb_recherche_nom_clicked()
{
    Employe E;
    QString nom= ui->le_nom_r->text();
    ui->tabler->setModel(E.afficher_nom(nom));

}

void MainWindow::on_Pb_recherche_fonction_clicked()
{
    Employe E;
    QString fonction= ui->le_fonction_r->text();
    ui->tabler->setModel(E.afficher_fonction(fonction));
}

void MainWindow::on_Pb_recherche_identifiant_clicked()
{
    Employe E;
    int id= ui->le_id_r->text().toInt();
    ui->tabler->setModel(E.afficher_id(id));
}

void MainWindow::on_Pb_trier_age_clicked()
{
    QMessageBox msgBox;
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYE order by age ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("fonction"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("annee_recrutement"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("absence"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("heure_de_travail"));

    ui->tabler->setModel(model);
    ui->tabler->show();
    msgBox.setText("Tri avec succes.");
    msgBox.exec();
}

void MainWindow::on_Pb_trier_annee_de_recrutement_clicked()
{
    QMessageBox msgBox;
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYE order by annee_de_recrutement ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("fonction"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("annee_recrutement"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("absence"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("heure_de_travail"));

    ui->tabler->setModel(model);
    ui->tabler->show();
    msgBox.setText("Tri avec succes.");
    msgBox.exec();
}

void MainWindow::on_Pb_trier_sexe_clicked()
{
    QMessageBox msgBox;
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYE order by sexe ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("fonction"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("annee_recrutement"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("absence"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("heure_de_travail"));

    ui->tabler->setModel(model);
    ui->tabler->show();
    msgBox.setText("Tri avec succes.");
    msgBox.exec();
}

void MainWindow::on_Pb_image_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose"),"",tr("Image(*png *,jpg *,jpeg *.bmp *.gif"));
if (QString::compare(filename,QString())!=0)
{
    QImage image;
    bool valid = image.load(filename);
    if(valid)
    {
        image = image.scaledToWidth(ui->le_image->width(),Qt::SmoothTransformation);
        ui->le_image->setPixmap(QPixmap::fromImage(image));
    }
    else
    {
        //Error handling
    }
}
}
