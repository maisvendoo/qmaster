//------------------------------------------------------------------------------
//
//
//
//
//
//------------------------------------------------------------------------------
/*!
 * \file
 * \brief Main window
 * \copyright maisvendoo
 * \author Dmitry Pritykin
 * \date
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include    <QMainWindow>
#include    <QTableWidget>

#include    "master.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
namespace Ui
{
    class MainWindow;
}

/*!
 * \class
 * \brief Main window class
 */
//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    /// Initialization
    void init();

    /// Get port settings from UI
    serial_config_t getSerialConfig();

    /// Add table row
    void addTableRow(QTableWidget *table);

    /// Delete table row
    void delTableRow(QTableWidget *table);

    /// Get data type name by Modbus function code
    QString getDataTypeName(int mb_func) const;

    Ui::MainWindow *ui;
    Master  *master;

    /// List of modbus functions
    QMap<QString, int> mb_func;

    /// Timer for update ports list
    QTimer *portsListUpdateTimer;

private slots:

    /// Button "Connect/Disconnect" is released
    void onConnectRelease();

    /// Button "Clean" released
    void onRawDataClean();

    /// Print message to status bar
    void statusPrint(QString msg);

    /// On change data table rows count action
    void changeDataTableRowsCount(int i);

    /// On change data address action
    void changeAddress(int i);

    /// On change modbus function action
    void changedFunc(QString text);

    /// On release send button action
    void sendButtonRelease();

    /// On slave answer action
    void onSlaveAnswer(answer_request_t answer);

    /// Put raw data to raw data log
    void onRawDataReceive(QByteArray rawData);

    /// Update ports list
    void updatePortsList();
};

#endif // MAINWINDOW_H
