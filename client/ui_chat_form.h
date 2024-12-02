/********************************************************************************
** Form generated from reading UI file 'chat_form.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_FORM_H
#define UI_CHAT_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chat_form
{
public:
    QLabel *photo;
    QLabel *comp_title;
    QFrame *line;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *chat_form)
    {
        if (chat_form->objectName().isEmpty())
            chat_form->setObjectName(QString::fromUtf8("chat_form"));
        chat_form->resize(384, 613);
        photo = new QLabel(chat_form);
        photo->setObjectName(QString::fromUtf8("photo"));
        photo->setGeometry(QRect(30, 10, 31, 31));
        comp_title = new QLabel(chat_form);
        comp_title->setObjectName(QString::fromUtf8("comp_title"));
        comp_title->setGeometry(QRect(70, 20, 301, 16));
        QFont font;
        font.setPointSize(11);
        comp_title->setFont(font);
        line = new QFrame(chat_form);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 40, 391, 31));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        lineEdit = new QLineEdit(chat_form);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 570, 311, 31));
        lineEdit->setFont(font);
        pushButton = new QPushButton(chat_form);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(329, 570, 41, 31));
        textBrowser = new QTextBrowser(chat_form);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 60, 361, 501));
        QFont font1;
        font1.setPointSize(14);
        textBrowser->setFont(font1);

        retranslateUi(chat_form);

        QMetaObject::connectSlotsByName(chat_form);
    } // setupUi

    void retranslateUi(QWidget *chat_form)
    {
        chat_form->setWindowTitle(QCoreApplication::translate("chat_form", "\320\247\320\260\321\202", nullptr));
        photo->setText(QString());
        comp_title->setText(QCoreApplication::translate("chat_form", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("chat_form", ">", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chat_form: public Ui_chat_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_FORM_H
