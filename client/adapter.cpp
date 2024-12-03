#include "adapter.h"

adapter::adapter() {}

void adapter::SendToServer(QString str)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_14);
    out << str;
    socket->write(Data);
}

void adapter::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_14);
    if(in.status()==QDataStream::Ok)
    {
        QString str;
        in >> str;
    } else {
        qDebug() << "$ QDataStream read error";
    }
}
