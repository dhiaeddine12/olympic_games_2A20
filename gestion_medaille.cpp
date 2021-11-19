#include "gestion_medaille.h"
#include "ui_gestion_medaille.h"
#include"medaille.h"
#include"medaille.h"
#include <QString>
#include<QDateEdit>
#include <QTabWidget>
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
#include<QIntValidator>
#include<QFile>
#include<QFileDialog>
#include<QMultimedia>
#include<QMediaPlayer>
#include<QThread>



#include<QtCharts>
#include<QChartView>




gestion_medaille::gestion_medaille(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_medaille)


{

    ui->setupUi(this);
    ui->tableView->setModel(mdl.afficher());
    ui->lineEdit_ID_M->setValidator(new QIntValidator(1,99999999,this));
    //ui->lineEdit_DATE_OBTENTION->setValidator(new QIntValidator(0,3000,this));
    player = new QMediaPlayer(this);
}

gestion_medaille::~gestion_medaille()
{
    delete ui;
}


void gestion_medaille::on_pushButton_ajouter_clicked()
{

    int ID_M=ui->lineEdit_ID_M->text().toInt();
  QString TYPE_MEDAILLE=ui->lineEdit_TYPE_MEDAILLE->text();
  QString DATE_OBTENTION=ui->lineEdit_DATE_OBTENTION->text();
   QString PAYS=ui->lineEdit_PAYS->text();
  QString TYPE_S=ui->lineEdit_TYPE_S->text();
    medaille M(ID_M,TYPE_MEDAILLE,DATE_OBTENTION,PAYS,TYPE_S);
    bool test=M.ajouter();
            if (test)
            {
                // Refresh (Actualiser)
                ui->tableView->setModel(mdl.afficher());
                QMessageBox::information(nullptr,QObject::tr("ok"),
                                         QObject::tr("ajout effectué.\n"
                                                     "click Cancel to exit."),QMessageBox::Cancel);
                player->setMedia(QUrl::fromLocalFile("C:\\Users\\medac\\OneDrive\\Bureau\\olympic games\\medaille\\Clapping .mp3"));
                player->play();
                               player->setVolume(100);
                               qDebug()<<player->errorString();

                               QThread::sleep(1);
            }
else if ((ui->lineEdit_TYPE_S->text().isEmpty()||ui->lineEdit_TYPE_MEDAILLE->text().isEmpty()||ui->lineEdit_PAYS->text().isEmpty()||ui->lineEdit_ID_M->text().isEmpty()||ui->lineEdit_DATE_OBTENTION->text().isEmpty()))
            {
                QMessageBox::critical(nullptr,QObject::tr("not ok"),
                           QObject::tr("remplir tout les donées.\n"
                                       "click Cancel to exit."),QMessageBox::Cancel);
            }
            else
                QMessageBox::critical(nullptr,QObject::tr("not ok"),
                           QObject::tr("ajout non effectué.\n"
                                       "click Cancel to exit."),QMessageBox::Cancel);
            if(TYPE_MEDAILLE=="gold")
            {
                //ui->lineEdit_MAILEV_2->setText(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),4)).toString());
                //ui->lineEdit_test->setText(ui->tableView_somme->model()->data(ui->tableView_somme->model()->index(index.row,3)))
            }
}


void gestion_medaille::on_pushButton_supprimer_clicked()
{
 int id=ui->lineEdit_sup->text().toInt();

 bool test1=mdl.supprimer(id);
 if (test1)
 {
     // Refresh (Actualiser)
      ui->tableView->setModel(mdl.afficher());
     QMessageBox::information(nullptr,QObject::tr("ok"),
                              QObject::tr("supression effectué.\n"
                                          "click Cancel to exit."),QMessageBox::Cancel);
     player->setMedia(QUrl::fromLocalFile("C:\\Users\\medac\\OneDrive\\Bureau\\olympic games\\medaille\\Clapping .mp3"));
     player->play();
                    player->setVolume(100);
                    qDebug()<<player->errorString();

                    QThread::sleep(1);
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
  QString DATE_OBTENTION=ui->lineEdit_annee_3->text();
   QString PAYS=ui->lineEdit_pays_3->text();
  QString TYPE_S=ui->lineEdit_typeS_3->text();
   bool test=m.modifier(ID_M,TYPE_MEDAILLE,DATE_OBTENTION,PAYS,TYPE_S);

    if (test)
    {
        // Refresh (Actualiser)
         ui->tableView->setModel(mdl.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("modification effectué.\n"
                                             "click Cancel to exit."),QMessageBox::Cancel);

    }
    else if ((ui->lineEdit_idM_3->text().isEmpty()))
                {
                    QMessageBox::critical(nullptr,QObject::tr("not ok"),
                               QObject::tr("donne l id de medaille\n"
                                           "click Cancel to exit."),QMessageBox::Cancel);
                }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                   QObject::tr("modification non effectué.\n"
                               "Click Cancel to exit."),QMessageBox::Cancel);
}

