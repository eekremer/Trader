#ifndef ORDER_H
#define ORDER_H

#include <QString>

//******************************************************************

class Order
{

    public:

        Order(          const QString  &id              =  "",
                        const QString  &timestamp       =  "",
                        const QString  &symbolExchange  =  "",
                        const QString  &action          =  "",
                        const QString  &type            =  "",
                        const QString  &details         =  "",
                        const QString  &quantity        =  "",
                        const QString  &status          =  "",
                        const QString  &fillPx          =  ""           );

        QString  id;
        QString  timestamp;
        QString  symbolExchange;
        QString  action;
        QString  type;
        QString  details;
        QString  quantity;
        QString  status;
        QString  fillPx;

};

//******************************************************************

#endif // ORDER_H
