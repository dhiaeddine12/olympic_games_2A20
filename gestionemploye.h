#ifndef GESTIONEMPLOYE_H
#define GESTIONEMPLOYE_H

#include <QDialog>
#include"employe.h"
#include<QFileDialog>
#include <QtCharts/QChartView>
#include <QPieSlice>
#include <QPieSeries>

namespace Ui {
class gestionemploye;
}

class gestionemploye : public QDialog
{
    Q_OBJECT

public:
    explicit gestionemploye(QWidget *parent = nullptr);
    ~gestionemploye();
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
    Ui::gestionemploye *ui;
    Employe E;
};

#endif // GESTIONEMPLOYE_H
