#include "profile_form.h"
#include "ui_profile_form.h"
#include "user.h"
#include <QPixmap>
#include <QDebug>
#include <QtGui>
#include "clickablelabel.h"
#include "adapter.h"
#include "chat_form.h"
#include <QMessageBox>
#include "mainwindow.h"

User user;
QTcpSocket *chat_socket;
profile_form::profile_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::profile_form)
{
    ui->setupUi(this);
    QPixmap pix("D:/PROJECTS/CYA_the_messanger/user_icon.png");
    ui->profile_photo->setPixmap(pix.scaled(130, 130, Qt::KeepAspectRatio));
}

void profile_form::SetUser(User& _user, QTcpSocket *sock)
{
    user = _user;   chat_socket = sock;
    ui->name_label->setText(user.name);
    ui->surname_label->setText(user.surname);
    int offset = 35;
    for (int i = 1; i < user.friends.size(); ++i) {

        ClickableLabel *olabel = new ClickableLabel(this);
        olabel->setText(user.friends[i]);
        QFont font("Arial", 13);
        olabel->setFont(font);
        olabel->setGeometry(65,280 + offset,0,0);
        olabel->setMinimumSize(271,21);

        connect(olabel, &ClickableLabel::clicked, this,
                [this, olabel]
                {
                    friendClicked(olabel);
                });
        olabel->show();

        QLabel *plabel = new QLabel(this);
        plabel->setText(user.friends[i]);
        plabel->setGeometry(25,275 + offset,0,0);
        plabel->setMinimumSize(31,31);
        QPixmap pix("D:/PROJECTS/CYA_the_messanger/friend_icon.png");
        plabel->setPixmap(pix.scaled(31, 31, Qt::KeepAspectRatio));
        plabel->show();
        offset += 40;

    }
}
void profile_form::friendClicked(QLabel *label)
{
    chat_form *form = new chat_form();
    form->set_comp(label->text(), user.name, chat_socket);
    form->show();
}
profile_form::~profile_form()
{
    delete ui;
}
