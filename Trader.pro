QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AccountTableModel.cpp \
    BuySellDialog.cpp \
    DataDbManager.cpp \
    DataTableModel.cpp \
    DataViewDelegate.cpp \
    Main.cpp \
    MainWindow.cpp \
    OrderDbManager.cpp \
    OrderTableModel.cpp \
    OrderViewDelegate.cpp \
    IB/ContractCondition.cpp \
    IB/DefaultEWrapper.cpp \
    IB/EClient.cpp \
    IB/EClientSocket.cpp \
    IB/EDecoder.cpp \
    IB/EMessage.cpp \
    IB/EMutex.cpp \
    IB/EOrderDecoder.cpp \
    IB/EReader.cpp \
    IB/EReaderOSSignal.cpp \
    IB/ESocket.cpp \
    IB/executioncondition.cpp \
    IB/MarginCondition.cpp \
    IB/OperatorCondition.cpp \
    IB/OrderCondition.cpp \
    IB/PercentChangeCondition.cpp \
    IB/PriceCondition.cpp \
    IB/SoftDollarTier.cpp \
    IB/TimeCondition.cpp \
    IB/VolumeCondition.cpp \
    Implementation/AccountSummaryTags.cpp \
    Implementation/AvailableAlgoParams.cpp \
    Implementation/ContractSamples.cpp \
    Implementation/OrderSamples.cpp \
    Implementation/ScannerSubscriptionSamples.cpp \
    Implementation/StdAfx.cpp \
    Implementation/Client.cpp \
    Implementation/Utils.cpp


HEADERS += \
    AccountTableModel.h \
    BuySellDialog.h \
    Data.h \
    DataDbManager.h \
    DataTableModel.h \
    DataViewDelegate.h \
    MainWindow.h \
    Order.h \
    OrderDbManager.h \
    OrderTableModel.h \
    OrderViewDelegate.h \
    IB/bar.h \
    IB/CommissionReport.h \
    IB/CommonDefs.h \
    IB/Contract.h \
    IB/ContractCondition.h \
    IB/DefaultEWrapper.h \
    IB/DepthMktDataDescription.h \
    IB/EClient.h \
    IB/EClientException.h \
    IB/EClientMsgSink.h \
    IB/EClientSocket.h \
    IB/EDecoder.h \
    IB/EMessage.h \
    IB/EMutex.h \
    IB/EOrderDecoder.h \
    IB/EPosixClientSocketPlatform.h \
    IB/EReader.h \
    IB/EReaderOSSignal.h \
    IB/ESocket.h \
    IB/ETransport.h \
    IB/EWrapper.h \
    IB/EWrapper_prototypes.h \
    IB/Execution.h \
    IB/executioncondition.h \
    IB/FamilyCode.h \
    IB/HistogramEntry.h \
    IB/HistoricalTick.h \
    IB/HistoricalTickBidAsk.h \
    IB/HistoricalTickLast.h \
    IB/IExternalizable.h \
    IB/MarginCondition.h \
    IB/NewsProvider.h \
    IB/OperatorCondition.h \
    IB/Order.h \
    IB/OrderCondition.h \
    IB/OrderState.h \
    IB/PercentChangeCondition.h \
    IB/platformspecific.h \
    IB/PriceCondition.h \
    IB/PriceIncrement.h \
    IB/resource.h \
    IB/ScannerSubscription.h \
    IB/SoftDollarTier.h \
    IB/TagValue.h \
    IB/TickAttrib.h \
    IB/TickAttribBidAsk.h \
    IB/TickAttribLast.h \
    IB/TimeCondition.h \
    IB/TwsSocketClientErrors.h \
    IB/VolumeCondition.h \
    Implementation/AccountSummaryTags.h \
    Implementation/AvailableAlgoParams.h \
    Implementation/ContractSamples.h \
    Implementation/FAMethodSamples.h \
    Implementation/OrderSamples.h \
    Implementation/ScannerSubscriptionSamples.h \
    Implementation/StdAfx.h \
    Implementation/Client.h \
    Implementation/Utils.h


FORMS += \
    BuySellDialog.ui \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
