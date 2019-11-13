#include "controller.h"
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QThread>

Controller::Controller(QObject *parent) : QObject(parent)
{
    _toolbar = new menu_toolbar();
    _login = NULL;
    _menu = NULL;
    QObject::connect(_toolbar, &menu_toolbar::alerts, this, &Controller::toolbar_alert);
    QObject::connect(_toolbar, &menu_toolbar::logoff, this, &Controller::toolbar_logoff);
    QObject::connect(_toolbar, &menu_toolbar::menu, this, &Controller::toolbar_menu);
    QObject::connect(_toolbar, &menu_toolbar::archive, this, &Controller::toolbar_archive);
    QObject::connect(_toolbar, &menu_toolbar::messages, this, &Controller::toolbar_messages);
    _user = new bdd_USER("test",true,"test","test","test",0,"test@test.com","test");
}

Main_Login* Controller::getLogin(){
    return _login;
}

bdd_USER* Controller::getUser(){
    return _user;
}

void Controller::cleanup(int win){
    qDebug() << "cleanup";
    if(win == 0){

        qDebug() << "effacage de la menu";
        if(_menu != NULL){
            _menu->hide();
            //_menu = NULL;
        }
    }else if(win == 1){
        qDebug() << "effacage de la login";
        if(_login != NULL){
            _login->hide();
            //_login = NULL;
        }
    }
}

int Controller::init(){
    try{
        _login = new Main_Login();
        QObject::connect(_login, &Main_Login::check_login, this, &Controller::login);
        QObject::connect(_login, &Main_Login::forgot_password, this, &Controller::login_forgot_password);
        QObject::connect(_login, &Main_Login::Initialized, this, &Controller::cleanup);
        _login->showFull();
        return 0;
    }
    catch( QString e){

        return 1;
    }

}



void Controller::login_forgot_password(){
    QDesktopServices::openUrl(QUrl("https://google.com"));
}


void Controller::login(QString user, QString pwd){

    qDebug() << user + " , "+ pwd;
    _toolbar->setWindow(0);
    _menu = new Main_Menu(0, _toolbar);
    QObject::connect(_menu, &Main_Menu::Initialized, this, &Controller::cleanup);
    _menu->showFull();
}

void Controller::toolbar_menu(){

    Main_Menu *m = new Main_Menu(0, _toolbar);
    m->showFull();

}

void Controller::toolbar_archive(){

    Main_Menu *m = new Main_Menu(0, _toolbar);
    m->showFull();

}

void Controller::toolbar_messages(){

    Main_Menu *m = new Main_Menu(0, _toolbar);
    m->showFull();

}

void Controller::toolbar_logoff(){

    this->init();

}

void Controller::toolbar_alert(){

    Main_Menu *m = new Main_Menu(0, _toolbar);
    m->showFull();

}
