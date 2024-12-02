#ifndef PROFILE_FORM_H
#define PROFILE_FORM_H

#include <QWidget>
#include "ui_profile_form.h"
#include "user.h"
#include <QTcpSocket>

namespace Ui {
class profile_form;
}

class profile_form : public QWidget
{
    Q_OBJECT

public:
    explicit profile_form(QWidget *parent = nullptr);
    ~profile_form();
    void SetUser(User& user, QTcpSocket *sock);
    void friendClicked(QLabel *label);

private:
    Ui::profile_form *ui;
};

#endif // PROFILE_FORM_H
