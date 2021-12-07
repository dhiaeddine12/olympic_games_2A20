#ifndef GESTIONSPORTIF_H
#define GESTIONSPORTIF_H

#include <QDialog>
#include"sportifs.h"
namespace Ui {
class Gestionsportif;
}

class Gestionsportif : public QDialog
{
    Q_OBJECT

public:
    explicit Gestionsportif(QWidget *parent = nullptr);
    ~Gestionsportif();

private slots:

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_rechercher_clicked();

    void on_pb_rechercher_id_clicked();

    void on_pb_rechercher_type_sport_clicked();

    void on_pb_trier_n_clicked();

    void on_pb_trier_i_clicked();

    void on_pb_trier_a_clicked();

    void on_pb_update_clicked();

    void on_pb_print_clicked();

   // void on_pb_somme_clicked();



    void on_pb_sommee_clicked();

private:
    Ui::Gestionsportif *ui;
    sportifs s;

};
#endif // GESTIONSPORTIF_H

