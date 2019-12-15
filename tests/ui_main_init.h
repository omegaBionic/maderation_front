/********************************************************************************
** Form generated from reading UI file 'main_init.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_INIT_H
#define UI_MAIN_INIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_init
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_titre;
    QLabel *label_info;
    QProgressBar *progressBar;

    void setupUi(QMainWindow *main_init)
    {
        if (main_init->objectName().isEmpty())
            main_init->setObjectName(QString::fromUtf8("main_init"));
        main_init->resize(800, 600);
        centralwidget = new QWidget(main_init);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 791, 601));
        label_titre = new QLabel(centralwidget);
        label_titre->setObjectName(QString::fromUtf8("label_titre"));
        label_titre->setGeometry(QRect(270, 90, 221, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("Futura Md BT"));
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_titre->setFont(font);
        label_titre->setStyleSheet(QString::fromUtf8("\n"
"font: 36px;"));
        label_titre->setAlignment(Qt::AlignCenter);
        label_info = new QLabel(centralwidget);
        label_info->setObjectName(QString::fromUtf8("label_info"));
        label_info->setGeometry(QRect(280, 300, 221, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Futura LT"));
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_info->setFont(font1);
        label_info->setStyleSheet(QString::fromUtf8("font: 18px \"Futura LT\";"));
        label_info->setAlignment(Qt::AlignCenter);
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(290, 200, 201, 61));
        progressBar->setStyleSheet(QString::fromUtf8("QProgressBar:horizontal {\n"
"border: 1px solid gray;\n"
"border-radius: 3px;\n"
"padding: 1px;\n"
"}\n"
"QProgressBar::chunk:horizontal {\n"
"border-radius: 10%;\n"
"border-image: url(DATA_IMG/loading_img/loading_leaf.png);\n"
"}"));
        progressBar->setMaximum(2000);
        progressBar->setValue(0);
        progressBar->setTextVisible(false);
        main_init->setCentralWidget(centralwidget);

        retranslateUi(main_init);

        QMetaObject::connectSlotsByName(main_init);
    } // setupUi

    void retranslateUi(QMainWindow *main_init)
    {
        main_init->setWindowTitle(QApplication::translate("main_init", "MainWindow", nullptr));
        label->setText(QString());
        label_titre->setText(QApplication::translate("main_init", "INITIALISATION", nullptr));
        label_info->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class main_init: public Ui_main_init {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_INIT_H
