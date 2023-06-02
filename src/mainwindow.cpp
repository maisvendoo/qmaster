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

#include    "mainwindow.h"
#include    "ui_mainwindow.h"

#include    <QtSerialPort/QSerialPortInfo>
#include    <QString>
#include    <QHeaderView>
#include    <QSpinBox>
#include    <QTableView>
#include    <QComboBox>
#include    <QPushButton>
#include    <QPlainTextEdit>
#include    <QTimer>
#include    <QCheckBox>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
enum
{
    TAB_DATA_TYPE = 0,
    TAB_ADDRESS = 1,
    TAB_DATA = 2
};

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
enum
{
    UPDATE_PORT_LIST_TIMEOUT = 100
};

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
    // Set window icon
    QIcon icon(":/icons/img/logo.png");
    setWindowIcon(icon);

    // Setup timer, for update ports list
    portsListUpdateTimer = new QTimer(this);

    connect(portsListUpdateTimer, &QTimer::timeout,
            this, &MainWindow::updatePortsList);

    currentSerialPorts = 0;
    portsListUpdateTimer->start(UPDATE_PORT_LIST_TIMEOUT);


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

    // Tune output data table
    QTableWidget *table = ui->tableData;
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    addTableRow(table);
    table->horizontalHeader()->setVisible(true);

    connect(ui->sbCount, SIGNAL(valueChanged(int)),
            this, SLOT(changeDataTableRowsCount(int)));

    connect(ui->sbAddress, SIGNAL(valueChanged(int)),
            this, SLOT(changeAddress(int)));

    connect(ui->cbFunc, &QComboBox::currentTextChanged,
            this, &MainWindow::changedFunc);

    QString dataType = getDataTypeName(mb_func[ui->cbFunc->currentText()]);

    ui->tableData->setItem(0, TAB_DATA_TYPE, new QTableWidgetItem(dataType));

    // Modbus master initialization
    master = new Master();

    connect(this, &MainWindow::sendMasterRequest,
            master, &Master::sendRequest);

    connect(ui->bConnect, &QPushButton::released,
            this, &MainWindow::onConnectRelease);

    connect(master, &Master::statusPrint,
            this, &MainWindow::statusPrint);

    connect(master, &Master::statusPrint,
            this, &MainWindow::printMsg);

    // Send button initialize
    connect(ui->bSend, &QPushButton::released, this, &MainWindow::sendButtonRelease);

    qRegisterMetaType<answer_request_t>();

    connect(master, &Master::sendAnswer, this, &MainWindow::onSlaveAnswer);

    connect(master, &Master::sendRawData, this, &MainWindow::onRawDataReceive);

    connect(ui->bRawDataClean, &QPushButton::released,
            this, &MainWindow::onRawDataClean);

    // Prepare work of data sender
    is_send_started = false;
    is_cyclic = false;

    connect(ui->cCyclicSend, &QCheckBox::stateChanged,
            this, &MainWindow::checkCyclicSend);

    connect(&sendRequestTimer, &QTimer::timeout,
            this, &MainWindow::slotCyclicRequestSend);

    is_close_event = false;
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
    s_cfg.parity = ui->cbParity->currentText();

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

    table->setItem(idx, TAB_ADDRESS,
                   new QTableWidgetItem(QString::number(addr)));

    table->setItem(idx, TAB_DATA,
                   new QTableWidgetItem(QString::number(0)));

    QString dataType = getDataTypeName(mb_func[ui->cbFunc->currentText()]);

    table->setItem(idx, TAB_DATA_TYPE,
                   new QTableWidgetItem(dataType));
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
QString MainWindow::getDataTypeName(int mb_func) const
{
    QString type = "Unknown";

    switch (mb_func)
    {
    case MB_FUNC_READ_COILS:
    case MB_FUNC_WRITE_COIL:
    case MB_FUNC_WRITE_MULTIPLE_COILS:

        type = "Coil";

        break;

    case MB_FUNC_READ_DISCRETE_INPUT:

        type = "Discrete Input";

        break;

    case MB_FUNC_READ_INPUT_REGISTERS:

        type = "Input Register";

        break;

    case MB_FUNC_READ_HOLDING_REGISTERS:
    case MB_FUNC_WRITE_HOLDING_REGISTER:
    case MB_FUNC_WRITE_MULTIPLE_REGISTERS:

        type = "Holding Register";

        break;

    default:

        break;
    }

    return type;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
abstract_request_t *MainWindow::getRequestData()
{
    // Get function code from user interface
    quint8 func = static_cast<quint8>(mb_func[ui->cbFunc->currentText()]);
    // Check request type (read or write data from slave)
    RequestType type = getRequestType(func);

    // Process request
    switch (type)
    {
    case REQ_READ:
    {
        // Setup request structure
        read_request_t *request = new read_request_t();
        request->id = static_cast<quint8>(ui->sbSlaveID->value());
        request->func = func;
        request->address = static_cast<quint16>(ui->sbAddress->value());
        request->count = static_cast<quint16>(ui->sbCount->value());

        return request;
    }

    case REQ_WRITE:
    {
        write_request_t *request = new write_request_t();
        request->id = static_cast<quint8>(ui->sbSlaveID->value());
        request->func = func;
        request->address = static_cast<quint16>(ui->sbAddress->value());
        request->count = static_cast<quint16>(ui->sbCount->value());

        // Setup data to request data field
        for (int i = 0; i < request->count; i++)
            request->data[i] = static_cast<quint16>(ui->tableData->item(i, TAB_DATA)->text().toInt());

        return request;
    }

    default:

        statusPrint("ERROR: Unknown requst type");

        return nullptr;
    }
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MainWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
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
void MainWindow::onRawDataClean()
{
    ui->ptRawData->clear();
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

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MainWindow::changeAddress(int i)
{
    // Calculate number of additional data table rows
    int delta = i - ui->tableData->item(0, TAB_ADDRESS)->text().toInt();

    // Update all data addresses in table
    for (int j = 0; j < ui->tableData->rowCount(); j++)
    {
        int addr = ui->tableData->item(j, TAB_ADDRESS)->text().toInt();
        addr += delta;

        QTableWidgetItem *item = new QTableWidgetItem;

        item->setText(QString::number(addr));

        ui->tableData->setItem(j, TAB_ADDRESS,item);
    }
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MainWindow::changedFunc(QString text)
{
     for (int j = 0; j < ui->tableData->rowCount(); j++)
    {
        QString dataType = getDataTypeName(mb_func[text]);

        ui->tableData->setItem(j, TAB_DATA_TYPE,
                               new QTableWidgetItem(dataType));
     }
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MainWindow::sendButtonRelease()
{
    // Check connection state
    if (!master->isConnected())
    {
        printMsg("ERROR: Device is not connected");
        return;
    }

    if (!is_cyclic)
    {
        emit sendMasterRequest(getRequestData());
    }
    else
    {
        if (!sendRequestTimer.isActive())
        {
            sendRequestTimer.setInterval(ui->sbSendInterval->value());
            sendRequestTimer.start();
            ui->bSend->setText("Stop");
            ui->bConnect->setEnabled(false);
        }
        else
        {
            sendRequestTimer.stop();
            ui->bSend->setText("Send");
            ui->bConnect->setEnabled(true);
        }
    }
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MainWindow::onSlaveAnswer(answer_request_t answer)
{
    if (getRequestType(answer.func) == REQ_READ)
    {
        // Put received data into data table
        for (int i = 0; i < answer.count; i++)
        {
            ui->tableData->setItem(i, TAB_DATA,
                                   new QTableWidgetItem(QString::number(answer.data[i])));
        }
    }

    // Put raw data into raw data log
    onRawDataReceive(answer.getRawData());
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MainWindow::onRawDataReceive(QByteArray rawData)
{
    QString buff = "Received data: ";
    quint8 tmp = 0;

    // Convert raw data to hexadicemal form
    for (int i = 0; i < rawData.count(); i++)
    {
        tmp = static_cast<quint8>(rawData.at(i));
        buff += QString("%1 ").arg(tmp, 2, 16, QLatin1Char('0'));
    }    

    ui->ptRawData->appendPlainText(buff);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MainWindow::updatePortsList()
{
    // Get list of available ports
    QList<QSerialPortInfo> info = QSerialPortInfo::availablePorts();

    if (currentSerialPorts != info.count())
    {
        // Clean ports list
        ui->cbPort->clear();

        // Update ports list
        for (int i = 0; i < info.count(); i++)
        {
            ui->cbPort->addItem(info.at(i).portName());
        }

        currentSerialPorts = info.count();
    }
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MainWindow::printMsg(QString msg)
{
    ui->ptRawData->appendPlainText(msg);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MainWindow::checkCyclicSend(int state)
{
    is_cyclic = static_cast<bool>(state);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MainWindow::getStartedFlag(bool *started)
{
    *started = is_send_started;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MainWindow::slotCyclicRequestSend()
{
    emit sendMasterRequest(getRequestData());
}
