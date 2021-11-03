#ifndef SPORTIFS_H
#define SPORTIFS_H
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QString>
class sportifs
{
public:
    sportifs();
    sportifs(int,int,QString,QString,QString);
    int getid();
    int getage();
    QString getnom();
    QString getprenom();
    QString gettype_sport();
    void setid(int);
    void setage(int);
    void setnom(QString);
    void setprenom(QString);
    void settype_sport(QString);
    bool ajouter();
   QSqlQueryModel* afficher();
   bool supprimer(int);
private :
    int id,age;
    QString nom,prenom,type_sport;
};

#endif // SPORTIFS_H
