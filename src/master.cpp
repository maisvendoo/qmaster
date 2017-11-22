
#include    "master.h"

#include    <QModbusRtuSerialMaster>
#include    <QVariant>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
Master::Master(QObject *parent) : QObject(parent)
{
    is_connected = false;
    modbusDevice = Q_NULLPTR;

    modbusDevice = new QModbusRtuSerialMaster(this);

    connect(modbusDevice, &QModbusClient::stateChanged, this, &Master::stateChanged);
    connect(modbusDevice, &QModbusClient::errorOccurred, this, &Master::errorModbus);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
Master::~Master()
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
bool Master::init(const serial_config_t &serial_config)
{
    if (modbusDevice == Q_NULLPTR)
        return false;

    if (modbusDevice->state() != QModbusDevice::ConnectedState)
    {
        modbusDevice->setConnectionParameter(QModbusDevice::SerialPortNameParameter,
                                             serial_config.portName);

        modbusDevice->setConnectionParameter(QModbusDevice::SerialBaudRateParameter,
                                             serial_config.baudrate);

        modbusDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter,
                                             serial_config.dataBits);

        modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter,
                                             serial_config.stopBits);

        modbusDevice->setConnectionParameter(QModbusDevice::SerialParityParameter,
                                             serial_config.parity);

        modbusDevice->setTimeout(serial_config.timeout);
        modbusDevice->setNumberOfRetries(serial_config.retries);
    }
    else
        return false;

    return true;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
bool Master::isConnected() const
{
    return is_connected;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void Master::openConnection()
{
    modbusDevice->connectDevice();
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void Master::closeConnection()
{
    modbusDevice->disconnectDevice();
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void Master::errorModbus(QModbusDevice::Error error)
{
    switch (error)
    {
    case QModbusDevice::NoError:
        statusPrint(modbusDevice->errorString());
        break;

    case QModbusDevice::ReadError:
        statusPrint(modbusDevice->errorString());
        break;

    case QModbusDevice::WriteError:
        statusPrint(modbusDevice->errorString());
        break;

    case QModbusDevice::ConnectionError:
        statusPrint(modbusDevice->errorString());
        break;

    case QModbusDevice::ConfigurationError:
        statusPrint(modbusDevice->errorString());
        break;

    case QModbusDevice::ProtocolError:
        statusPrint(modbusDevice->errorString());
        break;

    case QModbusDevice::TimeoutError:

        statusPrint(modbusDevice->errorString());
        break;

    case QModbusDevice::UnknownError:
        statusPrint(modbusDevice->errorString());
        break;

    default:

        break;
    }
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void Master::stateChanged(QModbusDevice::State state)
{
    switch (state)
    {
    case QModbusDevice::ConnectedState:

        is_connected = true;
        statusPrint("Device is connected...OK");

        break;

    case QModbusDevice::UnconnectedState:

        is_connected = false;
        statusPrint("Device is disconnected...OK");

        break;

    default:

        is_connected = false;

        break;
    }
}
