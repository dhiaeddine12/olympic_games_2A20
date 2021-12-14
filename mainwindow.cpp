#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QMainWindow>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{ sportiff= new Gestionsportif(this);
    sportiff->show();

}

void MainWindow::on_pushButton_2_clicked()
{
    vol= new Gestionvolontaire(this);
        vol->show();
}

void MainWindow::on_pushButton_3_clicked()
{

    emp=new gestionemploye(this)  ;
            emp->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    med=new gestion_medaille(this);
    med->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    mat=new Gestionmateriel(this);
    mat->show();
}

void MainWindow::update_etat()
{
  data =A.read_from_arduino();
    ui->label_3->setText(data);
}

void MainWindow::on_pushButton_6_clicked()
{
    A.write_to_arduino("1");
}