/*void gestion_medaille::on_sendBtn_clicked()
{
    Smtp* smtp = new Smtp("dhia.zeddini.14@gmail.com",ui->mail_pass->text(), "Smtp.gmail.com");
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    //(const QString &from, const QString &to, const QString &subject, const QString &body)
        if( !files.isEmpty() )
            smtp->sendMail("dhia.zeddini.14@gmail.com", ui->rcpt->text() ,ui->sujet->text(), ui->msg->toPlainText(), files );
        else
            smtp->sendMail("dhia.zeddini.14@gmail.com", ui->rcpt->text() ,ui->sujet->text(),ui->msg->toPlainText());
}

void gestion_medaille::on_browseBtn_clicked()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );
}
*/

void gestion_medaille::on_triM_clicked()
{
    medaille m;
    ui->tableView->setModel(mdl.triM());

}

void gestion_medaille::on_triA_clicked()
{
    medaille m;
    ui->tableView->setModel(mdl.triAn());
}

void gestion_medaille::on_triID_clicked()
{
    medaille m;
    ui->tableView->setModel(mdl.triI());
}

void gestion_medaille::on_pushButton_rech_clicked()
{
    QString rech=ui->lineEdit_rech->text();

             ui->tableView->setModel(mdl.rechercherP(rech));
             ui->lineEdit_rech->clear();

}

void gestion_medaille::on_calendarWidget_clicked(const QDate &date)
{
    QString date_t=date.toString("dd/MM/yyyy");
    ui->tableView->setModel(mdl.rechercherD(date_t));
}




void gestion_medaille::on_somme_clicked()
{

}

void gestion_medaille::on_stat_clicked()
{

    QSqlQueryModel * model= new QSqlQueryModel();
                                model->setQuery("select * from MEDAILLE where ID_M between 12 and 78 ");
                                float nbr1=model->rowCount();
                                model->setQuery("select * from MEDAILLE where ID_M >12 ");
                                float nbr2=model->rowCount();
                                model->setQuery("select * from MEDAILLE where ID_M >78 ");
                                float nbr3=model->rowCount();
                                float total=nbr1+nbr2+nbr3;
                                QString a=QString(" ID_M between 12 and 78 "+QString::number((nbr1*100)/total,'f',2)+"%" );
                                QString b=QString(" ID_M >12 "+QString::number((nbr2*100)/total,'f',2)+"%" );
                                QString c=QString("  ID_M >78 "+QString::number((nbr3*100)/total,'f',2)+"%" );
                                QPieSeries *series = new QPieSeries();
                                series->append(a,nbr1);
                                series->append(b,nbr2);
                                series->append(c,nbr3);
                        if (nbr1!=0)
                        {QPieSlice *slice = series->slices().at(0);
                         slice->setLabelVisible();
                         slice->setPen(QPen());}
                        if ( nbr2!=0)
                        {
                                 // Add label, explode and define brush for 2nd slice
                                 QPieSlice *slice1 = series->slices().at(1);
                                 //slice1->setExploded();
                                 slice1->setLabelVisible();
                        }
                        if(nbr3!=0)
                        {
                                 // Add labels to rest of slices
                                 QPieSlice *slice2 = series->slices().at(2);
                                 //slice1->setExploded();
                                 slice2->setLabelVisible();
                        }
                                // Create the chart widget
                                QChart *chart = new QChart();
                                // Add data to chart with title and hide legend
                                chart->addSeries(series);
                                chart->setTitle("Pourcentage Par medaille  :Nombre Des medailles "+ QString::number(total));
                                chart->legend()->hide();
                                // Used to display the chart
                                QChartView *chartView = new QChartView(chart);
                                chartView->setRenderHint(QPainter::Antialiasing);
                                chartView->resize(1000,500);
                                chartView->show();


}
