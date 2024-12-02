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
    quint16 nextBlockSize;
    void RegisterNewUser(QString str);
    void DecodeUserInfo(QString str, QString& name, QString& surname,
                        QString& photo, QString& password, QString &login);
    void DecodeUserInfo(QString str, QString& login, QString &password);
    void DecodeChatMessage(QString str, QString& sender_socket, QString& comp_socket,
                           QString& message);
    bool FindUser(QString login, QString password, QString& name,
                  QString& surname, QString& photo);

    QString GetAllUsers();

public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();
};

#endif // SERVER_H
