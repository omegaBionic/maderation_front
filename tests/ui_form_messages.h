/********************************************************************************
** Form generated from reading UI file 'form_messages.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_MESSAGES_H
#define UI_FORM_MESSAGES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_messages
{
public:
    QLabel *label;
    QLabel *label_bg;
    QPushButton *pushButton;
    QPlainTextEdit *plainTextEdit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *Form_messages)
    {
        if (Form_messages->objectName().isEmpty())
            Form_messages->setObjectName(QString::fromUtf8("Form_messages"));
        Form_messages->resize(900, 342);
        Form_messages->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color: #00000000;\n"
"border: 2px;\n"
"}"));
        label = new QLabel(Form_messages);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(360, -10, 181, 111));
        QFont font;
        font.setFamily(QString::fromUtf8("Futura Md BT"));
        font.setPointSize(24);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font: 24pt \"Futura Md BT\";"));
        label_bg = new QLabel(Form_messages);
        label_bg->setObjectName(QString::fromUtf8("label_bg"));
        label_bg->setGeometry(QRect(0, 10, 55, 16));
        pushButton = new QPushButton(Form_messages);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(730, 290, 93, 28));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        plainTextEdit = new QPlainTextEdit(Form_messages);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(40, 240, 371, 87));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Futura Lt BT"));
        font1.setPointSize(10);
        plainTextEdit->setFont(font1);
        plainTextEdit->setStyleSheet(QString::fromUtf8(""));
        scrollArea = new QScrollArea(Form_messages);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(90, 90, 741, 121));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 741, 121));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(Form_messages);

        QMetaObject::connectSlotsByName(Form_messages);
    } // setupUi

    void retranslateUi(QWidget *Form_messages)
    {
        Form_messages->setWindowTitle(QApplication::translate("Form_messages", "Form", nullptr));
        label->setText(QApplication::translate("Form_messages", "title", nullptr));
        label_bg->setText(QString());
        pushButton->setText(QString());
        plainTextEdit->setPlaceholderText(QApplication::translate("Form_messages", "max 240 characters...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_messages: public Ui_Form_messages {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_MESSAGES_H
