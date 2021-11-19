#include "login.h"
#include "ui_login.h"
#include <QtDebug>
#include "mainwindow.h"
#include "sportifs.h"
#include <QMessageBox>
#include <QSqlQuery>

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

void login::on_pb_register_clicked()
{
    sportifs s;
    s.LOGIN=ui->username_r->text();
    s.PASSWORD=ui->password_r->text();
s.ajouter1();


QMessageBox::information(this,"REGISTER","registration successful");

}

void login::on_pb_login_clicked()
{


    sportifs s;
    s.LOGIN=ui->username->text();
    s.PASSWORD=ui->password->text();
if(s.LOGIN == "wabi" && s.PASSWORD == "wabi")
{
    QMessageBox::information(this,"login","login et password correct");
    mainwindow = new MainWindow(this);
       mainwindow->show();
}

else if(s.LOGIN == "cc" && s.PASSWORD == "cc")
{
    QMessageBox::information(this,"login","login et password correct");
    mainwindow = new MainWindow(this);
       mainwindow->show();
}
else
{
   QMessageBox::warning(this,"login","login ou password incorrect");

}

/*
int cc=0;
        while(query.next())
        {
            cc++;
        }

        if(cc==1)

        {
            QMessageBox::information(this,"login","login et password correct");
            mainwindow = new MainWindow(this);
               mainwindow->show();
        }

        else if(cc>1)
        {
           QMessageBox::warning(this,"login","login ou password deja");

        }

        else if(cc<1)
        {
            QMessageBox::warning(this,"login","login ou password incorrect");

        }


query.prepare ("SELECT * from LOGIN WHERE  LOGIN = :s.LOGIN AND  password = :s.PASSWORD");

   query.bindValue(":LOGIN", s.LOGIN);
   query.bindValue(":PASSWORD", s.PASSWORD);

   if (query.exec())
       {
           if (query.size() > 0)
           {
               // You login a user here
               QMessageBox::information(this,"login","login et password correct");
               mainwindow = new MainWindow(this);
                  mainwindow->show();
           }
           else
           {
               qDebug() << "Login failed. Invalid username or password.";
           }
       }
*/
}



