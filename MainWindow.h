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

        void  buyButtonClicked();
        void  sellButtonClicked();
        void  setupButtonClicked();

        void  buyGoBackButtonClicked();
        void  sellGoBackButtonClicked();
        void  setupGoBackButtonClicked();

        void  confirmBuyClicked();

        void  on_pushButton_clicked();

        void  goToBuySellDialog();

    public:

        Queue               getQueue();
        static void*        doSomeThingBigger( void  *arg );

        void                setMainWindowOrderParams     ();
        void                setMainWindowContractParams  ();
        void                setOrderTableViewColumnWidth ();
        void                setDataTableViewColumnWidth  ();
        void                setMainWindowButtonConnection();
        void                setMainWindowButtonStyleSheet();


    private:

        Ui::MainWindow     *m_ui;
        OrderTableModel    *m_orderModel;
        DataTableModel     *m_dataModel;
        Queue               m_outboundQueue;
        DataViewDelegate   *m_delegate;


        void                createThread();

        static
        void*               executeClientWork( void*  lpParam );

};

//***********************************************************************************

#endif // MAINWINDOW_H
