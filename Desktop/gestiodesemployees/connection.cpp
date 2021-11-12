#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

db.setDatabaseName("test-db");//inserer le nom de la source de données ODBC
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("souha2021");//inserer mot de passe de cet utilisateur

if (db.open())

     test=true;

    return  test;
}

/*bool Connection::ouvrirConnexion()
{

  if (db.open())
      return true;
  else
      return false;
}
void Connection::fermerConnection()
{
    db.close();
}
*/
