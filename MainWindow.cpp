#include  <QTableWidget>
#include  <QDebug>
#include  <chrono>
#include  <thread>
#include  <QPainter>
#include  <QLinearGradient>


#include  "MainWindow.h"
#include  "ui_MainWindow.h"
#include  "BuySellDialog.h"
#include  "DataViewDelegate.h"
#include  "OrderViewDelegate.h"


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

    m_orderModel = new OrderTableModel(  10,  9, nullptr  );

    m_ui->orderTableView->setModel(  m_orderModel  );

    setOrderTableViewColumnWidth();

    //m_orderDelegate = new OrderViewDelegate( this );

    //----------------------------------------------------------------

    // Data Table & View

    m_dataModel = new DataTableModel(  1,  6, nullptr  );

    m_ui->dataTableView->setModel(  m_dataModel  );

    setDataTableViewColumnWidth();
    setDataTableViewHeaderSize ();

    m_dataDelegate = new DataViewDelegate( this );
    m_ui->dataTableView->setItemDelegate( m_dataDelegate );

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

    // set initial default to BUY
    buyButtonClicked();

    //----------------------------------------------------------------



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

    symbols << "AAPL" << "AMZN" << "TSLA" << "MSFT";

    m_ui->symbolComboBox->addItems( symbols );

    m_ui->symbolLabel->setStyleSheet(  "QLabel {  color: white;  }" );


    //----------------------------------------------


    // ComboBox - Security Types
    QStringList secTypes;

    secTypes << "STK" << "HOLA" << "CHAO";

    m_ui->securityTypeComboBox->addItems( secTypes );

    m_ui->securityLabel->setStyleSheet(  "QLabel {  color: white;  }" );


    //----------------------------------------------


    // ComboBox - Currencies
    QStringList currencies;

    currencies << "USD" << "EUR";

    m_ui->currencyComboBox->addItems( currencies );

    m_ui->currencyLabel->setStyleSheet(  "QLabel {  color: white;  }" );


    //----------------------------------------------


    // ComboBox - Exchanges
    QStringList exchanges;

    exchanges << "SMART";

    m_ui->exchangeComboBox->addItems( exchanges );

    m_ui->exchangeLabel->setStyleSheet(  "QLabel {  color: white;  }" );


    //----------------------------------------------


    // ComboBox - Exchanges
    QStringList primaryExchanges;

    primaryExchanges << "ISLAND";

    m_ui->primaryExchangeComboBox->addItems( primaryExchanges );

    m_ui->primaryExchangeLabel->setStyleSheet(  "QLabel {  color: white;  }" );


    //----------------------------------------------


}

//********************************************************************************************

void MainWindow::setMainWindowContractParams()
{

    //----------------------------------------------

    // Label - Take Profit price

    m_ui->takeProfitPriceLabel->setStyleSheet(  "QLabel {  color: white;  }"  );
    m_ui->takeProfitLabel->setStyleSheet     (  "QLabel {  color: white;  }"  );

    //----------------------------------------------

    // Label - Stop Loss price

    m_ui->stopLossPriceLabel->setStyleSheet  (  "QLabel {  color: white;  }"  );
    m_ui->stopLossLabel->setStyleSheet       (  "QLabel {  color: white;  }"  );


    //----------------------------------------------

    // Label - Action

    m_ui->actionLabel_2->setStyleSheet       (  "QLabel {  color: white;  }"  );
    m_ui->actionLabel->setStyleSheet         (  "QLabel {  color: white;  }"  );

    //----------------------------------------------

    // LineEdit - Quantity

    m_ui->quantityLabel->setStyleSheet       (  "QLabel {  color: white;  }"  );

    //----------------------------------------------

    // ComboBox - Order Type
    QStringList orderTypes;

    orderTypes << "LMT" << "MKT";

    m_ui->orderTypeComboBox->addItems( orderTypes );

    m_ui->orderTypeLabel->setStyleSheet(  "QLabel {  color: white;  }"  );

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


    QVector< int > columnWidths     {      100,     // BID
                                           100,     // ASK
                                           100,     // Last
                                           100,     // Change in USD
                                           100,     // Change %
                                           100,     // Volume
                                    };


    // set qtableview's column width

    for ( int i = 0; i < columnWidths.size(); i++ )
        m_ui->dataTableView->setColumnWidth(  i, columnWidths[ i ] );

}

//*****************************************************************************************

void  MainWindow::setDataTableViewHeaderSize()
{

    //m_ui->dataTableView->setFont(   QFont( "Arial", 30 )   );
/*
    // Example 1
    QFont font = m_ui->dataTableView->horizontalHeader()->font();

    font.setPointSize( 14 );

    m_ui->dataTableView->horizontalHeader()->setFont( font );
*/
    // Example 2
    m_ui->dataTableView->horizontalHeader()->setStyleSheet(
                                            "QHeaderView {   font-size: 12pt;"
                                                            "color:white;"
                                                            "background-color:black;"
                                                                                        "}" );

}

//*****************************************************************************************

