#include<QMessageBox>
#include "employe.h"
#include<QSqlQuery>
#include<QtDebug>
#include <QObject>

Employe::Employe()
{
    id=0;
    nom=" ";
    prenom=" ";
    fonction=" ";
    age=0;
    sexe=" ";
    annee_recrutement=0;
    absence=0;
    heure_de_travail=0;

}
Employe::Employe(int id,QString nom,QString prenom,QString fonction,int age,QString sexe,int annee_recrutement,int absence,int heure_de_travail)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->fonction=fonction;
    this->age=age;
    this->sexe=sexe;
    this->annee_recrutement=annee_recrutement;
    this->absence=absence;
    this->heure_de_travail=heure_de_travail;
}
int Employe::getid()
{
    return id;
}
QString Employe::getnom()
{
    return nom;
}
QString Employe::getprenom()
{
    return prenom;
}
QString Employe::getfonction()
{
    return fonction;
}
int Employe::getage()
{
    return age;
}
QString Employe::getsexe()
{
    return sexe;
}
int Employe::getannee_recrutement()
{
    return annee_recrutement;
}
int Employe::getabsence()
{
    return absence;
}
int Employe::getheure_de_travail()
{
    return heure_de_travail;
}

void Employe::setid(int id)
{
    this->id=id;
}
void Employe::setnom(QString nom)
{
    this->nom=nom;
}
void Employe::setprenom(QString prenom)
{
    this->prenom=prenom;
}
void Employe::setfonction(QString fonction)
{
    this->fonction=fonction;
}
void Employe::setage(int age)
{
    this->age=age;
}
void Employe::setsexe(QString sexe)
{
    this->sexe=sexe;
}
void Employe::setannee_recrutement(int annee_recrutement)
{
    this->annee_recrutement=annee_recrutement;
}
void Employe::setabsence(int absence)
{
    this->absence=absence;
}
void Employe::setheure_de_travail(int heure_de_travail)
{
    this->heure_de_travail=heure_de_travail;
}




bool Employe::ajouter()
{

    QSqlQuery query;
    QString id_string=QString::number(id);
    QString age_string=QString::number(age);
    QString annee_recrutement_string=QString::number(annee_recrutement);
    QString absence_string=QString::number(absence);
    QString heure_de_travail_string=QString::number(heure_de_travail);

    query.prepare("INSERT INTO EMPLOYE (id,nom,prenom,fonction,age,sexe,annee_recrutement,absence,heure_de_travail) "
                  "VALUES (:id,:nom,:prenom,:fonction,:age,:sexe,:annee_recrutement,:absence,:heure_de_travail)");
    query.bindValue(":id", id_string);
    query.bindValue(":nom", nom );
    query.bindValue(":prenom", prenom);
    query.bindValue(":fonction", fonction);
    query.bindValue(":age", age_string);
    query.bindValue(":sexe", sexe);
    query.bindValue(":annee_recrutement", annee_recrutement_string);
    query.bindValue(":absence", absence_string);
    query.bindValue(":heure_de_travail", heure_de_travail_string);
    query.exec();

   return query.exec();
}

QSqlQueryModel* Employe::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM  EMPLOYE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("fonction"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("annee_recrutement"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("absence"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("heure_de_travail"));

    return model;
}
QSqlQueryModel* Employe::afficher_nom(QString nom)
{

 QSqlQuery query;
 QSqlQueryModel* model=new QSqlQueryModel();
 query.prepare("select * from EMPLOYE where nom=:nom");
 query.bindValue(":nom",nom);
 query.exec();
 model->setQuery(query);
 return  model;

}

QSqlQueryModel* Employe::afficher_fonction(QString fonction)
{
    QSqlQuery query;
    QSqlQueryModel* model=new QSqlQueryModel();
    query.prepare("select * from EMPLOYE where fonction=:fonction");
    query.bindValue(":fonction",fonction);
    query.exec();
    model->setQuery(query);
    return  model;
}

QSqlQueryModel* Employe::afficher_id(int id)
{
    QSqlQuery query;
    QSqlQueryModel* model=new QSqlQueryModel();
    query.prepare("select * from EMPLOYE where id=:id");
    query.bindValue(":id",id);
    query.exec();
    model->setQuery(query);
    return  model;
}

bool Employe::Supprimer(int id)
{
    QSqlQuery query;
    QString id_string=QString::number(id);
    query.prepare("DELETE from EMPLOYE where id=:id");
    query.bindValue(0,id);

    return query.exec();
}

bool Employe::Modifier(int)

{
         QSqlQuery query;
         query.prepare("UPDATE EMPLOYE set id=:id, nom=:nom, prenom=:prenom, fonction=:fonction, age=:age, sexe=:sexe, annee_recrutement=:annee_recrutement, absence=:absence, heure_de_travail=:heure_de_travail where id=:id");
         query.bindValue(":id", id);
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":fonction", fonction);
         query.bindValue(":age", age);
         query.bindValue(":sexe", sexe);
         query.bindValue(":annee_recrutement", annee_recrutement);
         query.bindValue(":absence", absence);
         query.bindValue(":heure_de_travail", heure_de_travail);
         return query.exec();

}

bool   Employe::rechercher_nom(QString nom)
 {
     QMessageBox msgBox;
    QSqlQuery query;
     query.prepare("select * from EMPLOYE where nom=:nom");
     query.bindValue(":nom",nom);
     if (query.exec()&& query.next())
     {
         return true;
     }
     else
     {
         msgBox.setText("nom n existe pas");
         msgBox.exec();
         return  false;
     }

 }

bool Employe::rechercher_fonction(QString fonction)
 {

    QMessageBox msgBox;
    QSqlQuery query;
     query.prepare("select * from EMPLOYE where fonction=:fonction");
     query.bindValue(":fonction",fonction);
     if (query.exec()&& query.next())
     {
         return true;
     }
     else
     {
         msgBox.setText("fonction n existe pas");
         msgBox.exec();
         return  false;
     }

 }

bool   Employe::rechercher_identifiant(int id)
 {
     QMessageBox msgBox;
     QSqlQuery query;
     query.prepare("select * from EMPLOYE where id=:id");
     query.bindValue(":id",id);
     if (query.exec()&& query.next())
     {
         return true;
     }
     else
     {
         msgBox.setText("identifiant n existe pas");
         msgBox.exec();
         return  false;
     }


 }

