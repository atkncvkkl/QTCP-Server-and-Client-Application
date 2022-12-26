#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class mythread : public QThread
{
    Q_OBJECT
public:
    explicit mythread(QObject *parent = nullptr);
    void doConnect();
    //void run();

signals:

public slots:
    void sendMessage();

private:

    QString *qString;
    QTcpSocket *socket;

};

#endif // MYTHREAD_H
