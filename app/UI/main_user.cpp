#include "main_user.h"
#include "ui_main_user.h"
#include <QDebug>
#include "dialog_critical.h"
#include "dialog_new_user.h"
#include "form_users.h"
#include "../CORE/core_user_management.h"
#include "../CORE/api_get_request.h"

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
    _menu->setParent(this);

    _listUsers = *list_User;

    this->setUsers();

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
    ui->pushButton->setGeometry(115*_width, 5*_height, 6*_width, 6*_height);
    int height_toolbox = ui->scrollArea->height() - 2*_height + (_height * ui->toolBox->count());
    ui->toolBox->setGeometry(0*_width, 0*_height, ui->scrollAreaWidgetContents->width() - _width, height_toolbox);
    ui->scrollAreaWidgetContents->setGeometry(13*_width, 11*_height, 100*_width, height_toolbox);

    ui->pushButton_power->setGeometry(124*_width, 0*_height ,4*_width, 4*_height);
    _menu->setGeometry(42*_width, 62*_height, 48*_width, 12*_height);

}

void main_user::on_pushButton_power_clicked()
{
    Dialog_Critical *c = new Dialog_Critical(this,"Exit ?", "êtes vous sûr de vouloir quitter l'application ?", "question");
    int result = c->exec();
    qDebug() << "result du exit : "<< result;
    if(result == QDialog::Accepted){
        this->close();
    }
}

void main_user::on_pushButton_clicked()
{
    Dialog_new_user* d = new Dialog_new_user(this);

    if(d->exec() == QDialog::Accepted){
        this->reloadUsers(0);
    }
}

void main_user::setUsers(){
    int index = ui->toolBox->currentIndex();
    while(ui->toolBox->count() > 0){
        ui->toolBox->removeItem(0);
    }
    core_user_management* core = new core_user_management();

    QVector<bdd_USER> listUsers = core->getUsers();
    _listUsers = listUsers;

    _listUIUsers = new QVector<Form_users*>();
    for(int i = 0; i< _listUsers.count();i++){
        bdd_USER user = _listUsers.at(i);
        _listUIUsers->append(new Form_users(this, user));

    }

    for(int i = 0; i< _listUIUsers->count();i++){
        Form_users* form = _listUIUsers->at(i);
        bdd_USER user = _listUsers.at(i);
        QObject::connect(form, &Form_users::UsersUpdated, this, &main_user::reloadUsers);
        ui->toolBox->addItem(form, user.getUsername());
    }
    ui->toolBox->setCurrentIndex(index);
}

void main_user::reloadUsers(int status){
    if(status == 0){

        Dialog_Critical* d = new Dialog_Critical(this, "Success", "User added successfully", "information");
        d->show();
    }else if (status == 1){

        Dialog_Critical* d = new Dialog_Critical(this, "Success", "User deleted successfully", "information");
        d->show();
    }else if (status == 2){

        Dialog_Critical* d = new Dialog_Critical(this, "Success", "User modified successfully", "information");
        d->show();
    }
    this->wait(500,500);
    api_get_request* api = new api_get_request();
    QObject::connect(api, &api_get_request::downloadended, this, &main_user::reloadTable);
    api->get_table_role();
    api->get_table_user();
}

void main_user::reloadTable(QString table){
    qDebug() << "[main_user] got " << table << "up";
    if(table == "User"){

        this->setUsers();
    }else if (table == "Role"){

        this->setUsers();
    }


}


void main_user::wait(int time, int interval){
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
