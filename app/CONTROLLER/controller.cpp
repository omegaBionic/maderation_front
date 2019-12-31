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
    _chat = nullptr;
    QObject::connect(_toolbar, &menu_toolbar::user_mgt, this, &Controller::toolbar_user_mgt);
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
    qDebug() << "[controller] --- cleanup ---";

    if(win == 0){ //login page

        if(_menu != nullptr){
            qDebug() << "[controller] effacage du menu";
            _menu->close();
            _menu = nullptr;
        }
        if(_init != nullptr){
            qDebug() << "[controller] effacage du init";
            _init->close();
            _init = nullptr;
        }
        if(_chat != nullptr){
            qDebug() << "[controller] effacage du chat";
            _chat->close();
            _chat = nullptr;
        }
    }else if(win == 1){ //menu page
        if(_login != nullptr){
            qDebug() << "[controller] effacage de la login";
            _login->close();
            _login = nullptr;
        }
        if(_chat != nullptr){
            qDebug() << "[controller] effacage du chat";
            _chat->close();
            _chat = nullptr;
        }
        if(_init != nullptr){
            qDebug() << "[controller] effacage du init";
            _init->close();
            _init = nullptr;
        }
    }else if(win == 2){ //chat page
        if(_login != nullptr){
            qDebug() << "[controller] effacage de la login";
            _login->close();
            _login = nullptr;
        }
        if(_menu != nullptr){
            qDebug() << "[controller] effacage du menu";
            _menu->close();
            _menu = nullptr;
        }
        if(_init != nullptr){
            qDebug() << "[controller] effacage du init";
            _init->close();
            _init = nullptr;
        }
    }
}

void Controller::init_folder(int step){
    qDebug() << "[controller] step : "+QString::number(step);
    if(step == 0){

        qDebug() << "[controller] checking folder";
        _init->Check_folder();
    }else if(step == 1){

        qDebug() << "[controller] checking connexion";
        if( _init->checkConnection()){

            this->init_folder(2);
        }else{
            //gestion offline a rajouter
            //gestion offline a rajouter
            //gestion offline a rajouter
            this->init_folder(2);
        }
    }else if(step == 2){

        qDebug() << "[controller] ending init";
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

    qDebug() << "[controller] " << user + " , "+ pwd;
    _toolbar->setWindow("menu");
    _menu = new Main_Menu(0, _toolbar);
    QObject::connect(_menu, &Main_Menu::Initialized, this, &Controller::cleanup);
    _menu->showFull();
}

void Controller::toolbar_menu(){

    _toolbar->setWindow("menu");
    _menu = new Main_Menu(0, _toolbar);
    QObject::connect(_menu, &Main_Menu::Initialized, this, &Controller::cleanup);
    _menu->showFull();

}

void Controller::toolbar_archive(){

    Main_Menu *m = new Main_Menu(0, _toolbar);
    m->showFull();

}

void Controller::toolbar_messages(){

    qDebug() << "[controller] ouverture du chat";
    QVector<bdd_CHAT>* listChat = new QVector<bdd_CHAT>();
    listChat->append(bdd_CHAT(0,"test","11 novembre 2019", "test"));
    listChat->append(bdd_CHAT(0,"test","12 novembre 2019", "polop"));
    listChat->append(bdd_CHAT(0,"test","13 novembre 2019", "test"));
    listChat->append(bdd_CHAT(0,"test","14 novembre 2019", "polop"));
    listChat->append(bdd_CHAT(0,"test","15 novembre 2019", "test"));

    _chat = new main_chat(0, _toolbar, listChat, _user->getUsername());
    _toolbar->setWindow("chat");
    QObject::connect(_chat, &main_chat::Initialized, this, &Controller::cleanup);
    _chat->showFullScreen();

}

void Controller::toolbar_logoff(){

    this->launchLogin();

}

void Controller::toolbar_user_mgt(){

}
