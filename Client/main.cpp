#include <QCoreApplication>
#include "mythread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    mythread mclient;
    mclient.doConnect();

    return a.exec();
}
