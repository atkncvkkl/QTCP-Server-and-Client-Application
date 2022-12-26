#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>

class mythread : public QThread
{
    Q_OBJECT
public:
    explicit    mythread(qintptr ID, QObject *parent=0);
    void run();

signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnected();
private:
    QTcpServer *server;
    QTcpSocket *socket;
    qintptr socketDescriptor;
};

#endif // MYTHREAD_H
