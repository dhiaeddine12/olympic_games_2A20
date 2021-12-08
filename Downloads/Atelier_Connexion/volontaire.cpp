  #include "volontaire.h"
#include "mainwindow.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QDialog>

volontaire::volontaire()
{
    id=0;
    nom="";
    prenom="";
    age=0;
    categorie="";
    disponibilite=0;
}

volontaire::volontaire(int id,QString nom,QString prenom,int age ,QString categorie ,int disponibilte)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->age=age;
    this->categorie=categorie;
    this->disponibilite=disponibilte;
}
void volontaire::set_id(int id)
{this->id=id;
}
int volontaire::get_id()
{
    return id;
}
bool volontaire::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id);

    query.prepare("INSERT INTO VOLONTAIRE (id,nom,prenom,age,categorie,disponibilite)"
                  "VALUES (:id,:nom,:prenom,:age,:categorie,:disponibilite) ");

    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":age",age);
    query.bindValue(":categorie",categorie);
     query.bindValue(":disponibilite",disponibilite);

    return    query.exec();
}


QSqlQueryModel * volontaire::afficher_dispo()
{

    QSqlQueryModel * model1= new QSqlQueryModel();

    model1->setQuery(" SELECT * FROM VOLONTAIRE WHERE DISPONIBILITE=0");
     model1->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model1->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model1->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model1->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model1->setHeaderData(4, Qt::Horizontal, QObject::tr("categorie"));
    model1->setHeaderData(5, Qt::Horizontal, QObject::tr("disponibilite"));
        return model1;


}
QSqlQueryModel * volontaire::afficher_non_dispo()
{

    QSqlQueryModel * model2= new QSqlQueryModel();

    model2->setQuery("SELECT * FROM VOLONTAIRE WHERE DISPONIBILITE=1");
    model2->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model2->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model2->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model2->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model2->setHeaderData(4, Qt::Horizontal, QObject::tr("categorie"));
    model2->setHeaderData(5, Qt::Horizontal, QObject::tr("disponibilite"));

        return model2;


}
QSqlQueryModel* volontaire ::afficher_id()
   {
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select id from volontaire");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    return model;

   }

bool volontaire::supprimer(int id)
{
    QSqlQuery query;
    QString rest = QString::number(id);

    query.prepare("DELETE FROM volontaire  where id=:id");
    query.bindValue(":id",id);

    return query.exec();
}
//***************************** Modifier ****************

bool  volontaire ::modifier(int id,QString nom,QString prenom,int age ,QString categorie ,int disponibilite)
{
        QSqlQuery query;
        QString res= QString::number(id);

        query.prepare("update VOLONTAIRE set id=:id,nom=:nom,prenom=:prenom,age=:age,categorie=:categorie,disponibilite=:disponibilite where id=:id");
        query.bindValue(":id",id);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":age",age);
        query.bindValue(":categorie",categorie);
         query.bindValue(":disponibilite",disponibilite);



        return    query.exec();

}

QSqlQueryModel * volontaire::trier()
{
    QSqlQueryModel * model3= new QSqlQueryModel();

    model3->setQuery("select * FROM VOLONTAIRE WHERE DISPONIBILITE=0 ORDER BY AGE");
    model3->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model3->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model3->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model3->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model3->setHeaderData(4, Qt::Horizontal, QObject::tr("categorie"));

    return model3;
}
QSqlQueryModel * volontaire::trier2()
{
    QSqlQueryModel * model4= new QSqlQueryModel();

    model4->setQuery("select * FROM VOLONTAIRE WHERE DISPONIBILTE=1 ORDER BY AGE");
    model4->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model4->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model4->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model4->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model4->setHeaderData(4, Qt::Horizontal, QObject::tr("categorie"));


    return model4;
}



//******************* reccherche id***********************************************************************************
/*QSqlQueryModel * volontaire::chercher(QString rech)
{
QSqlQueryModel * model = new QSqlQueryModel();
QSqlQuery query;
//query.prepare("SELECT * FROM VOLONTAIRE WHERE ID LIKE'%"+rech+"%' or CATEGORIE LIKE'%"+rech+"%'");
//query.bindValue(":id",id);
//query.exec();
model ->setQuery("SELECT * FROM VOLONTAIRE WHERE ID LIKE'%"+rech+"%' or CATEGORIE LIKE'%"+rech+"%'");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("categorie"));

return model;
}*/





//************************** reccherche categorie**************************************************************************
QSqlQueryModel * volontaire::chercher(QString rech)
{
QSqlQueryModel * model6 = new QSqlQueryModel();
model6->setQuery("SELECT * FROM volontaire WHERE ID LIKE'%"+rech+"%' or NOM LIKE'%"+rech+"%' or PRENOM LIKE'%"+rech+"%' or AGE LIKE'%"+rech+"%' or CATEGORIE LIKE'%"+rech+"%' ");
return model6;
}

QSqlQueryModel * volontaire::somme()

{QSqlQueryModel * model6 = new QSqlQueryModel();
    model6->setQuery("SELECT COUNT(*)FROM volontaire");
    return model6;
 }

