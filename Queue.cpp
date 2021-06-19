#include <chrono>
#include <thread>
#include <QTextStream>
#include <iostream>
#include <QDebug>

#include "Queue.h"


extern pthread_mutex_t mutex;


//****************************************************************************

Queue::Queue()
{

}

//****************************************************************************

Queue::~Queue( void )
{

}

//****************************************************************************

void Queue::insertMsgIntoQueue( InterObject* obj )
{


    std::this_thread::sleep_for(    std::chrono::milliseconds( 100 )   );

    qInfo( "at the beginning of Queue::insertMsgIntoQueue()" );


    //************************************
    // Mutual exclusion
    //************************************

    pthread_mutex_lock( &mutex );

        m_interThreadQueue.push_back( *obj );

    pthread_mutex_unlock( &mutex );

    //************************************
    //************************************


    //object2 = this->interThreadQueue.front();
    //qInfo( "object2.quantity: %f", object2.quantity );

    qInfo( "at the end of Queue::insertMsgIntoQueue()" );

}

//***************************************************************************

void Queue::getMsgFromQueue()
{


    InterObject  obj;

    // check whether there is any element in the queue
    if ( m_interThreadQueue.size() == 0 )
    {
        qInfo( "No element in the queue !!" );

        return;
    }

    std::this_thread::sleep_for(    std::chrono::milliseconds( 300 )   );



    //**************************************
    //  Mutual exclusion zone
    //**************************************

    pthread_mutex_lock( &mutex );

        /*
            std::deque::front()

            Returns a reference to the first element in the deque
            Calling this function on an empty container causes undefined behavior
        */

        obj = m_interThreadQueue.front();

        /*
            std::deque::pop_front()

            Removes the first element in the deque container, effectively reducing its size by one.
            This destroys the removed element.
        */

        m_interThreadQueue.pop_front();


    pthread_mutex_unlock( &mutex );

    //**************************************
    //**************************************




    qInfo(     ( obj.symbol          ).toLatin1()      );
    qInfo(     ( obj.secType         ).toLatin1()      );
    qInfo(     ( obj.currency        ).toLatin1()      );
    qInfo(     ( obj.exchange        ).toLatin1()      );
    qInfo(     ( obj.primaryExchange ).toLatin1()      );


}

//***************************************************************************
