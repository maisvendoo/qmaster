/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QComboBox *cbPort;
    QComboBox *cbBaud;
    QComboBox *cbDataBits;
    QComboBox *cbStopBits;
    QComboBox *cbParity;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *bConnect;
    QSpinBox *sbSlaveID;
    QLabel *lSlaveID;
    QComboBox *cbFunc;
    QLabel *slaveID_2;
    QSpinBox *sbAddress;
    QSpinBox *sbCount;
    QLabel *slaveID_3;
    QLabel *slaveID_4;
    QPushButton *bSend;
    QTableWidget *tableData;
    QPlainTextEdit *ptRawData;
    QLabel *label_6;
    QPushButton *bRawDataClean;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1041, 727);
        QIcon icon;
        QString iconThemeName = QStringLiteral(":/img/logo.png");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        cbPort = new QComboBox(centralWidget);
        cbPort->setObjectName(QStringLiteral("cbPort"));
        cbPort->setGeometry(QRect(10, 50, 141, 25));
        cbBaud = new QComboBox(centralWidget);
        cbBaud->setObjectName(QStringLiteral("cbBaud"));
        cbBaud->setGeometry(QRect(160, 50, 141, 25));
        cbDataBits = new QComboBox(centralWidget);
        cbDataBits->setObjectName(QStringLiteral("cbDataBits"));
        cbDataBits->setGeometry(QRect(310, 50, 71, 25));
        cbStopBits = new QComboBox(centralWidget);
        cbStopBits->setObjectName(QStringLiteral("cbStopBits"));
        cbStopBits->setGeometry(QRect(390, 50, 71, 25));
        cbParity = new QComboBox(centralWidget);
        cbParity->setObjectName(QStringLiteral("cbParity"));
        cbParity->setGeometry(QRect(470, 50, 71, 25));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 30, 71, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(200, 30, 71, 17));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(320, 30, 51, 17));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(400, 30, 51, 17));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(490, 30, 41, 17));
        bConnect = new QPushButton(centralWidget);
        bConnect->setObjectName(QStringLiteral("bConnect"));
        bConnect->setGeometry(QRect(450, 100, 91, 25));
        sbSlaveID = new QSpinBox(centralWidget);
        sbSlaveID->setObjectName(QStringLiteral("sbSlaveID"));
        sbSlaveID->setGeometry(QRect(10, 200, 51, 26));
        sbSlaveID->setMinimum(1);
        sbSlaveID->setMaximum(32);
        lSlaveID = new QLabel(centralWidget);
        lSlaveID->setObjectName(QStringLiteral("lSlaveID"));
        lSlaveID->setGeometry(QRect(10, 180, 61, 17));
        cbFunc = new QComboBox(centralWidget);
        cbFunc->setObjectName(QStringLiteral("cbFunc"));
        cbFunc->setGeometry(QRect(70, 200, 251, 25));
        slaveID_2 = new QLabel(centralWidget);
        slaveID_2->setObjectName(QStringLiteral("slaveID_2"));
        slaveID_2->setGeometry(QRect(160, 180, 61, 17));
        sbAddress = new QSpinBox(centralWidget);
        sbAddress->setObjectName(QStringLiteral("sbAddress"));
        sbAddress->setGeometry(QRect(330, 200, 51, 26));
        sbAddress->setMinimum(0);
        sbAddress->setMaximum(65536);
        sbAddress->setValue(0);
        sbCount = new QSpinBox(centralWidget);
        sbCount->setObjectName(QStringLiteral("sbCount"));
        sbCount->setGeometry(QRect(390, 200, 51, 26));
        sbCount->setMinimum(1);
        sbCount->setMaximum(65536);
        slaveID_3 = new QLabel(centralWidget);
        slaveID_3->setObjectName(QStringLiteral("slaveID_3"));
        slaveID_3->setGeometry(QRect(330, 180, 61, 17));
        slaveID_4 = new QLabel(centralWidget);
        slaveID_4->setObjectName(QStringLiteral("slaveID_4"));
        slaveID_4->setGeometry(QRect(390, 180, 41, 17));
        bSend = new QPushButton(centralWidget);
        bSend->setObjectName(QStringLiteral("bSend"));
        bSend->setGeometry(QRect(450, 200, 91, 25));
        tableData = new QTableWidget(centralWidget);
        if (tableData->columnCount() < 3)
            tableData->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableData->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableData->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableData->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableData->setObjectName(QStringLiteral("tableData"));
        tableData->setGeometry(QRect(10, 240, 531, 421));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableData->sizePolicy().hasHeightForWidth());
        tableData->setSizePolicy(sizePolicy);
        tableData->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableData->setRowCount(0);
        tableData->setColumnCount(3);
        tableData->horizontalHeader()->setVisible(false);
        tableData->horizontalHeader()->setHighlightSections(true);
        tableData->horizontalHeader()->setStretchLastSection(true);
        tableData->verticalHeader()->setVisible(false);
        tableData->verticalHeader()->setDefaultSectionSize(20);
        tableData->verticalHeader()->setStretchLastSection(false);
        ptRawData = new QPlainTextEdit(centralWidget);
        ptRawData->setObjectName(QStringLiteral("ptRawData"));
        ptRawData->setGeometry(QRect(550, 90, 481, 571));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(560, 70, 51, 17));
        bRawDataClean = new QPushButton(centralWidget);
        bRawDataClean->setObjectName(QStringLiteral("bRawDataClean"));
        bRawDataClean->setGeometry(QRect(930, 60, 91, 25));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1041, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        cbDataBits->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QMaster - Modbus RTU PC emulator", Q_NULLPTR));
        cbBaud->clear();
        cbBaud->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "9600", Q_NULLPTR)
         << QApplication::translate("MainWindow", "19200", Q_NULLPTR)
         << QApplication::translate("MainWindow", "38400", Q_NULLPTR)
         << QApplication::translate("MainWindow", "57600", Q_NULLPTR)
         << QApplication::translate("MainWindow", "115200", Q_NULLPTR)
         << QApplication::translate("MainWindow", "125000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "230400", Q_NULLPTR)
         << QApplication::translate("MainWindow", "250000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "460800", Q_NULLPTR)
         << QApplication::translate("MainWindow", "500000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1000000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2000000", Q_NULLPTR)
        );
        cbDataBits->clear();
        cbDataBits->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "5", Q_NULLPTR)
         << QApplication::translate("MainWindow", "6", Q_NULLPTR)
         << QApplication::translate("MainWindow", "7", Q_NULLPTR)
         << QApplication::translate("MainWindow", "8", Q_NULLPTR)
         << QApplication::translate("MainWindow", "9", Q_NULLPTR)
        );
        cbStopBits->clear();
        cbStopBits->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2", Q_NULLPTR)
        );
        cbParity->clear();
        cbParity->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "None", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Odd", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Even", Q_NULLPTR)
        );
        label->setText(QApplication::translate("MainWindow", "Serial port", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Baudrate", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Data bits", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Stop bits", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Parity", Q_NULLPTR));
        bConnect->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        lSlaveID->setText(QApplication::translate("MainWindow", "Slave ID", Q_NULLPTR));
        slaveID_2->setText(QApplication::translate("MainWindow", "Function", Q_NULLPTR));
        slaveID_3->setText(QApplication::translate("MainWindow", "Address", Q_NULLPTR));
        slaveID_4->setText(QApplication::translate("MainWindow", "Count", Q_NULLPTR));
        bSend->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Data type", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Address", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Value", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Raw data", Q_NULLPTR));
        bRawDataClean->setText(QApplication::translate("MainWindow", "Clean", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
