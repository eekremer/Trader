#ifndef QUEUE_H
#define QUEUE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <deque>

#include "Interobject.h"


class Queue
{

    public:

        Queue();
       ~Queue( void );

        void  insertMsgIntoQueue( InterObject* );
        void  getMsgFromQueue();


    private:

        std::deque< InterObject >    m_interThreadQueue;


};

#endif // QUEUE_H
