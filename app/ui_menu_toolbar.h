/********************************************************************************
** Form generated from reading UI file 'menu_toolbar.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_TOOLBAR_H
#define UI_MENU_TOOLBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu_toolbar
{
public:
    QPushButton *btn_messages;
    QPushButton *btn_logoff;
    QPushButton *btn_menu;
    QPushButton *btn_archive;
    QPushButton *btn_user;
    QPushButton *push_background;
    QPushButton *btn_hide;

    void setupUi(QWidget *menu_toolbar)
    {
        if (menu_toolbar->objectName().isEmpty())
            menu_toolbar->setObjectName(QString::fromUtf8("menu_toolbar"));
        menu_toolbar->resize(866, 373);
        menu_toolbar->setStyleSheet(QString::fromUtf8("QWidget {\n"
"background-color: black;\n"
"border-color: rgb(0, 0, 0);\n"
"border-radius: 12px;\n"
"}"));
        btn_messages = new QPushButton(menu_toolbar);
        btn_messages->setObjectName(QString::fromUtf8("btn_messages"));
        btn_messages->setGeometry(QRect(560, 180, 57, 16));
        btn_messages->setCursor(QCursor(Qt::PointingHandCursor));
        btn_messages->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color: white;\n"
"	background-color: rgb(93, 82, 82);\n"
"border-radius: 0px;\n"
"}"));
        btn_logoff = new QPushButton(menu_toolbar);
        btn_logoff->setObjectName(QString::fromUtf8("btn_logoff"));
        btn_logoff->setGeometry(QRect(390, 170, 33, 16));
        btn_logoff->setCursor(QCursor(Qt::PointingHandCursor));
        btn_logoff->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color: white;\n"
"	background-color: rgb(93, 82, 82);\n"
"border-radius: 0px;\n"
"}"));
        btn_menu = new QPushButton(menu_toolbar);
        btn_menu->setObjectName(QString::fromUtf8("btn_menu"));
        btn_menu->setGeometry(QRect(730, 180, 32, 16));
        btn_menu->setCursor(QCursor(Qt::PointingHandCursor));
        btn_menu->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color: white;\n"
"	background-color: rgb(93, 82, 82);\n"
"border-radius: 0px;\n"
"}"));
        btn_archive = new QPushButton(menu_toolbar);
        btn_archive->setObjectName(QString::fromUtf8("btn_archive"));
        btn_archive->setGeometry(QRect(60, 170, 41, 16));
        btn_archive->setCursor(QCursor(Qt::PointingHandCursor));
        btn_archive->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 0px;\n"
"	background-color: rgb(93, 82, 82);\n"
"}"));
        btn_user = new QPushButton(menu_toolbar);
        btn_user->setObjectName(QString::fromUtf8("btn_user"));
        btn_user->setGeometry(QRect(210, 180, 26, 16));
        btn_user->setCursor(QCursor(Qt::PointingHandCursor));
        btn_user->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color: white;\n"
"	background-color: rgb(93, 82, 82);\n"
"border-radius: 0px;\n"
"}"));
        push_background = new QPushButton(menu_toolbar);
        push_background->setObjectName(QString::fromUtf8("push_background"));
        push_background->setGeometry(QRect(150, 250, 93, 28));
        push_background->setCursor(QCursor(Qt::PointingHandCursor));
        push_background->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color: white;\n"
"border-radius: 20px;\n"
"	background-color: rgb(93, 82, 82);\n"
"}"));
        btn_hide = new QPushButton(menu_toolbar);
        btn_hide->setObjectName(QString::fromUtf8("btn_hide"));
        btn_hide->setGeometry(QRect(430, 280, 93, 28));
        btn_hide->setCursor(QCursor(Qt::PointingHandCursor));
        btn_hide->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color: white;\n"
"border-radius: 20px;\n"
"background-color: rgba(0,0,0,0);\n"
"}"));
        btn_hide->raise();
        push_background->raise();
        btn_messages->raise();
        btn_logoff->raise();
        btn_menu->raise();
        btn_archive->raise();
        btn_user->raise();

        retranslateUi(menu_toolbar);

        QMetaObject::connectSlotsByName(menu_toolbar);
    } // setupUi

    void retranslateUi(QWidget *menu_toolbar)
    {
        menu_toolbar->setWindowTitle(QApplication::translate("menu_toolbar", "Form", nullptr));
        btn_messages->setText(QString());
        btn_logoff->setText(QString());
        btn_menu->setText(QString());
        btn_archive->setText(QString());
        btn_user->setText(QString());
        push_background->setText(QString());
        btn_hide->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class menu_toolbar: public Ui_menu_toolbar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_TOOLBAR_H
