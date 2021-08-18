#ifndef INTEROBJECT_H
#define INTEROBJECT_H

//#endif // INTEROBJECT_H

#include <QString>


struct InterObject
{

    int         typeOfMessage;  // 1: market data;  2: order; 3: account information

    // Order
    std::string     action;
    double          quantity;
    double          limitPrice;
    double          takeProfitLimitPrice;
    double          stopLossPrice;
    std::string     orderType;  // "LMT"

    // Contract
    std::string     symbol;
    std::string     secType;
    std::string     currency;
    std::string     exchange;
    std::string     primaryExchange;

};

#endif // INTEROBJECT_H
