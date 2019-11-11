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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Main_Menu
{
public:
    QWidget *centralwidget;
    QLabel *background;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QMainWindow *Main_Menu)
    {
        if (Main_Menu->objectName().isEmpty())
            Main_Menu->setObjectName(QString::fromUtf8("Main_Menu"));
        Main_Menu->resize(1254, 634);
        Main_Menu->setStyleSheet(QString::fromUtf8("QWidget {\n"
"background-color: #00000000;\n"
"\n"
"}"));
        centralwidget = new QWidget(Main_Menu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        background = new QLabel(centralwidget);
        background->setObjectName(QString::fromUtf8("background"));
        background->setGeometry(QRect(160, 60, 55, 16));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(360, 140, 451, 301));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"background-color: #00000000;\n"
"border: 0px;\n"
"\n"
"}"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 451, 301));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setWidget(scrollAreaWidgetContents);
        Main_Menu->setCentralWidget(centralwidget);

        retranslateUi(Main_Menu);

        QMetaObject::connectSlotsByName(Main_Menu);
    } // setupUi

    void retranslateUi(QMainWindow *Main_Menu)
    {
        Main_Menu->setWindowTitle(QApplication::translate("Main_Menu", "MainWindow", nullptr));
        background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Main_Menu: public Ui_Main_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_MENU_H
