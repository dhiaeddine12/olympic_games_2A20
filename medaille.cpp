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
         DATE_OBTENTION =" ";
}
medaille::medaille(int ID_M, QString TYPE_MEDAILLE ,QString DATE_OBTENTION, QString PAYS, QString TYPE_S)
{
    this->ID_M = ID_M ;
    this->TYPE_MEDAILLE= TYPE_MEDAILLE;
    this->DATE_OBTENTION=DATE_OBTENTION;
    this->PAYS= PAYS ;
    this->TYPE_S =TYPE_S;

};
bool medaille::ajouter()
{

   QSqlQuery query;

    QString ID_M_S = QString::number(ID_M);
    query.prepare("insert into MEDAILLE (ID_M,TYPE_MEDAILLE,DATE_OBTENTION,TYPE_S,PAYS,NBR_MEDAILLE)"
                  "values(:ID_M,:TYPE_MEDAILLE,:DATE_OBTENTION,:TYPE_S,:PAYS,:NBR_MEDAILLE)");
       query.bindValue(":ID_M",ID_M_S);
       query.bindValue(":TYPE_MEDAILLE",TYPE_MEDAILLE);
       query.bindValue(":DATE_OBTENTION",DATE_OBTENTION);
       query.bindValue(":TYPE_S",TYPE_S);
       query.bindValue(":PAYS",PAYS);



       return query.exec();



}


bool medaille::supprimer(int id)
{

    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("Delete from MEDAILLE where ID_M = :ID_M");
    query.bindValue(":ID_M",res);
    return  query.exec();
};
QSqlQueryModel * medaille::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from medaille");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_M"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_MEDAILLE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE_OBTENTION"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("TYPE_S"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("PAYS"));
        return model;
};

QSqlQueryModel * medaille::afficherS()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from SOMME");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("PAYS"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("GOLD"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ARGENT"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("BRONZE"));

        return model;
};









bool medaille::modifier(int id, QString TYPE_MEDAILLE ,QString DATE_OBTENTION, QString PAYS, QString TYPE_S)
{
    QSqlQuery query;
    QString res=QString::number(id);
            query.prepare("update MEDAILLE set ID_M =:ID_M,TYPE_MEDAILLE=:TYPE_MEDAILLE,DATE_OBTENTION=:DATE_OBTENTION,PAYS=:PAYS,TYPE_S=:TYPE_S WHERE ID_M=:ID_M");
            query.bindValue(":ID_M",res);
            query.bindValue(":TYPE_MEDAILLE",TYPE_MEDAILLE);
            query.bindValue(":DATE_OBTENTION",DATE_OBTENTION);
            query.bindValue(":TYPE_S",TYPE_S);
            query.bindValue(":PAYS",PAYS);
            return  query.exec();
}


QSqlQueryModel* medaille::affichervaleur(QString valeur)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString ch="SELECT ";
    QString query=" FROM medaille";
    query=ch+valeur+query;
    model->setQuery(query);
    return model;


}














QSqlQueryModel* medaille::triAn()
{
    QSqlQueryModel * model= new QSqlQueryModel();
           model->setQuery("SELECT * FROM MEDAILLE ORDER BY DATE_OBTENTION");
           return model;
}
QSqlQueryModel* medaille::triM()
{
    QSqlQueryModel * model= new QSqlQueryModel();
           model->setQuery("SELECT * FROM MEDAILLE ORDER BY TYPE_MEDAILLE");
           return model;

 }

QSqlQueryModel* medaille::triI()
{
    QSqlQueryModel * model= new QSqlQueryModel();
           model->setQuery("SELECT * FROM MEDAILLE ORDER BY ID_M");
           return model;

 }

QSqlQueryModel* medaille::rechercherP(QString PAYS)
{
//    QSqlQueryModel * model= new QSqlQueryModel();
//        QString recher="select * from MEDAILLE where PAYS like '%"+PAYS+"%' ";
//        model->setQuery(recher);
//        return model;

       QSqlQuery qry;
       qry.prepare("SELECT * FROM MEDAILLE where PAYS =:PAYS");
       qry.bindValue(":PAYS",PAYS);
       qry.exec();
       QSqlQueryModel *model=new QSqlQueryModel;
       model->setQuery(qry);

       return model;

}
QSqlQueryModel* medaille::rechercherD(QString DATE_OBTENTION)
{


       QSqlQuery qry;
       qry.prepare("SELECT * FROM MEDAILLE where DATE_OBTENTION =:DATE_OBTENTION");
       qry.bindValue(":DATE_OBTENTION",DATE_OBTENTION);
       qry.exec();
       QSqlQueryModel *model=new QSqlQueryModel;
       model->setQuery(qry);

       return model;

}














