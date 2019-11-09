/********************************************************************************
** Form generated from reading UI file 'main_login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_LOGIN_H
#define UI_MAIN_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Main_Login
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QLineEdit *lineEdit_user;
    QLineEdit *lineEdit_pwd;
    QCheckBox *chk_remember;
    QFrame *line;
    QPushButton *btn_login;
    QLabel *label_title;
    QPushButton *btn_forgot;
    QLabel *background;

    void setupUi(QMainWindow *Main_Login)
    {
        if (Main_Login->objectName().isEmpty())
            Main_Login->setObjectName(QString::fromUtf8("Main_Login"));
        Main_Login->resize(857, 620);
        Main_Login->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(Main_Login);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 531, 521));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../../Users/XN5798/Pictures/woodhouse.jpg")));
        label_2->setScaledContents(true);
        lineEdit_user = new QLineEdit(centralwidget);
        lineEdit_user->setObjectName(QString::fromUtf8("lineEdit_user"));
        lineEdit_user->setGeometry(QRect(230, 190, 251, 31));
        lineEdit_user->setStyleSheet(QString::fromUtf8("background:none;\n"
"border:none;\n"
"border-bottom:1px solid black;\n"
"font-size:18px;\n"
"background-color: #00000000;"));
        lineEdit_pwd = new QLineEdit(centralwidget);
        lineEdit_pwd->setObjectName(QString::fromUtf8("lineEdit_pwd"));
        lineEdit_pwd->setGeometry(QRect(230, 250, 251, 31));
        lineEdit_pwd->setStyleSheet(QString::fromUtf8("background:none;\n"
"border:none;\n"
"border-bottom:1px solid black;\n"
"font-size:18px;\n"
"background-color: #00000000;"));
        lineEdit_pwd->setEchoMode(QLineEdit::Password);
        chk_remember = new QCheckBox(centralwidget);
        chk_remember->setObjectName(QString::fromUtf8("chk_remember"));
        chk_remember->setGeometry(QRect(230, 310, 111, 17));
        chk_remember->setCursor(QCursor(Qt::PointingHandCursor));
        chk_remember->setStyleSheet(QString::fromUtf8("font-size:12px;"));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(257, 420, 211, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        btn_login = new QPushButton(centralwidget);
        btn_login->setObjectName(QString::fromUtf8("btn_login"));
        btn_login->setGeometry(QRect(250, 370, 221, 31));
        btn_login->setCursor(QCursor(Qt::PointingHandCursor));
        btn_login->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font-size:12px;\n"
"background:#11b91c;\n"
"Border-radius:12px;\n"
"border: 2px solid black;\n"
"color:white;\n"
"}"));
        label_title = new QLabel(centralwidget);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setGeometry(QRect(250, 50, 221, 61));
        QPalette palette;
        QBrush brush(QColor(254, 254, 254, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        label_title->setPalette(palette);
        label_title->setLayoutDirection(Qt::LeftToRight);
        label_title->setStyleSheet(QString::fromUtf8("font: 24pt \"Futura LT\";\n"
""));
        label_title->setAlignment(Qt::AlignCenter);
        btn_forgot = new QPushButton(centralwidget);
        btn_forgot->setObjectName(QString::fromUtf8("btn_forgot"));
        btn_forgot->setGeometry(QRect(300, 450, 131, 41));
        btn_forgot->setCursor(QCursor(Qt::PointingHandCursor));
        btn_forgot->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font-size:12px;\n"
"background:rgba(0,0,0,0);\n"
"Border-radius:12px;\n"
"border: 0px solid black;\n"
"color:black;\n"
"}"));
        background = new QLabel(centralwidget);
        background->setObjectName(QString::fromUtf8("background"));
        background->setGeometry(QRect(550, 160, 121, 121));
        Main_Login->setCentralWidget(centralwidget);
        background->raise();
        label_2->raise();
        lineEdit_user->raise();
        lineEdit_pwd->raise();
        chk_remember->raise();
        line->raise();
        btn_login->raise();
        label_title->raise();
        btn_forgot->raise();

        retranslateUi(Main_Login);

        QMetaObject::connectSlotsByName(Main_Login);
    } // setupUi

    void retranslateUi(QMainWindow *Main_Login)
    {
        Main_Login->setWindowTitle(QApplication::translate("Main_Login", "MainWindow", nullptr));
        label_2->setText(QString());
        lineEdit_user->setText(QString());
        lineEdit_user->setPlaceholderText(QApplication::translate("Main_Login", "Username", nullptr));
        lineEdit_pwd->setText(QString());
        lineEdit_pwd->setPlaceholderText(QApplication::translate("Main_Login", "Password", nullptr));
        chk_remember->setText(QApplication::translate("Main_Login", "Remember me", nullptr));
        btn_login->setText(QApplication::translate("Main_Login", "Log In", nullptr));
        label_title->setText(QApplication::translate("Main_Login", "WOOD IN STOCK", nullptr));
        btn_forgot->setText(QApplication::translate("Main_Login", "Forgot Password ?", nullptr));
        background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Main_Login: public Ui_Main_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_LOGIN_H
