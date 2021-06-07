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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
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
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *buyButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *sellButton;
    QTableView *orderTableView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QTableView *dataTableView;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QComboBox *symbolComboBox;
    QComboBox *securityTypeComboBox;
    QComboBox *currencyComboBox;
    QComboBox *exchangeComboBox;
    QComboBox *primaryExchangeComboBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *symbolLabel;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_6;
    QLabel *label_5;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *symbolLabel_2;
    QLabel *label_12;
    QLabel *label_15;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *stopLossLabel;
    QLabel *takeProfitLabel;
    QComboBox *actioncomboBox;
    QLineEdit *quantityLineEdit;
    QComboBox *orderTypeComboBox;
    QPushButton *setupButton;
    QWidget *page_2;
    QPushButton *buyGoBackButton;
    QLabel *label_8;
    QPushButton *confirmBuy;
    QWidget *page_3;
    QPushButton *sellGoBackButton;
    QLabel *label_7;
    QWidget *page_4;
    QPushButton *setupGoBackButton;
    QLabel *label_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1333, 1000);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1301, 1030));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        layoutWidget = new QWidget(page);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(520, 170, 391, 61));
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

        orderTableView = new QTableView(page);
        orderTableView->setObjectName(QString::fromUtf8("orderTableView"));
        orderTableView->setGeometry(QRect(60, 570, 1191, 341));
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(410, 510, 89, 25));
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(830, 450, 291, 61));
        label_2 = new QLabel(page);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 530, 191, 31));
        dataTableView = new QTableView(page);
        dataTableView->setObjectName(QString::fromUtf8("dataTableView"));
        dataTableView->setGeometry(QRect(520, 40, 731, 71));
        verticalLayoutWidget = new QWidget(page);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(210, 40, 161, 241));
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

        verticalLayoutWidget_2 = new QWidget(page);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(70, 40, 131, 241));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(7, 0, 0, 0);
        symbolLabel = new QLabel(verticalLayoutWidget_2);
        symbolLabel->setObjectName(QString::fromUtf8("symbolLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(symbolLabel->sizePolicy().hasHeightForWidth());
        symbolLabel->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(symbolLabel);

        label_11 = new QLabel(verticalLayoutWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy2.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(label_11);

        label_10 = new QLabel(verticalLayoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy2.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(label_10);

        label_6 = new QLabel(verticalLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(label_6);

        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(label_5);

        verticalLayoutWidget_3 = new QWidget(page);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(950, 170, 128, 251));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_3->setContentsMargins(7, 0, 0, 0);
        label_13 = new QLabel(verticalLayoutWidget_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy2.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(label_13);

        label_14 = new QLabel(verticalLayoutWidget_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy2.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(label_14);

        symbolLabel_2 = new QLabel(verticalLayoutWidget_3);
        symbolLabel_2->setObjectName(QString::fromUtf8("symbolLabel_2"));
        sizePolicy2.setHeightForWidth(symbolLabel_2->sizePolicy().hasHeightForWidth());
        symbolLabel_2->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(symbolLabel_2);

        label_12 = new QLabel(verticalLayoutWidget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy2.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(label_12);

        label_15 = new QLabel(verticalLayoutWidget_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy2.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(label_15);

        verticalLayoutWidget_4 = new QWidget(page);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(1090, 170, 160, 251));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        stopLossLabel = new QLabel(verticalLayoutWidget_4);
        stopLossLabel->setObjectName(QString::fromUtf8("stopLossLabel"));
        sizePolicy2.setHeightForWidth(stopLossLabel->sizePolicy().hasHeightForWidth());
        stopLossLabel->setSizePolicy(sizePolicy2);

        verticalLayout_4->addWidget(stopLossLabel);

        takeProfitLabel = new QLabel(verticalLayoutWidget_4);
        takeProfitLabel->setObjectName(QString::fromUtf8("takeProfitLabel"));
        sizePolicy2.setHeightForWidth(takeProfitLabel->sizePolicy().hasHeightForWidth());
        takeProfitLabel->setSizePolicy(sizePolicy2);

        verticalLayout_4->addWidget(takeProfitLabel);

        actioncomboBox = new QComboBox(verticalLayoutWidget_4);
        actioncomboBox->setObjectName(QString::fromUtf8("actioncomboBox"));

        verticalLayout_4->addWidget(actioncomboBox);

        quantityLineEdit = new QLineEdit(verticalLayoutWidget_4);
        quantityLineEdit->setObjectName(QString::fromUtf8("quantityLineEdit"));

        verticalLayout_4->addWidget(quantityLineEdit);

        orderTypeComboBox = new QComboBox(verticalLayoutWidget_4);
        orderTypeComboBox->setObjectName(QString::fromUtf8("orderTypeComboBox"));

        verticalLayout_4->addWidget(orderTypeComboBox);

        setupButton = new QPushButton(page);
        setupButton->setObjectName(QString::fromUtf8("setupButton"));
        setupButton->setGeometry(QRect(220, 460, 91, 31));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        buyGoBackButton = new QPushButton(page_2);
        buyGoBackButton->setObjectName(QString::fromUtf8("buyGoBackButton"));
        buyGoBackButton->setGeometry(QRect(950, 40, 89, 25));
        label_8 = new QLabel(page_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(60, 40, 67, 17));
        confirmBuy = new QPushButton(page_2);
        confirmBuy->setObjectName(QString::fromUtf8("confirmBuy"));
        confirmBuy->setGeometry(QRect(710, 410, 271, 71));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        sellGoBackButton = new QPushButton(page_3);
        sellGoBackButton->setObjectName(QString::fromUtf8("sellGoBackButton"));
        sellGoBackButton->setGeometry(QRect(990, 30, 89, 25));
        label_7 = new QLabel(page_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(50, 40, 67, 17));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        setupGoBackButton = new QPushButton(page_4);
        setupGoBackButton->setObjectName(QString::fromUtf8("setupGoBackButton"));
        setupGoBackButton->setGeometry(QRect(970, 30, 89, 25));
        label_9 = new QLabel(page_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(60, 40, 67, 17));
        stackedWidget->addWidget(page_4);
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

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        buyButton->setText(QCoreApplication::translate("MainWindow", "BUY", nullptr));
        sellButton->setText(QCoreApplication::translate("MainWindow", "SELL", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "SUBMIT", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Orders", nullptr));
        symbolLabel->setText(QCoreApplication::translate("MainWindow", "Symbol", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Security Type", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Currency", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Exchange", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Primary Exchange", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Take Profit price", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Stop Loss price", nullptr));
        symbolLabel_2->setText(QCoreApplication::translate("MainWindow", "Action", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Quantity", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Order Type", nullptr));
        stopLossLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        takeProfitLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        setupButton->setText(QCoreApplication::translate("MainWindow", "SetUp", nullptr));
        buyGoBackButton->setText(QCoreApplication::translate("MainWindow", "go back", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "BUY", nullptr));
        confirmBuy->setText(QCoreApplication::translate("MainWindow", "confirm BUY", nullptr));
        sellGoBackButton->setText(QCoreApplication::translate("MainWindow", "go back", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "SELL", nullptr));
        setupGoBackButton->setText(QCoreApplication::translate("MainWindow", "go back", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "SETUP", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
