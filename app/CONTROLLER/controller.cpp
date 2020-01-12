#include "controller.h"
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QThread>
#include <QCoreApplication>
#include "../CORE/core_menu.h"
#include "../CORE/core_messages.h"
#include "../CORE/core_user_management.h"
#include "../CORE/core_login.h"
#include "../CORE/core_template.h"


Controller::Controller(QObject *parent) : QObject(parent)
{
    _toolbar = new menu_toolbar();
    _login = nullptr;
    _init = nullptr;
    _menu = nullptr;
    _chat = nullptr;
    _template = nullptr;
    _main_user = nullptr;
    _quotation = nullptr;
    QObject::connect(_toolbar, &menu_toolbar::user_mgt, this, &Controller::toolbar_user_mgt);
    QObject::connect(_toolbar, &menu_toolbar::logoff, this, &Controller::toolbar_logoff);
    QObject::connect(_toolbar, &menu_toolbar::menu, this, &Controller::toolbar_menu);
    QObject::connect(_toolbar, &menu_toolbar::archive, this, &Controller::toolbar_archive);
    QObject::connect(_toolbar, &menu_toolbar::messages, this, &Controller::toolbar_messages);
//    _user = new bdd_USER("polop",true,"test","test","test",0,"test@test.com","polop");
}

Main_Login* Controller::getLogin(){
    return _login;
}

bdd_USER* Controller::getUser(){
    return _user;
}

