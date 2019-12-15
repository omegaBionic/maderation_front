#include "controller.h"
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QThread>
#include <QCoreApplication>
#include "../CORE/core_menu.h"


Controller::Controller(QObject *parent) : QObject(parent)
{
    _toolbar = new menu_toolbar();
    _login = nullptr;
    _init = nullptr;
    _menu = nullptr;
    _chat = nullptr;
    _main_user = nullptr;
    QObject::connect(_toolbar, &menu_toolbar::user_mgt, this, &Controller::toolbar_user_mgt);
    QObject::connect(_toolbar, &menu_toolbar::logoff, this, &Controller::toolbar_logoff);
    QObject::connect(_toolbar, &menu_toolbar::menu, this, &Controller::toolbar_menu);
    QObject::connect(_toolbar, &menu_toolbar::archive, this, &Controller::toolbar_archive);
    QObject::connect(_toolbar, &menu_toolbar::messages, this, &Controller::toolbar_messages);
    _user = new bdd_USER("polop",true,"test","test","test",0,"test@test.com","polop");
}

Main_Login* Controller::getLogin(){
    return _login;
}

bdd_USER* Controller::getUser(){
    return _user;
}

void Controller::cleanup(int win){
    qDebug() << "--- cleanup ---";

    if(win == 0){ //login page

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
        if(_chat != nullptr){
            qDebug() << "effacage du chat";
            _chat->close();
            _chat = nullptr;
        }
        if(_main_user != nullptr){
            qDebug() << "effacage du main_user";
            _main_user->close();
            _main_user = nullptr;
        }

    }
    else if(win == 1){ //menu page
        if(_login != nullptr){
            qDebug() << "effacage de la login";
            _login->close();
            _login = nullptr;
        }
        if(_chat != nullptr){
            qDebug() << "effacage du chat";
            _chat->close();
            _chat = nullptr;
        }
        if(_init != nullptr){
            qDebug() << "effacage du init";
            _init->close();
            _init = nullptr;
        }
        if(_main_user != nullptr){
            qDebug() << "effacage du main_user";
            _main_user->close();
            _main_user = nullptr;
        }
    }
    else if(win == 2){ //chat page
        if(_login != nullptr){
            qDebug() << "effacage de la login";
            _login->close();
            _login = nullptr;
        }
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
        if(_main_user != nullptr){
            qDebug() << "effacage du main_user";
            _main_user->close();
            _main_user = nullptr;
        }
    }
    else if(win == 3){ //user page
        if(_login != nullptr){
            qDebug() << "effacage de la login";
            _login->close();
            _login = nullptr;
        }
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
        if(_chat != nullptr){
            qDebug() << "effacage du chat";
            _chat->close();
            _chat = nullptr;
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

    _toolbar->setWindow("menu");
    core_menu* menu = new core_menu(this);
    QVector<bdd_PROJECT>* listProject = menu->getProject(*_user);
    qDebug() << "amount of project : " << listProject->count();
    _menu = new Main_Menu(0, _toolbar, listProject);
    QObject::connect(_menu, &Main_Menu::Initialized, this, &Controller::cleanup);
    QObject::connect(_menu, &Main_Menu::deleteProject, this, &Controller::delete_project);
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

    qDebug() << "ouverture du chat";
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

    qDebug() << "ouverture du user_management";
    QVector<bdd_USER>* listUser = new QVector<bdd_USER>();
    listUser->append(bdd_USER("0606060606",true,"polop","test","polop",0,"polop@polop.polop","polop"));
    listUser->append(bdd_USER("1111111111",false,"test","test","polop",0,"polop@polop.polop","polop"));
    listUser->append(bdd_USER("9999999999",true,"truc","test","polop",0,"polop@polop.polop","polop"));
    listUser->append(bdd_USER("2222222222",false,"polop","test","polop",0,"polop@polop.polop","polop"));
    listUser->append(bdd_USER("0685485241",true,"machin","test","polop",0,"polop@polop.polop","polop"));
    listUser->append(bdd_USER("7582410522",false,"polop","test","polop",0,"polop@polop.polop","polop"));

    _toolbar->setWindow("user");
    _main_user = new main_user(0, _toolbar, listUser);
    QObject::connect(_main_user, &main_user::Initialized, this, &Controller::cleanup);
    _main_user->showFullScreen();
}


void Controller::delete_project(int ID) {
    core_menu* menu = new core_menu();
    bdd_PROJECT project = menu->getProject(ID);
    menu->deleteProject(project);
}
