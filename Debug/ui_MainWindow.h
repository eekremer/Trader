/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *dataTableView;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *buyButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *sellButton;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *takeProfitPriceLabel;
    QLabel *stopLossPriceLabel;
    QLabel *actionLabel_2;
    QLabel *quantityLabel;
    QLabel *orderTypeLabel;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *takeProfitLabel;
    QLabel *stopLossLabel;
    QLabel *actionLabel;
    QLineEdit *quantityLineEdit;
    QComboBox *orderTypeComboBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *symbolLabel;
    QLabel *securityLabel;
    QLabel *currencyLabel;
    QLabel *exchangeLabel;
    QLabel *primaryExchangeLabel;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QComboBox *symbolComboBox;
    QComboBox *securityTypeComboBox;
    QComboBox *currencyComboBox;
    QComboBox *exchangeComboBox;
    QComboBox *primaryExchangeComboBox;
    QTableView *orderTableView;
    QPushButton *confirmButton;
    QLabel *orderTypeLabel_2;
    QComboBox *orderComboBox;
    QSlider *horizontalSlider;
    QTableView *bracketTableView;
    QLabel *priceLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1333, 889);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        dataTableView = new QTableView(centralwidget);
        dataTableView->setObjectName(QString::fromUtf8("dataTableView"));
        dataTableView->setGeometry(QRect(40, 30, 661, 71));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 250, 261, 47));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        buyButton = new QPushButton(layoutWidget);
        buyButton->setObjectName(QString::fromUtf8("buyButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buyButton->sizePolicy().hasHeightForWidth());
        buyButton->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("FreeSans"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        buyButton->setFont(font);

        horizontalLayout->addWidget(buyButton);

        horizontalSpacer = new QSpacerItem(30, 28, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        sellButton = new QPushButton(layoutWidget);
        sellButton->setObjectName(QString::fromUtf8("sellButton"));
        sizePolicy1.setHeightForWidth(sellButton->sizePolicy().hasHeightForWidth());
        sellButton->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(24);
        font1.setBold(true);
        font1.setWeight(75);
        sellButton->setFont(font1);
        sellButton->setAutoFillBackground(true);
        sellButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(sellButton);

        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(980, 240, 128, 251));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_3->setContentsMargins(7, 0, 0, 0);
        takeProfitPriceLabel = new QLabel(verticalLayoutWidget_3);
        takeProfitPriceLabel->setObjectName(QString::fromUtf8("takeProfitPriceLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(takeProfitPriceLabel->sizePolicy().hasHeightForWidth());
        takeProfitPriceLabel->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(takeProfitPriceLabel);

        stopLossPriceLabel = new QLabel(verticalLayoutWidget_3);
        stopLossPriceLabel->setObjectName(QString::fromUtf8("stopLossPriceLabel"));
        sizePolicy2.setHeightForWidth(stopLossPriceLabel->sizePolicy().hasHeightForWidth());
        stopLossPriceLabel->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(stopLossPriceLabel);

        actionLabel_2 = new QLabel(verticalLayoutWidget_3);
        actionLabel_2->setObjectName(QString::fromUtf8("actionLabel_2"));
        sizePolicy2.setHeightForWidth(actionLabel_2->sizePolicy().hasHeightForWidth());
        actionLabel_2->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(actionLabel_2);

        quantityLabel = new QLabel(verticalLayoutWidget_3);
        quantityLabel->setObjectName(QString::fromUtf8("quantityLabel"));
        sizePolicy2.setHeightForWidth(quantityLabel->sizePolicy().hasHeightForWidth());
        quantityLabel->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(quantityLabel);

        orderTypeLabel = new QLabel(verticalLayoutWidget_3);
        orderTypeLabel->setObjectName(QString::fromUtf8("orderTypeLabel"));
        sizePolicy2.setHeightForWidth(orderTypeLabel->sizePolicy().hasHeightForWidth());
        orderTypeLabel->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(orderTypeLabel);

        verticalLayoutWidget_4 = new QWidget(centralwidget);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(1120, 240, 160, 251));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        takeProfitLabel = new QLabel(verticalLayoutWidget_4);
        takeProfitLabel->setObjectName(QString::fromUtf8("takeProfitLabel"));
        sizePolicy2.setHeightForWidth(takeProfitLabel->sizePolicy().hasHeightForWidth());
        takeProfitLabel->setSizePolicy(sizePolicy2);

        verticalLayout_4->addWidget(takeProfitLabel);

        stopLossLabel = new QLabel(verticalLayoutWidget_4);
        stopLossLabel->setObjectName(QString::fromUtf8("stopLossLabel"));
        sizePolicy2.setHeightForWidth(stopLossLabel->sizePolicy().hasHeightForWidth());
        stopLossLabel->setSizePolicy(sizePolicy2);

        verticalLayout_4->addWidget(stopLossLabel);

        actionLabel = new QLabel(verticalLayoutWidget_4);
        actionLabel->setObjectName(QString::fromUtf8("actionLabel"));
        sizePolicy2.setHeightForWidth(actionLabel->sizePolicy().hasHeightForWidth());
        actionLabel->setSizePolicy(sizePolicy2);

        verticalLayout_4->addWidget(actionLabel);

        quantityLineEdit = new QLineEdit(verticalLayoutWidget_4);
        quantityLineEdit->setObjectName(QString::fromUtf8("quantityLineEdit"));

        verticalLayout_4->addWidget(quantityLineEdit);

        orderTypeComboBox = new QComboBox(verticalLayoutWidget_4);
        orderTypeComboBox->setObjectName(QString::fromUtf8("orderTypeComboBox"));

        verticalLayout_4->addWidget(orderTypeComboBox);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(40, 330, 131, 241));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(7, 0, 0, 0);
        symbolLabel = new QLabel(verticalLayoutWidget_2);
        symbolLabel->setObjectName(QString::fromUtf8("symbolLabel"));
        sizePolicy2.setHeightForWidth(symbolLabel->sizePolicy().hasHeightForWidth());
        symbolLabel->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setPointSize(13);
        symbolLabel->setFont(font2);

        verticalLayout_2->addWidget(symbolLabel);

        securityLabel = new QLabel(verticalLayoutWidget_2);
        securityLabel->setObjectName(QString::fromUtf8("securityLabel"));
        sizePolicy2.setHeightForWidth(securityLabel->sizePolicy().hasHeightForWidth());
        securityLabel->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(securityLabel);

        currencyLabel = new QLabel(verticalLayoutWidget_2);
        currencyLabel->setObjectName(QString::fromUtf8("currencyLabel"));
        sizePolicy2.setHeightForWidth(currencyLabel->sizePolicy().hasHeightForWidth());
        currencyLabel->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(currencyLabel);

        exchangeLabel = new QLabel(verticalLayoutWidget_2);
        exchangeLabel->setObjectName(QString::fromUtf8("exchangeLabel"));
        sizePolicy2.setHeightForWidth(exchangeLabel->sizePolicy().hasHeightForWidth());
        exchangeLabel->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(exchangeLabel);

        primaryExchangeLabel = new QLabel(verticalLayoutWidget_2);
        primaryExchangeLabel->setObjectName(QString::fromUtf8("primaryExchangeLabel"));
        sizePolicy2.setHeightForWidth(primaryExchangeLabel->sizePolicy().hasHeightForWidth());
        primaryExchangeLabel->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(primaryExchangeLabel);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(190, 330, 161, 241));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        symbolComboBox = new QComboBox(verticalLayoutWidget);
        symbolComboBox->setObjectName(QString::fromUtf8("symbolComboBox"));

        verticalLayout->addWidget(symbolComboBox);

        securityTypeComboBox = new QComboBox(verticalLayoutWidget);
        securityTypeComboBox->setObjectName(QString::fromUtf8("securityTypeComboBox"));

        verticalLayout->addWidget(securityTypeComboBox);

        currencyComboBox = new QComboBox(verticalLayoutWidget);
        currencyComboBox->setObjectName(QString::fromUtf8("currencyComboBox"));

        verticalLayout->addWidget(currencyComboBox);

        exchangeComboBox = new QComboBox(verticalLayoutWidget);
        exchangeComboBox->setObjectName(QString::fromUtf8("exchangeComboBox"));

        verticalLayout->addWidget(exchangeComboBox);

        primaryExchangeComboBox = new QComboBox(verticalLayoutWidget);
        primaryExchangeComboBox->setObjectName(QString::fromUtf8("primaryExchangeComboBox"));

        verticalLayout->addWidget(primaryExchangeComboBox);

        orderTableView = new QTableView(centralwidget);
        orderTableView->setObjectName(QString::fromUtf8("orderTableView"));
        orderTableView->setGeometry(QRect(40, 610, 1241, 201));
        confirmButton = new QPushButton(centralwidget);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(980, 520, 301, 61));
        QFont font3;
        font3.setPointSize(19);
        font3.setBold(true);
        font3.setWeight(75);
        confirmButton->setFont(font3);
        orderTypeLabel_2 = new QLabel(centralwidget);
        orderTypeLabel_2->setObjectName(QString::fromUtf8("orderTypeLabel_2"));
        orderTypeLabel_2->setGeometry(QRect(390, 210, 61, 17));
        sizePolicy2.setHeightForWidth(orderTypeLabel_2->sizePolicy().hasHeightForWidth());
        orderTypeLabel_2->setSizePolicy(sizePolicy2);
        orderComboBox = new QComboBox(centralwidget);
        orderComboBox->setObjectName(QString::fromUtf8("orderComboBox"));
        orderComboBox->setGeometry(QRect(450, 200, 159, 25));
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(60, 160, 211, 16));
        horizontalSlider->setOrientation(Qt::Horizontal);
        bracketTableView = new QTableView(centralwidget);
        bracketTableView->setObjectName(QString::fromUtf8("bracketTableView"));
        bracketTableView->setGeometry(QRect(390, 250, 531, 121));
        priceLabel = new QLabel(centralwidget);
        priceLabel->setObjectName(QString::fromUtf8("priceLabel"));
        priceLabel->setGeometry(QRect(120, 120, 101, 31));
        QFont font4;
        font4.setPointSize(16);
        priceLabel->setFont(font4);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1333, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        buyButton->setText(QCoreApplication::translate("MainWindow", "BUY", nullptr));
        sellButton->setText(QCoreApplication::translate("MainWindow", "SELL", nullptr));
        takeProfitPriceLabel->setText(QCoreApplication::translate("MainWindow", "Take Profit price", nullptr));
        stopLossPriceLabel->setText(QCoreApplication::translate("MainWindow", "Stop Loss price", nullptr));
        actionLabel_2->setText(QCoreApplication::translate("MainWindow", "Action", nullptr));
        quantityLabel->setText(QCoreApplication::translate("MainWindow", "Quantity", nullptr));
        orderTypeLabel->setText(QCoreApplication::translate("MainWindow", "Order Type", nullptr));
        takeProfitLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        stopLossLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        actionLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        symbolLabel->setText(QCoreApplication::translate("MainWindow", "Symbol", nullptr));
        securityLabel->setText(QCoreApplication::translate("MainWindow", "Security Type", nullptr));
        currencyLabel->setText(QCoreApplication::translate("MainWindow", "Currency", nullptr));
        exchangeLabel->setText(QCoreApplication::translate("MainWindow", "Exchange", nullptr));
        primaryExchangeLabel->setText(QCoreApplication::translate("MainWindow", "Primary Exchange", nullptr));
        confirmButton->setText(QCoreApplication::translate("MainWindow", "SUBMIT", nullptr));
        orderTypeLabel_2->setText(QCoreApplication::translate("MainWindow", "ORDER", nullptr));
        priceLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
