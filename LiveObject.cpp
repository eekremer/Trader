#include "LiveObject.h"

#include <utility> // for std::move
#include  <QDebug>



//************************************************************************************

LiveObject::LiveObject()    :       m_priceToOffer          ( -1 ),
                                    m_bidPrice              ( -1 ),
                                    m_askPrice              ( -1 ),
                                    m_sliderValue           ( -1 ),

                                    m_lastPrice             ( -1 ),
                                    m_priceDiff             ( -1 ),
                                    m_pricePercentageDiff   ( -1 ),
                                    m_openingPrice          ( -1 ),
                                    m_closingPrice          ( -1 ),
                                    m_tradingVolume         ( -1 ),

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

    showPriceToOffer();

}





//************************************************************************************
//************************************************************************************
// Emit signals
//************************************************************************************
//************************************************************************************


void  LiveObject::showPriceToOffer()
{

    emit sendPriceToOfferLabel(  (  QString::number( m_priceToOffer, 'f', 2 )  )  );

}

//************************************************************************************

void  LiveObject::showBidPrice()
{

    emit sendBidPrice(  (  QString::number( m_bidPrice, 'f', 2 )  )  );

}

//************************************************************************************

void  LiveObject::showAskPrice()
{

    emit sendAskPrice(  (  QString::number( m_askPrice, 'f', 2 )  )  );

}

//************************************************************************************

void  LiveObject::showLastPrice()
{

    emit sendLastPrice(  (  QString::number( m_lastPrice, 'f', 2 )  )  );

}

//************************************************************************************

void  LiveObject::showPriceDiff()
{

    emit sendPriceDiff(  (  QString::number( m_priceDiff, 'f', 2 )  )  );

}

//************************************************************************************

void  LiveObject::showPricePercentageDiff()
{

    emit sendPricePercentageDiff(  (  QString::number( m_pricePercentageDiff, 'f', 2 )  )  );

}

//************************************************************************************

void  LiveObject::showOpeningPrice()
{

    emit sendOpeningPrice(  QString::number( m_openingPrice, 'f', 2 )   );

}

//************************************************************************************

void  LiveObject::showClosingPrice()
{

    emit sendClosingPrice(  QString::number( m_closingPrice, 'f', 2 )   );

}

//************************************************************************************

void  LiveObject::showTradingVolume()
{

    emit sendTradingVolume(  (  QString::number( m_tradingVolume, 'f', 2 )   )   );

}

//************************************************************************************






//************************************************************************************
//************************************************************************************
// getter's & setter's
//************************************************************************************
//************************************************************************************

// getter
double  LiveObject::LiveObject::priceToOffer() const
{

    return m_priceToOffer;

}

//************************************************************************************

// setter
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

}

//************************************************************************************

// getter
int  LiveObject::sliderValue() const
{

    return m_sliderValue;

}

//************************************************************************************

// setter
void  LiveObject::sliderValue( int  sliderValue )
{

    m_sliderValue = std::move(  sliderValue  );

    computePriceToOffer();

}

//************************************************************************************

// getter
double  LiveObject::lastPrice() const
{

    return m_lastPrice;

}

//************************************************************************************

// setter
void  LiveObject::lastPrice( double  lastPrice )
{

    m_lastPrice = std::move(  lastPrice  );

    showLastPrice();

    priceDiff(  m_lastPrice - m_openingPrice  );

    pricePercentageDiff(  ( m_lastPrice - m_openingPrice ) / m_openingPrice * 100  );

}

//************************************************************************************

// getter
double  LiveObject::priceDiff() const
{

    return m_lastPrice;

}

//************************************************************************************

// setter
void  LiveObject::priceDiff( double  priceDiff )
{

    m_priceDiff = std::move(  priceDiff  );

    showPriceDiff();

}

//************************************************************************************

// getter
double  LiveObject::pricePercentageDiff() const
{

    return m_pricePercentageDiff;

}

//************************************************************************************

// setter
void  LiveObject::pricePercentageDiff(  double  pricePorcentageDiff  )
{

    m_pricePercentageDiff = std::move(  pricePorcentageDiff  );

    showPricePercentageDiff();

}

//************************************************************************************

// getter
double  LiveObject::openingPrice() const
{

    return m_openingPrice;

}

//************************************************************************************

// setter
void  LiveObject::openingPrice( double  openingPrice )
{

    m_openingPrice = std::move(  openingPrice  );

    showOpeningPrice();

}

//************************************************************************************

// getter
double  LiveObject::closingPrice() const
{

    return m_closingPrice;

}

//************************************************************************************

// setter
void  LiveObject::closingPrice( double  closingPrice )
{

    m_closingPrice = std::move(  closingPrice  );

    showClosingPrice();

}

//************************************************************************************

// getter
double  LiveObject::tradingVolume() const
{

    return m_tradingVolume;

}

//************************************************************************************

// setter
void  LiveObject::tradingVolume(  double  tradingVolume  )
{

    m_tradingVolume = std::move(  tradingVolume  );

    showTradingVolume();

}

//************************************************************************************

// getter
double  LiveObject::profitToTakePrice() const
{

    return m_profitToTakePrice;

}

//************************************************************************************

// setter
void  LiveObject::profitToTakePrice(  double  profitToTakePrice  )
{

    m_profitToTakePrice = std::move(  profitToTakePrice  );

}

//************************************************************************************

// getter
double  LiveObject::stopLossPrice() const
{

    return m_stopLossPrice;

}

//************************************************************************************

// setter
void  LiveObject::stopLossPrice(  double  stopLossPrice  )
{

    m_stopLossPrice = std::move(  stopLossPrice  );

}

//************************************************************************************

// getter
double  LiveObject::profitToTakePercentage() const
{

    return m_profitToTakePercentage;

}

//************************************************************************************

// setter
void  LiveObject::profitToTakePercentage  (  double  profitToTakePercentage  )
{

    m_profitToTakePercentage = std::move(  profitToTakePercentage  );

}

//************************************************************************************

// getter
double  LiveObject::stopLossPercentage() const
{

    return m_stopLossPercentage;

}

//************************************************************************************

// setter
void  LiveObject::stopLossPercentage( double  stopLossPercentage )
{

    m_stopLossPercentage = std::move(  stopLossPercentage  );

}

//************************************************************************************

// getter
double  LiveObject::incrementalProfit() const
{

    return m_incrementalProfit;

}

//************************************************************************************

// setter
void  LiveObject::incrementalProfit(  double  incrementalProfit  )
{

    m_incrementalProfit = std::move(  incrementalProfit  );

}

//************************************************************************************

// getter
double  LiveObject::incrementalLoss() const
{

    return m_incrementalLoss;

}

//************************************************************************************

// setter
void  LiveObject::incrementalLoss(  double  incrementalLoss  )
{

    m_incrementalLoss = std::move(  incrementalLoss  );

}

//************************************************************************************


