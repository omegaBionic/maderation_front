#include "main_menu.h"
#include "ui_main_menu.h"

Main_Menu::Main_Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Main_Menu)
{
    ui->setupUi(this);
    _menu = new menu_toolbar(this);
}

Main_Menu::Main_Menu(QWidget *parent, menu_toolbar* m) :
    QMainWindow(parent),
    ui(new Ui::Main_Menu)
{
    ui->setupUi(this);
    _menu = m;
    _menu->setParent(this);
}

Main_Menu::~Main_Menu()
{
    delete ui;
}


void Main_Menu::resizeEvent(QResizeEvent *){
    // format 16:9 only for the moment
    QRect win = this->geometry();

    _width = win.width()/128;
    _height = win.height()/72;

    ui->background->setGeometry(0*_width, 0*_height, 128*_width, 72*_height);
    ui->background->setPixmap(QPixmap(":/pictures/img/background_1920.png").scaled(128*_width, 72*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));


    _menu->setGeometry(42*_width, 62*_height, 48*_width, 12*_height);

}
