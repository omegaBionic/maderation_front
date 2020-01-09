#include "dialog_chat.h"
#include "ui_dialog_chat.h"
#include "../CORE/core_user_management.h"
#include "../CORE/api_post_request.h"
#include "../CORE/core_messages.h"
#include "../DB_CLASSES/bdd_chat.h"

Dialog_chat::Dialog_chat(QWidget *parent, QString userName) :
    QDialog(parent),
    ui(new Ui::Dialog_chat)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);
    int width = parent->width()/128;
    int height = parent->height()/72;
    ui->label_title->setText("NEW CHAT");
    this->setGeometry(52*width,22*height,30*width - (30*width%128),32*height - (32*height%72));
    ui->validate->raise();
    ui->cancel->raise();
    _author = userName;
    core_user_management* core = new core_user_management();
    QVector<bdd_USER> listUsers = core->getUsers();

    for(int i = 0; i < listUsers.count(); i++){
        bdd_USER user = listUsers.at(i);

        if(user.getUsername() != userName){
            ui->comboBox->addItem(user.getUsername());
        }
    }


}

Dialog_chat::~Dialog_chat()
{
    delete ui;
}

void Dialog_chat::resizeEvent(QResizeEvent *){
    // format 16:9 only for the moment
    QRect win = this->geometry();

    _width = win.width()/128;
    _height = win.height()/72;
    ui->line->setGeometry(0,5*_height, 128*_width, _height);
    ui->cancel->setGeometry(76*_width,58*_height, 24*_width, 12*_height);
    ui->validate->setGeometry(102*_width,58*_height, 24*_width, 12*_height);
    ui->label_title->setGeometry(32*_width,1*_height, 60*_width, 5*_height);
    ui->lineEdit->setGeometry(24*_width, 20*_height, 70*_width, 8*_height);
    ui->comboBox->setGeometry(24*_width, 36*_height, 70*_width, 8*_height);
}

void Dialog_chat::on_cancel_clicked()
{
    this->close();
}

void Dialog_chat::on_validate_clicked()
{
    core_messages* core = new core_messages();
    bdd_CHAT chat = bdd_CHAT(core->getIDChat(), ui->comboBox->currentText(), _author, core->getTime(), ui->lineEdit->text());
    chat.getDict();
    api_post_request* api = new api_post_request();
    api->modifyData(chat, "add");
    this->accept();
}
