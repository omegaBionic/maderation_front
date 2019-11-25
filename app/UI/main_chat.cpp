#include "main_chat.h"
#include "ui_main_chat.h"
#include "form_messages.h"
#include <QDebug>

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
        QVector<bdd_MESSAGE>* listMessage = new QVector<bdd_MESSAGE>();
        listMessage->append(bdd_MESSAGE("11 novembre 2100", "this is a message", chat.getIdChat(),"toto", "0"));
        listMessage->append(bdd_MESSAGE("12 novembre 2100", "this is not a message", chat.getIdChat(),chat.getUserUsernameAsReceiver(), "0"));
        listMessage->append(bdd_MESSAGE("13 novembre 2100", "this is maybe a message", chat.getIdChat(),"toto", "0"));
        listMessage->append(bdd_MESSAGE("14 novembre 2100", "this is sometimes a message", chat.getIdChat(),chat.getUserUsernameAsReceiver(), "0"));
        listMessage->append(bdd_MESSAGE("15 novembre 2100", "this is strangely a message", chat.getIdChat(),"toto", "0"));
        ui->tabWidget->addTab(new Form_messages(this, listMessage, chat.getTitle(), _user),chat.getTitle() + "("+chat.getUserUsernameAsReceiver()+")");
    }

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
    _menu->setGeometry(42*_width, 62*_height, 48*_width, 12*_height);



}
