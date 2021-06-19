#include <QApplication>

#include <chrono>
#include <thread>
#include <QDebug>

#include "MainWindow.h"
#include "OrderDbManager.h"



static const QString path = "example.db";  // change to any path you wish



int main( int argc, char *argv[] ) //
{


    QApplication app( argc, argv );

    MainWindow window;

    //---------------------------------------

    OrderDbManager db( path );


    if ( db.isOpen() )
    {

        db.createTable();   // creates a table if it doens't exist. Otherwise, it will use existing table.

        db.addPerson( "A" );
        db.addPerson( "B" );
        db.addPerson( "C" );

        db.printAllPersons();

        db.removePerson( "C" );

        db.printAllPersons();

        db.removeAllPersons();

        qDebug() << "End";

    }
    else
    {
        qDebug() << "Database is not open!";
    }

    //---------------------------------------

    window.show();

    return app.exec();

}


