#ifndef GESTIONMATERIEL_H
#define GESTIONMATERIEL_H

#include <QDialog>
#include "materiel.h"

namespace Ui {
class Gestionmateriel;
}

class Gestionmateriel : public QDialog
{
    Q_OBJECT

public:
    explicit Gestionmateriel(QWidget *parent = nullptr);
    ~Gestionmateriel();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();


private:
    Ui::Gestionmateriel *ui;
     materiel m;
};

#endif // GESTIONMATERIEL_H
