#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "gestionsportif.h"
#include"gestionvolontaire.h"
#include <QMainWindow>
#include "gestionemploye.h"
#include "gestion_medaille.h"
#include "gestionmateriel.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
namespace Ui {
class  MainWindow;
}

class  MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit  MainWindow(QWidget *parent = nullptr);
    ~ MainWindow();

private slots:



    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui:: MainWindow*ui;
 Gestionsportif *sportiff;
 Gestionvolontaire *vol;
gestionemploye *emp;
gestion_medaille *med;
Gestionmateriel *mat;
};

#endif // MAINWINDOW_H
