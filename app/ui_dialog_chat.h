/********************************************************************************
** Form generated from reading UI file 'dialog_chat.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_CHAT_H
#define UI_DIALOG_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog_chat
{
public:
    QPushButton *validate;
    QLabel *label_title;
    QPushButton *cancel;
    QFrame *line;
    QComboBox *comboBox;
    QLineEdit *lineEdit;

    void setupUi(QDialog *Dialog_chat)
    {
        if (Dialog_chat->objectName().isEmpty())
            Dialog_chat->setObjectName(QString::fromUtf8("Dialog_chat"));
        Dialog_chat->resize(934, 634);
        Dialog_chat->setStyleSheet(QString::fromUtf8("QDialog{\n"
"border-image: url(:/pictures/img/background_dialog.png);\n"
"}"));
        validate = new QPushButton(Dialog_chat);
        validate->setObjectName(QString::fromUtf8("validate"));
        validate->setEnabled(true);
        validate->setGeometry(QRect(520, 380, 100, 50));
        validate->setCursor(QCursor(Qt::PointingHandCursor));
        validate->setMouseTracking(true);
        validate->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-image: url(:/pictures/img/validate.png);\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	border-image: url(:/pictures/img/validate_hover.png);\n"
"\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	border-image: url(:/pictures/img/validate_pressed.png);\n"
"\n"
"}"));
        validate->setCheckable(true);
        validate->setChecked(false);
        validate->setAutoDefault(false);
        label_title = new QLabel(Dialog_chat);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setGeometry(QRect(161, 31, 60, 60));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_title->sizePolicy().hasHeightForWidth());
        label_title->setSizePolicy(sizePolicy);
        label_title->setMinimumSize(QSize(60, 60));
        label_title->setMaximumSize(QSize(999999, 999999));
        label_title->setBaseSize(QSize(60, 60));
        label_title->setLayoutDirection(Qt::LeftToRight);
        label_title->setStyleSheet(QString::fromUtf8("color:black;\n"
"border-image : \"\";\n"
"\n"
"font: 16pt \"Futura Lt BT\";"));
        label_title->setAlignment(Qt::AlignCenter);
        cancel = new QPushButton(Dialog_chat);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(630, 380, 100, 50));
        cancel->setCursor(QCursor(Qt::PointingHandCursor));
        cancel->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-image: url(:/pictures/img/cancel.png);\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	border-image: url(:/pictures/img/cancel_hover.png);\n"
"\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	border-image: url(:/pictures/img/cancel_pressed.png);\n"
"\n"
"}"));
        cancel->setCheckable(true);
        line = new QFrame(Dialog_chat);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(160, 100, 579, 60));
        line->setMinimumSize(QSize(0, 60));
        line->setStyleSheet(QString::fromUtf8("color: rgb(135, 97, 79);\n"
"padding: (-50,-50,-50,-50);\n"
"border-image:\"\";"));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(5);
        line->setMidLineWidth(0);
        line->setFrameShape(QFrame::HLine);
        comboBox = new QComboBox(Dialog_chat);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(480, 230, 231, 22));
        QFont font;
        font.setFamily(QString::fromUtf8("Futura Lt BT"));
        font.setPointSize(10);
        comboBox->setFont(font);
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"  background-color: #00000000;\n"
"  padding-top: 2px;\n"
"  /* This QLineEdit fix  103, 111 */\n"
"  padding-bottom: 2px;\n"
"  /* This QLineEdit fix  103, 111 */\n"
"  padding-left: 4px;\n"
"  padding-right: 4px;\n"
"  border-style: solid;\n"
"  border-left: 2px solid rgb(141, 121, 99);\n"
"  border-bottom: 2px solid rgb(141, 121, 99);\n"
"  border-radius: 2%;\n"
"}\n"
"\n"
"\n"
"QComboBox QAbstractItemView {\n"
"  background-color:  rgb(181, 163, 136);\n"
"  border-radius: 4px;\n"
"  border: 1px solid #32414B;\n"
"  selection-color: #148CD2;\n"
"  selection-background-color: rgb(255, 211, 179);\n"
"}\n"
"\n"
"\n"
"QComboBox::indicator {\n"
"  background-color:transparent;\n"
"  selection-background-color: transparent;\n"
"  color: transparent;\n"
"  selection-color: transparent;\n"
"  /* Needed to remove indicator - fix #132 */\n"
"}\n"
"\n"
"QComboBox::indicator:alternate {\n"
"  background: #19232D;\n"
"}\n"
"\n"
"QComboBox::item:alternate {\n"
"  background: #19232D;\n"
"}\n"
"\n"
"QCombo"
                        "Box::item:checked {\n"
"  font-weight: bold;\n"
"}\n"
"\n"
"QComboBox::item:selected {\n"
"  border: 0px solid transparent;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"  subcontrol-origin: padding;\n"
"  subcontrol-position: top right;\n"
"  width: 20px;\n"
"  border-left-width: 0px;\n"
"  border-left-color: #32414B;\n"
"  border-left-style: solid;\n"
"  border-top-right-radius: 3px;\n"
"  border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"  image:url(:/pictures/img/down_arrow.png);\n"
"height: 20%;\n"
"width: 20%;\n"
"}\n"
"\n"
"QComboBox::down-arrow:on, QComboBox::down-arrow:hover, QComboBox::down-arrow:focus {\n"
"  image: url(:/pictures/img/down_arrow_hover.png);\n"
"height: 20%;\n"
"width: 20%;\n"
"}\n"
""));
        lineEdit = new QLineEdit(Dialog_chat);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(480, 290, 231, 22));
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"  background-color: #00000000;\n"
"  padding-top: 2px;\n"
"  /* This QLineEdit fix  103, 111 */\n"
"  padding-bottom: 2px;\n"
"  /* This QLineEdit fix  103, 111 */\n"
"  padding-left: 4px;\n"
"  padding-right: 4px;\n"
"  border-style: solid;\n"
"  border-left: 2px solid rgb(141, 121, 99);\n"
"  border-bottom: 2px solid rgb(141, 121, 99);\n"
"  border-radius: 2%;\n"
"}\n"
""));

        retranslateUi(Dialog_chat);

        QMetaObject::connectSlotsByName(Dialog_chat);
    } // setupUi

    void retranslateUi(QDialog *Dialog_chat)
    {
        Dialog_chat->setWindowTitle(QApplication::translate("Dialog_chat", "Dialog", nullptr));
        validate->setText(QString());
        label_title->setText(QString());
        cancel->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("Dialog_chat", "Title", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_chat: public Ui_Dialog_chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_CHAT_H
