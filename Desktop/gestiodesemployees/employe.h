#ifndef EMPLOYE_H
#define EMPLOYE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QtCharts/QChartView>
#include <QPieSlice>
#include <QPieSeries>

class Employe
{
public:
    Employe();
    Employe(int,QString,QString,QString,int,QString,int,int,int);
    int getid();
    QString getnom();
    QString getprenom();
    QString getfonction();
    int getage();
    QString getsexe();
    int getannee_recrutement();
    int getabsence();
    int getheure_de_travail();

    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setfonction(QString);
    void setage(int);
    void setsexe(QString);
    void setannee_recrutement(int);
    void setabsence(int);
    void setheure_de_travail(int);

      bool ajouter();
      QSqlQueryModel* afficher();
      QSqlQueryModel* afficher_nom(QString);
      QSqlQueryModel* afficher_fonction(QString);
      QSqlQueryModel* afficher_id(int);
      bool Supprimer(int);
      bool Modifier(int);
      bool rechercher_nom(QString );
      bool rechercher_fonction(QString );
      bool rechercher_identifiant(int );


private:
    int id, age, annee_recrutement, absence, heure_de_travail;
    QString nom,prenom,sexe,fonction;


};

#endif // EMPLOYE_H
