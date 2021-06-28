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



//***********************************************************************************

QT_BEGIN_NAMESPACE

namespace Ui
{
    class MainWindow;
}

QT_END_NAMESPACE


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

        Queue               getQueue();

        static void*        doSomeThingBigger( void  *arg );
        static void*        exMain( void*  arg );

        void                setMainWindowOrderParams     ();
        void                setMainWindowContractParams  ();
        void                setOrderTableViewColumnWidth ();
        void                setDataTableViewColumnWidth  ();
        void                setDataTableViewHeaderSize   ();

        void                setMainWindowButtonConnection();
        void                setMainWindowButtonStyleSheet();


    private:

        Ui::MainWindow     *m_ui;
        OrderTableModel    *m_orderModel;
        DataTableModel     *m_dataModel;
        Queue               m_outboundQueue;
        DataViewDelegate   *m_dataDelegate;
        OrderViewDelegate  *m_orderDelegate;


        void                createExMainThread();

        static void*        executeExMainWork( void*  lpParam );

};

//***********************************************************************************

#endif // MAINWINDOW_H
