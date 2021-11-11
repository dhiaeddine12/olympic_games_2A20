#include "medaille.h"
#include<QString>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlQueryModel>
medaille::medaille()
{
         TYPE_MEDAILLE =" ";
         TYPE_S =" ";
         PAYS =" ";
         ID_M=0;
         ANNEE_OBTENTION =0;
}
medaille::medaille(int ID_M, QString TYPE_MEDAILLE ,int ANNEE_OBTENTION, QString PAYS, QString TYPE_S)
{
    this->ID_M = ID_M ;
    this->TYPE_MEDAILLE= TYPE_MEDAILLE;
    this->ANNEE_OBTENTION=ANNEE_OBTENTION;
    this->PAYS= PAYS ;
    this->TYPE_S =TYPE_S;

};
bool medaille::ajouter()
{
     bool test=false;
   QSqlQuery query;
    QString ID_M_S = QString::number(ID_M);
    QString ANNEE_S = QString::number(ANNEE_OBTENTION);
    query.prepare("insert into MEDAILLE (ID_M,TYPE_MEDAILLE,ANNEE_OBTENTION,TYPE_S,PAYS)"
                  "values(:ID_M,:TYPE_MEDAILLE,:ANNEE_OBTENTION,:PAYS,:TYPE_S)");
       query.bindValue(":ID_M",ID_M_S);
       query.bindValue(":TYPE_MEDAILLE",TYPE_MEDAILLE);
       query.bindValue(":ANNEE_OBTENTION",ANNEE_S);
       query.bindValue(":TYPE_S",TYPE_S);
       query.bindValue(":PAYS",PAYS);

       return query.exec();


      return test;
};

bool medaille::supprimer(int id)
{
    bool test=false;
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("Delete from MEDAILLE where ID_M = :ID_M");
    query.bindValue(":ID_M",res);
    return  query.exec();
    return test;
};
QSqlQueryModel * medaille::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from medaille");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_M"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_MEDAILLE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ANNEE_OBTENTION"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("TYPE_S"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("PAYS"));
        return model;
};
bool medaille::modifier(int id, QString TYPE_MEDAILLE ,int ANNEE_OBTENTION, QString PAYS, QString TYPE_S)
{
    QSqlQuery query;
    QString res=QString::number(id);
    QString res1=QString::number(ANNEE_OBTENTION);
            query.prepare("update MEDAILLE set ID_M =:ID_M,TYPE_MEDAILLE=:TYPE_MEDAILLE,ANNEE_OBTENTION=:ANNEE_OBTENTION,PAYS=:PAYS,TYPE_S=:TYPE_S WHERE ID_M=:ID_M");
            query.bindValue(":ID_M",res);
            query.bindValue(":TYPE_MEDAILLE",TYPE_MEDAILLE);
            query.bindValue(":ANNEE_OBTENTION",res1);
            query.bindValue(":TYPE_S",TYPE_S);
            query.bindValue(":PAYS",PAYS);
            return  query.exec();
}
