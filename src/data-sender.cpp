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

#include    "data-sender.h"

#include    <QThread>
#include    <QTest>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
DataSender::DataSender(QObject *parent) : QObject(parent)
{
    is_cyclic = is_send_started = false;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
DataSender::~DataSender()
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void DataSender::init(bool is_cyclic, int delay, abstract_request_t request)
{
    this->is_cyclic = is_cyclic;
    this->delay = delay;
    this->request = request;

    is_send_started = true;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void DataSender::cyclicDataSend()
{
    do
    {
        // Send request
        emit sendMasterRequest(&request);

        // Sleeping thread, if requed cyclical data send
        if (is_cyclic)
            QTest::qSleep(delay);

        // Get started flag from main window
        emit isStarted(&is_send_started);

    } while (is_cyclic && is_send_started);

    // Terminate sender thread
    emit quit();
}
