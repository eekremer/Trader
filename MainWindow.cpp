#include <QTableWidget>
#include <QDebug>
#include <chrono>
#include <thread>


#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "BuySellDialog.h"
#include "DataViewDelegate.h"



pthread_t        clientThread;
pthread_t        tid1;
pthread_mutex_t  mutex;


//********************************************************************************************

MainWindow::MainWindow( QWidget  *parent )
    : QMainWindow( parent )
    , m_ui( new Ui::MainWindow )
{


    m_ui->setupUi( this );

    //----------------------------------------------------------------

    // Order Table and View

    m_orderModel = new OrderTableModel( 10, 9, nullptr );

    m_ui->orderTableView->setModel(  m_orderModel  );

    setOrderTableViewColumnWidth();

    //----------------------------------------------------------------

    // Data Table & View

    m_dataModel = new DataTableModel( 1, 5, nullptr );

    m_ui->dataTableView->setModel(  m_dataModel  );

    setDataTableViewColumnWidth();

    m_ui->dataTableView->setFont( QFont( "Arial", 30 ) );

    DataViewDelegate delegate( this );
    //m_ui->dataTableView->setItemDelegate( &delegate );

    //----------------------------------------------------------------

    // Order params: symbol, security type, currency...
    setMainWindowOrderParams();

    //----------------------------------------------------------------

    // Contract params: action, order type,...
    setMainWindowContractParams();

    //----------------------------------------------------------------

    // set Button's connect...
    setMainWindowButtonConnection();

    //----------------------------------------------------------------

    // set Button's StyleSheet...
    setMainWindowButtonStyleSheet();

    //----------------------------------------------------------------


    // set trader page as landing page
    m_ui->stackedWidget->setCurrentIndex( 0 );


    //*******************
    // pthreads
    //*******************

    createThread();

    //*******************


    pthread_create(                 &tid1,
                                     NULL,
                                    &doSomeThingBigger,
                                    this                                 );

    // initialize random seed
    srand( time( NULL ) );


}

//*********************************************************************************************

MainWindow::~MainWindow()
{
    delete m_ui;
}

//*********************************************************************************************
void MainWindow::createThread()
{

    pthread_mutex_init(         &mutex,
                                 NULL                         );

    /*

        The pthread_create() function starts a new thread in the calling process.
        The new thread starts execution by invoking start_routine(); arg is passed as
        the sole argument of start_routine().

        int pthread_create(                 pthread_t *restrict         thread,
                                 const pthread_attr_t *restrict         attr,
                                                void                    *(*start_routine)(void *),
                                            void *restrict              arg                                 );

    */

    pthread_create(             &clientThread,
                                NULL,
                                &executeClientWork,   // C function
                                &m_outboundQueue                            );

    // note: we are passing on a pointer to the queue object as an arg for the C function

}


//********************************************************************************************

Queue MainWindow::getQueue()
{
    return m_outboundQueue;
}

//********************************************************************************************


void MainWindow::setMainWindowOrderParams()
{


    //----------------------------------------------


    // ComboBox - Symbols
    QStringList symbols;

    symbols << "AAPL" <<"AMZN" << "TSLA" << "MSFT";

    m_ui->symbolComboBox->addItems( symbols );

    m_ui->symbolLabel->setStyleSheet(  "QLabel {  color : red;  }" );


    //----------------------------------------------


    // ComboBox - Security Types
    QStringList secTypes;

    secTypes << "STK";

    m_ui->securityTypeComboBox->addItems( secTypes );


    //----------------------------------------------


    // ComboBox - Currencies
    QStringList currencies;

    currencies << "USD" << "EUR";

    m_ui->currencyComboBox->addItems( currencies );


    //----------------------------------------------


    // ComboBox - Exchanges
    QStringList exchanges;

    exchanges << "SMART";

    m_ui->exchangeComboBox->addItems( exchanges );


    //----------------------------------------------


    // ComboBox - Exchanges
    QStringList primaryExchanges;

    primaryExchanges << "ISLAND";

    m_ui->primaryExchangeComboBox->addItems( primaryExchanges );


    //----------------------------------------------


}

