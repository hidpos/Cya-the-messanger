#include "chat_form.h"
#include "ui_chat_form.h"
#include <QDebug>
#include <QTime>

chat_form::chat_form(QWidget *parent) : QWidget(parent), ui(new Ui::chat_form) {
    ui->setupUi(this);
    QPixmap pix("friend_icon.png"), pix2("user_icon.png");
    ui->photo->setPixmap(pix.scaled(31,31,Qt::KeepAspectRatio));
    ui->photo_2->setPixmap(pix.scaled(31,31,Qt::KeepAspectRatio));
    ui->typing_lab->setVisible(false); ui->photo_2->setVisible(false);
}

chat_form::~chat_form() {
    delete ui;
}

void chat_form::set_comp(QString companion, QString prof_name) {
    conadapt.socket = new QTcpSocket(this);
    connect(conadapt.socket, &QTcpSocket::readyRead, this, &chat_form::slotReadyRead);
    connect(conadapt.socket, &QTcpSocket::disconnected, conadapt.socket, &QTcpSocket::deleteLater);
    conadapt.socket->connectToHost("127.0.0.1", 2323);
    ui->comp_title->setText(companion);
    chat_companion = companion;
    profile_name = prof_name;
    conadapt.SendToServer(profile_name);
}

void chat_form::slotReadyRead() {
    QDataStream in(conadapt.socket);
    in.setVersion(QDataStream::Qt_5_14);
    if(in.status()==QDataStream::Ok)
    {
        QString str;
        in >> str;
        if (str[0] == "@") {
            ui->typing_lab->setVisible(false);
        }
        else if (str[0] == "#") {
            ui->typing_lab->setVisible(true);
        }
        else {
            ui->textBrowser->append(QTime::currentTime().toString("HH:mm") + ": " + chat_companion + " - " + str);
        }
    } else {
        qDebug() << "$ QDataStream error";
    }
}

void chat_form::on_lineEdit_returnPressed() {
    conadapt.SendToServer("|" + profile_name + "^" + chat_companion + "^" + ui->lineEdit->text());
    ui->textBrowser->append(QTime::currentTime().toString("HH:mm") + ": " + profile_name + " - " + ui->lineEdit->text());
    ui->lineEdit->clear();
}

void chat_form::on_pushButton_clicked() {
    conadapt.SendToServer("|" + profile_name + "^" + chat_companion + "^" + ui->lineEdit->text());
    ui->textBrowser->append(QTime::currentTime().toString("HH:mm") + ": " + profile_name + " - " + ui->lineEdit->text());
    ui->lineEdit->clear();
}

void chat_form::on_chat_form_destroyed()
{

}

void chat_form::closeEvent(QCloseEvent *event) {
    conadapt.SendToServer("-" + profile_name);
}

void chat_form::on_lineEdit_textChanged(const QString &arg1)
{
    //conadapt.SendToServer("#" + profile_name + "^" + chat_companion);
}

void chat_form::on_lineEdit_editingFinished()
{
    //conadapt.SendToServer("@" + profile_name + "^" + chat_companion);
}
