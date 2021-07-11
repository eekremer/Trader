#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QItemDelegate>
#include <QStandardItemModel>
#include <QSystemTrayIcon>
#include <pthread.h>

#include "OrderTableModel.h"
#include "DataTableModel.h"
#include "DataViewDelegate.h"
#include "OrderViewDelegate.h"
#include "Implementation/Client.h"



//***********************************************************************************

QT_BEGIN_NAMESPACE

namespace Ui
{
    class MainWindow;
}

QT_END_NAMESPACE

//***********************************************************************************

struct InterObject
{

    int         typeOfMessage;  // 1: market data;  2: order; 3: account information

    // Order
    QString     action;
    double      quantity;
    double      limitPrice;
    double      takeProfitLimitPrice;
    double      stopLossPrice;
    QString     orderType;  // "LMT"

    // Contract
    QString     symbol;
    QString     secType;
    QString     currency;
    QString     exchange;
    QString     primaryExchange;

};

//***********************************************************************************


// forward declaration
class Client;


//***********************************************************************************

class MainWindow : public QMainWindow
{


        Q_OBJECT

    public:

        MainWindow( QWidget *parent = nullptr );

       ~MainWindow();


    signals:




    private slots:

        void                buyButtonClicked();
        void                sellButtonClicked();
        void                setupButtonClicked();
        void                confirmBuyClicked();
        void                confirmButtonClicked();

        void                goToBuySellDialog();
        void                symbolComboBoxTextChanged( const QString&  symbol );


    public:


        void                setMainWindowOrderParams     ();
        void                setMainWindowContractParams  ();
        void                setOrderTableViewColumnWidth ();
        void                setDataTableViewColumnWidth  ();
        void                setDataTableViewHeaderSize   ();

        void                setMainWindowButtonConnection();
        void                setMainWindowButtonStyleSheet();
        void                insertMsgIntoQueue           (    InterObject  msg      );


    private:

        Ui::MainWindow     *m_ui;


    public:


        OrderTableModel    *m_orderModel;
        DataTableModel     *m_dataModel;
        DataViewDelegate   *m_dataDelegate;
        OrderViewDelegate  *m_orderDelegate;

        std::deque<InterObject>         m_guiEventQueue;
        pthread_mutex_t                 m_guiEventQueueMutex;


};

//***********************************************************************************
#endif // MAINWINDOW_H
