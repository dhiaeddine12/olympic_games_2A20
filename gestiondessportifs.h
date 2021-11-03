#ifndef GESTIONDESSPORTIFS_H
#define GESTIONDESSPORTIFS_H


#include <QDialog>

namespace Ui {
class gestiondessportifs;
}

class gestiondessportifs : public QDialog
{
    Q_OBJECT

public:
    explicit gestiondessportifs(QWidget *parent = nullptr);
    ~gestiondessportifs();

private:
    Ui::gestiondessportifs *ui;
};

#endif // GESTIONDESSPORTIFS_H


#include <Qstring>

