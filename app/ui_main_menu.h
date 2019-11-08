/********************************************************************************
** Form generated from reading UI file 'main_menu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_MENU_H
#define UI_MAIN_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Main_Menu
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Main_Menu)
    {
        if (Main_Menu->objectName().isEmpty())
            Main_Menu->setObjectName(QString::fromUtf8("Main_Menu"));
        Main_Menu->resize(1254, 634);
        centralwidget = new QWidget(Main_Menu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Main_Menu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Main_Menu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1254, 26));
        Main_Menu->setMenuBar(menubar);
        statusbar = new QStatusBar(Main_Menu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Main_Menu->setStatusBar(statusbar);

        retranslateUi(Main_Menu);

        QMetaObject::connectSlotsByName(Main_Menu);
    } // setupUi

    void retranslateUi(QMainWindow *Main_Menu)
    {
        Main_Menu->setWindowTitle(QApplication::translate("Main_Menu", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Main_Menu: public Ui_Main_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_MENU_H
