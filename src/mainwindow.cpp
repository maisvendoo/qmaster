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
#include    <QHeaderView>
#include    <QSpinBox>
#include    <QTableView>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    init();   
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
    // Tune output data table
    QTableWidget *table = ui->tableData;
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    addTableRow(table);
    table->horizontalHeader()->setVisible(true);

    connect(ui->sbCount, SIGNAL(valueChanged(int)),
            this, SLOT(changeDataTableRowsCount(int)));

    // Get available serial ports
    QList<QSerialPortInfo> info = QSerialPortInfo::availablePorts();

    for (int i = 0; i < info.count(); i++)
    {
        ui->cbPort->addItem(info.at(i).portName());
    }

    // Modbus functuions list to UI
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

    // Modbus master initialization
    master = new Master();

    connect(ui->bConnect, SIGNAL(released()),
            this, SLOT(onConnectRelease()));

    connect(master, SIGNAL(statusPrint(QString)),
            this, SLOT(statusPrint(QString)));
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
void MainWindow::addTableRow(QTableWidget *table)
{
    int idx = table->rowCount();
    table->insertRow(table->rowCount());

    int addr = ui->sbAddress->value() + ui->sbCount->value() - 1;
    table->setItem(idx, 1, new QTableWidgetItem(QString::number(addr)));
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MainWindow::delTableRow(QTableWidget *table)
{
    table->removeRow(table->rowCount() - 1);
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
        // Get port settings from form controls
        serial_config_t serial_config = getSerialConfig();

        // Master init
        if (!master->init(serial_config))
        {
            statusPrint("ERROR: Master device initialization failed");
            return;
        }

        // Try connection
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

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MainWindow::changeDataTableRowsCount(int i)
{
    if (i > ui->tableData->rowCount())
        addTableRow(ui->tableData);

    if (i < ui->tableData->rowCount())
        delTableRow(ui->tableData);
}
