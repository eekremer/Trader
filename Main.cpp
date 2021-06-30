#include <QApplication>

#include <chrono>
#include <thread>
#include <QDebug>

#include "MainWindow.h"
#include "OrderDbManager.h"


// prototypes
void* createClientThread(  void*  arg );
void* launchClientThread(  void*  arg );


// global var
Client         *g_client;
pthread_t       clientThread;

extern MainWindow window;

const unsigned 	MAX_ATTEMPTS        =  50           ;
const unsigned 	SLEEP_TIME          =  10           ;
const char*     host                =  "127.0.0.1"  ;
      int       port                =  7497         ;
const char*     connectOptions      =  ""           ;
      int 		clientId            =   0           ;
      unsigned 	attempt             =   0           ;

static const QString   path         =  "example.db" ;



//**************************************************************************

int main( int argc, char *argv[] )
{

    QApplication app( argc, argv );

    MainWindow *window = new MainWindow();

    g_client = new Client( window );

    createClientThread( g_client );

    window->show();

    return app.exec();

}

//****************************************************************************

void* createClientThread( void*  arg )
{

    pthread_create(                &clientThread,
                                    NULL,
                                   &launchClientThread,
                                    arg                            );

    return nullptr;

}

//****************************************************************************

void* launchClientThread( void*  arg )
{


    int 		clientId 	= 0;
    unsigned 	attempt 	= 0;

    Client *l_client = reinterpret_cast< Client* >( arg );


    qInfo(          "Start of C++ Socket Client Test %u\n",
                    attempt                                             );

    for (;;)
    {

        ++attempt;

        qInfo(              "Attempt %u of %u \n",
                            attempt,
                            MAX_ATTEMPTS                                    );

        // Run time error will occur (here) if TestCppClient.exe is compiled in debug mode but TwsSocketClient.dll is compiled in Release mode
        // TwsSocketClient.dll (in Release Mode) is copied by API installer into SysWOW64 folder within Windows directory
/*
        if( connectOptions )
        {

            l_client->setConnectOptions( connectOptions );

        }
*/
       l_client->connect(                   host,
                                            port,
                                            clientId                        );

        int trial = 0;

        while(  l_client->isConnected()  )
        {


            // stuff goes here !!!!

            if ( trial == 1 )
            {
                // contractDetails
                l_client->setState(  	ST_CONTRACTOPERATION  		);
            }

            if ( trial == 2 )
            {
                // reqMktDepth and reqMktData
                l_client->setState(  	ST_REROUTECFD				);
            }

            if ( trial == 3 )
            {
                // reqMktDepth and reqMktData
                l_client->setState(  	ST_REQMKTDEPTHEXCHANGES		);
            }

            if ( trial == 4 )
            {

                // reqMktDepth and reqMktData
                l_client->setState(  	ST_TICKDATAOPERATION		);
            }

            qInfo(          "before processMessages()...\n"                 );

            //****************************************
            //****************************************

            l_client->processMessages();

            //****************************************
            //****************************************

            trial++;

        }

        if( attempt >= MAX_ATTEMPTS )
        {
            break;
        }


        qInfo(      "could not connect with TWS...\n"                         );
        qInfo(      "going to sleep for %u seconds...\n",  SLEEP_TIME         );

        std::this_thread::sleep_for(    std::chrono::seconds( SLEEP_TIME ) 			);

    }

    printf ( "End of C++ Socket Client Test\n" );

    return nullptr;

}

//****************************************************************************


// code that shall go on main()

/*
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
*/
