#ifndef INTEROBJECT_H
#define INTEROBJECT_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include <float.h>

#define UNSET_DOUBLE DBL_MAX




//******************************************************************************************

struct Order
{

};

//******************************************************************************************

struct Contract
{

};

//******************************************************************************************

struct InterObject
{

    // Order
    std::string 		action;  // "BUY" or "SELL"
    double     			quantity                = 	0;
    double   			limitPrice              = 	UNSET_DOUBLE;
    double              takeProfitLimitPrice    =   UNSET_DOUBLE;
    double   			stopLossPrice           = 	UNSET_DOUBLE;
    std::string 		orderType;  // "LMT"

    // Contract
    std::string         symbol;
    std::string         secType;
    std::string         currency;
    std::string         exchange;
    std::string         primaryExchange;

};

//******************************************************************************************

#endif // INTEROBJECT_H
