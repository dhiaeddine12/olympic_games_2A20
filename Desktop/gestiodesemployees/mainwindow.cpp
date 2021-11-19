#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "connection.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QtCharts/QChartView>
#include <QPieSlice>
#include <QPieSeries>

//#include <QDebug>
//#include <QTableWidget>
//#include <QRegExpValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
            ui->setupUi(this);
            ui->le_id->setValidator( new QIntValidator(0, 99999999, this));
            ui->le_id_modifier->setValidator( new QIntValidator(0, 99999999, this));
            ui->le_id_r->setValidator( new QIntValidator(0, 99999999, this));
            ui->le_id_supp->setValidator( new QIntValidator(0, 99999999, this));
            ui->le_age->setValidator( new QIntValidator(0, 60, this));
            ui->le_age_modifier->setValidator( new QIntValidator(0, 60, this));
            ui->le_absence->setValidator( new QIntValidator(0, 99, this));
            ui->le_absence_modifier->setValidator( new QIntValidator(0, 99, this));
            ui->le_annee_recrutement->setValidator( new QIntValidator(0, 2500, this));
            ui->le_annee_recrutement_modifier->setValidator( new QIntValidator(0, 2500, this));
            ui->le_heure_de_travail->setValidator( new QIntValidator(0, 900, this));
            ui->le_heure_de_travail_modifier->setValidator( new QIntValidator(0, 900, this));
            ui->Box_sexe->addItem(" ");
            ui->Box_sexe->addItem("Femme");
            ui->Box_sexe->addItem("Homme");
            ui->Box_sexe_modifier->addItem(" ");
            ui->Box_sexe_modifier->addItem("Femme");
            ui->Box_sexe_modifier->addItem("Homme");



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
      //QString sexe=ui->le_sexe->text();
      QString sexe=ui->Box_sexe->currentText();
   int annee_recrutement=ui->le_annee_recrutement->text().toInt();
   int absence =ui->le_absence->text().toInt();
   int heure_de_travail=ui->le_heure_de_travail->text().toInt();

Employe E(id,nom,prenom,fonction,age,sexe,annee_recrutement,absence,heure_de_travail);
bool test=E.ajouter();
QMessageBox msgBox;
if(test)
{
    msgBox.setText("Echec d'ajout");
    ui->tab_employe->setModel(E.afficher());
}
    else
        msgBox.setText("Ajout avec succes");
    msgBox.exec();
}

