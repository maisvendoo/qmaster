//------------------------------------------------------------------------------
//
//
//
//
//
//------------------------------------------------------------------------------
/*!
 * \file
 * \brief PC Modbus master emulator
 * \copyright maisvendoo
 * \author maisvendoo
 * \date 22/11/2017
 */

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

    connect(modbusDevice, &QModbusClient::stateChanged,
            this, &Master::stateChanged);

    connect(modbusDevice, &QModbusClient::errorOccurred,
            this, &Master::errorModbus);
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
bool Master::init(serial_config_t serial_config)
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
                                             serial_config.getPariry());

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
void Master::writeCoils(write_request_t *request)
{
    // Data unit creation
    QModbusDataUnit dataUnit(QModbusDataUnit::Coils,
                             request->address,
                             request->count);

   // Fill all required data
   for (int i = 0; i < request->count; i++)
       dataUnit.setValue(i, request->data[i]);

    sendWriteRequest(dataUnit, request->id);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void Master::readInputRegisters(read_request_t *request)
{
    QModbusDataUnit dataUnit(QModbusDataUnit::InputRegisters,
                             request->address,
                             request->count);

    sendReadRequest(dataUnit, request->id);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void Master::readDiscreteInputs(read_request_t *request)
{
    QModbusDataUnit dataUnit(QModbusDataUnit::DiscreteInputs,
                             request->address,
                             request->count);

    sendReadRequest(dataUnit, request->id);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void Master::readHoldingRegisters(read_request_t *request)
{
    QModbusDataUnit dataUnit(QModbusDataUnit::HoldingRegisters,
                             request->address,
                             request->count);

    sendReadRequest(dataUnit, request->id);
}

//-----------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void Master::writeHoldingRegisters(write_request_t *request)
{
    QModbusDataUnit dataUnit(QModbusDataUnit::HoldingRegisters,
                             request->address,
                             request->count);

    for (int i = 0; i < request->count; i++)
        dataUnit.setValue(i, request->data[i]);

    sendWriteRequest(dataUnit, request->id);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void Master::sendReadRequest(QModbusDataUnit dataUnit, quint8 id)
{
    QModbusReply *reply = modbusDevice->sendReadRequest(dataUnit, id);

    if (reply != nullptr)
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished,
                    this, &Master::onRecieved);

            connect(reply, &QModbusReply::errorOccurred,
                    this, &Master::errorModbus);
        }
        else
            reply->deleteLater();
    }
    else
    {
        statusPrint("ERROR: Master send data error");
    }
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void Master::sendWriteRequest(QModbusDataUnit dataUnit, quint8 id)
{
    // Send reply
    QModbusReply *reply = modbusDevice->sendWriteRequest(dataUnit, id);

    if (reply != nullptr)
    {
         if (!reply->isFinished())
         {
             connect(reply, &QModbusReply::finished,
                     this, &Master::onWrited);

             connect(reply, &QModbusReply::errorOccurred,
                     this, &Master::errorModbus);
         }
         else
             reply->deleteLater();
    }
    else
    {
        statusPrint("ERROR: Master send data error");
    }
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
void Master::sendRequest(abstract_request_t *request)
{
    switch (request->func)
    {
    // Write coils
    case MB_FUNC_WRITE_COIL:
    case MB_FUNC_WRITE_MULTIPLE_COILS:
        {
            write_request_t *w_req = static_cast<write_request_t *>(request);
            writeCoils(w_req);

            break;
        }
    case MB_FUNC_READ_INPUT_REGISTERS:
        {
            read_request_t *r_req = static_cast<read_request_t *>(request);
            readInputRegisters(r_req);

            break;
        }
    }
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

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void Master::onWrited()
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void Master::onRecieved()
{
    QModbusReply *reply = qobject_cast<QModbusReply *>(sender());

    if (reply == nullptr)
    {
        statusPrint("ERROR: empty reply");
        return;
    }

    QModbusDataUnit dataUnit = reply->result();

    answer_request_t answer;
    answer.id = static_cast<quint8>(reply->serverAddress());
    answer.address = static_cast<quint16>(dataUnit.startAddress());
    answer.count = static_cast<quint16>(dataUnit.valueCount());

    for (int i = 0; i < answer.count; i++)
        answer.data[i] = dataUnit.value(i);

    emit sendAnswer(answer);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
RequestType getRequestType(quint8 func)
{
    switch (func)
    {
    case MB_FUNC_WRITE_COIL:
    case MB_FUNC_WRITE_HOLDING_REGISTER:
    case MB_FUNC_WRITE_MULTIPLE_COILS:
    case MB_FUNC_WRITE_MULTIPLE_REGISTERS:

        return REQ_WRITE;

    case MB_FUNC_READ_COILS:
    case MB_FUNC_READ_DISCRETE_INPUT:
    case MB_FUNC_READ_HOLDING_REGISTERS:
    case MB_FUNC_READ_INPUT_REGISTERS:

        return REQ_READ;

    default:

        break;
    }

    return REQ_UNKNOWN;
}
