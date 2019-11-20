#include "controller.h"
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QThread>
#include <QCoreApplication>


Controller::Controller(QObject *parent) : QObject(parent)
{
    _toolbar = new menu_toolbar();
    _login = nullptr;
    _init = nullptr;
    _menu = nullptr;
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
    qDebug() << "--- cleanup ---";
    if(win == 0){

        if(_menu != nullptr){
            qDebug() << "effacage du menu";
            _menu->close();
            _menu = nullptr;
        }
        if(_init != nullptr){
            qDebug() << "effacage du init";
            _init->close();
            _init = nullptr;
        }
    }else if(win == 1){
        if(_login != nullptr){
            qDebug() << "effacage de la login";
            _login->close();
            _login = nullptr;
        }
        if(_init != nullptr){
            qDebug() << "effacage du init";
            _init->close();
            _init = nullptr;
        }
    }
}

void Controller::init_folder(int step){
    qDebug() << "step : "+QString::number(step);
    if(step == 0){

        qDebug() << "checking folder";
        _init->Check_folder();
    }else if(step == 1){

        qDebug() << "checking connexion";
        if( _init->checkConnection()){

            this->init_folder(2);
        }else{
            //gestion offline a rajouter
            //gestion offline a rajouter
            //gestion offline a rajouter
            this->init_folder(2);
        }
    }else if(step == 2){

        qDebug() << "ending init";
        _init->endInit();

    }else if(step == 3){
        this->launchLogin();
    }
}

void Controller::launchLogin(){
    _login = new Main_Login();
    QObject::connect(_login, &Main_Login::check_login, this, &Controller::login);
    QObject::connect(_login, &Main_Login::forgot_password, this, &Controller::login_forgot_password);
    QObject::connect(_login, &Main_Login::Initialized, this, &Controller::cleanup);
    _login->showFull();
}

int Controller::init(){


    try{

        _init = new main_init();
        QObject::connect(_init, &main_init::Initialized, this, &Controller::init_folder);
        _init->showFullScreen();

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

    this->launchLogin();

}

void Controller::toolbar_alert(){

    Main_Menu *m = new Main_Menu(0, _toolbar);
    m->showFull();

}
