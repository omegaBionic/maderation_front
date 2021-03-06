#include "menu_toolbar.h"
#include "ui_menu_toolbar.h"

menu_toolbar::menu_toolbar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu_toolbar)
{
    _isHided = false;
    ui->setupUi(this);
    _window = -1;
    _admin = false;
}

menu_toolbar::~menu_toolbar()
{
    delete ui;
}

void menu_toolbar::setWindow(QString win){
    if(win == "menu"){
        _window = 0;
    }else if (win == "chat"){
        _window = 1;
    }else if (win == "user"){
        _window = 2;
    }else if (win == "template"){
        _window = 3;
    }else if (win == "quotation"){
        _window = 4;
    }else{
        _window = 0;
    }

}



void menu_toolbar::resizeAll(){
    QRect win = this->geometry();

    _width = win.width()/128;
    _height = win.height()/72;
    int widthButton = 16*_width;
    int heightButton = 36*_height;

    if(_window == 0){
        ui->btn_menu->setVisible(false);
        ui->btn_user->setVisible(true);
        ui->btn_logoff->setVisible(true);
        ui->btn_archive->setVisible(true);
        ui->btn_messages->setVisible(true);

        ui->btn_archive->setGeometry(26*_width, 34*_height, widthButton, heightButton);
        ui->btn_archive->setIcon(QPixmap(":/pictures/img/logo archive.png").scaled(widthButton, heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_archive->setIconSize(QSize(widthButton, heightButton));
        ui->btn_messages->setGeometry(46*_width, 34*_height, widthButton, heightButton);
        ui->btn_messages->setIcon(QPixmap(":/pictures/img/logo message.png").scaled(widthButton,heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_messages->setIconSize(QSize(widthButton, heightButton));
        ui->btn_user->setGeometry(66*_width, 34*_height, widthButton, heightButton);
        ui->btn_user->setIcon(QPixmap(":/pictures/img/logo user.png").scaled(widthButton,heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_user->setIconSize(QSize(widthButton, heightButton));
        ui->btn_logoff->setGeometry(86*_width, 34*_height, widthButton, heightButton);
        ui->btn_logoff->setIcon(QPixmap(":/pictures/img/logo logoff.png").scaled(widthButton, heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_logoff->setIconSize(QSize(widthButton, heightButton));
        ui->btn_hide->setGeometry(56*_width, 14*_height, 18*_width, 18*_height);
        ui->btn_hide->setIcon(QPixmap(":/pictures/img/logo_hide.png").scaled(18*_width, 18*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_hide->setIconSize(QSize(18*_width, 18*_height));
        ui->push_background->setGeometry(16*_width, 32*_height, 96*_width, 40*_height);
        ui->push_background->setStyleSheet("QPushButton{color: white;border-radius: "+QString::number(ui->push_background->height()/2)+"px;background-color: rgb(93, 82, 82);}");

    }else if(_window == 1){
        ui->btn_menu->setVisible(true);
        ui->btn_user->setVisible(true);
        ui->btn_logoff->setVisible(true);
        ui->btn_archive->setVisible(true);
        ui->btn_messages->setVisible(false);

        ui->btn_menu->setGeometry(26*_width, 34*_height, widthButton, heightButton);
        ui->btn_menu->setIcon(QPixmap(":/pictures/img/logo accueil.png").scaled(widthButton,heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_menu->setIconSize(QSize(widthButton, heightButton));
        ui->btn_archive->setGeometry(46*_width, 34*_height, widthButton, heightButton);
        ui->btn_archive->setIcon(QPixmap(":/pictures/img/logo archive.png").scaled(widthButton, heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_archive->setIconSize(QSize(widthButton, heightButton));
        ui->btn_user->setGeometry(66*_width, 34*_height, widthButton, heightButton);
        ui->btn_user->setIcon(QPixmap(":/pictures/img/logo user.png").scaled(widthButton,heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_user->setIconSize(QSize(widthButton, heightButton));
        ui->btn_logoff->setGeometry(86*_width, 34*_height, widthButton, heightButton);
        ui->btn_logoff->setIcon(QPixmap(":/pictures/img/logo logoff.png").scaled(widthButton, heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_logoff->setIconSize(QSize(widthButton, heightButton));
        ui->btn_hide->setGeometry(56*_width, 14*_height, 18*_width, 18*_height);
        ui->btn_hide->setIcon(QPixmap(":/pictures/img/logo_hide.png").scaled(18*_width, 18*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_hide->setIconSize(QSize(18*_width, 18*_height));
        ui->push_background->setGeometry(16*_width, 32*_height, 96*_width, 40*_height);
        ui->push_background->setStyleSheet("QPushButton{color: white;border-radius: "+QString::number(ui->push_background->height()/2)+"px;background-color: rgb(93, 82, 82);}");

    }else if(_window == 2){
        ui->btn_menu->setVisible(true);
        ui->btn_user->setVisible(false);
        ui->btn_logoff->setVisible(true);
        ui->btn_archive->setVisible(true);
        ui->btn_messages->setVisible(true);

        ui->btn_menu->setGeometry(26*_width, 34*_height, widthButton, heightButton);
        ui->btn_menu->setIcon(QPixmap(":/pictures/img/logo accueil.png").scaled(widthButton,heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_menu->setIconSize(QSize(widthButton, heightButton));
        ui->btn_archive->setGeometry(46*_width, 34*_height, widthButton, heightButton);
        ui->btn_archive->setIcon(QPixmap(":/pictures/img/logo archive.png").scaled(widthButton, heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_archive->setIconSize(QSize(widthButton, heightButton));
        ui->btn_messages->setGeometry(66*_width, 34*_height, widthButton, heightButton);
        ui->btn_messages->setIcon(QPixmap(":/pictures/img/logo message.png").scaled(widthButton,heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_messages->setIconSize(QSize(widthButton, heightButton));
        ui->btn_logoff->setGeometry(86*_width, 34*_height, widthButton, heightButton);
        ui->btn_logoff->setIcon(QPixmap(":/pictures/img/logo logoff.png").scaled(widthButton, heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_logoff->setIconSize(QSize(widthButton, heightButton));
        ui->btn_hide->setGeometry(56*_width, 14*_height, 18*_width, 18*_height);
        ui->btn_hide->setIcon(QPixmap(":/pictures/img/logo_hide.png").scaled(18*_width, 18*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_hide->setIconSize(QSize(18*_width, 18*_height));
        ui->push_background->setGeometry(16*_width, 32*_height, 96*_width, 40*_height);
        ui->push_background->setStyleSheet("QPushButton{color: white;border-radius: "+QString::number(ui->push_background->height()/2)+"px;background-color: rgb(93, 82, 82);}");

    }else{

        ui->btn_menu->setVisible(true);
        ui->btn_user->setVisible(true);
        ui->btn_logoff->setVisible(true);
        ui->btn_archive->setVisible(true);
        ui->btn_messages->setVisible(true);
        ui->btn_menu->setGeometry(8*_width, 34*_height, widthButton, heightButton);
        ui->btn_menu->setIcon(QPixmap(":/pictures/img/logo accueil.png").scaled(widthButton, heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_menu->setIconSize(QSize(widthButton, heightButton));
        ui->btn_archive->setGeometry(32*_width, 34*_height, widthButton, heightButton);
        ui->btn_archive->setIcon(QPixmap(":/pictures/img/logo archive.png").scaled(widthButton, heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_archive->setIconSize(QSize(widthButton, heightButton));
        ui->btn_messages->setGeometry(56*_width, 34*_height, widthButton, heightButton);
        ui->btn_messages->setIcon(QPixmap(":/pictures/img/logo message.png").scaled(widthButton,heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_messages->setIconSize(QSize(widthButton, heightButton));
        ui->btn_user->setGeometry(80*_width, 34*_height, widthButton, heightButton);
        ui->btn_user->setIcon(QPixmap(":/pictures/img/logo user.png").scaled(widthButton,heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_user->setIconSize(QSize(widthButton, heightButton));
        ui->btn_logoff->setGeometry(104*_width, 34*_height, widthButton, heightButton);
        ui->btn_logoff->setIcon(QPixmap(":/pictures/img/logo logoff.png").scaled(widthButton, heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_logoff->setIconSize(QSize(widthButton, heightButton));
        ui->btn_hide->setGeometry(55*_width, 14*_height, 18*_width, 18*_height);
        ui->btn_hide->setIcon(QPixmap(":/pictures/img/logo_hide.png").scaled(18*_width, 18*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_hide->setIconSize(QSize(18*_width, 18*_height));
        ui->push_background->setGeometry(0*_width, 32*_height, 128*_width, 40*_height);
        ui->push_background->setStyleSheet("QPushButton{color: white;border-radius: "+QString::number(ui->push_background->height()/2)+"px;background-color: rgb(93, 82, 82);}");
    }
}


void menu_toolbar::resizeAllNonAdmin(){

    ui->btn_archive->setVisible(false);
    ui->btn_user->setVisible(false);
    QRect win = this->geometry();

    _width = win.width()/128;
    _height = win.height()/72;
    int widthButton = 16*_width;
    int heightButton = 36*_height;

    if(_window == 0){
        ui->btn_menu->setVisible(false);
        ui->btn_logoff->setVisible(true);
        ui->btn_messages->setVisible(true);

        ui->btn_messages->setGeometry(46*_width, 34*_height, widthButton, heightButton);
        ui->btn_messages->setIcon(QPixmap(":/pictures/img/logo message.png").scaled(widthButton,heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_messages->setIconSize(QSize(widthButton, heightButton));
        ui->btn_logoff->setGeometry(66*_width, 34*_height, widthButton, heightButton);
        ui->btn_logoff->setIcon(QPixmap(":/pictures/img/logo logoff.png").scaled(widthButton, heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_logoff->setIconSize(QSize(widthButton, heightButton));
        ui->btn_hide->setGeometry(56*_width, 14*_height, 18*_width, 18*_height);
        ui->btn_hide->setIcon(QPixmap(":/pictures/img/logo_hide.png").scaled(18*_width, 18*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_hide->setIconSize(QSize(18*_width, 18*_height));
        ui->push_background->setGeometry(40*_width, 32*_height, 48*_width, 40*_height);
        ui->push_background->setStyleSheet("QPushButton{color: white;border-radius: "+QString::number(ui->push_background->height()/2)+"px;background-color: rgb(93, 82, 82);}");

    }else if(_window == 1){
        ui->btn_menu->setVisible(true);
        ui->btn_logoff->setVisible(true);
        ui->btn_messages->setVisible(false);

        ui->btn_menu->setGeometry(46*_width, 34*_height, widthButton, heightButton);
        ui->btn_menu->setIcon(QPixmap(":/pictures/img/logo accueil.png").scaled(widthButton,heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_menu->setIconSize(QSize(widthButton, heightButton));
        ui->btn_logoff->setGeometry(66*_width, 34*_height, widthButton, heightButton);
        ui->btn_logoff->setIcon(QPixmap(":/pictures/img/logo logoff.png").scaled(widthButton, heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_logoff->setIconSize(QSize(widthButton, heightButton));
        ui->btn_hide->setGeometry(56*_width, 14*_height, 18*_width, 18*_height);
        ui->btn_hide->setIcon(QPixmap(":/pictures/img/logo_hide.png").scaled(18*_width, 18*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_hide->setIconSize(QSize(18*_width, 18*_height));
        ui->push_background->setGeometry(40*_width, 32*_height, 48*_width, 40*_height);
        ui->push_background->setStyleSheet("QPushButton{color: white;border-radius: "+QString::number(ui->push_background->height()/2)+"px;background-color: rgb(93, 82, 82);}");

    }else if(_window == 2){
        ui->btn_menu->setVisible(true);
        ui->btn_logoff->setVisible(true);
        ui->btn_messages->setVisible(true);

        ui->btn_menu->setGeometry(36*_width, 34*_height, widthButton, heightButton);
        ui->btn_menu->setIcon(QPixmap(":/pictures/img/logo accueil.png").scaled(widthButton,heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_menu->setIconSize(QSize(widthButton, heightButton));
        ui->btn_archive->setGeometry(56*_width, 34*_height, widthButton, heightButton);
        ui->btn_archive->setIcon(QPixmap(":/pictures/img/logo archive.png").scaled(widthButton, heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_archive->setIconSize(QSize(widthButton, heightButton));
        ui->btn_logoff->setGeometry(76*_width, 34*_height, widthButton, heightButton);
        ui->btn_logoff->setIcon(QPixmap(":/pictures/img/logo logoff.png").scaled(widthButton, heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_logoff->setIconSize(QSize(widthButton, heightButton));
        ui->btn_hide->setGeometry(56*_width, 14*_height, 18*_width, 18*_height);
        ui->btn_hide->setIcon(QPixmap(":/pictures/img/logo_hide.png").scaled(18*_width, 18*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_hide->setIconSize(QSize(18*_width, 18*_height));
        ui->push_background->setGeometry(28*_width, 32*_height, 72*_width, 40*_height);
        ui->push_background->setStyleSheet("QPushButton{color: white;border-radius: "+QString::number(ui->push_background->height()/2)+"px;background-color: rgb(93, 82, 82);}");

    }else{
        ui->btn_menu->setVisible(true);
        ui->btn_logoff->setVisible(true);
        ui->btn_messages->setVisible(true);

        ui->btn_menu->setGeometry(36*_width, 34*_height, widthButton, heightButton);
        ui->btn_menu->setIcon(QPixmap(":/pictures/img/logo accueil.png").scaled(widthButton,heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_menu->setIconSize(QSize(widthButton, heightButton));
        ui->btn_archive->setGeometry(56*_width, 34*_height, widthButton, heightButton);
        ui->btn_archive->setIcon(QPixmap(":/pictures/img/logo archive.png").scaled(widthButton, heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_archive->setIconSize(QSize(widthButton, heightButton));
        ui->btn_logoff->setGeometry(76*_width, 34*_height, widthButton, heightButton);
        ui->btn_logoff->setIcon(QPixmap(":/pictures/img/logo logoff.png").scaled(widthButton, heightButton,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_logoff->setIconSize(QSize(widthButton, heightButton));
        ui->btn_hide->setGeometry(56*_width, 14*_height, 18*_width, 18*_height);
        ui->btn_hide->setIcon(QPixmap(":/pictures/img/logo_hide.png").scaled(18*_width, 18*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_hide->setIconSize(QSize(18*_width, 18*_height));
        ui->push_background->setGeometry(28*_width, 32*_height, 72*_width, 40*_height);
        ui->push_background->setStyleSheet("QPushButton{color: white;border-radius: "+QString::number(ui->push_background->height()/2)+"px;background-color: rgb(93, 82, 82);}");
    }
}

void menu_toolbar::resizeEvent(QResizeEvent *){
    // format 16:9 only for the moment
    if(_admin){
        this->resizeAll();
    }else{
        this->resizeAllNonAdmin();
    }


}
void menu_toolbar::on_btn_hide_clicked()
{
    _isHided = !_isHided;
    if(_isHided){
        ui->btn_hide->setGeometry(56*_width, 52*_height, 18*_width, 18*_height);
        ui->btn_hide->setIcon(QPixmap(":/pictures/img/logo_show.png").scaled(18*_width, 18*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_hide->setIconSize(QSize(18*_width, 18*_height));
        ui->btn_menu->setVisible(false);
        ui->btn_user->setVisible(false);
        ui->btn_logoff->setVisible(false);
        ui->btn_archive->setVisible(false);
        ui->btn_messages->setVisible(false);
        ui->push_background->setVisible(false);

    }else{
        ui->btn_hide->setGeometry(56*_width, 14*_height, 18*_width, 18*_height);
        ui->btn_hide->setIcon(QPixmap(":/pictures/img/logo_hide.png").scaled(18*_width, 18*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        ui->btn_hide->setIconSize(QSize(18*_width, 18*_height));
        ui->btn_menu->setVisible(true);
        ui->btn_user->setVisible(true);
        ui->btn_logoff->setVisible(true);
        ui->btn_archive->setVisible(true);
        ui->btn_messages->setVisible(true);
        ui->push_background->setVisible(true);

    }
}

void menu_toolbar::on_btn_archive_clicked()
{
    emit(archive());
}

void menu_toolbar::on_btn_logoff_clicked()
{
    emit(logoff());
}

void menu_toolbar::on_btn_messages_clicked()
{
    emit(messages());
}

void menu_toolbar::on_btn_menu_clicked()
{
    emit(menu());
}

void menu_toolbar::on_btn_user_clicked()
{
    emit(user_mgt());
}

void menu_toolbar::setAdmin(bool val){
    _admin = val;
}

bool menu_toolbar::isAdmin(){
    return _admin;
}