void Controller::cleanup(int win){
    qDebug() << "[controller] --- cleanup ---";
    try {
        if(win == 0){ //login page
            qDebug() << "from login";
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
            if(_main_user != nullptr){
                qDebug() << "[controller] effacage du main_user";
                _main_user->close();
                _main_user = nullptr;
            }
            if(_template != nullptr){
                qDebug() << "[controller] effacage du main_template";
                _template->close();
                _template = nullptr;
            }
            if(_quotation != nullptr){
                qDebug() << "[controller] effacage du quotation";
                _quotation->close();
                _quotation = nullptr;
            }


        }
        else if(win == 1){ //menu page
            qDebug() << "[controller] from menu";
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
            if(_main_user != nullptr){
                qDebug() << "[controller] effacage du main_user";
                _main_user->close();
                _main_user = nullptr;
            }
            if(_template != nullptr){
                qDebug() << "[controller] effacage du main_template";
                _template->close();
                _template = nullptr;
            }
            if(_quotation != nullptr){
                qDebug() << "[controller] effacage du quotation";
                _quotation->close();
                _quotation = nullptr;
            }
        }
        else if(win == 2){ //chat page
            qDebug() << "[controller] from chat";
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
            if(_main_user != nullptr){
                qDebug() << "[controller] effacage du main_user";
                _main_user->close();
                _main_user = nullptr;
            }
            if(_template != nullptr){
                qDebug() << "[controller] effacage du main_template";
                _template->close();
                _template = nullptr;
            }
            if(_quotation != nullptr){
                qDebug() << "[controller] effacage du quotation";
                _quotation->close();
                _quotation = nullptr;
            }
        }
        else if(win == 3){ //user page
            qDebug() << "[controller] from user mgt";
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
            if(_chat != nullptr){
                qDebug() << "[controller] effacage du chat";
                _chat->close();
                _chat = nullptr;
            }
            if(_template != nullptr){
                qDebug() << "[controller] effacage du main_template";
                _template->close();
                _template = nullptr;
            }
            if(_quotation != nullptr){
                qDebug() << "[controller] effacage du quotation";
                _quotation->close();
                _quotation = nullptr;
            }
        }
        else if(win == 4){ //template page
            qDebug() << "[controller] from template";
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
            if(_chat != nullptr){
                qDebug() << "[controller] effacage du chat";
                _chat->close();
                _chat = nullptr;
            }
            if(_main_user != nullptr){
                qDebug() << "[controller] effacage du main_user";
                _main_user->close();
                _main_user = nullptr;
            }
            if(_quotation != nullptr){
                qDebug() << "[controller] effacage du quotation";
                _quotation->close();
                _quotation = nullptr;
            }
        }
        else if(win == 5){ //quotation page
            qDebug() << "[controller] from quotation";
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
            if(_chat != nullptr){
                qDebug() << "[controller] effacage du chat";
                _chat->close();
                _chat = nullptr;
            }
            if(_main_user != nullptr){
                qDebug() << "[controller] effacage du main_user";
                _main_user->close();
                _main_user = nullptr;
            }
            if(_template != nullptr){
                qDebug() << "[controller] effacage du main_template";
                _template->close();
                _template = nullptr;
            }
        }
    } catch (...) {
        qDebug() << "[controller] Error : QwaitCondition probably";
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
    if(_login == nullptr){
        _login = new Main_Login();
        QObject::connect(_login, &Main_Login::check_login, this, &Controller::login);
        QObject::connect(_login, &Main_Login::forgot_password, this, &Controller::login_forgot_password);
        QObject::connect(_login, &Main_Login::Initialized, this, &Controller::cleanup);
        _login->showFull();
    }
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

    if(user == "" || pwd == ""){

        Dialog_Critical* error = new Dialog_Critical(nullptr, "Error", "Error: please enter username and password !", "critical");
        error->show();
        return;
    }

    qDebug() << "[controller] " << user + " , "+ pwd;

    core_login* login = new core_login();
    bdd_USER temp = login->getUser(user,pwd);
    qDebug()<< "username : " + temp.getUsername();
    if(temp.getUsername() == ""){
           Dialog_Critical* error = new Dialog_Critical(nullptr, "Error", "Error: wrong username or password...", "critical");
           error->show();
           return;
    }else{
        _user = new bdd_USER(temp.getPhoneNumber(), temp.getIsActive(),temp.getLastName(),temp.getPassword(), temp.getFirstName(), temp.getAddressIdAddress(), temp.getMail(), temp.getUsername());
        _user_roles = login->getRoles(_user);

        for(int i = 0; i<_user_roles.count(); i++){
            bdd_ROLE role = _user_roles.at(i);
            qDebug() << role.getLabel();
            if(role.getLabel()=="admin"){
                _toolbar->setAdmin(true);
            }
        }
        _toolbar->setWindow("menu");
        core_menu* menu = new core_menu();
        QVector<bdd_PROJECT>* listProject = menu->getProject(*_user);

        _menu = new Main_Menu(nullptr, _toolbar, listProject);
        QObject::connect(_menu, &Main_Menu::Initialized, this, &Controller::cleanup);
        QObject::connect(_menu, &Main_Menu::deleteProject, this, &Controller::delete_project);
        QObject::connect(_menu, &Main_Menu::button_clicked, this, &Controller::open_project_by_ID);
        _menu->showFull();
    }
}

void Controller::toolbar_menu(){

    _toolbar->setWindow("menu");
    core_menu* menu = new core_menu();
    QVector<bdd_PROJECT>* listProject = menu->getProject(*_user);
    _menu = new Main_Menu(nullptr, _toolbar, listProject);
    QObject::connect(_menu, &Main_Menu::Initialized, this, &Controller::cleanup);
    QObject::connect(_menu, &Main_Menu::deleteProject, this, &Controller::delete_project);
    QObject::connect(_menu, &Main_Menu::button_clicked, this, &Controller::open_project_by_ID);
    _menu->showFull();

}

void Controller::toolbar_archive(){

    Main_Menu *m = new Main_Menu(nullptr, _toolbar);
    m->showFull();

}

void Controller::toolbar_messages(){

    core_messages* msg = new core_messages();
    qDebug() << "[controller] ouverture du chat";

    QVector<bdd_CHAT> listChat = msg->getChats(_user->getUsername());
    _chat = new main_chat(nullptr, _toolbar, &listChat, _user->getUsername());
    _toolbar->setWindow("chat");
    QObject::connect(_chat, &main_chat::Initialized, this, &Controller::cleanup);
    _chat->showFullScreen();

}

void Controller::toolbar_logoff(){
    _user = nullptr;
    this->launchLogin();

}

void Controller::toolbar_user_mgt(){

    qDebug() << "ouverture du user_management";
    core_user_management* mgt = new core_user_management();
    QVector<bdd_USER> listUser = mgt->getUsers();
    _toolbar->setWindow("user");
    _main_user = new main_user(nullptr, _toolbar, &listUser);
    QObject::connect(_main_user, &main_user::Initialized, this, &Controller::cleanup);
    _main_user->showFullScreen();
}


void Controller::delete_project(int ID) {
    core_menu* menu = new core_menu();
    bdd_PROJECT project = menu->getProject(ID);
    menu->deleteProject(project);
}


void Controller::open_project_by_ID(int ID) {
    if(ID == -1){
        qDebug()<<"template to open";

        core_template* tpl = new core_template();
        QVector<bdd_PROJECT>* listProject = tpl->getTemplates();
        _toolbar->setWindow("template");
        _template = new main_template(nullptr, _toolbar, listProject, _user->getUsername());
        QObject::connect(_template, &main_template::Initialized, this, &Controller::cleanup);
        QObject::connect(_template, &main_template::deleteProject, this, &Controller::delete_project);
        QObject::connect(_template, &main_template::openProject, this, &Controller::open_project);
        _template->showFullScreen();
    }else{

        api_get_request* api = new api_get_request();
        QVector<bdd_PROJECT> listProject = api->parse_file_project();
        bdd_PROJECT project;
        for(int i = 0; i< listProject.count(); i++){
            bdd_PROJECT temp = listProject.at(i);
            if(temp.getIdProject().toInt() == ID){
                project = temp;
            }
        }
        this->open_project(project);
    }

}

void Controller::open_project(bdd_PROJECT project) {
        qDebug()<<"template to open";

        _toolbar->setWindow("quotation");
        _quotation = new Main_Quotation(nullptr, _toolbar, project);
        QObject::connect(_quotation, &Main_Quotation::Initialized, this, &Controller::cleanup);
        _quotation->showFullScreen();

}
