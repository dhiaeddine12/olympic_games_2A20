#include "login.h"
#include "ui_login.h"
#include <QtDebug>
#include "mainwindow.h"
#include "sportifs.h"
#include <QMessageBox>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pb_login_clicked()
{
    sportifs s;
    s.LOGIN=ui->username->text();
    s.PASSWORD=ui->password->text();
s.ajouter1();
if(s.LOGIN == "test" && s.PASSWORD =="test" )

{

    QMessageBox::information(this,"login","login et password correct");
    mainwindow = new MainWindow(this);
       mainwindow->show();
}
    else

    {
         QMessageBox::warning(this,"login","login ou password incorrect");
    }
}
