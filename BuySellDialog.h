#ifndef BUYSELLDIALOG_H
#define BUYSELLDIALOG_H

#include <QDialog>

#include "ui_BuySellDialog.h"



//***************************************************************************************

QT_BEGIN_NAMESPACE

namespace Ui
{
    class BuySellDialog;
}

QT_END_NAMESPACE

//***************************************************************************************

class BuySellDialog : public QDialog, public Ui::BuySellDialog
{

    Q_OBJECT

    public:

        BuySellDialog( QWidget *parent = 0 );

    signals:



    private slots:



    private:

        Ui::BuySellDialog       *m_dui;

};

//***************************************************************************************

#endif // BUYSELLDIALOG_H