//********************************************************************************************

void MainWindow::setMainWindowContractParams()
{

    //----------------------------------------------

    // ComboBox - Action
    QStringList actions;

    actions << "BUY" << "SELL";

    m_ui->actioncomboBox->addItems( actions );

    //----------------------------------------------

    // ComboBox - Order Type
    QStringList orderTypes;

    orderTypes << "LMT" << "MKT";

    m_ui->orderTypeComboBox->addItems( orderTypes );

    //----------------------------------------------


}

//*****************************************************************************************

void MainWindow::setOrderTableViewColumnWidth()
{


    QVector< int > columnWidths     {       70,     // Id
                                           180,     // Timestamp
                                           180,     // Symbol/Exchange
                                            70,     // Action
                                            70,     // Type
                                           180,     // Details
                                            80,     // Quantity
                                           180,     // Status
                                           160      // Fill Px
                                    };

    // set qtableview's column width

    for ( int i = 0; i < columnWidths.size(); i++ )
        m_ui->orderTableView->setColumnWidth(  i, columnWidths[ i ] );

}

//*****************************************************************************************

void MainWindow::setDataTableViewColumnWidth()
{


    QVector< int > columnWidths     {      200,     // BID
                                           200,     // ASK
                                           120,     // Change in USD
                                           120,     // Change %
                                            70,     // Volume
                                           180,     //
                                    };


    // set qtableview's column width

    for ( int i = 0; i < columnWidths.size(); i++ )
        m_ui->dataTableView->setColumnWidth(  i, columnWidths[ i ] );

}

//*****************************************************************************************

void MainWindow::setMainWindowButtonConnection()
{

    // BUY button
    connect(                m_ui->buyButton,
                            SIGNAL(clicked()),
                            this,
                            SLOT(buyButtonClicked())                    );

    // SELL button
    connect(                m_ui->sellButton,
                            SIGNAL(clicked()),
                            this,
                            SLOT(sellButtonClicked())                    );


    // Setup button
    connect(                m_ui->setupButton,
                            SIGNAL(clicked()),
                            this,
                            SLOT(setupButtonClicked())                    );

    // BUY go-back button
    connect(                m_ui->buyGoBackButton,
                            SIGNAL(clicked()),
                            this,
                            SLOT(buyGoBackButtonClicked())                    );


    // SELL go-back button
    connect(                m_ui->sellGoBackButton,
                            SIGNAL(clicked()),
                            this,
                            SLOT(sellGoBackButtonClicked())                    );

    // Setup go-back button
    connect(                m_ui->setupGoBackButton,
                            SIGNAL(clicked()),
                            this,
                            SLOT(setupGoBackButtonClicked())                    );

    // Confirm buy button
    connect(                m_ui->confirmBuy,
                            SIGNAL(clicked()),
                            this,
                            SLOT(confirmBuyClicked())                           );

    connect(                m_ui->pushButton,
                            SIGNAL( clicked() ),
                            this,
                            SLOT( on_pushButton_clicked() )                        );

}

//*****************************************************************************************

void  MainWindow::setMainWindowButtonStyleSheet()
{


    this->setStyleSheet(                        "QMainWindow{"
                                                "background-color:#A3E4B7;"
                                                "}"                                     );

    m_ui->buyButton->setStyleSheet(             "QPushButton{"
                                                "background-color:#CB4335;"
                                                "}"                                     );

    m_ui->sellButton->setStyleSheet(            "QPushButton{"
                                                "background-color:#2ECC71;"
                                                "}"                                     );

    //SET-UP button
    m_ui->setupButton->setStyleSheet(           "QPushButton{"
                                                "background-color:#2ECC71;"
                                                "}"                                     );

    // go-back button
    m_ui->buyGoBackButton->setStyleSheet(       "QPushButton{"
                                                "background-color:#0066ff;"
                                                "}"                                     );

    // go-back button
    m_ui->sellGoBackButton->setStyleSheet(      "QPushButton{"
                                                "background-color:#0066ff;"
                                                "}"                                     );

    // go-back button
    m_ui->setupButton->setStyleSheet(           "QPushButton{"
                                                "background-color:#0066ff;"
                                                "}"                                     );

    // go-back button
    m_ui->confirmBuy->setStyleSheet(            "QPushButton{"
                                                "background-color:#0066ff;"
                                                "}"                                     );

}

