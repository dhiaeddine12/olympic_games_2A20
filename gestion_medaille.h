#ifndef GESTION_MEDAILLE_H
#define GESTION_MEDAILLE_H

#include <QDialog>
#include"medaille.h"
#include <QString>
#include<QDateEdit>
#include <QTabWidget>
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
namespace Ui
{
class gestion_medaille;
}
class gestion_medaille : public QDialog
{
    Q_OBJECT
medaille mdl;
public:
    explicit gestion_medaille(QWidget *parent = nullptr);
    ~gestion_medaille();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_Modifier_clicked();

private:
    Ui::gestion_medaille *ui;

};

#endif // GESTION_MEDAILLE_H
