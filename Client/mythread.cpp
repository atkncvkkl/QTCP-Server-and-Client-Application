#include "mythread.h"
#include <qtcpsocket.h>
#include <stdio.h>
#include <iostream>
#include <QHostAddress>

mythread::mythread(QObject *parent)
    : QThread{parent}
{
    /* Creating TCP socket to connect TCP Server */
    socket = new QTcpSocket(this);

    qDebug() << "Enter adress";

    std::string adres_Str;
    std::getline(std::cin, adres_Str);
    qString = new QString(adres_Str.c_str());

}


void mythread::doConnect()
{

    /* Connect to Host address that written into qString */
    socket->connectToHost(qString->toUtf8(),1234);

    if(socket->ConnectedState)
    {
        qDebug() << "Connected";

        /* When socket is connected this signal trigger the sendMessage function */
        connect(socket, SIGNAL(connected()), this, SLOT(sendMessage()),Qt::DirectConnection);

        /* Every message is written to socket sendMessage fucntion triggered again (avoided from while loop) */
        connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(sendMessage()),Qt::DirectConnection);

    }

    /* Making this thread a loop */
    exec();
}


void mythread::sendMessage()
{
    /* Taking input from keyboard and convert it into qString*/
    std::string str;
    std::getline(std::cin, str);
    QString qString(str.c_str());
    /* Writing message in qString to socket */
    socket->write(qString.toUtf8());
}

