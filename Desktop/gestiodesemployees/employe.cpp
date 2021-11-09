#include<QMessageBox>
#include "employe.h"

Employe::Employe()
{
id=0; age=0; annee_recrutement=0; absence=0; heure_de_travail=0;

fonction=" "; sexe=" "; nom=" "; prenom=" ";
}
Employe::Employe(int id,int age,int annee_recrutement,int absence,int heure_de_travail,QString nom,QString prenom,QString sexe,QString fonction)
{ this->id=id;this->age=age; this->annee_recrutement=annee_recrutement; this->absence=absence; this->heure_de_travail=heure_de_travail; this->nom=nom; this->prenom=prenom; this->sexe=sexe; this->fonction=fonction; }
int Employe::getid(){return id;}
int Employe::getage(){return age;}
int Employe::getannee_recrutement(){return annee_recrutement;}
int Employe::getabsence(){return absence;}
int Employe::getheure_de_travail(){return heure_de_travail;}
QString Employe::getfonction(){return fonction;}
QString Employe::getsexe(){return sexe;}
QString Employe::getnom(){return nom;}
QString Employe::getprenom(){return prenom;}
void Employe::setid(int id) {this->id=id;}
void Employe::setage(int age){this->age=age;}
void Employe::setannee_recrutement(int annee_recrutement){this->annee_recrutement=annee_recrutement;}
void Employe::setabsence(int absence){this->absence=absence;}
void Employe::setheure_de_travail(int heure_de_travail){this->heure_de_travail=heure_de_travail;}
void Employe::setnom(QString nom){this->nom=nom;}
void Employe::setprenom(QString prenom){ this->prenom=prenom;}
void Employe::setsexe(QString sexe){this->sexe=sexe;}
void Employe::setfonction(QString fonction){this->fonction=fonction;}

bool Employe::ajouter()
{

    QSqlQuery query;
    QString id_string=QString::number(id);
    QString age_string=QString::number(age);
    QString annee_recrutement_string=QString::number(annee_recrutement);
    QString absence_string=QString::number(absence);
    QString heure_de_travail_string=QString::number(heure_de_travail);
    query.prepare("INSERT INTO EMPLOYE (id,age,annee_recrutement,absence,heure_de_travail,fonction,sexe,nom,prenom) "
                     "VALUES (:id,:age,:annee_recrutement,:absence,:heure_de_travail,:fonction,:sexe,:nom,:prenom)");
     query.bindValue(":id", id_string);
     query.bindValue(":age", age_string);
     query.bindValue(":annee_recrutement", annee_recrutement_string);
     query.bindValue(":absence", absence_string);
     query.bindValue(":heure_de_travail", heure_de_travail_string);
     query.bindValue(":fonction", fonction);
     query.bindValue(":sexe", sexe);
     query.bindValue(":nom", nom );
     query.bindValue(":prenom", prenom);

    return query.exec();
}

QSqlQueryModel* Employe::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM  EMPLOYE");
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("annee_recrutement"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("absence"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("heure_de_travail"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("fonction"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr(""));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr(""));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr(""));
    return model;
}



