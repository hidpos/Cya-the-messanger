#include "adapter.h"
#include <QTime>

adapter::adapter()
{

}

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
        //ui->textBrowser->append("read error");
    }
}
