#include "mythread.h"
#include <stdio.h>
#include <QHostAddress>
#include <iostream>

mythread::mythread(qintptr ID, QObject *parent):
    QThread(parent)
{
    this->socketDescriptor = ID;
}

void mythread::run()
{
    /*Creating TCP Server and Socket for connection*/
    socket = new QTcpSocket();
    server = new QTcpServer();

    /* Emitting Socket Error through the socket descriptor */
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }

    /* Every new data is available for reading from socket it is ready for read another one */
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);

    /* When socket disconnected state, disconnected function was triggered */
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    /* Writting peerAddress to console to know which one is connected */
    qDebug() << socket->localAddress().toString() << "Client Connected";

    exec();
}

void mythread::readyRead()
{
    qDebug() << socket->peerAddress().toString() << socket->readAll();
}

void mythread::disconnected()
{
    qDebug() << socketDescriptor << "Disconnected";
    socket->deleteLater();
    exit(0);
}

