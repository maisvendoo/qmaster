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
 * \brief Serial port settings
 */
//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
struct serial_config_t
{
    /// Port name
    QString     portName;
    /// Baudrate
    int         baudrate;
    /// Data bits count
    int         dataBits;
    /// Stop bits count
    int         stopBits;
    /// Parity bit
    int         parity;
    /// Flow control
    int         flowControl;
    /// Request timeout
    int         timeout;
    /// Requiest retries number
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
