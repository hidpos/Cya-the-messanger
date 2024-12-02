#ifndef USER_H
#define USER_H

#include <QMainWindow>

class User
{
public:
    User(QString _name, QString _surname, QString _photo, QString password,
         QString login, QVector<QString> logins);
    User();
    QString photo;
    QString name, surname;
    QString login, password;
    QVector<QString> friends;
};

#endif // USER_H
