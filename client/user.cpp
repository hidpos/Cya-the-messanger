#include "user.h"

User::User(QString _name, QString _surname, QString _photo,
           QString _password, QString _login, QVector<QString> logins)
{
    name = _name;   surname = _surname; photo = _photo;
    password = _password;   login = _login; friends = logins;
}
User::User(){}
