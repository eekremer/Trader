#include "BuySellDialog.h"

#include <QWidget>


//*************************************************************************************

BuySellDialog::BuySellDialog( QWidget *parent )
    : QDialog ( parent )

{

    /*

        void QWidget::setupUi( QWidget *widget )

        Sets up the user interface for the specified widget.

        See also Using a Designer UI File in Your C++ Application.

    */

    setupUi( this );


    this->setStyleSheet(                "QDialog{"
                                        "background-color: #333333;"
                                        "}"                                         );


}

//*************************************************************************************
