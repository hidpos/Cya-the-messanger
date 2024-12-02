#ifndef CHAT_FORM_H
#define CHAT_FORM_H

#include <QWidget>
#include "adapter.h"

namespace Ui {
class chat_form;
}

class chat_form : public QWidget
{
    Q_OBJECT

public:
    explicit chat_form(QWidget *parent = nullptr);
    ~chat_form();
    void set_comp(QString companion, QString prof_name, QTcpSocket* socket);
private:
    adapter conadapt;
    QString chat_companion;
    QString profile_name;
    Ui::chat_form *ui;
public slots:
    void slotReadyRead();
private slots:
    void on_lineEdit_returnPressed();
    void on_pushButton_clicked();
    void on_chat_form_destroyed();
    void closeEvent(QCloseEvent *event);
};

#endif // CHAT_FORM_H