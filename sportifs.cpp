#include "sportifs.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QMessageBox>
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
          query.prepare("INSERT INTO SPORTIF (id,nom,prenom,type_sport,age) "
                        "VALUES (:id, :nom, :prenom, :type_sport, :age)");
          query.bindValue(":id",id_string);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":type_sport", type_sport);
          query.bindValue(":age", age_string);
          query.exec();

   return query.exec();
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

QSqlQueryModel* sportifs::afficher_id(int id)
{
    QSqlQuery query ;
        QSqlQueryModel* model=new QSqlQueryModel();
       query.prepare("select * from SPORTIF where id=:id");
       query.bindValue(":id",id);
       query.exec();
       model->setQuery(query);
       return model;
}

QSqlQueryModel* sportifs::afficher_nom(QString nom)
{
    {

         QSqlQuery query ;
         QSqlQueryModel* model=new QSqlQueryModel();
        query.prepare("select * from SPORTIF where nom=:nom");
        query.bindValue(":nom",nom);
        query.exec();
        model->setQuery(query);
        return model;
     }
}

QSqlQueryModel* sportifs::afficher_type_sport(QString type_sport)
{
    QSqlQuery query ;
         QSqlQueryModel* model=new QSqlQueryModel();
        query.prepare("select * from SPORTIF where type_sport=:type_sport");
        query.bindValue(":type_sport",type_sport);
        query.exec();
        model->setQuery(query);
        return model;
}

bool sportifs::supprimer(int id)
{
    QSqlQuery query;
    QString id_string=QString::number(id);

          query.prepare("Delete from SPORTIF where id=:id");
          query.bindValue(":id",id );
     query.exec();
         return  query.exec();

}





bool sportifs::modifier(int)

{

         QSqlQuery query;
         query.prepare("UPDATE SPORTIF set id=:id, nom=:nom, prenom=:prenom, type_sport=:type_sport , age=:age where id=:id");
         query.bindValue(":id", id);
         query.bindValue(":nom",nom);
         query.bindValue(":prenom",prenom);
         query.bindValue(":type_sport",type_sport);
         query.bindValue(":age", age);
         return query.exec();

}

bool sportifs::rechercher_nom(QString nom)
{
    QMessageBox msgBox;
    QSqlQuery query;

    query.prepare("SELECT * FROM SPORTIF WHERE nom= :nom");
    query.bindValue(":nom", nom);
    if (query.exec() && query.next())
    {
            return true;
    }
    else
    {
        msgBox.setText("sportif n existe pas");
        msgBox.exec();
        return false;
    }
}

bool sportifs::rechercher_type_sport(QString type_sport)
{
    QMessageBox msgBox;
    QSqlQuery query;
    query.prepare("SELECT * FROM SPORTIF WHERE type_sport= :type_sport");
    query.bindValue(":type_sport", type_sport);
    if (query.exec() && query.next())
    {
            return true;
    }
    else
    {
        msgBox.setText("sport n existe pas");
        msgBox.exec();
        return false;
    }
}

bool sportifs::rechercher_id(int id)
{
    QMessageBox msgBox;
    QSqlQuery query;
    query.prepare("SELECT * FROM SPORTIF WHERE id= :id");
    query.bindValue(":id", id);
    if (query.exec() && query.next())
    {
            return true;
    }
    else
    {

        msgBox.setText("id n existe pas");
        msgBox.exec();
        return false;
    }
}

bool sportifs::ajouter1()
{

    QSqlQuery query;
    //QString id_string=QString::number(id);
    //QString age_string=QString::number(age);
          query.prepare("INSERT INTO LOGIN(LOGIN,PASSWORD) "
                        "VALUES (:LOGIN, :PASSWORD)");
          query.bindValue(":LOGIN",LOGIN);
           query.bindValue(":PASSWORD",PASSWORD);
          query.exec();

   return query.exec();
}

QSqlQueryModel* sportifs::affichervaleur(QString valeur)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString ch="SELECT ";
    QString query=" FROM SPORTIF";
    query=ch+valeur+query;
    model->setQuery(query);
    return model;


}

