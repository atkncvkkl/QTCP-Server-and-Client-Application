#include "myserver.h"
#include "mythread.h"

myserver::myserver(QObject *parent)
    : QTcpServer{parent}
{

}

void myserver::startServer()
{
    if(!this->listen(QHostAddress::Any,1234))
    {
        qDebug() << "Not Started";
    }
    else
    {
        qDebug() << "Server Started";
    }
}


void myserver::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << socketDescriptor << "Connecting...";

    /* Every incoming connection thread was started for connected socket */
    mythread *thread = new mythread(socketDescriptor,this);

    thread->start();
}
