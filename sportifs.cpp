#include "sportifs.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
sportifs::sportifs()
{
   id=0; age=0; nom=" "; prenom=" "; type_sport=" ";

}

sportifs::sportifs( int id,QString nom ,QString prenom ,QString type_sport ,int age)
{
    this->id=id ;this->nom=nom ;this->prenom=prenom; this->type_sport=type_sport; this->age=age;}
int sportifs::getid(){return id;}
int sportifs::getage(){return age;}
QString sportifs::getnom(){return nom;}
QString sportifs::getprenom(){return prenom;}
QString sportifs::gettype_sport(){return type_sport;}
void sportifs::setid(int id){this->id=id;}
void sportifs::setage(int age){this->age=age;}
void sportifs::setnom(QString nom){this->nom=nom;}
void sportifs::setprenom(QString prenom){this->prenom=prenom;}
void sportifs::settype_sport(QString type_sport) {this->type_sport=type_sport;}

bool sportifs::ajouter()
{

    QSqlQuery query;
    QString id_string=QString::number(id);
    QString age_string=QString::number(age);
          query.prepare("INSERT INTO SPORTIF(id,nom,prenom,type_sport,age) "
                        "VALUES (:id, :nom, :prenom, :type_sport, :age)");
          query.bindValue(":id",id);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":type_sport", type_sport);
          query.bindValue(":age", age);
          query.exec();

   return query.exec();
}

bool sportifs::supprimer(int id)
{
    QSqlQuery query;
    QString id_string=QString::number(id);
    QString age_string=QString::number(age);
          query.prepare("Delete from SPORTIF where id=:id");
          query.bindValue(0,id );

         return  query.exec();

}




QSqlQueryModel* sportifs::afficher()
{
   QSqlQueryModel* model=new QSqlQueryModel();

        model->setQuery("SELECT* FROM SPORTIF");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("type_sport"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));

   return model;

}

bool sportifs::modifier()

{
         QSqlQuery query;
         query.prepare("UPDATE SPORTIF set id=:id, nom=:nom, prenom=:prenom, type_sport=:type_sport , age=:age where id=:id");
         query.bindValue(":id", id);
         query.bindValue(":nom",nom);
         query.bindValue(":prenom",prenom);
         query.bindValue(":type_sport", type_sport);
         query.bindValue(":age", age);
         return query.exec();

}

