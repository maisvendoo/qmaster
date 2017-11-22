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

    /// Начальная инициализация
    void init();

    /// Получение настроек порта
    serial_config_t getSerialConfig();

    Ui::MainWindow *ui;
    Master  *master;

    QMap<QString, int> mb_func;

private slots:

    void onConnectRelease();

    void statusPrint(QString msg);
};

#endif // MAINWINDOW_H
