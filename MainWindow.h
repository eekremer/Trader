#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QItemDelegate>
#include <QStandardItemModel>
#include <pthread.h>

#include "Queue.h"
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
        void                on_pushButton_clicked();
        void                confirmButtonClicked();

        void                goToBuySellDialog();
        void                symbolComboBoxTextChanged( const QString&  symbol );


    public:

        Queue*              getQueue();

        static void*        doSomeThingBigger            (  void*    arg  );

        void                setMainWindowOrderParams     ();
        void                setMainWindowContractParams  ();
        void                setOrderTableViewColumnWidth ();
        void                setDataTableViewColumnWidth  ();
        void                setDataTableViewHeaderSize   ();

        void                setMainWindowButtonConnection();
        void                setMainWindowButtonStyleSheet();


    public:

        Client              *m_client; // needs to be a ptr as it's an incomplete type
        pthread_t           clientThread;
        pthread_mutex_t     guiEventQueueMutex;


    private:

        Ui::MainWindow     *m_ui;
        OrderTableModel    *m_orderModel;
        DataTableModel     *m_dataModel;
        DataViewDelegate   *m_dataDelegate;
        OrderViewDelegate  *m_orderDelegate;
        Queue              *m_guiEventQueue;


        void                createExMainThread();

        static void*        executeExMainWork( void*  lpParam );



};

//***********************************************************************************
#endif // MAINWINDOW_H
