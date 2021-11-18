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
    bool ajouter1();
   QSqlQueryModel* afficher();
   QSqlQueryModel* afficher_id(int);
   QSqlQueryModel* afficher_nom(QString);
   QSqlQueryModel* afficher_type_sport(QString);
   QSqlQueryModel* affichervaleur(QString);
   bool supprimer(int);
   bool modifier(int);
   bool rechercher_nom(QString);
   bool rechercher_type_sport(QString);
   bool rechercher_id(int);
  QString LOGIN,PASSWORD;
private :
    int id,age;
    QString nom,prenom,type_sport;

};

#endif // SPORTIFS_H
