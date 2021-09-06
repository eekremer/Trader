#ifndef LIVEOBJECT_H
#define LIVEOBJECT_H

#include <QObject>


class LiveObject  :  public QObject
{

    Q_OBJECT

    public:


       LiveObject();

       void     computePriceToOffer     ();

       void     showPriceToOffer        ();
       void     showBidPrice            ();
       void     showAskPrice            ();
       void     showLastPrice           ();
       void     showPriceDiff           ();
       void     showPricePercentageDiff ();
       void     showOpeningPrice        ();
       void     showClosingPrice        ();
       void     showTradingVolume       ();


       // getter's and setter's

       double   priceToOffer            (                                               ) const;
       void     priceToOffer            (           double      priceToOffer            );

       double   bidPrice                (                                               ) const;
       void     bidPrice                (           double      bidPrice                );

       double   askPrice                (                                               ) const;
       void     askPrice                (           double      askPrice                );

       int      sliderValue             (                                               ) const;
       void     sliderValue             (           int         sliderValue             );

       double   lastPrice               (                                               ) const;
       void     lastPrice               (           double      lastPrice               );

       double   priceDiff               (                                               ) const;
       void     priceDiff               (           double      priceDiff               );

       double   pricePercentageDiff     (                                               ) const;
       void     pricePercentageDiff     (           double      pricePorcentageDiff     );

       double   openingPrice            (                                               ) const;
       void     openingPrice            (           double      openingPrice            );

       double   closingPrice            (                                               ) const;
       void     closingPrice            (           double      closingPrice            );

       double   tradingVolume           (                                               ) const;
       void     tradingVolume           (           double      tradingVolume           );

       double   profitToTakePrice       (                                               ) const;
       void     profitToTakePrice       (           double      profitToTakePrice       );

       double   stopLossPrice           (                                               ) const;
       void     stopLossPrice           (           double      stopLossPrice           );

       double   profitToTakePercentage  (                                               ) const;
       void     profitToTakePercentage  (           double      profitToTakePercentage  );

       double   stopLossPercentage      (                                               ) const;
       void     stopLossPercentage      (           double      stopLossPercentage      );

       double   incrementalProfit       (                                               ) const;
       void     incrementalProfit       (           double      incrementalProfit       );

       double   incrementalLoss         (                                               ) const;
       void     incrementalLoss         (           double      incrementalLoss         );


    public slots:



    signals:

       void     sendPriceToOfferLabel   (   const   QString&    newText                 );
       void     sendBidPrice            (   const   QString&    newBidPrice             );
       void     sendAskPrice            (   const   QString&    newAskPrice             );
       void     sendLastPrice           (   const   QString&    newAskPrice             );

       void     sendPriceDiff           (   const   QString&    newAskPrice             );
       void     sendPricePercentageDiff (   const   QString&    newAskPrice             );
       void     sendOpeningPrice        (   const   QString&    newAskPrice             );
       void     sendClosingPrice        (   const   QString&    newAskPrice             );
       void     sendTradingVolume       (   const   QString&    newAskPrice             );

    private:

       // dataTableView
       double   m_priceToOffer;
       double   m_bidPrice;
       double   m_askPrice;
       double   m_sliderValue;

       // diffTableView
       double   m_lastPrice;
       double   m_priceDiff;
       double   m_pricePercentageDiff;
       double   m_openingPrice;
       double   m_closingPrice;
       double   m_tradingVolume;

       // brackettableView
       double   m_profitToTakePrice;
       double   m_stopLossPrice;
       double   m_profitToTakePercentage;
       double   m_stopLossPercentage;
       double   m_incrementalProfit;
       double   m_incrementalLoss;

       // orderTableView


};

#endif // LIVEOBJECT_H
