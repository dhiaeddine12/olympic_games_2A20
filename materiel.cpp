#include <QMessageBox>
#include "materiel.h"


materiel::materiel()
{
id=0; nom=" "; prix=0;  qualite=" ";
}
materiel::materiel(int id,int prix , QString date_achat ,QString nom,QString qualite)
{this->id=id; this->nom=nom; this->prix=prix; this->date_achat=date_achat; this->qualite=qualite;}
int materiel::getid(){return id;}
int materiel::getprix(){return prix;}
QString materiel::getdate_achat(){return date_achat;}
QString materiel:: getnom(){return nom;}
QString materiel::getqualite(){return qualite;}
void materiel::setid(int id){this->id=id;}
void materiel::setprix(int prix){this->prix=prix;}
void materiel::setdate_achat(QString date_achat){this->date_achat=date_achat;}
void materiel::setnom(QString nom){this->nom=nom;}
void materiel::setqualite(QString qualite){this->qualite=qualite;}

bool materiel::ajouter()
{

    QSqlQuery query;
    QString id_string=QString::number(id);
     QString prix_string=QString::number(prix);
    query.prepare("INSERT INTO materiel (id,prix,nom,qualite,date_achat) "
                  "VALUES (:id,:prix,:nom,:qualite,:date_achat)");
    query.bindValue(":id", id_string);
    query.bindValue(":prix", prix_string);
    query.bindValue(":nom",nom);
    query.bindValue(":qualite", qualite);
    query.bindValue(":date_achat",date_achat);
    return query.exec();



}


QSqlQueryModel* materiel::afficher()
{
QSqlQueryModel* model=new QSqlQueryModel();
model->setQuery("SELECT* FROM materiel");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("qualite"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_achat"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("nom"));

return model;
}


bool materiel::supprimer(int id){
    QSqlQuery query;
    materiel C;
    bool test=C.recherche_id(id);
    if(test){
    query.prepare(" Delete from materiel where id=:id");
    query.bindValue(":id", id);
    }
    return query.exec();
}

bool materiel::recherche_nom(QString nom)
{
    QMessageBox msgBox;
    QSqlQuery query;

    query.prepare("SELECT * FROM materiel WHERE NOM= :nom");
    query.bindValue(":nom", nom);
    if (query.exec() && query.next())
    {
            return true;
    }
    else
    {

        msgBox.setText("materiel n existe pas");
        msgBox.exec();
        return false;
    }
}



bool materiel::recherche_prix(int prix)
{
    QMessageBox msgBox;
    QSqlQuery query;

    query.prepare("SELECT * FROM materiel WHERE prix= :prix");
    query.bindValue(":prix", prix);
    if (query.exec() && query.next())
    {
            return true;
    }
    else
    {
        msgBox.setText("materiel n existe pas");
        msgBox.exec();
        return false;
    }
}



bool materiel::recherche_id(int id)
{

    QMessageBox msgBox;
    QSqlQuery query;
     QString id_string=QString::number(id);
    query.prepare("SELECT * FROM materiel WHERE id= :id");
    query.bindValue(":id", id_string);
    if (query.exec() && query.next())
    {
            return true;
    }
    else
    {
        msgBox.setText("materiel n existe pas");
        msgBox.exec();
        return false;
    }
}



QSqlQueryModel* materiel::afficher_id(int id)
{
    QSqlQueryModel* model= new QSqlQueryModel();
    QString id_string=QString::number(id);

          model->setQuery("SELECT * FROM materiel WHERE id='"+id_string+"'");

    return model;
}




QSqlQueryModel* materiel::afficher_nom(QString nom)
{
    QSqlQueryModel* model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM materiel WHERE NOM='"+nom+"'");

    return model;
}




QSqlQueryModel* materiel::afficher_prix(int prix)
{
    QSqlQueryModel* model= new QSqlQueryModel();
    QString prix_string=QString::number(prix);


          model->setQuery("SELECT * FROM materiel WHERE prix='"+prix_string+"'");

    return model;
}





bool materiel::modifier(int id)
{
    QSqlQuery query;
    QString id_string=QString::number(id);
    QString prix_string=QString::number(prix);

    if (recherche_id(id))
    {

          query.prepare("UPDATE materiel SET prix=:prix, nom=:nom, qualite=:qualite, date_achat=:date_achat WHERE id=:id");
          query.bindValue(":id", id_string);
          query.bindValue(":prix", prix_string);
          query.bindValue(":nom",nom);
          query.bindValue(":qualite", qualite);
          query.bindValue(":date_achat", date_achat);

    }
          return query.exec();
}