void MainWindow::on_Pb_image_clicked()
{

    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName = QFileDialog::getOpenFileName(this,
    tr("Open Images"), "/home/rpi/Desktop/Picture/Sample Pictures", tr("Image Files (*.png *.jpg *.bmp)"));
    if (!fileName.isEmpty())
    {
        QImage image(fileName);
        ui->le_image->setPixmap(QPixmap::fromImage(image));
    }
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
       //QString sexe=ui->le_sexe_modifier->text();
       QString sexe=ui->Box_sexe_modifier->currentText();
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


QT_CHARTS_USE_NAMESPACE
void MainWindow::on_Pb_stat_absence_clicked()
{



                QSqlQueryModel * model= new QSqlQueryModel();
                model->setQuery("select * from EMPLOYE where ABSENCE <1 ");
                float tranche_absences1=model->rowCount();
                model->setQuery("select * from EMPLOYE where ABSENCE  between 1 and 10 ");
                float tranche_absences2=model->rowCount();
                model->setQuery("select * from EMPLOYE where ABSENCE >10 ");
                float tranche_absences3=model->rowCount();
                float total=tranche_absences1+tranche_absences2+tranche_absences3;
                QString a=QString("Aucune absence . "+QString::number((tranche_absences1*100)/total,'f',2)+"%" );
                QString b=QString("Entre 1 et 10 absences .  "+QString::number((tranche_absences2*100)/total,'f',2)+"%" );
                QString c=QString("Plus que 10 absences ."+QString::number((tranche_absences3*100)/total,'f',2)+"%" );
                QPieSeries *series = new QPieSeries();
                series->append(a,tranche_absences1);
                series->append(b,tranche_absences2);
                series->append(c,tranche_absences3);
                if (tranche_absences1!=0)
                {QPieSlice *slice = series->slices().at(0);
                    slice->setLabelVisible();
                    slice->setPen(QPen());}
                if ( tranche_absences2!=0)
                {
                    QPieSlice *slice1 = series->slices().at(1);
                    slice1->setLabelVisible();
                }
                if(tranche_absences3!=0)
                {
                    QPieSlice *slice2 = series->slices().at(2);
                    slice2->setLabelVisible();
                }
                QChart *chart = new QChart();
                chart->addSeries(series);
                chart->setTitle("Absence Par Pourcentage des Employes :Nombre Des Employes "+ QString::number(total));
                chart->legend()->hide();
                QChartView *chartView = new QChartView(chart);
                chartView->setRenderHint(QPainter::Antialiasing);
                chartView->resize(1000,500);
                chartView->show();
        }


void MainWindow::on_Pb_stat_heure_de_travail_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from EMPLOYE where HEURE_DE_TRAVAIL between 10 and 20 ");
    float tranche_heure1=model->rowCount();
    model->setQuery("select * from EMPLOYE where HEURE_DE_TRAVAIL  between 20 and 30 ");
    float tranche_heure2=model->rowCount();
    model->setQuery("select * from EMPLOYE where HEURE_DE_TRAVAIL between 30 and 45 ");
    float tranche_heure3=model->rowCount();
    float total=tranche_heure1+tranche_heure2+tranche_heure3;
    QString a=QString("Entre 10 et 20 ans . "+QString::number((tranche_heure1*100)/total,'f',2)+"%" );
    QString b=QString("Entre 20 et 30 ans .  "+QString::number((tranche_heure2*100)/total,'f',2)+"%" );
    QString c=QString("Entre 30 et 45 ans ."+QString::number((tranche_heure3*100)/total,'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
    series->append(a,tranche_heure1);
    series->append(b,tranche_heure2);
    series->append(c,tranche_heure3);
    if (tranche_heure1!=0)
    {QPieSlice *slice = series->slices().at(0);
        slice->setLabelVisible();
        slice->setPen(QPen());}
    if ( tranche_heure2!=0)
    {
        QPieSlice *slice1 = series->slices().at(1);
        slice1->setLabelVisible();
    }
    if(tranche_heure3!=0)
    {
        QPieSlice *slice2 = series->slices().at(2);
        slice2->setLabelVisible();
    }
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Heure de travail Par Pourcentage des Employes :Nombre Des Employes "+ QString::number(total));
    chart->legend()->hide();
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1000,500);
    chartView->show();
}

void MainWindow::on_Pb_stat_age_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from EMPLOYE where AGE between 20 and 30 ");
    float tranche_age1=model->rowCount();
    model->setQuery("select * from EMPLOYE where AGE  between 30 and 40 ");
    float tranche_age2=model->rowCount();
    model->setQuery("select * from EMPLOYE where AGE between 40 and 60 ");
    float tranche_age3=model->rowCount();
    float total=tranche_age1+tranche_age2+tranche_age3;
    QString a=QString("Entre 20 et 30 ans . "+QString::number((tranche_age1*100)/total,'f',2)+"%" );
    QString b=QString("Entre 30 et 40 ans .  "+QString::number((tranche_age2*100)/total,'f',2)+"%" );
    QString c=QString("Entre 40 et 60 ans ."+QString::number((tranche_age3*100)/total,'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
    series->append(a,tranche_age1);
    series->append(b,tranche_age2);
    series->append(c,tranche_age3);
    if (tranche_age1!=0)
    {QPieSlice *slice = series->slices().at(0);
        slice->setLabelVisible();
        slice->setPen(QPen());}
    if ( tranche_age2!=0)
    {
        QPieSlice *slice1 = series->slices().at(1);
        slice1->setLabelVisible();
    }
    if(tranche_age3!=0)
    {
        QPieSlice *slice2 = series->slices().at(2);
        slice2->setLabelVisible();
    }
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Age Par Pourcentage des Employes :Nombre Des Employes "+ QString::number(total));
    chart->legend()->hide();
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1000,500);
    chartView->show();
}

void MainWindow::on_Pb_mise_a_jour_clicked()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM  EMPLOYE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("fonction"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("annee_recrutement"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("absence"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("heure_de_travail"));

    ui->tab_employe->setModel(model);
    ui->tab_employe->show();
}
