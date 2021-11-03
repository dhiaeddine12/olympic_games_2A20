#include "sportifs.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
sportifs::sportifs()
{
   id=0; age=0; nom=" "; prenom=" "; type_sport=" ";


}

sportifs::sportifs( int id, int age ,QString nom ,QString prenom ,QString type_sport )
{this->id=id ; this->age=age ;this->nom=nom ;this->prenom=prenom; this->type_sport=type_sport;}
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
    bool test=false;

    QSqlQuery query;
    QString id_string=QString::number(id);
    QString age_string=QString::number(age);
          query.prepare("INSERT INTO sportifs (id, nom, prenom,age,type_sport) "
                        "VALUES (:id, :nom, :prenom, :age, :type_sport)");
          query.bindValue(":id",id_string );
          query.bindValue(":forename", nom);
          query.bindValue(":surname", prenom);
          query.bindValue(":age", age_string);
          query.bindValue(":type sport", type_sport);
          query.exec();

    return test;
}

bool sportifs::supprimer(int id)
{
    QSqlQuery query;
    QString id_string=QString::number(id);
    QString age_string=QString::number(age);
          query.prepare("Delete from sportifs where id=:id");
          query.bindValue(":id",id );

         return  query.exec();

}




QSqlQueryModel* sportifs::afficher()
{
   QSqlQueryModel* model=new QSqlQueryModel();

        model->setQuery("SELECT* FROM sportifs");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("type de sport"));
   return model;

}



