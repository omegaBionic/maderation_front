#include "main_user.h"
#include "ui_main_user.h"

main_user::main_user(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::main_user)
{
    ui->setupUi(this);
}

main_user::main_user(QWidget *parent, menu_toolbar* menu, QVector<bdd_USER>* list_User) :
    QMainWindow(parent),
    ui(new Ui::main_user)
{
    ui->setupUi(this);
    _menu = menu;

    _listUsers = list_User;


    _listUIUsers = new QVector<Form_users*>();
    ui->toolBox->removeItem(0);
    for(int i = 0; i< _listUsers->count();i++){
        bdd_USER user = _listUsers->at(i);
        _listUIUsers->append(new Form_users(this, &user));

    }

    for(int i = 0; i< _listUIUsers->count();i++){
        Form_users* form = _listUIUsers->at(i);
        bdd_USER user = _listUsers->at(i);
        ui->toolBox->addItem(form, user.getUsername());
    }
    ui->scrollArea->setWidgetResizable(false);

}

main_user::~main_user()
{
    delete ui;
}

bool main_user::event(QEvent * e)
{
    if(e->type() == QEvent::HoverEnter){
        emit Initialized(3);
    }

    return QMainWindow::event(e) ;
}

void main_user::resizeEvent(QResizeEvent *){
    // format 16:9 only for the moment
    QRect win = this->geometry();

    _width = win.width()/128;
    _height = win.height()/72;
    ui->label_bg->setGeometry(0*_width, 0*_height, 128*_width, 72*_height);
    ui->label_bg->setPixmap(QPixmap(":/pictures/img/background_users.png").scaled(128*_width, 72*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->label_titre->setGeometry(44*_width, 3*_height, 40*_width, 10*_height);
    ui->scrollArea->setGeometry((int)(13.7*_width), 11*_height, 101*_width, 50*_height);
    int height_toolbox = ui->scrollArea->height() + (_height * ui->toolBox->count());
    ui->toolBox->setGeometry(0*_width, 0*_height, ui->scrollAreaWidgetContents->width() - _width, height_toolbox);
    ui->scrollAreaWidgetContents->setGeometry(13*_width, 11*_height, 100*_width, height_toolbox);
    _menu->setGeometry(42*_width, 62*_height, 48*_width, 12*_height);


}
