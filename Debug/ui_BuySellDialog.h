/********************************************************************************
** Form generated from reading UI file 'BuySellDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUYSELLDIALOG_H
#define UI_BUYSELLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_BuySellDialog
{
public:
    QPushButton *pushButton;
    QCheckBox *checkBox;

    void setupUi(QDialog *BuySellDialog)
    {
        if (BuySellDialog->objectName().isEmpty())
            BuySellDialog->setObjectName(QString::fromUtf8("BuySellDialog"));
        BuySellDialog->resize(1184, 512);
        BuySellDialog->setModal(false);
        pushButton = new QPushButton(BuySellDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(100, 80, 201, 71));
        QFont font;
        font.setPointSize(23);
        pushButton->setFont(font);
        checkBox = new QCheckBox(BuySellDialog);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(360, 250, 131, 61));

        retranslateUi(BuySellDialog);

        pushButton->setDefault(true);


        QMetaObject::connectSlotsByName(BuySellDialog);
    } // setupUi

    void retranslateUi(QDialog *BuySellDialog)
    {
        BuySellDialog->setWindowTitle(QCoreApplication::translate("BuySellDialog", "BUY SELL Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("BuySellDialog", "MARACA", nullptr));
        checkBox->setText(QCoreApplication::translate("BuySellDialog", "CheckBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BuySellDialog: public Ui_BuySellDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUYSELLDIALOG_H
