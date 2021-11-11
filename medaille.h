#ifndef MEDAILLE_H
#define MEDAILLE_H
#include<QString>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlQueryModel>


class medaille
{
private:
    QString TYPE_MEDAILLE,TYPE_S,PAYS ;
    int ID_M, ANNEE_OBTENTION;
public:
    medaille();
    medaille(int,QString,int, QString,QString);
    int getid(){return ID_M;}
    QString gettypem(){return TYPE_MEDAILLE;}
    int getannee(){return ANNEE_OBTENTION;}
    QString getpays(){return PAYS;}
    QString gettypes(){return TYPE_S;}
    void settypem(QString m ){this->TYPE_MEDAILLE=m;}
    void settypes(QString s ){this->TYPE_S=s;}
    void setpays(QString p ){this->PAYS=p;}
    void setid(int id){this->ID_M=id;}
    void setannee(int a){this->ANNEE_OBTENTION=a;}
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int id);
    bool modifier(int id, QString TYPE_MEDAILLE ,int ANNEE_OBTENTION, QString PAYS, QString TYPE_S);
};

#endif // MEDAILLE_H
