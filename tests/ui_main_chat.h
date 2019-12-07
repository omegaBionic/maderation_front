/********************************************************************************
** Form generated from reading UI file 'main_chat.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_CHAT_H
#define UI_MAIN_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_chat
{
public:
    QWidget *centralwidget;
    QLabel *label_bg;
    QTabWidget *tabWidget;

    void setupUi(QMainWindow *main_chat)
    {
        if (main_chat->objectName().isEmpty())
            main_chat->setObjectName(QString::fromUtf8("main_chat"));
        main_chat->resize(1090, 634);
        centralwidget = new QWidget(main_chat);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_bg = new QLabel(centralwidget);
        label_bg->setObjectName(QString::fromUtf8("label_bg"));
        label_bg->setGeometry(QRect(60, 10, 55, 16));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(30, 20, 1011, 351));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget{\n"
"border-color: #00000000;\n"
"background-color: #00000000;\n"
"}\n"
"\n"
"QTabWidget::pane{\n"
"background-color: #00000000;\n"
"border:1px;\n"
"}\n"
"\n"
"QTabWidget::tab-bar:top {\n"
"    top: 1px;\n"
"}\n"
"\n"
"QTabWidget::tab-bar:bottom {\n"
"    bottom: 1px;\n"
"}\n"
"\n"
"QTabWidget::tab-bar:left {\n"
"    right: 1px;\n"
"}\n"
"\n"
"QTabWidget::tab-bar:right {\n"
"    left: 1px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"	border-image: url(:/pictures/img/tab_selected.png);\n"
"}\n"
"\n"
"QTabBar::tab:!selected {\n"
"	border-image: url(:/pictures/img/tab_mid.png);\n"
"}\n"
"\n"
"QTabBar::tab:!selected:hover {\n"
"	border-image: url(:/pictures/img/tab_mid_hover.png);\n"
"}\n"
"\n"
"QTabBar::tab:top:!selected {\n"
"    margin-top: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:bottom:!selected {\n"
"    margin-bottom: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:top, QTabBar::tab:bottom {\n"
"	\n"
"    min-width: 8ex;\n"
"    margin-right: -1px;\n"
"    padding: 5px 10px 5px 10px;\n"
"}\n"
""
                        "\n"
"\n"
"QTabBar::tab:top:selected {\n"
"    border-bottom-color: none;\n"
"}\n"
"\n"
"QTabBar::tab:bottom:selected {\n"
"	border-image: url(:/pictures/img/tab_last_hover.png);\n"
"    border-top-color: none;\n"
"}\n"
"\n"
"QTabBar::tab:top:last, QTabBar::tab:bottom:last,\n"
"QTabBar::tab:top:only-one, QTabBar::tab:bottom:only-one {\n"
"\n"
"    margin-right: 0;\n"
"}\n"
"\n"
"QTabBar::tab:left:!selected {\n"
"    margin-right: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:right:!selected {\n"
"    margin-left: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:left, QTabBar::tab:right {\n"
"    min-height: 8ex;\n"
"    margin-bottom: -1px;\n"
"    padding: 10px 5px 10px 5px;\n"
"}\n"
"\n"
"QTabBar::tab:left:selected {\n"
"    border-left-color: none;\n"
"}\n"
"\n"
"QTabBar::tab:right:selected {\n"
"    border-right-color: none;\n"
"}\n"
"\n"
"QTabBar::tab:left:last, QTabBar::tab:right:last,\n"
"QTabBar::tab:left:only-one, QTabBar::tab:right:only-one {\n"
"    margin-bottom: 0;\n"
"}"));
        main_chat->setCentralWidget(centralwidget);

        retranslateUi(main_chat);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(main_chat);
    } // setupUi

    void retranslateUi(QMainWindow *main_chat)
    {
        main_chat->setWindowTitle(QApplication::translate("main_chat", "MainWindow", nullptr));
        label_bg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class main_chat: public Ui_main_chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_CHAT_H
