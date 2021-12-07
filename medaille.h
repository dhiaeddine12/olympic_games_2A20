#ifndef MEDAILLE_H
#define MEDAILLE_H
#include<QString>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlQueryModel>
#include <QSqlQueryModel>

class medaille
{
private:
    QString TYPE_MEDAILLE,TYPE_S,PAYS,DATE_OBTENTION;
    int ID_M;
public:
    medaille();
    medaille(int,QString,QString, QString,QString);
    int getid(){return ID_M;}
    QString gettypem(){return TYPE_MEDAILLE;}
    QString getDATE(){return DATE_OBTENTION;}
    QString getpays(){return PAYS;}
    QString gettypes(){return TYPE_S;}
    void settypem(QString m ){this->TYPE_MEDAILLE=m;}
    void settypes(QString s ){this->TYPE_S=s;}
    void setpays(QString p ){this->PAYS=p;}
    void setid(int id){this->ID_M=id;}
    void setDATE(QString a){this->DATE_OBTENTION=a;}
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int id);
    bool modifier(int id, QString TYPE_MEDAILLE ,QString DATE_OBTENTION, QString PAYS, QString TYPE_S);
    bool controlsaisiechar(QString,QString);
    bool controlSaisieNumVide(int num, QString numm);
    bool controlSaisieCharVide (QString,QString);
    bool controlsaisieMail(QString saisi);
    QSqlQueryModel*triM();
    QSqlQueryModel*triAn();

    QSqlQueryModel*triI();

    QSqlQueryModel* rechercherP(QString );
    QSqlQueryModel* rechercherD(QString );

    QSqlQueryModel* affichervaleur(QString valeur);
    QSqlQueryModel * afficherS();


};

#endif // MEDAILLE_H
