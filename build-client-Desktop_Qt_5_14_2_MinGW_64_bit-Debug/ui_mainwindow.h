/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *image;
    QLineEdit *login_text;
    QLineEdit *pass_text;
    QPushButton *login_button;
    QPushButton *regop_button;
    QPushButton *reg_button;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *surname_text;
    QLabel *label_3;
    QLineEdit *name_text;
    QLabel *label_4;
    QLineEdit *photo_text;
    QLabel *label_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(414, 466);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        image = new QLabel(centralwidget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(90, 30, 191, 121));
        login_text = new QLineEdit(centralwidget);
        login_text->setObjectName(QString::fromUtf8("login_text"));
        login_text->setGeometry(QRect(70, 170, 251, 21));
        QFont font;
        font.setPointSize(11);
        login_text->setFont(font);
        pass_text = new QLineEdit(centralwidget);
        pass_text->setObjectName(QString::fromUtf8("pass_text"));
        pass_text->setGeometry(QRect(70, 210, 251, 21));
        pass_text->setFont(font);
        pass_text->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        pass_text->setEchoMode(QLineEdit::Password);
        login_button = new QPushButton(centralwidget);
        login_button->setObjectName(QString::fromUtf8("login_button"));
        login_button->setGeometry(QRect(70, 240, 251, 31));
        QFont font1;
        font1.setPointSize(10);
        login_button->setFont(font1);
        regop_button = new QPushButton(centralwidget);
        regop_button->setObjectName(QString::fromUtf8("regop_button"));
        regop_button->setGeometry(QRect(70, 280, 251, 31));
        regop_button->setFont(font1);
        reg_button = new QPushButton(centralwidget);
        reg_button->setObjectName(QString::fromUtf8("reg_button"));
        reg_button->setGeometry(QRect(70, 360, 251, 31));
        reg_button->setFont(font1);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 150, 111, 21));
        QFont font2;
        font2.setPointSize(8);
        label->setFont(font2);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 190, 111, 21));
        label_2->setFont(font2);
        surname_text = new QLineEdit(centralwidget);
        surname_text->setObjectName(QString::fromUtf8("surname_text"));
        surname_text->setGeometry(QRect(70, 290, 251, 21));
        surname_text->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 270, 111, 21));
        label_3->setFont(font2);
        name_text = new QLineEdit(centralwidget);
        name_text->setObjectName(QString::fromUtf8("name_text"));
        name_text->setGeometry(QRect(70, 250, 251, 21));
        name_text->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 230, 111, 21));
        label_4->setFont(font2);
        photo_text = new QLineEdit(centralwidget);
        photo_text->setObjectName(QString::fromUtf8("photo_text"));
        photo_text->setEnabled(true);
        photo_text->setGeometry(QRect(70, 330, 251, 21));
        photo_text->setFont(font);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(70, 310, 111, 21));
        label_5->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 414, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Login", nullptr));
        image->setText(QString());
        login_button->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        regop_button->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        reg_button->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\244\320\276\321\202\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
