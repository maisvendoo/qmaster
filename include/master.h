//------------------------------------------------------------------------------
//
//
//
//
//
//------------------------------------------------------------------------------
#ifndef MASTER_H
#define MASTER_H

#include    <QObject>
#include    <QModbusClient>
#include    <QMetaType>

#include    "serial-config.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
enum
{
    MB_FUNC_NONE = 0x00,
    MB_FUNC_READ_COILS = 0x01,
    MB_FUNC_READ_DISCRETE_INPUT = 0x02,
    MB_FUNC_READ_HOLDING_REGISTERS = 0x03,
    MB_FUNC_READ_INPUT_REGISTERS = 0x04,
    MB_FUNC_WRITE_COIL = 0x05,
    MB_FUNC_WRITE_HOLDING_REGISTER = 0x06,
    MB_FUNC_WRITE_MULTIPLE_COILS = 0x0F,
    MB_FUNC_WRITE_MULTIPLE_REGISTERS = 0x10
};

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class Master : public QObject
{
    Q_OBJECT

public:

    explicit Master(QObject *parent = Q_NULLPTR);

    virtual ~Master();

    bool init(const serial_config_t &serial_config);

    bool isConnected() const;

signals:

    void statusPrint(QString msg);

protected:

    QModbusClient   *modbusDevice;

    bool is_connected;    

public slots:

    void openConnection();

    void closeConnection();

private slots:

    void errorModbus(QModbusDevice::Error error);

    void stateChanged(QModbusDevice::State state);
};

#endif // MASTER_H