//*****************************************************************************************

// slot: BUY button
void MainWindow::buyButtonClicked()
{

    qInfo( "BUY button clicked !!" );

    // go to page BUY
    //m_ui->stackedWidget->setCurrentIndex( 1 );


    // go to BUY dialog
    BuySellDialog dialog( this );

    if ( dialog.exec() )
    {

    }


}

//*******************************************************************************************************

// slot: SELL button
void MainWindow::sellButtonClicked()
{

    qInfo( "SELL button clicked !!" );

    // go to page SELL
    m_ui->stackedWidget->setCurrentIndex( 2 );

}


//*******************************************************************************************************

// slot: Setup button
void MainWindow::setupButtonClicked()
{

    qInfo( "Setup button clicked !!" );

    // go to page SELL
    m_ui->stackedWidget->setCurrentIndex( 3 );

}

//*******************************************************************************************************

void MainWindow::goToBuySellDialog()
{



}

//*******************************************************************************************************

void MainWindow::buyGoBackButtonClicked()
{
    m_ui->stackedWidget->setCurrentIndex( 0 );
}

//*******************************************************************************************************

void MainWindow::sellGoBackButtonClicked()
{
    m_ui->stackedWidget->setCurrentIndex( 0 );
}

//*******************************************************************************************************

void MainWindow::setupGoBackButtonClicked()
{
    m_ui->stackedWidget->setCurrentIndex( 0 );
}

//*******************************************************************************************************

void MainWindow::confirmBuyClicked()
{


    qInfo( "confirmBuy button clicked" );

    InterObject  object;

    object.action                   =   "BUY";
    object.quantity                 =   100;
    object.limitPrice               =   50;
    object.takeProfitLimitPrice     =   70;
    object.stopLossPrice            =   30;
    object.orderType                =   "LMT";

    object.symbol                   =   "TSLA";
    object.secType                  =   "STK";
    object.currency                 =   "EUR";
    object.exchange                 =   "SMART";
    object.primaryExchange          =   "HEX";


    //******************************************

    m_outboundQueue.insertMsgIntoQueue( &object );

    //******************************************

    m_ui->stackedWidget->setCurrentIndex( 0 );

}

//*******************************************************************************************************


// this will be the main...
void* MainWindow::executeClientWork( void *lpParam )
{

    while( 1 )
    {

        std::this_thread::sleep_for(    std::chrono::seconds( 1 )   );

        qInfo( "pthread worker !!" );

        // here we are casting to Queue* from void*
        Queue *pThis = reinterpret_cast< Queue* >( lpParam );

        // we check whether there is any object in the queue
        pThis->getMsgFromQueue();

    }

    return 0;

}

//*******************************************************************************************************



void MainWindow::on_pushButton_clicked()
{

    QModelIndex index1 = m_orderModel->index(            0,
                                                    0,
                                                    QModelIndex()           );

    m_orderModel->setData(          index1,
                                    "200",
                                    Qt::EditRole          );

}

//*******************************************************************************************************

void* MainWindow::doSomeThingBigger( void  *arg )
{

    while( 1 )
    {

        MainWindow *win = reinterpret_cast< MainWindow* >( arg );

        QModelIndex l_index = win->m_orderModel->index(         0,
                                                                0,
                                                                QModelIndex()       );
        // hack
        static int counter = 100;

        win->m_orderModel->setData(             l_index,
                                                counter,
                                                Qt::EditRole                        );

        std::this_thread::sleep_for(            std::chrono::seconds( 1 )           );

        qInfo( "second thread !!" );

        counter++;

    }

}

//*******************************************************************************************************
