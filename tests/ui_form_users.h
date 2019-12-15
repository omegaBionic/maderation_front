/********************************************************************************
** Form generated from reading UI file 'form_users.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_USERS_H
#define UI_FORM_USERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_users
{
public:
    QComboBox *comboBox_shop;
    QPushButton *pushButton_validate;
    QPushButton *pushButton_reset;
    QPushButton *pushButton_delete;
    QLineEdit *lineEdit_firstname;
    QLineEdit *lineEdit_lastname;
    QLineEdit *lineEdit_email;
    QLineEdit *lineEdit_phone;
    QPushButton *pushButton_reset_pwd;
    QCheckBox *checkBox_active;
    QGroupBox *groupBox_roles;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_user;
    QCheckBox *checkBox_admin;
    QCheckBox *checkBox_super_admin;

    void setupUi(QWidget *Form_users)
    {
        if (Form_users->objectName().isEmpty())
            Form_users->setObjectName(QString::fromUtf8("Form_users"));
        Form_users->resize(1009, 637);
        QFont font;
        font.setFamily(QString::fromUtf8("Futura Lt BT"));
        font.setPointSize(10);
        Form_users->setFont(font);
        comboBox_shop = new QComboBox(Form_users);
        comboBox_shop->addItem(QString());
        comboBox_shop->addItem(QString());
        comboBox_shop->addItem(QString());
        comboBox_shop->addItem(QString());
        comboBox_shop->addItem(QString());
        comboBox_shop->setObjectName(QString::fromUtf8("comboBox_shop"));
        comboBox_shop->setGeometry(QRect(360, 60, 211, 31));
        comboBox_shop->setFont(font);
        comboBox_shop->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        pushButton_validate = new QPushButton(Form_users);
        pushButton_validate->setObjectName(QString::fromUtf8("pushButton_validate"));
        pushButton_validate->setGeometry(QRect(800, 540, 151, 71));
        pushButton_validate->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-image: url(:/pictures/img/validate_user.png);\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	border-image: url(:/pictures/img/validate_user_hover.png);\n"
"\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	border-image: url(:/pictures/img/validate_user_pressed.png);\n"
"\n"
"}"));
        pushButton_reset = new QPushButton(Form_users);
        pushButton_reset->setObjectName(QString::fromUtf8("pushButton_reset"));
        pushButton_reset->setGeometry(QRect(400, 530, 111, 91));
        pushButton_reset->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-image: url(:/pictures/img/reset.png);\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	border-image: url(:/pictures/img/reset_hover.png);\n"
"\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	border-image: url(:/pictures/img/reset_pressed.png);\n"
"\n"
"}"));
        pushButton_delete = new QPushButton(Form_users);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setGeometry(QRect(640, 560, 131, 71));
        pushButton_delete->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-image: url(:/pictures/img/button_trash.png);\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	border-image: url(:/pictures/img/button_trash_hover.png);\n"
"\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	border-image: url(:/pictures/img/button_trash_pressed.png);\n"
"\n"
"}"));
        lineEdit_firstname = new QLineEdit(Form_users);
        lineEdit_firstname->setObjectName(QString::fromUtf8("lineEdit_firstname"));
        lineEdit_firstname->setGeometry(QRect(40, 70, 113, 22));
        lineEdit_firstname->setFont(font);
        lineEdit_firstname->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_lastname = new QLineEdit(Form_users);
        lineEdit_lastname->setObjectName(QString::fromUtf8("lineEdit_lastname"));
        lineEdit_lastname->setGeometry(QRect(40, 110, 191, 22));
        lineEdit_lastname->setFont(font);
        lineEdit_lastname->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_email = new QLineEdit(Form_users);
        lineEdit_email->setObjectName(QString::fromUtf8("lineEdit_email"));
        lineEdit_email->setGeometry(QRect(40, 150, 201, 22));
        lineEdit_email->setFont(font);
        lineEdit_email->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_email->setMaxLength(100);
        lineEdit_phone = new QLineEdit(Form_users);
        lineEdit_phone->setObjectName(QString::fromUtf8("lineEdit_phone"));
        lineEdit_phone->setGeometry(QRect(40, 180, 211, 22));
        lineEdit_phone->setFont(font);
        lineEdit_phone->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_phone->setMaxLength(10);
        pushButton_reset_pwd = new QPushButton(Form_users);
        pushButton_reset_pwd->setObjectName(QString::fromUtf8("pushButton_reset_pwd"));
        pushButton_reset_pwd->setGeometry(QRect(510, 530, 101, 91));
        pushButton_reset_pwd->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-image: url(:/pictures/img/reset_password.png);\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	border-image: url(:/pictures/img/reset_pwd_hover.png);\n"
"\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	border-image: url(:/pictures/img/reset_pwd_pressed.png);\n"
"\n"
"}"));
        checkBox_active = new QCheckBox(Form_users);
        checkBox_active->setObjectName(QString::fromUtf8("checkBox_active"));
        checkBox_active->setGeometry(QRect(50, 230, 131, 20));
        checkBox_active->setFont(font);
        checkBox_active->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"  margin-left: 4px;\n"
"  height: 16px;\n"
"  width: 16px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"  image: url(:/pictures/img/checkBox_unchecked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover, QCheckBox::indicator:unchecked:focus, QCheckBox::indicator:unchecked:pressed {\n"
"  border: none;\n"
"  image: url(:/pictures/img/checkBox_unchecked_hover.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"  image: url(:/pictures/img/checkBox_checked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:hover, QCheckBox::indicator:checked:focus, QCheckBox::indicator:checked:pressed {\n"
"  border: none;\n"
"  image: url(:/pictures/img/checkBox_checked_hover.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:disabled {\n"
"  image: url(:/pictures/img/checkBox_disabled.png);\n"
"}\n"
"\n"
"\n"
"QCheckBox::indicator:checked:disabled {\n"
"  image: url(:/pictures/img/checkBox_checked_disabled.png);\n"
"}\n"
""));
        checkBox_active->setChecked(false);
        groupBox_roles = new QGroupBox(Form_users);
        groupBox_roles->setObjectName(QString::fromUtf8("groupBox_roles"));
        groupBox_roles->setGeometry(QRect(660, 40, 191, 281));
        verticalLayoutWidget = new QWidget(groupBox_roles);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 30, 160, 211));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox_user = new QCheckBox(verticalLayoutWidget);
        checkBox_user->setObjectName(QString::fromUtf8("checkBox_user"));
        checkBox_user->setFont(font);
        checkBox_user->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"  margin-left: 4px;\n"
"  height: 16px;\n"
"  width: 16px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"  image: url(:/pictures/img/checkBox_unchecked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover, QCheckBox::indicator:unchecked:focus, QCheckBox::indicator:unchecked:pressed {\n"
"  border: none;\n"
"  image: url(:/pictures/img/checkBox_unchecked_hover.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"  image: url(:/pictures/img/checkBox_checked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:hover, QCheckBox::indicator:checked:focus, QCheckBox::indicator:checked:pressed {\n"
"  border: none;\n"
"  image: url(:/pictures/img/checkBox_checked_hover.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:disabled {\n"
"  image: url(:/pictures/img/checkBox_disabled.png);\n"
"}\n"
"\n"
"\n"
"QCheckBox::indicator:checked:disabled {\n"
"  image: url(:/pictures/img/checkBox_checked_disabled.png);\n"
"}\n"
""));

        verticalLayout->addWidget(checkBox_user);

        checkBox_admin = new QCheckBox(verticalLayoutWidget);
        checkBox_admin->setObjectName(QString::fromUtf8("checkBox_admin"));
        checkBox_admin->setFont(font);
        checkBox_admin->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"  margin-left: 4px;\n"
"  height: 16px;\n"
"  width: 16px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"  image: url(:/pictures/img/checkBox_unchecked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover, QCheckBox::indicator:unchecked:focus, QCheckBox::indicator:unchecked:pressed {\n"
"  border: none;\n"
"  image: url(:/pictures/img/checkBox_unchecked_hover.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"  image: url(:/pictures/img/checkBox_checked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:hover, QCheckBox::indicator:checked:focus, QCheckBox::indicator:checked:pressed {\n"
"  border: none;\n"
"  image: url(:/pictures/img/checkBox_checked_hover.png);\n"
"}\n"
"\n"
"\n"
"QCheckBox::indicator:unchecked:disabled {\n"
"  image: url(:/pictures/img/checkBox_disabled.png);\n"
"}\n"
"\n"
"\n"
"QCheckBox::indicator:checked:disabled {\n"
"  image: url(:/pictures/img/checkBox_checked_disabled.png);\n"
"}\n"
""));

        verticalLayout->addWidget(checkBox_admin);

        checkBox_super_admin = new QCheckBox(verticalLayoutWidget);
        checkBox_super_admin->setObjectName(QString::fromUtf8("checkBox_super_admin"));
        checkBox_super_admin->setFont(font);
        checkBox_super_admin->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"  margin-left: 4px;\n"
"  height: 16px;\n"
"  width: 16px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"  image: url(:/pictures/img/checkBox_unchecked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover, QCheckBox::indicator:unchecked:focus, QCheckBox::indicator:unchecked:pressed {\n"
"  border: none;\n"
"  image: url(:/pictures/img/checkBox_unchecked_hover.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"  image: url(:/pictures/img/checkBox_checked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:hover, QCheckBox::indicator:checked:focus, QCheckBox::indicator:checked:pressed {\n"
"  border: none;\n"
"  image: url(:/pictures/img/checkBox_checked_hover.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:disabled {\n"
"  image: url(:/pictures/img/checkBox_disabled.png);\n"
"}\n"
"\n"
"\n"
"QCheckBox::indicator:checked:disabled {\n"
"  image: url(:/pictures/img/checkBox_checked_disabled.png);\n"
"}\n"
""));

        verticalLayout->addWidget(checkBox_super_admin);


        retranslateUi(Form_users);

        QMetaObject::connectSlotsByName(Form_users);
    } // setupUi

    void retranslateUi(QWidget *Form_users)
    {
        Form_users->setWindowTitle(QApplication::translate("Form_users", "Form", nullptr));
        comboBox_shop->setItemText(0, QApplication::translate("Form_users", "shop", nullptr));
        comboBox_shop->setItemText(1, QApplication::translate("Form_users", "test", nullptr));
        comboBox_shop->setItemText(2, QApplication::translate("Form_users", "polop", nullptr));
        comboBox_shop->setItemText(3, QApplication::translate("Form_users", "123", nullptr));
        comboBox_shop->setItemText(4, QApplication::translate("Form_users", "truc", nullptr));

        pushButton_validate->setText(QString());
        pushButton_reset->setText(QString());
        pushButton_delete->setText(QString());
        lineEdit_firstname->setText(QString());
        lineEdit_firstname->setPlaceholderText(QApplication::translate("Form_users", "FirstName", nullptr));
        lineEdit_lastname->setPlaceholderText(QApplication::translate("Form_users", "LastName", nullptr));
        lineEdit_email->setPlaceholderText(QApplication::translate("Form_users", "Email", nullptr));
        lineEdit_phone->setPlaceholderText(QApplication::translate("Form_users", "Phone Number", nullptr));
        pushButton_reset_pwd->setText(QString());
        checkBox_active->setText(QApplication::translate("Form_users", "IS Active", nullptr));
        groupBox_roles->setTitle(QApplication::translate("Form_users", "R\303\264les", nullptr));
        checkBox_user->setText(QApplication::translate("Form_users", "User", nullptr));
        checkBox_admin->setText(QApplication::translate("Form_users", "Admin", nullptr));
        checkBox_super_admin->setText(QApplication::translate("Form_users", "SuperAdmin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_users: public Ui_Form_users {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_USERS_H
