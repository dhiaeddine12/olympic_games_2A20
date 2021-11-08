#ifndef EMPLOYE_H
#define EMPLOYE_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class Employe
{
public:
    Employe();
    Employe(int,int, int, int, int, QString, QString, QString, QString);
    int getid();
    int getage();
    int getannee_recrutement();
    int getabsence();
    int getheure_de_travail();
    QString getfonction();
    QString getsexe();
    QString getnom();
    QString getprenom();
    void setid(int);
    void setage(int);
    void setannee_recrutement(int);
    void setabsence(int);
    void setheure_de_travail(int);
    void setnom(QString);
    void setprenom(QString);
    void setsexe(QString);
    void setfonction(QString);

    bool ajouter();
    SQqlQueryModel* afficher();



private:
    int id, age, annee_recrutement, absence, heure_de_travail;
    QString nom,prenom,sexe,fonction;


};

#endif // EMPLOYE_H
