#ifndef SPORTIFS_H
#define SPORTIFS_H
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QString>
class sportifs
{
public:
    sportifs();
    sportifs(int,QString,QString,QString,int);
    int getid();
    QString getnom();
    QString getprenom();
    QString gettype_sport();
    int getage();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void settype_sport(QString);
    void setage(int);
    bool ajouter();
   QSqlQueryModel* afficher();
   bool supprimer(int);
   bool modifier(int);
private :
    int id,age;
    QString nom,prenom,type_sport;
};

#endif // SPORTIFS_H
