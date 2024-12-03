#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QTime>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server();
    QTcpSocket *socket;
private:
    QVector<QTcpSocket*> Sockets;
    QVector<QString> socket_names;
    QByteArray Data;
    void SendToClient(QString str);
    void RegisterNewUser(QString str);
    void Decode(QString str, QString& name, QString& surname, QString& photo, QString& password, QString &login);
    bool FindUser(QString login, QString password, QString& name, QString& surname, QString& photo);
    QString GetAllUsers();

public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();
};

#endif // SERVER_H
