#include "chat_form.h"
#include "ui_chat_form.h"
#include <QDebug>
#include "adapter.h"
#include <QMessageBox>
#include <QTime>

chat_form::chat_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chat_form)
{
    ui->setupUi(this);
//    conadapt.socket = new QTcpSocket(this);
//    connect(conadapt.socket, &QTcpSocket::readyRead, this, &chat_form::slotReadyRead);
//    connect(conadapt.socket, &QTcpSocket::disconnected,
//            conadapt.socket, &QTcpSocket::deleteLater);
    QPixmap pix("D:/PROJECTS/CYA_the_messanger/friend_icon.png");
    ui->photo->setPixmap(pix.scaled(31,31,Qt::KeepAspectRatio));
    //conadapt.socket->connectToHost("127.0.0.1", 2323);
}

chat_form::~chat_form()
{
    delete ui;
}

void chat_form::set_comp(QString companion, QString prof_name, QTcpSocket* socket)
{
    conadapt.socket = socket;
    ui->comp_title->setText(companion);
    chat_companion = companion;
    profile_name = prof_name;
    conadapt.SendToServer(profile_name);
}

void chat_form::slotReadyRead()
{
    QDataStream in(conadapt.socket);
    in.setVersion(QDataStream::Qt_5_14);
    if(in.status()==QDataStream::Ok)
    {
        QString str;
        in >> str;
        ui->textBrowser->append(QTime::currentTime().toString() + ":  " + str);
    } else {
        qDebug() << "Data stream error";
    }
}

void chat_form::on_lineEdit_returnPressed()
{
    conadapt.SendToServer("|" + profile_name + "^" + chat_companion + "^" + ui->lineEdit->text());
    ui->textBrowser->append(QTime::currentTime().toString() + " --- " + ui->lineEdit->text());
    ui->lineEdit->clear();
}

void chat_form::on_pushButton_clicked()
{
    conadapt.SendToServer("|" + profile_name + "^" + chat_companion + "^" + ui->lineEdit->text());
    ui->textBrowser->append(QTime::currentTime().toString("HH:mm") + " --- " + ui->lineEdit->text());
    ui->lineEdit->clear();
}

void chat_form::on_chat_form_destroyed()
{
}

void chat_form::closeEvent(QCloseEvent *event)
{
    conadapt.SendToServer("-" + profile_name);
}
