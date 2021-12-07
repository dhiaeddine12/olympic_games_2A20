#include "gestionmateriel.h"
#include "ui_gestionmateriel.h"
#include "materiel.h"
#include <QtSql/QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QValidator>
#include <QIntValidator>
#include <QPrintDialog>
#include<QFileDialog>
#include<QPrinter>
#include<QTextDocument>
#include<QTextStream>
#include"connection.h"

Gestionmateriel::Gestionmateriel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gestionmateriel)
{
    Connection c;


        c.createconnect();


        bool test;
        test=c.ouvrirConnexion();

     ui->setupUi(this);


    ui->table_materiel->setModel(m.afficher());

    ui->id->setValidator (new QIntValidator(0,99999999, this));
}

Gestionmateriel::~Gestionmateriel()
{
    delete ui;
}


void
Gestionmateriel::on_pushButton_2_clicked()
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


void
Gestionmateriel::on_pushButton_4_clicked()
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


void
Gestionmateriel::on_pushButton_clicked()
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



void
Gestionmateriel::on_pushButton_3_clicked()
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

void
Gestionmateriel::on_pushButton_6_clicked()
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

void
Gestionmateriel::on_pushButton_5_clicked()
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



void
Gestionmateriel::on_pushButton_10_clicked()
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

void
Gestionmateriel::on_pushButton_11_clicked()
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

void
Gestionmateriel::on_pushButton_7_clicked()
{
    QString strStream;
                  QTextStream out(&strStream);

                  const int rowCount = ui->table_materiel->model()->rowCount();
                  const int columnCount = ui->table_materiel->model()->columnCount();

                  out <<  "<html>\n"
                      "<head>\n"
                      "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                      <<  QString("<title>%1</title>\n").arg("strTitle")
                      <<  "</head>\n"
                      "<body bgcolor=#ffffff link=#5000A0>\n"

                     //     "<align='right'> " << datefich << "</align>"
                      "<center> <H1>Liste des Materiels </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                  // headers
                  out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                  for (int column = 0; column < columnCount; column++)
                      if (!ui->table_materiel->isColumnHidden(column))
                          out << QString("<th>%1</th>").arg(ui->table_materiel->model()->headerData(column, Qt::Horizontal).toString());
                  out << "</tr></thead>\n";

                  // data table
                  for (int row = 0; row < rowCount; row++) {
                      out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                      for (int column = 0; column < columnCount; column++) {
                          if (!ui->table_materiel->isColumnHidden(column)) {
                              QString data = ui->table_materiel->model()->data(ui->table_materiel->model()->index(row, column)).toString().simplified();
                              out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                          }
                      }
                      out << "</tr>\n";
                  }
                  out <<  "</table> </center>\n"
                      "</body>\n"
                      "</html>\n";

            QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
              if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

             QPrinter printer (QPrinter::PrinterResolution);
              printer.setOutputFormat(QPrinter::PdfFormat);
             printer.setPaperSize(QPrinter::A4);
            printer.setOutputFileName(fileName);

             QTextDocument doc;
              doc.setHtml(strStream);
              doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
              doc.print(&printer);
}

void
Gestionmateriel::on_pushButton_8_clicked()
{
    QPrinter printer;

    printer.setPrinterName("desiered printer name");

  QPrintDialog dialog(&printer,this);

    if(dialog.exec()== QDialog::Rejected)

        return;
}
