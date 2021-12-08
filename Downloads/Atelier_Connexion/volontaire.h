#ifndef VOLONTAIRE_H
#define VOLONTAIRE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class volontaire
{

public:
    //constructeurs
    volontaire();
    volontaire(int,QString,QString,int,QString,int);
    //get set
    int get_id();
    void set_id(int);
    QString get_nom();
    QString set_nom();
    QString get_prenom();
    QString set_prenom();
    int get_age();
    int set_age();
    QString get_categorie();
    QString set_categorie();
    int get_disponibilite();
    int set_disponibilite();
    //crud

    bool ajouter();
    QSqlQueryModel * afficher_dispo();
    QSqlQueryModel   * afficher_non_dispo();
        QSqlQueryModel   * afficher_id();
    bool supprimer(int);

bool modifier(int,QString,QString,int,QString,int);
QSqlQueryModel * trier();
QSqlQueryModel * trier2();

QSqlQueryModel * chercher(QString);
QSqlQueryModel * somme();
private:
    int id;
    QString nom;
    QString prenom;
    int age;
    QString categorie;
    int disponibilite;
};

#endif // VOLONTAIRE_H
