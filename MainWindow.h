#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QTableView>
#include <QItemDelegate>
#include <QStandardItemModel>
#include <QSystemTrayIcon>
#include <pthread.h>

#include "DataTableModel.h"
#include "BracketTableModel.h"
#include "OrderTableModel.h"

#include "DataViewDelegate.h"
#include "OrderViewDelegate.h"
#include "InterObject.h"
#include "Implementation/Client.h"

// forward declaration
class Client;


//***********************************************************************************

QT_BEGIN_NAMESPACE

namespace Ui
{
    class MainWindow;
}

QT_END_NAMESPACE


//***********************************************************************************
//***********************************************************************************


class MainWindow : public QMainWindow
{


        Q_OBJECT

    public:

        MainWindow( QWidget *parent = nullptr );

       ~MainWindow();


    signals:




    private slots:

        void                buyButtonClicked                ();
        void                sellButtonClicked               ();
        void                setupButtonClicked              ();
        void                confirmBuyClicked               ();
        void                confirmButtonClicked            ();

        void                goToBuySellDialog               ();
        void                symbolComboBoxTextChanged       ( const QString&  symbol );


    public:


        void                setMainWindowOrderParams        ();
        void                setMainWindowContractParams     ();
        void                setOrderTableViewColumnWidth    ();
        void                setDataTableViewColumnWidth     ();
        void                setDataTableViewHeaderSize      ();

        void                setMainWindowButtonConnection   ();
        void                setMainWindowButtonStyleSheet   ();
        void                insertMsgIntoQueue              (    InterObject   msg     );

        void                convertQstringToString          ();

        void                setInitialSymbol                ();

        void                initialSetUp                    ();

    private:

        Ui::MainWindow     *m_ui;


    public:


        OrderTableModel                 *m_orderModel   ;
        DataTableModel                  *m_dataModel    ;
        BracketTableModel               *m_bracketModel ;
        DataViewDelegate                *m_dataDelegate ;
        OrderViewDelegate               *m_orderDelegate;

        std::deque<InterObject>         m_guiEventQueue;
        pthread_mutex_t                 m_guiEventQueueMutex;


};

//***********************************************************************************
#endif // MAINWINDOW_H
