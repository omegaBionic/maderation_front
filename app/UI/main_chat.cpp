#include "main_chat.h"
#include "ui_main_chat.h"
#include "form_messages.h"
#include "../CORE/core_messages.h"
#include "../CORE/api_get_request.h"
#include <QDebug>
#include "dialog_critical.h"
#include "dialog_chat.h"

main_chat::main_chat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::main_chat)
{
    ui->setupUi(this);
}

main_chat::main_chat(QWidget *parent, menu_toolbar* m, QVector<bdd_CHAT>* listChat, QString username) :
    QMainWindow(parent),
    ui(new Ui::main_chat)
{
    ui->setupUi(this);
    _menu = m;
    _menu->setParent(this);

    _user = username;
    for(int i = 0; i < listChat->count(); i++){
        bdd_CHAT chat = listChat->at(i);
        core_messages* msg = new core_messages();

        QVector<bdd_MESSAGE> listMessage = msg->getMessages(chat.getIdChat());
        ui->tabWidget->addTab(new Form_messages(this, &listMessage, chat.getTitle(), _user, chat.getIdChat()),chat.getTitle() + "("+chat.getUserUsernameAsReceiver()+")");
    }

}

void main_chat::setAttributs(){
    int index = ui->tabWidget->currentIndex();
    while(ui->tabWidget->count() > 0){
        ui->tabWidget->removeTab(0);
    }
    core_messages* core = new core_messages();

    QVector<bdd_CHAT> listChat = core->getChats(_user);
    for(int i = 0; i < listChat.count(); i++){
        bdd_CHAT chat = listChat.at(i);
        core_messages* msg = new core_messages();

        QVector<bdd_MESSAGE> listMessage = msg->getMessages(chat.getIdChat());
        ui->tabWidget->addTab(new Form_messages(this, &listMessage, chat.getTitle(), _user, chat.getIdChat()),chat.getTitle() + "("+chat.getUserUsernameAsReceiver()+")");
    }

    ui->tabWidget->setCurrentIndex(index);
}



main_chat::~main_chat()
{
    delete ui;
}


bool main_chat::event(QEvent * e)
{
    if(e->type() == QEvent::HoverEnter){
        emit Initialized(2);
    }

    return QMainWindow::event(e) ;
}


void main_chat::resizeEvent(QResizeEvent *){
    // format 16:9 only for the moment
    QRect win = this->geometry();

    _width = win.width()/128;
    _height = win.height()/72;

    ui->label_bg->setGeometry(0*_width, 0*_height, 128*_width, 72*_height);
    ui->label_bg->setPixmap(QPixmap(":/pictures/img/background_messages.png").scaled(128*_width, 72*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->tabWidget->setGeometry(20*_width, 6*_height, 92*_width, 54*_height);

//    ui->scrollAreaWidgetContents->setGeometry(0*_width, 0*_height, 128*_width, ui->listWidget_title->height());
//    ui->scrollArea->setGeometry(0*_width, 0*_height, 128*_width, 60*_height);
//    ui->scrollArea->setWidget(ui->scrollAreaWidgetContents);
    ui->pushButton_power->setGeometry(124*_width, 0*_height ,4*_width, 4*_height);
    ui->pushButton_addChat->setGeometry(103*_width, 8*_height, 5*_width, 5*_height);
    _menu->setGeometry(42*_width, 62*_height, 48*_width, 12*_height);



}

void main_chat::on_pushButton_power_clicked()
{
    Dialog_Critical *c = new Dialog_Critical(this,"Exit ?", "êtes vous sûr de vouloir quitter l'application ?", "question");
    int result = c->exec();
    qDebug() << "result du exit : "<< result;
    if(result == QDialog::Accepted){
        this->close();
    }
}

void main_chat::on_pushButton_addChat_clicked()
{
    Dialog_chat* c = new Dialog_chat(this, _user);
    if(c->exec() == QDialog::Accepted){
        this->reloadChats(0);
    }
}


void main_chat::reloadChats(int status){
    if(status == 0){

        Dialog_Critical* d = new Dialog_Critical(this, "Success", "Chat added successfully", "information");
        d->show();
    }
    this->wait(500,500);
    api_get_request* api = new api_get_request();
    QObject::connect(api, &api_get_request::downloadended, this, &main_chat::reloadTable);
    api->get_table_chat();
}

void main_chat::reloadTable(QString table){
    qDebug() << "[main_chat] got " << table << "up";
    if(table == "Chat"){

        this->setAttributs();
    }


}


void main_chat::wait(int time, int interval){
    qDebug() << "waiting...";
    int timer = clock() + time;
    qDebug()<<clock();
    qDebug()<<timer;
    bool hasUpgrade = false;
    while(timer > clock()){
        qApp->processEvents();
        if(clock()%interval == 0){
            if(!hasUpgrade){
                hasUpgrade = true;
            }
        }else{
            hasUpgrade = false;
        }
    }
    qDebug() << "end of wait...";
}
