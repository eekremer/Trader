#ifndef DATA_H
#define DATA_H

#include <QString>


//************************************************************************

class Data
{

    public:

        Data(           const QString  &bid              =  "",
                        const QString  &ask              =  "",
                        const QString  &lastClosing      =  "",
                        const QString  &absoluteChange   =  "",
                        const QString  &porcentualChange =  ""           );

        QString  bid;
        QString  ask;
        QString  lastClosing;
        QString  absoluteChange;
        QString  porcentualChange;

};

//************************************************************************

#endif // DATA_H