void MainWindow::setMainWindowButtonConnection()
{

    // BUY button
    connect(                m_ui->buyButton,
                            SIGNAL(clicked()),
                            this,
                            SLOT(buyButtonClicked())                            );

    // SELL button
    connect(                m_ui->sellButton,
                            SIGNAL(clicked()),
                            this,
                            SLOT(sellButtonClicked())                           );


    // Setup button
    connect(                m_ui->setupButton,
                            SIGNAL(clicked()),
                            this,
                            SLOT(setupButtonClicked())                          );


    // Confirm buy button
    connect(                m_ui->confirmButton,
                            SIGNAL(clicked()),
                            this,
                            SLOT(confirmButtonClicked())                        );

    connect(                m_ui->pushButton,
                            SIGNAL( clicked() ),
                            this,
                            SLOT(on_pushButton_clicked())                       );


    connect(                m_ui->symbolComboBox,
                            SIGNAL(currentTextChanged(QString)),
                            this,
                            SLOT(symbolComboBoxTextChanged(QString))                                 );

}

//*****************************************************************************************

void  MainWindow::setMainWindowButtonStyleSheet()
{


    this->setStyleSheet(                        "QMainWindow{"
                                                "background-color: #333333;"
                                                "}"                                     );

    m_ui->confirmButton->setStyleSheet(         "QPushButton{"
                                                "background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 black, stop: 1 orange );"
                                                "color: white;"
                                                "font-size: 25px;"
                                                "border-style: solid;"
                                                "border-color: grey;"
                                                "border-width: 1px;"
                                                "border-radius: 5px;"
                                                "}"
                                                "QPushButton:hover {"
                                                "background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 black, stop: 1  #cf8917 );"
                                                "}"

                                    );

    m_ui->setupButton->setStyleSheet(           "QPushButton{"
                                                "background-color: #2ECC71;"
                                                "}"                                     );


}

//*****************************************************************************************

// slot: BUY button
void MainWindow::buyButtonClicked()
{

    qInfo( "BUY button clicked !!" );

    m_ui->buyButton->setStyleSheet(             "QPushButton{"
                                                "background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 black, stop: 1 green );"
                                                "color: white;"
                                                "font-size: 25px;"
                                                "border-style: solid;"
                                                "border-color: black;"
                                                "border-width: 1px;"
                                                "border-radius: 5px;"
                                                "}"
                                                "QPushButton:hover {"
                                                "background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #7f8c8d, stop: 1  green );"
                                                "}"
                                                                                            );


    m_ui->sellButton->setStyleSheet(            "QPushButton{"
                                                "background-color: #999999;"
                                                "color: #454545;"
                                                "font-size: 25px;"
                                                "border-style: solid;"
                                                "border-color: black;"
                                                "border-width: 1px;"
                                                "border-radius: 5px;"
                                                "}"
                                                "QPushButton:hover {"
                                                "background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 grey, stop: 1  #7f8c8d );"
                                                "}"
                                                                                            );

    m_ui->actionLabel->setText( "BUY" );

}

//*****************************************************************************************

// slot: SELL button
void MainWindow::sellButtonClicked()
{

    qInfo( "SELL button clicked !!" );

    qInfo( "BUY button clicked !!" );

    m_ui->sellButton->setStyleSheet(            "QPushButton{"
                                                "background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 black, stop: 1 red );"
                                                "color: white;"
                                                "font-size: 25px;"
                                                "border-style: solid;"
                                                "border-color: grey;"
                                                "border-width: 1px;"
                                                "border-radius: 5px;"
                                                "}"
                                                "QPushButton:hover {"
                                                "background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #7f8c8d, stop: 1 red );"
                                                "}"                                         );

    m_ui->buyButton->setStyleSheet(            "QPushButton{"
                                                "background-color: #999999;"
                                                "color: #454545;"
                                                "font-size: 25px;"
                                                "border-style: solid;"
                                                "border-color: grey;"
                                                "border-width: 1px;"
                                                "border-radius: 5px;"
                                                "}"
                                                "QPushButton:hover {"
                                                "background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 grey, stop: 1  #7f8c8d );"
                                                "}"                                    );

    m_ui->actionLabel->setText( "SELL" );

}

//***************************************************************************************

void MainWindow::confirmButtonClicked()
{

    // go to BUY dialog
    BuySellDialog dialog( this );

    if ( dialog.exec() )
    {

    }

}

//****************************************************************************************

// slot: Setup button
void MainWindow::setupButtonClicked()
{

    qInfo( "Setup button clicked !!" );

    // go to page SELL


}

//****************************************************************************************

void MainWindow::goToBuySellDialog()
{



}

//****************************************************************************************

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

}

//**************************************************************************************


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

//************************************************************************************


void MainWindow::on_pushButton_clicked()
{

    QModelIndex index1 = m_orderModel->index(            0,
                                                    0,
                                                    QModelIndex()           );

    m_orderModel->setData(          index1,
                                    "200",
                                    Qt::EditRole          );

}

//***************************************************************************************

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

//***************************************************************************************


void MainWindow::symbolComboBoxTextChanged( const QString&  symbol )
{

    InterObject marketDataToRequest;

    // populate obj
    marketDataToRequest.typeOfMessage   =  1;       // market data request
    marketDataToRequest.symbol          =  symbol;
    marketDataToRequest.secType         =  m_ui->securityTypeComboBox->currentText();
    marketDataToRequest.currency        =  m_ui->currencyComboBox->currentText();
    marketDataToRequest.exchange        =  m_ui->exchangeComboBox->currentText();
    marketDataToRequest.primaryExchange =  m_ui->primaryExchangeComboBox->currentText();

    // insert obj into the queue
    this->m_outboundQueue.insertMsgIntoQueue( &marketDataToRequest );

    // hack
    int index = m_ui->securityTypeComboBox->currentIndex();
    qInfo( "index: %d", index );

}

//***************************************************************************************


