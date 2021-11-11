#include "connection.h"
//first commit
connection::connection()
{

}

bool connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Olympic_Commitee");//inserer le nom de la source de données ODBC
db.setUserName("mohamed");//inserer nom de l'utilisateur
db.setPassword("esprit21");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
};
