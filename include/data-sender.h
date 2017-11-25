//------------------------------------------------------------------------------
//
//
//
//
//
//------------------------------------------------------------------------------
/*!
 * \file
 * \brief Modbus master data sender
 * \copyright maisvendoo
 * \author Dmitry Pritykin
 * \date 25/11/2017
 */

#ifndef DATA_SENDER_H
#define DATA_SENDER_H

#include    <QObject>
#include    "request.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class DataSender : public QObject
{
    Q_OBJECT

public:

    explicit DataSender(QObject *parent = Q_NULLPTR);
    virtual ~DataSender();

    void init(bool is_cyclic, int delay, abstract_request_t request);

private:

    bool is_cyclic;
    bool is_send_started;
    int delay;
    abstract_request_t request;

signals:

    /// Send request from master to slave
    void sendMasterRequest(abstract_request_t *request);

    void quit();

    ///
    void isStarted(bool *started);

public slots:

    void cyclicDataSend();
};

#endif // DATA_SENDER_H
