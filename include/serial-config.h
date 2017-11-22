//------------------------------------------------------------------------------
//
//
//
//
//
//------------------------------------------------------------------------------
#ifndef SERIAL_CONFIG_H
#define SERIAL_CONFIG_H

#include    <QString>

/*!
 * \struct
 * \brief Настройки последовательного порта
 */
//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
struct serial_config_t
{
    /// Имя порта
    QString     portName;
    /// Скорость
    int         baudrate;
    /// Биты данных
    int         dataBits;
    /// Стоп-биты
    int         stopBits;
    /// Биты четности
    int         parity;
    /// Управление потоком
    int         flowControl;
    /// Таймаут между попытками запросов
    int         timeout;
    /// Число повторений попыток
    int         retries;

    serial_config_t()
    {
        portName = "/dev/ttyUSB0";
        baudrate = 9600;
        dataBits = 8;
        stopBits = 1;
        parity = 0;
        flowControl = 0;
        timeout = 1000;
        retries = 2;
    }
};

#endif // SERIAL_CONFIG_H
