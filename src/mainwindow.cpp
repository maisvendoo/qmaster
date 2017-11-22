//------------------------------------------------------------------------------
//
//
//
//
//
//------------------------------------------------------------------------------
#include    "mainwindow.h"
#include    "ui_mainwindow.h"

#include    <QtSerialPort/QSerialPortInfo>
#include    <QString>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    init();

    master = new Master();

    connect(ui->bConnect, SIGNAL(released()), this, SLOT(onConnectRelease()));

    connect(master, SIGNAL(statusPrint(QString)), this, SLOT(statusPrint(QString)));
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
MainWindow::~MainWindow()
{
    delete ui;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MainWindow::init()
{
    /// Получаем список доступных последовательных портов
    QList<QSerialPortInfo> info = QSerialPortInfo::availablePorts();

    for (int i = 0; i < info.count(); i++)
    {
        ui->cbPort->addItem(info.at(i).portName());
    }

    /// Формируем список функций
    mb_func.insert("Read Coils (0x01)", MB_FUNC_READ_COILS);
    mb_func.insert("Read Discrete Inputs (0x02)", MB_FUNC_READ_DISCRETE_INPUT);
    mb_func.insert("Read Holding Registers (0x03)", MB_FUNC_READ_HOLDING_REGISTERS);
    mb_func.insert("Read Input Registers (0x04)", MB_FUNC_READ_INPUT_REGISTERS);
    mb_func.insert("Write Coil (0x05)", MB_FUNC_WRITE_COIL);
    mb_func.insert("Write Holding Register (0x06)", MB_FUNC_WRITE_HOLDING_REGISTER);
    mb_func.insert("Write Multiple Coils (0x0F)", MB_FUNC_WRITE_MULTIPLE_COILS);
    mb_func.insert("Write Multiple Registers (0x10)", MB_FUNC_WRITE_MULTIPLE_REGISTERS);

    QMap<QString, int>::iterator it;

    for (it = mb_func.begin(); it != mb_func.end(); ++it)
    {
        ui->cbFunc->addItem(it.key());
    }
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
serial_config_t MainWindow::getSerialConfig()
{
    serial_config_t s_cfg;

    s_cfg.portName = ui->cbPort->currentText();
    s_cfg.baudrate = ui->cbBaud->currentText().toInt();
    s_cfg.dataBits = ui->cbDataBits->currentText().toInt();
    s_cfg.stopBits = ui->cbStopBits->currentText().toInt();

    return s_cfg;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MainWindow::onConnectRelease()
{
    if (master->isConnected())
    {
        master->closeConnection();
        ui->bConnect->setText("Connect");
    }
    else
    {
        /// Получаем настройки порта с формы
        serial_config_t serial_config = getSerialConfig();

        /// Инициализируем мастер
        master->init(serial_config);

        /// Выполняем соединение
        master->openConnection();

        ui->bConnect->setText("Disconnect");
    }
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MainWindow::statusPrint(QString msg)
{
    ui->statusBar->clearMessage();
    ui->statusBar->showMessage(msg);
}
