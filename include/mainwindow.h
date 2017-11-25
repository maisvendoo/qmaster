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
#include    <QThread>

#include    "master.h"
#include    "data-sender.h"

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

    /// Get request data from user interface
    abstract_request_t *getRequestData();

    /// Close window event handler
    void closeEvent(QCloseEvent *event);

    Ui::MainWindow *ui;
    Master  *master;

    /// List of modbus functions
    QMap<QString, int> mb_func;

    /// Timer for update ports list
    QTimer *portsListUpdateTimer;

    /// Current serial ports count
    int currentSerialPorts;

    /// Flag of send data theread is started
    bool is_send_started;

    /// Cyclic send flag
    bool is_cyclic;

    DataSender  dataSender;
    QThread threadCyclicSend;

    /// Flag of close window event
    bool is_close_event;

signals:

    /// Send request from master to slave
    void sendMasterRequest(abstract_request_t *request);

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

    /// Print error message to processing console
    void printMsg(QString msg);

    /// Check/uncheck cyclic send of data
    void checkCyclicSend(int state);

    /// Actions by finish sender thread
    void onFinishSendThread();

    /// Send started flag to data sender
    void getStartedFlag(bool *started);
};

#endif // MAINWINDOW_H
