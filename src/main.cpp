//------------------------------------------------------------------------------
//
//      Modbus RTU master device emulator
//      (c) Dmitry Pritykin, masivendoo
//      22/11/2017
//
//------------------------------------------------------------------------------
/*!
 * \file
 * \brief Modbus RTU master device emulator
 * \copyright maisvendoo
 * \author Dmitry Pritykin
 * \date 22/11/2017
 */

#include    "main.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
