/********************************************************************************
** Form generated from reading UI file 'dialog_critical.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_CRITICAL_H
#define UI_DIALOG_CRITICAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Critical
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_title;
    QFrame *line;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *icon;
    QLabel *label_text;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *validate;
    QPushButton *cancel;

    void setupUi(QDialog *Dialog_Critical)
    {
        if (Dialog_Critical->objectName().isEmpty())
            Dialog_Critical->setObjectName(QString::fromUtf8("Dialog_Critical"));
        Dialog_Critical->resize(600, 434);
        Dialog_Critical->setStyleSheet(QString::fromUtf8("background-image: url(:/icon);\n"
"background-color:rgb(19,24,34);"));
        verticalLayoutWidget = new QWidget(Dialog_Critical);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 581, 411));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_title = new QLabel(verticalLayoutWidget);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_title->sizePolicy().hasHeightForWidth());
        label_title->setSizePolicy(sizePolicy);
        label_title->setMinimumSize(QSize(60, 60));
        label_title->setMaximumSize(QSize(999999, 999999));
        label_title->setBaseSize(QSize(60, 60));
        label_title->setLayoutDirection(Qt::LeftToRight);
        label_title->setStyleSheet(QString::fromUtf8("color:white;\n"
"\n"
"font: 16pt \"Futura Lt BT\";"));
        label_title->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_title);

        line = new QFrame(verticalLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(0, 60));
        line->setStyleSheet(QString::fromUtf8("color: rgb(30, 198, 184);\n"
"padding: (-50,-50,-50,-50);"));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(5);
        line->setMidLineWidth(0);
        line->setFrameShape(QFrame::HLine);

        verticalLayout->addWidget(line);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        icon = new QPushButton(verticalLayoutWidget);
        icon->setObjectName(QString::fromUtf8("icon"));
        icon->setMinimumSize(QSize(50, 50));
        icon->setStyleSheet(QString::fromUtf8("background-image:url(:\\icon);\n"
"\n"
"border-radius:1px;"));

        horizontalLayout_2->addWidget(icon, 0, Qt::AlignLeft);

        label_text = new QLabel(verticalLayoutWidget);
        label_text->setObjectName(QString::fromUtf8("label_text"));
        label_text->setStyleSheet(QString::fromUtf8("background-image:url(:\\icon);\n"
"color:white;\n"
"font: 12pt \"Futura Lt BT\";"));

        horizontalLayout_2->addWidget(label_text, 0, Qt::AlignLeft);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        validate = new QPushButton(verticalLayoutWidget);
        validate->setObjectName(QString::fromUtf8("validate"));
        validate->setEnabled(true);
        validate->setCursor(QCursor(Qt::PointingHandCursor));
        validate->setMouseTracking(true);
        validate->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(49, 121, 169, 255), stop:1 rgba(67, 167, 200, 255));\n"
"border-radius : 3px;\n"
"width : 100px;\n"
"height : 50px;\n"
"font: 10pt \"Futura Lt BT\";\n"
"color : rgb(255,255,255);"));
        validate->setCheckable(true);
        validate->setChecked(false);
        validate->setAutoDefault(false);

        horizontalLayout->addWidget(validate);

        cancel = new QPushButton(verticalLayoutWidget);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setCursor(QCursor(Qt::PointingHandCursor));
        cancel->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(49, 121, 169, 255), stop:1 rgba(67, 167, 200, 255));\n"
"border-radius : 3px;\n"
"width : 100px;\n"
"height : 50px;\n"
"font: 10pt \"Futura Lt BT\";\n"
"color : rgb(255,255,255);"));
        cancel->setCheckable(true);

        horizontalLayout->addWidget(cancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Dialog_Critical);

        QMetaObject::connectSlotsByName(Dialog_Critical);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Critical)
    {
        Dialog_Critical->setWindowTitle(QApplication::translate("Dialog_Critical", "Dialog", nullptr));
        label_title->setText(QString());
        icon->setText(QString());
        label_text->setText(QApplication::translate("Dialog_Critical", "TextLabel", nullptr));
        validate->setText(QApplication::translate("Dialog_Critical", "OK", nullptr));
        cancel->setText(QApplication::translate("Dialog_Critical", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Critical: public Ui_Dialog_Critical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_CRITICAL_H
