#include "menu_toolbar.h"
#include "ui_menu_toolbar.h"

menu_toolbar::menu_toolbar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu_toolbar)
{
    ui->setupUi(this);
}

menu_toolbar::~menu_toolbar()
{
    delete ui;
}



void menu_toolbar::resizeEvent(QResizeEvent *){
    // format 16:9 only for the moment
    QRect win = this->geometry();

    _width = win.width()/128;
    _height = win.height()/72;
    ui->btn_menu->setGeometry(4*_width, 0*_height, 24*_width, 72*_height);
    ui->btn_menu->setIcon(QPixmap(":/pictures/img/logo accueil.png").scaled(24*_width, 72*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->btn_archive->setGeometry(28*_width, 0*_height, 24*_width, 72*_height);
    ui->btn_archive->setIcon(QPixmap(":/pictures/img/logo archive.png").scaled(24*_width, 72*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->btn_messages->setGeometry(52*_width, 0*_height, 24*_width, 72*_height);
    ui->btn_messages->setIcon(QPixmap(":/pictures/img/logo message.png").scaled(24*_width, 72*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->btn_alert->setGeometry(76*_width, 0*_height, 24*_width, 72*_height);
    ui->btn_alert->setIcon(QPixmap(":/pictures/img/logo accueil.png").scaled(24*_width, 72*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->btn_logoff->setGeometry(100*_width, 0*_height, 24*_width, 72*_height);
    ui->btn_logoff->setIcon(QPixmap(":/pictures/img/logo logoff.png").scaled(24*_width, 72*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

}
