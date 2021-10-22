#include "gestiondessportifs.h"
#include "ui_gestiondessportifs.h"

gestiondessportifs::gestiondessportifs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestiondessportifs)
{
    ui->setupUi(this);
}

gestiondessportifs::~gestiondessportifs()
{
    delete ui;
}
