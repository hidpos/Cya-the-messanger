#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "adapter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    adapter con_adapt;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void DecodeUserInfo(QString str, QString& name, QString& surname,
                        QString& photo, QString& password, QString &login,
                        QVector<QString>& logins);

public slots:
    void slotReadyRead();
private slots:
    void on_regop_button_clicked();
    void on_reg_button_clicked();
    void on_login_button_clicked();
};
#endif // MAINWINDOW_H
