#ifndef LOGIN_BD_H
#define LOGIN_BD_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>



class login_bd
{
     QSqlDatabase db1;
public:
    login_bd();
    bool createconnect1();
    bool ouvrirConnexion1();
       void fermerConnexion1();

};

#endif // LOGIN_BD_H
