/********************************************************************************
** Form generated from reading UI file 'profile_form.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILE_FORM_H
#define UI_PROFILE_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_profile_form
{
public:
    QLabel *profile_photo;
    QLabel *name_label;
    QLabel *surname_label;
    QFrame *line;
    QLineEdit *lineEdit;
    QLabel *surname_label_2;

    void setupUi(QWidget *profile_form)
    {
        if (profile_form->objectName().isEmpty())
            profile_form->setObjectName(QString::fromUtf8("profile_form"));
        profile_form->resize(349, 568);
        profile_photo = new QLabel(profile_form);
        profile_photo->setObjectName(QString::fromUtf8("profile_photo"));
        profile_photo->setGeometry(QRect(110, 20, 161, 151));
        QFont font;
        font.setPointSize(10);
        profile_photo->setFont(font);
        name_label = new QLabel(profile_form);
        name_label->setObjectName(QString::fromUtf8("name_label"));
        name_label->setGeometry(QRect(0, 180, 351, 21));
        QFont font1;
        font1.setPointSize(12);
        name_label->setFont(font1);
        name_label->setAlignment(Qt::AlignCenter);
        surname_label = new QLabel(profile_form);
        surname_label->setObjectName(QString::fromUtf8("surname_label"));
        surname_label->setGeometry(QRect(0, 200, 351, 31));
        QFont font2;
        font2.setPointSize(12);
        font2.setKerning(true);
        surname_label->setFont(font2);
        surname_label->setAlignment(Qt::AlignCenter);
        surname_label->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard);
        line = new QFrame(profile_form);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 250, 351, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        lineEdit = new QLineEdit(profile_form);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 270, 331, 291));
        lineEdit->setReadOnly(true);
        surname_label_2 = new QLabel(profile_form);
        surname_label_2->setObjectName(QString::fromUtf8("surname_label_2"));
        surname_label_2->setGeometry(QRect(20, 270, 351, 31));
        QFont font3;
        font3.setPointSize(14);
        font3.setKerning(true);
        surname_label_2->setFont(font3);

        retranslateUi(profile_form);

        QMetaObject::connectSlotsByName(profile_form);
    } // setupUi

    void retranslateUi(QWidget *profile_form)
    {
        profile_form->setWindowTitle(QCoreApplication::translate("profile_form", "\320\237\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        profile_photo->setText(QString());
        name_label->setText(QCoreApplication::translate("profile_form", "TextLabel", nullptr));
        surname_label->setText(QCoreApplication::translate("profile_form", "TextLabel", nullptr));
        surname_label_2->setText(QCoreApplication::translate("profile_form", "\320\222\320\260\321\210\320\270 \320\264\321\200\321\203\320\267\321\214\321\217:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class profile_form: public Ui_profile_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILE_FORM_H
