//------------------------------------------------------------------------------
//
//
//
//
//
//------------------------------------------------------------------------------
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

    QMap<QString, int> mb_func;

private slots:

    void onConnectRelease();

    void onRawDataClean();

    void statusPrint(QString msg);

    void changeDataTableRowsCount(int i);

    void changeAddress(int i);

    void changedFunc(QString text);

    void sendButtonRelease();

    void onSlaveAnswer(answer_request_t answer);

    void onRawDataReceive(QByteArray rawData);
};

#endif // MAINWINDOW_H
