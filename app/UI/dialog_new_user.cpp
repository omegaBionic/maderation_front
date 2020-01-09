#include "dialog_new_user.h"
#include "ui_dialog_new_user.h"
#include "form_users.h"

Dialog_new_user::Dialog_new_user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_new_user)
{
    ui->setupUi(this);
    _form = new Form_users(this, "new");
    this->setWindowFlags(Qt::FramelessWindowHint);
    int width = parent->width()/128;
    int height = parent->height()/72;
    ui->label_title->setText("NEW USER");
    this->setGeometry(42*width,12*height,50*width - (50*width%128),52*height - (52*height%72));
    ui->validate->raise();
    ui->cancel->raise();
}


Dialog_new_user::~Dialog_new_user()
{
    delete ui;
}


void Dialog_new_user::resizeEvent(QResizeEvent *){
    // format 16:9 only for the moment
    QRect win = this->geometry();

    _width = win.width()/128;
    _height = win.height()/72;
    ui->line->setGeometry(0,5*_height, 128*_width, _height);
    ui->cancel->setGeometry(95*_width,62*_height, 15*_width, 8*_height);
    ui->validate->setGeometry(111*_width,62*_height, 15*_width, 8*_height);
    ui->label_title->setGeometry(42*_width,1*_height, 40*_width, 5*_height);
    _form->setGeometry(0*_width,10*_height, 128*_width, 60*_height);

}

void Dialog_new_user::on_validate_clicked()
{
    _form->addUser();
    this->accept();
}

void Dialog_new_user::on_cancel_clicked()
{
    this->close();
}
