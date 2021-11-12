#ifndef MATERIEL_H
#define MATERIEL_H

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>


class materiel
{
public:
    materiel();
    materiel(int,int,QString,QString,QString);
    int getid();
    int getprix();
    QString getdate_achat();
    QString getnom();
    QString getqualite();
    void setid(int);
    void setprix(int);
    void setdate_achat(QString);
    void setnom(QString);
    void setqualite(QString);


    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficher_id(int);
    QSqlQueryModel* afficher_nom(QString);
    QSqlQueryModel* afficher_prix(int);
    bool modifier(int);
    bool recherche_nom(QString);
    bool recherche_prix(int);
    bool recherche_id(int);
    bool supprimer(int);

private:
    int id,prix;
    QString nom,qualite,date_achat;
};

#endif // MATERIEL_H
