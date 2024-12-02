#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adapter.h"
#include <QPixmap>
#include <QMessageBox>
#include "user.h"
#include "profile_form.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    con_adapt.socket = new QTcpSocket(this);
    connect(con_adapt.socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    connect(con_adapt.socket, &QTcpSocket::disconnected,
            con_adapt.socket, &QTcpSocket::deleteLater);
    QPixmap pix("D:/PROJECTS/CYA_the_messanger/cya_icon.png");
    ui->image->setPixmap(pix.scaled(250,250,Qt::KeepAspectRatio));
    con_adapt.socket->connectToHost("127.0.0.1", 2323);
    // set visibility
    {
        ui->reg_button->setVisible(false);
        ui->photo_text->setVisible(false);
        ui->name_text->setVisible(false);
        ui->surname_text->setVisible(false);
        ui->label_3->setVisible(false);
        ui->label_4->setVisible(false);
        ui->label_5->setVisible(false);
    }
}

MainWindow::~MainWindow()
{
    disconnect(con_adapt.socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    delete ui;
}

void MainWindow::slotReadyRead()
{
    QDataStream in(con_adapt.socket);
    in.setVersion(QDataStream::Qt_5_14);
    if(in.status()==QDataStream::Ok)
    {
        QString str;
        in >> str;
        if (str == "<-")
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Ошибка!");
            msgBox.setIcon(QMessageBox::Icon::Warning);
            msgBox.setText("Пользователь не найден!");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.show();
            msgBox.exec();
        }
        if (str[0] == '>')
        {
            profile_form *form = new profile_form();
            QString password, login, photo, name, surname;
            QVector<QString> logins;
            DecodeUserInfo(str, name, surname, photo, password, login, logins);
            User user(name, surname, photo, password, login, logins);
            form->show(); form->SetUser(user, con_adapt.socket);
            this->hide();
        }
    } else {
        qDebug() << "Data stream error";
    }
}

void MainWindow::on_regop_button_clicked() {
    // set visibility
    {
        ui->reg_button->setVisible(true);
        ui->login_button->setVisible(false);
        ui->regop_button->setVisible(false);
        ui->reg_button->setVisible(true);
        ui->photo_text->setVisible(true);
        ui->name_text->setVisible(true);
        ui->surname_text->setVisible(true);
        ui->label_3->setVisible(true);
        ui->label_4->setVisible(true);
        ui->label_5->setVisible(true);
    }
}

void MainWindow::on_reg_button_clicked()
{
    if (!ui->login_text->text().isEmpty() && !ui->pass_text->text().isEmpty() &&
            !ui->surname_text->text().isEmpty() && !ui->name_text->text().isEmpty())
    {
        QString login(ui->login_text->text()),
                password(ui->pass_text->text()),
                name(ui->name_text->text()),
                surname(ui->surname_text->text()),
                photo(ui->photo_text->text());
        con_adapt.SendToServer(">" + name + "^" + surname + "^" + photo
                               + "^" + password + "^" + login);

        QMessageBox msgBox;
        msgBox.setWindowTitle("Успешно!");
        msgBox.setIcon(QMessageBox::Icon::Information);
        msgBox.setText("Вы были зарегистированы!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.show();
        msgBox.exec();
        // visibility & cleaning
        {
            ui->reg_button->setVisible(false);
            ui->login_button->setVisible(true);
            ui->regop_button->setVisible(true);
            ui->reg_button->setVisible(false);
            ui->photo_text->setVisible(false); ui->photo_text->clear();
            ui->name_text->setVisible(false); ui->name_text->clear();
            ui->surname_text->setVisible(false); ui->surname_text->clear();
            ui->label_3->setVisible(false);
            ui->label_4->setVisible(false);
            ui->label_5->setVisible(false);
            ui->login_text->clear();
            ui->pass_text->clear();
        }
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Внимание!");
        msgBox.setIcon(QMessageBox::Icon::Information);
        msgBox.setText("Заполните все поля!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.show();
        msgBox.exec();
    }
}

void MainWindow::on_login_button_clicked()
{
    if (!ui->login_text->text().isEmpty() && !ui->pass_text->text().isEmpty())
    {
        QString login(ui->login_text->text()), password(ui->pass_text->text());
        con_adapt.SendToServer("<" + login + "^" + password);
    }
}

void MainWindow::DecodeUserInfo(QString str, QString& name, QString& surname,
                            QString& photo, QString& password, QString &login,
                                QVector<QString>& logins)
{
    int word = 0;
    QString _login;
    for(int i = 1; i < str.size(); i++)
    {
        if (str[i] == '^')
        {
            i++;
            word++;
            if (word > 4)
            {
                if (_login != login)
                {
                    logins.push_back(_login);
                }
                _login = "";
            }
        }
        if (word == 0) name += str[i];
        if (word == 1) surname += str[i];
        if (word == 2) photo += str[i];
        if (word == 3) password += str[i];
        if (word == 4) login += str[i];
        if (word > 4){
            _login += str[i];
        }
    }
}
