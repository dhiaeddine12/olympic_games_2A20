#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sportifs.h"

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

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_rechercher_clicked();









    void on_pb_rechercher_id_clicked();

    void on_pb_rechercher_type_sport_clicked();

    void on_pb_trier_n_clicked();

    void on_pb_trier_i_clicked();

    void on_pb_trier_a_clicked();

private:
    Ui::MainWindow *ui;
    sportifs s;
};
#endif // MAINWINDOW_H
