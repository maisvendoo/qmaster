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

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
enum
{
    MAX_DATA_COUNT = 65536
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

    abstract_request_t()
    {
        id = 1;
        func = 0x00;
        count = 0;
    }
};

#pragma pack(pop)

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

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
#pragma pack(push, 1)

struct write_request_t : public abstract_request_t
{
    quint16 data[MAX_DATA_COUNT];

    write_request_t() : abstract_request_t()
    {
        memset(data, 0, sizeof(quint16) * MAX_DATA_COUNT);
    }
};

#pragma pack(pop)

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
#pragma pack(push, 1)

struct answer_request_t : public write_request_t
{
    quint16 crc;

    answer_request_t() : write_request_t()
    {
        crc = 0;
    }
};

#pragma pack(pop)

#endif // REQUEST_H
