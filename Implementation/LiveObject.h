#ifndef LIVEOBJECT_H
#define LIVEOBJECT_H

#include <QObject>


class LiveObject  :  public QObject
{

    Q_OBJECT

    public:


       LiveObject();


       void     computePrice            (                                           );

    // bool     didDataChanged          (       double                              );


       // getter's and setter's

       double   priceToOffer            (                                           ) const;
       void     priceToOffer            (       double      priceToOffer            );

       double   bidPrice                (                                           ) const;
       void     bidPrice                (       double      bidPrice                );

       double   askPrice                (                                           ) const;
       void     askPrice                (       double      askPrice                );

       int      sliderValue             (                                           ) const;
       void     sliderValue             (       int         sliderValue             );

       double   openingPrice            (                                           ) const;
       void     openingPrice            (       double      openingPrice            );

       double   closingPrice            (                                           ) const;
       void     closingPrice            (       double      closingPrice            );

       double   lastPrice               (                                           ) const;
       void     lastPrice               (       double      lastPrice               );

       double   profitToTakePrice       (                                           ) const;
       void     profitToTakePrice       (       double      profitToTakePrice       );

       double   stopLossPrice           (                                           ) const;
       void     stopLossPrice           (       double      stopLossPrice           );

       double   profitToTakePercentage  (                                           ) const;
       void     profitToTakePercentage  (       double      profitToTakePercentage  );

       double   stopLossPercentage      (                                           ) const;
       void     stopLossPercentage      (       double      stopLossPercentage      );

       double   incrementalProfit       (                                           ) const;
       void     incrementalProfit       (       double      incrementalProfit       );

       double   incrementalLoss         (                                           ) const;
       void     incrementalLoss         (       double      incrementalLoss         );


    public slots:



    signals:

       void     sendText                (  const QString&   newText                 );


    private:

       double   m_priceToOffer;
       double   m_bidPrice;
       double   m_askPrice;
       double   m_sliderValue;
       double   m_openingPrice;
       double   m_closingPrice;
       double   m_lastPrice;
       double   m_profitToTakePrice;
       double   m_stopLossPrice;
       double   m_profitToTakePercentage;
       double   m_stopLossPercentage;
       double   m_incrementalProfit;
       double   m_incrementalLoss;

};

#endif // LIVEOBJECT_H
