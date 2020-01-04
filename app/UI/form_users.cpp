#include "form_users.h"
#include "ui_form_users.h"

Form_users::Form_users(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_users)
{
    ui->setupUi(this);
}

Form_users::Form_users(QWidget *parent, bdd_USER* user) :
    QWidget(parent),
    ui(new Ui::Form_users)
{
    ui->setupUi(this);
    _user = user;

    ui->lineEdit_email->setText(_user->getMail());
    ui->lineEdit_phone->setText(_user->getPhoneNumber());
    ui->lineEdit_lastname->setText(_user->getLastName());
    ui->lineEdit_firstname->setText(_user->getFirstName());

    if(_user->getIsActive()){
        ui->checkBox_active->setChecked(true);
    }

}

Form_users::~Form_users()
{
    delete ui;
}


void Form_users::resizeEvent(QResizeEvent *){
    // format 16:9 only for the moment
    QRect win = this->geometry();
    _width = win.width()/128;
    _height = win.height()/72;
    ui->groupBox_roles->setGeometry(90*_width, 10*_height, 20*_width, 40*_height);
    ui->verticalLayout->setGeometry(QRect(0*_width, 0*_height, 20*_width, 40*_height));
    ui->lineEdit_firstname->setGeometry(3*_width, 10*_height, 30*_width, 6*_height);
    ui->lineEdit_lastname->setGeometry(3*_width, 20*_height, 30*_width, 6*_height);
    ui->lineEdit_email->setGeometry(3*_width, 30*_height, 30*_width, 6*_height);
    ui->lineEdit_phone->setGeometry(3*_width, 40*_height, 30*_width, 6*_height);
    ui->checkBox_active->setGeometry(3*_width, 50*_height, 30*_width, 4*_height);
    ui->pushButton_reset->setGeometry(86*_width, 64*_height, 10*_width, 10*_height);

    ui->pushButton_delete->setGeometry(98*_width, 64*_height, 10*_width, 10*_height);

    ui->pushButton_validate->setGeometry(110*_width, 64*_height, 10*_width, 10*_height);

    ui->pushButton_reset_pwd->setGeometry(122*_width, 64*_height, 10*_width, 10*_height);

    ui->comboBox_shop->setGeometry(40*_width, 10*_height, 20*_width, 6*_height);

}
