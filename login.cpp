#include "login.h"
#include "ui_login.h"
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

void login::on_pushButton_clicked()
{
     gestion_medaille geste;
    QString username= ui->lineEdit_2->text();
    QString password= ui->lineEdit->text();
     if (username== "admin" && password == "admin")
    {
         QMessageBox::information(nullptr, QObject::tr("database is open"),

            hide();
            geste.show();



    }
    else {
        QMessageBox::warning(this,"login","username and password are incorrect ");
    }
}
