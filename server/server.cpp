#include "server.h"
#include <fstream>
#include <QDataStream>
#include <QFile>
#include <QTime>
#define USERDATAPATH "userdata.ud"

Server::Server()
{
    if (this->listen(QHostAddress::Any, 2323)) qDebug() << "$ server started";
    else qDebug() << "$ server started with error";
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    Sockets.push_back(socket);
    qDebug() << "$ new client connected with socket " << socketDescriptor;
    socket_names.push_back("CLIENT");
}

void Server::slotReadyRead()
{
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_14);
    if(in.status() == QDataStream::Ok)
    {
        qDebug() << "$ recieved new request:";
        QString str;
        in >> str;
        if (str[0] == '>')
        {
            qDebug() << "$ new user registration: " << str;
            RegisterNewUser(str);
        }
        else if(str[0] == '<')
        {
            qDebug() << "$ login attempt: " << str;
            QString login, pasword, name, surname, photo;  QString empty1, empty2, empty3;
            Decode(str, login, pasword, empty1, empty2, empty3);
            if (FindUser(login, pasword, name, surname, photo))
            {
                qDebug() << "$ user found, sending userdata to client";
                SendToClient(">" + name + "^" + surname + "^" + photo
                             + "^" + login + "^" + pasword + GetAllUsers());
            }
            else
            {
                qDebug() << "$ user not found!";
                SendToClient("<-");
            }
        }
        else if(str[0] == "|")
        {
            QString sender_name, comp_name, message;    QString empty1, empty2;
            Decode(str, sender_name, comp_name, message, empty1, empty2);
            qDebug() << "$ got message from " << sender_name << " to "
                     << comp_name << ": " << message;
            for (int i = 0; i < socket_names.size(); i++)
            {
                if (comp_name == socket_names[i])
                {
                    socket = Sockets[i];
                    SendToClient(message);
                    qDebug() << "$ message sent!";
                }
            }
        }
        else if(str[0] == "-")
        {
            QString deleted_name = "";
            for (int i = 1; i < str.length(); i++)
                deleted_name += str[i];
            int index = 0;
            for (int i = 0; i < socket_names.length(); i++)
            {
                if (deleted_name == socket_names[i])
                    index = i;
            }
            qDebug() << "$ chat entry ended from " << deleted_name;
            socket_names.erase(socket_names.begin() + index);
            Sockets.erase(Sockets.begin() + index);
        }
        else if(str[0] == "@")
        {
            QString sender_name, comp_name, message;    QString empty1, empty2;
            Decode(str, sender_name, comp_name, message, empty1, empty2);
            for (int i = 0; i < socket_names.size(); i++)
            {
                if (comp_name == socket_names[i])
                {
                    socket = Sockets[i];
                    SendToClient("@");
                }
            }
        }
        else if (str[0] == "#")
        {
            QString sender_name, comp_name, message;    QString empty1, empty2;
            Decode(str, sender_name, comp_name, message, empty1, empty2);
            for (int i = 0; i < socket_names.size(); i++)
            {
                if (comp_name == socket_names[i])
                {
                    socket = Sockets[i];
                    SendToClient("#");
                }
            }
        }
        else
        {
            bool name_added = false;
            for (int i = 0; i < socket_names.size(); i++)
            {
                if (socket_names[i] == str)
                    name_added = true;
            }
            if (!name_added)
            {
                qDebug() << "$ new chat entry from " << str;
                socket_names.pop_back();
                socket_names.push_back(str);
            }
        }
    } else {
        qDebug() << "$ datastream error!";
    }
}

void Server::SendToClient(QString str)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_14);
    out << str;
    socket->write(Data);
}

void Server::RegisterNewUser(QString str)
{
    std::ofstream fout(USERDATAPATH, std::ios::app);
    fout << str.toStdString() << "\n";
}

void Server::Decode(QString str, QString& name, QString& surname, QString& photo, QString& password, QString &login)
{
    int word = 0;
    for(int i = 1; i < str.size(); i++)
    {
        if (str[i] == '^')
        {
            i++;
            word++;
        }
        switch (word)
        {
        case 0:
            name += str[i];
            break;
        case 1:
            surname += str[i];
            break;
        case 2:
            photo += str[i];
            break;
        case 3:
            login += str[i];
            break;
        case 4:
            password += str[i];
            break;
        }
    }
}

bool Server::FindUser(QString login, QString password, QString& name, QString& surname, QString& photo)
{
    std::ifstream counter(USERDATAPATH);
    QFile fin(USERDATAPATH);
    QTextStream stream(&fin);
    if (!fin.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "$ cannot open userdata database: " << fin.errorString();
        return false;
    }
    qDebug() << "$ userdata database opened successfully";
    int count = -1; char *str = new char [1024];
    while (!counter.eof())
    {
        counter.getline(str, 1024, '\n');
        count++;
    }
    QString* users = new QString [count];
    qDebug() << "$ amount of registred users: " << count;
    for (int i = 0; i < count; i ++)
    {
        QString _login, _password;
        users[i] = stream.readLine();
        name = "";  surname = ""; photo = "";
        Decode(users[i], name, surname, photo, _login, _password);
        if (_login == login && _password == password)
        {
            i = count;
            return true;
        }
    }
    return false;
}

QString Server::GetAllUsers()
{
    QString logins = "";
    std::ifstream counter(USERDATAPATH);
    QFile fin(USERDATAPATH);
    QTextStream stream(&fin);
    if (!fin.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "$ cannot open userdata database: " << fin.errorString();
    }
    qDebug() << "$ userdata database opened successfully";
    int count = 0; char *str = new char [1024];
    while (!counter.eof())
    {
        counter.getline(str, 1024, '\n');
        count++;
    }
    QString* users = new QString [count];
    qDebug() << "$ amount of registred users: " << count;
    for (int i = 0; i < count; i ++)
    {
        QString login, password, name, surname, photo;
        users[i] = stream.readLine();
        Decode(users[i], name, surname, photo, login, password);
        qDebug() << name << "; " << surname << "; " << photo << "; " << login << "; " << password;
        logins += "^" + name;
    }
    return logins;
}
