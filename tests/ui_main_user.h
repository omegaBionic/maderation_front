/********************************************************************************
** Form generated from reading UI file 'main_user.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_USER_H
#define UI_MAIN_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_user
{
public:
    QWidget *centralwidget;
    QLabel *label_bg;
    QLabel *label_titre;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QToolBox *toolBox;
    QWidget *page;

    void setupUi(QMainWindow *main_user)
    {
        if (main_user->objectName().isEmpty())
            main_user->setObjectName(QString::fromUtf8("main_user"));
        main_user->resize(800, 600);
        main_user->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(main_user);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_bg = new QLabel(centralwidget);
        label_bg->setObjectName(QString::fromUtf8("label_bg"));
        label_bg->setGeometry(QRect(0, 0, 111, 81));
        label_titre = new QLabel(centralwidget);
        label_titre->setObjectName(QString::fromUtf8("label_titre"));
        label_titre->setGeometry(QRect(220, 60, 291, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Futura Md BT"));
        font.setPointSize(22);
        label_titre->setFont(font);
        label_titre->setAlignment(Qt::AlignCenter);
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(100, 140, 511, 241));
        scrollArea->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color:#00000000;\n"
"border-color: #00000000;\n"
"border: 0px;\n"
"}"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 511, 241));
        toolBox = new QToolBox(scrollAreaWidgetContents);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(0, 10, 491, 201));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Futura Lt BT"));
        font1.setPointSize(10);
        toolBox->setFont(font1);
        toolBox->setStyleSheet(QString::fromUtf8("QToolBox {\n"
"  padding: 0px;\n"
"  border: 0px;\n"
"  border:0px solid #32414B;\n"
"}\n"
"\n"
"QToolBox::selected {\n"
"  border: 2px solid #1464A0;\n"
"}\n"
"\n"
"QToolBox::tab {\n"
"  background-color: #19232D;\n"
"  border: 1px solid #32414B;\n"
"  color: #F0F0F0;\n"
"  border-top-left-radius: 5%;\n"
"  border-top-right-radius: 5%;\n"
"}\n"
"\n"
"QToolBox::tab:disabled {\n"
"  color: #787878;\n"
"}\n"
"\n"
"QToolBox::tab:selected {\n"
"  background-color: qlineargradient(spread:pad, x1:0, y1:0.642, x2:1, y2:1, stop:0 rgba(171, 161, 148, 255), stop:1 rgba(186, 169, 128, 255));\n"
"  border-bottom: 2px solid  rgb(177, 45, 45);\n"
"}\n"
"\n"
"\n"
"QToolBox::tab:!selected {\n"
"  background-color: rgb(118, 111, 98);\n"
"  border-bottom: 2px solid rgb(182, 157, 80);\n"
"}\n"
"\n"
"QToolBox::tab:hover:!selected {\n"
"  background-color: rgb(175, 154, 135);\n"
"  border-bottom: 2px solid rgb(255, 168, 105);\n"
"}\n"
""));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 491, 166));
        toolBox->addItem(page, QString::fromUtf8("Page 1"));
        scrollArea->setWidget(scrollAreaWidgetContents);
        main_user->setCentralWidget(centralwidget);

        retranslateUi(main_user);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(main_user);
    } // setupUi

    void retranslateUi(QMainWindow *main_user)
    {
        main_user->setWindowTitle(QApplication::translate("main_user", "MainWindow", nullptr));
        label_bg->setText(QString());
        label_titre->setText(QApplication::translate("main_user", "USER MANAGEMENT", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("main_user", "Page 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main_user: public Ui_main_user {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_USER_H
