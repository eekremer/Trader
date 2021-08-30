#include "LiveObject.h"

#include <utility> // for std::move
#include  <QDebug>



//************************************************************************************

LiveObject::LiveObject()    :       m_priceToOffer          ( -1 ),
                                    m_bidPrice              ( -1 ),
                                    m_askPrice              ( -1 ),
                                    m_sliderValue           ( -1 ),
                                    m_openingPrice          ( -1 ),
                                    m_closingPrice          ( -1 ),
                                    m_lastPrice             ( -1 ),
                                    m_profitToTakePrice     ( -1 ),
                                    m_stopLossPrice         ( -1 ),
                                    m_profitToTakePercentage( -1 ),
                                    m_stopLossPercentage    ( -1 ),
                                    m_incrementalProfit     ( -1 ),
                                    m_incrementalLoss       ( -1 )
{

    qInfo(  "inside default ctor LiveObject::LiveObject()\n"  );

}

//************************************************************************************

void  LiveObject::computePriceToOffer()
{


    if (  ( m_bidPrice != -1 ) && ( m_askPrice != -1 ) && ( m_sliderValue != -1 )  )
    {

        // price computation
        // if m_slideValue = 0  =>  m_bidPrice
        // if m_slideValue = 6  =>  m_askPrice
        m_priceToOffer = m_bidPrice * ( 1 - ( m_sliderValue / 6 ) ) + m_askPrice * ( m_sliderValue / 6 );

    }
    else
    {

        m_priceToOffer = -1;

    }

}

//************************************************************************************

void  LiveObject::showPriceToOffer()
{

    emit sendPriceToOfferLabel(  (  QString::number( m_priceToOffer, 'f', 2 )  )  );  // "hola"

}

//************************************************************************************

void  LiveObject::showBidPrice()
{

    emit sendBidPrice(  (  QString::number( m_bidPrice, 'f', 2 )  )  );  // "hola"

}

//************************************************************************************

void  LiveObject::showAskPrice()
{

    emit sendAskPrice(  (  QString::number( m_askPrice, 'f', 2 )  )  );  // "hola"

}

//************************************************************************************

double  LiveObject::LiveObject::priceToOffer() const
{

    return m_priceToOffer;

}

//************************************************************************************

void  LiveObject::priceToOffer( double  priceToOffer )
{

    m_priceToOffer = std::move(  priceToOffer  );

}

//************************************************************************************

// getter
double  LiveObject::bidPrice() const
{

    return m_bidPrice;

}

//************************************************************************************

// setter
void  LiveObject::bidPrice( double  bidPrice )
{

    m_bidPrice = std::move(  bidPrice  );

    showBidPrice();

    computePriceToOffer();

    showPriceToOffer();

}

//************************************************************************************

// getter
double  LiveObject::askPrice() const
{

    return m_askPrice;

}

//************************************************************************************

// setter
void  LiveObject::askPrice( double  askPrice )
{

    m_askPrice = std::move(  askPrice  );

    showAskPrice();

    computePriceToOffer();

    showPriceToOffer();

}

//************************************************************************************

int  LiveObject::sliderValue() const
{

    return m_sliderValue;

}

//************************************************************************************

void  LiveObject::sliderValue( int  sliderValue )
{

    m_sliderValue = std::move(  sliderValue  );

    computePriceToOffer();

    showPriceToOffer();

}

//************************************************************************************

double  LiveObject::openingPrice() const
{

    return m_openingPrice;

}

//************************************************************************************

void  LiveObject::openingPrice( double  openingPrice )
{

    m_sliderValue = std::move(  openingPrice  );

}

//************************************************************************************

double  LiveObject::closingPrice() const
{

    return m_closingPrice;

}

//************************************************************************************

void  LiveObject::closingPrice( double  closingPrice )
{

    m_closingPrice = std::move(  closingPrice  );

}

//************************************************************************************

double  LiveObject::lastPrice() const
{

    return m_lastPrice;

}

//************************************************************************************

void  LiveObject::lastPrice( double  lastPrice )
{

    m_lastPrice = std::move(  lastPrice  );

}

//************************************************************************************


double  LiveObject::profitToTakePrice() const
{

    return m_profitToTakePrice;

}

//************************************************************************************

void  LiveObject::profitToTakePrice( double  profitToTakePrice )
{

    m_profitToTakePrice = std::move(  profitToTakePrice  );

}

//************************************************************************************

double  LiveObject::stopLossPercentage() const
{

    return m_stopLossPercentage;

}

//************************************************************************************

void  LiveObject::stopLossPercentage( double  stopLossPercentage )
{

    m_stopLossPercentage = std::move(  stopLossPercentage  );

}

//************************************************************************************

double  LiveObject::incrementalProfit() const
{

    return m_incrementalProfit;

}

//************************************************************************************

void  LiveObject::incrementalProfit(  double  incrementalProfit  )
{

    m_incrementalProfit = std::move(  incrementalProfit  );

}

//************************************************************************************

double  LiveObject::incrementalLoss() const
{

    return m_incrementalLoss;

}

//************************************************************************************

void  LiveObject::incrementalLoss(  double  incrementalLoss  )
{

    m_incrementalLoss = std::move(  incrementalLoss  );

}

//************************************************************************************

