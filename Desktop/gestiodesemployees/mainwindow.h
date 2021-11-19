#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include"employe.h"
#include<QFileDialog>
#include <QtCharts/QChartView>
#include <QPieSlice>
#include <QPieSeries>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pb_ajouter_clicked();
    void on_Pb_image_clicked();
    void on_pushButton_clicked();
    void on_pb_modifier_clicked();

    void on_Pb_recherche_nom_clicked();
    void on_Pb_recherche_fonction_clicked();
    void on_Pb_recherche_identifiant_clicked();

    void on_Pb_trier_age_clicked();
    void on_Pb_trier_annee_de_recrutement_clicked();
    void on_Pb_trier_sexe_clicked();


    void on_Pb_stat_absence_clicked();
    void on_Pb_stat_heure_de_travail_clicked();
    void on_Pb_stat_age_clicked();

    void on_Pb_mise_a_jour_clicked();

private:
    Ui::MainWindow *ui;
    Employe E;
};
#endif // MAINWINDOW_H
