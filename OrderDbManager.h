#ifndef ORDERDBMANAGER_H
#define ORDERDBMANAGER_H

#include <QSqlDatabase>
#include <QString>


/*
  DbManager sets up the connection with SQL database
  and performs some basics queries. The class requires
  existing SQL database. You can create it with sqlite:
  1. $ sqlite3 people.db
  2. sqilte> CREATE TABLE people(ids integer primary key, name text);
  3. sqlite> .quit
*/


//***********************************************************************************

class OrderDbManager
{

    public:

        // Constructor sets up connection with db and opens it
        // path - absolute path to db file

        OrderDbManager( const QString&  path );

       ~OrderDbManager();


        bool    isOpen          () const;

        bool    createTable     ();

        bool    addPerson       ( const QString&  name );

        bool    removePerson    ( const QString&  name );

        bool    personExists    ( const QString&  name ) const;

        void    printAllPersons () const;

        bool    removeAllPersons();


    private:

        QSqlDatabase  m_db;

};

//***********************************************************************************

#endif // DBMANAGER_H
