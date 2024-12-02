#ifndef ADAPTER_H
#define ADAPTER_H

#include <QMainWindow>
#include <QTcpSocket>
#include "user.h"

class adapter
{
public:
    adapter();
    QTcpSocket *socket;
    void SendToServer(QString str);
private:
    QByteArray Data;

public slots:
    void slotReadyRead();
};

#endif // ADAPTER_H
