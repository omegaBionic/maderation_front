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
    QPushButton *btn_alert;

    void setupUi(QWidget *menu_toolbar)
    {
        if (menu_toolbar->objectName().isEmpty())
            menu_toolbar->setObjectName(QString::fromUtf8("menu_toolbar"));
        menu_toolbar->resize(866, 373);
        menu_toolbar->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"background-color: black;"));
        btn_messages = new QPushButton(menu_toolbar);
        btn_messages->setObjectName(QString::fromUtf8("btn_messages"));
        btn_messages->setGeometry(QRect(515, 177, 57, 16));
        btn_logoff = new QPushButton(menu_toolbar);
        btn_logoff->setObjectName(QString::fromUtf8("btn_logoff"));
        btn_logoff->setGeometry(QRect(343, 177, 33, 16));
        btn_menu = new QPushButton(menu_toolbar);
        btn_menu->setObjectName(QString::fromUtf8("btn_menu"));
        btn_menu->setGeometry(QRect(686, 177, 32, 16));
        btn_archive = new QPushButton(menu_toolbar);
        btn_archive->setObjectName(QString::fromUtf8("btn_archive"));
        btn_archive->setGeometry(QRect(1, 177, 41, 16));
        btn_alert = new QPushButton(menu_toolbar);
        btn_alert->setObjectName(QString::fromUtf8("btn_alert"));
        btn_alert->setGeometry(QRect(172, 177, 26, 16));

        retranslateUi(menu_toolbar);

        QMetaObject::connectSlotsByName(menu_toolbar);
    } // setupUi

    void retranslateUi(QWidget *menu_toolbar)
    {
        menu_toolbar->setWindowTitle(QApplication::translate("menu_toolbar", "Form", nullptr));
        btn_messages->setText(QApplication::translate("menu_toolbar", "messages", nullptr));
        btn_logoff->setText(QApplication::translate("menu_toolbar", "logoff", nullptr));
        btn_menu->setText(QApplication::translate("menu_toolbar", "menu", nullptr));
        btn_archive->setText(QApplication::translate("menu_toolbar", "archive", nullptr));
        btn_alert->setText(QApplication::translate("menu_toolbar", "alert", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menu_toolbar: public Ui_menu_toolbar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_TOOLBAR_H
