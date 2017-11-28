//------------------------------------------------------------------------------
//
//
//
//
//
//------------------------------------------------------------------------------
/*!
 * \file
 * \brief Modbus request data structures
 * \copyright maisvendoo
 * \author Dmitry Pritykin
 * \date 23/11/2017
 */

#ifndef REQUEST_H
#define REQUEST_H

#include    <QtGlobal>
#include    <string.h>
#include    <QMetaType>
#include    <QByteArray>
#include    <QtEndian>

/*!
 * \fn
 * \brief CRC16 calculation
 */
//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
quint16 calcCRC16(char *buff, quint8 size);

quint8 hiByte(quint16 value);

quint8 loByte(quint16 value);

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
enum
{
    MAX_DATA_SIZE = 252
};

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
enum RequestType
{
    REQ_UNKNOWN = 0,
    REQ_READ = 1,
    REQ_WRITE = 2,
    REQ_ANSWER = 3
};

/*!
 * \struct
 * \brief Abctract request
 */
//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
#pragma pack(push, 1)

struct abstract_request_t
{
    /// Slave id
    quint8      id;
    /// Function code
    quint8      func;
    /// Initial data address
    quint16     address;
    /// Data count
    quint16     count;
    /// Data
    quint16 data[MAX_DATA_SIZE / 2];

    abstract_request_t()
    {
        id = 1;
        func = 0x00;
        count = 0;
        memset(data, 0, sizeof(quint16) * MAX_DATA_SIZE / 2);
    }
};

#pragma pack(pop)

Q_DECLARE_METATYPE(abstract_request_t)

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
#pragma pack(push, 1)

struct read_request_t : public abstract_request_t
{
    read_request_t() : abstract_request_t()
    {

    }    
};

#pragma pack(pop)

Q_DECLARE_METATYPE(read_request_t)

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
#pragma pack(push, 1)

struct write_request_t : public abstract_request_t
{
    write_request_t() : abstract_request_t()
    {

    }   
};

#pragma pack(pop)

Q_DECLARE_METATYPE(write_request_t)

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
#pragma pack(push, 1)

struct answer_request_t
{
    quint8      id;
    quint8      func;
    quint16     count;
    quint16     data[MAX_DATA_SIZE / 2];
    QByteArray  rawPduData;
    quint16     crc;

    answer_request_t()
    {
        id = 1;
        func = 0;
        count = 0;

        memset(data, 0, sizeof(quint16) * MAX_DATA_SIZE / 2);
        rawPduData.clear();
        crc = 0;
    }

    QByteArray getRawData()
    {
        QByteArray buff;

        buff.append(id);
        buff.append(func);
        buff += rawPduData;

        crc = calcCRC16(buff.data(), static_cast<quint8>(buff.size()));

        buff.append(hiByte(crc));
        buff.append(loByte(crc));

        return buff;
    }
};

#pragma pack(pop)

Q_DECLARE_METATYPE(answer_request_t)

#endif // REQUEST_H
