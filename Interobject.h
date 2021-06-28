#ifndef INTEROBJECT_H
#define INTEROBJECT_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include <float.h>

#define UNSET_DOUBLE DBL_MAX


//******************************************************************************************

struct InterObject
{

    int         typeOfMessage           =   0 ;  // 1: market data;  2: order; 3: account information

    // Order
    QString     action;  // "BUY" or "SELL"
    double      quantity                = 	0 ;
    double      limitPrice              = 	UNSET_DOUBLE;
    double      takeProfitLimitPrice    =   UNSET_DOUBLE;
    double      stopLossPrice           = 	UNSET_DOUBLE;
    QString     orderType;  // "LMT"

    // Contract
    QString     symbol;
    QString     secType;
    QString     currency;
    QString     exchange;
    QString     primaryExchange;

};

//******************************************************************************************

#endif // INTEROBJECT_H
