#include "controller.h"
#include <QDebug>

Controller::Controller(QObject *parent) : QObject(parent)
{
    _user = new User("test","0606060606",true,"test","test","test","test@test.test",0);
    _toolbar = new menu_toolbar();
    _login = NULL;
    _menu = NULL;
    QObject::connect(_toolbar, &menu_toolbar::alerts, this, &Controller::toolbar_alert);
    QObject::connect(_toolbar, &menu_toolbar::logoff, this, &Controller::toolbar_logoff);
    QObject::connect(_toolbar, &menu_toolbar::menu, this, &Controller::toolbar_menu);
    QObject::connect(_toolbar, &menu_toolbar::archive, this, &Controller::toolbar_archive);
    QObject::connect(_toolbar, &menu_toolbar::messages, this, &Controller::toolbar_messages);
}

Main_Login* Controller::getLogin(){
    return _login;
}

User* Controller::getUser(){
    return _user;
}

void Controller::cleanup(){
    if(_menu != NULL){
        _menu->close();
        _menu = NULL;
    }
    if(_login != NULL){
        _login->close();
        _login = NULL;
    }
}

int Controller::init(){
    this->cleanup();
    _login = new Main_Login();
    QObject::connect(_login, &Main_Login::check_login, this, &Controller::login);
    _login->showFullScreen();
    return 0;
}

void Controller::login(QString user, QString pwd){

    qDebug() << user + " , "+ pwd;
    this->cleanup();
    _toolbar->setWindow(0);
    _menu = new Main_Menu(0, _toolbar);
    _menu->showFullScreen();
}

void Controller::toolbar_menu(){

    Main_Menu *m = new Main_Menu(0, _toolbar);
    m->showFullScreen();

}

void Controller::toolbar_archive(){

    Main_Menu *m = new Main_Menu(0, _toolbar);
    m->showFullScreen();

}

void Controller::toolbar_messages(){

    Main_Menu *m = new Main_Menu(0, _toolbar);
    m->showFullScreen();

}

void Controller::toolbar_logoff(){

    this->init();

}

void Controller::toolbar_alert(){

    Main_Menu *m = new Main_Menu(0, _toolbar);
    m->showFullScreen();

}
