#include "controller.h"
#include <QDebug>

Controller::Controller(QObject *parent) : QObject(parent)
{
    _login = new Main_Login();
    _user = new bdd_USER("test",true,"test","test","test",0,"test@test.com","test");
    QObject::connect(_login, &Main_Login::check_login, this, &Controller::login);
}

Main_Login* Controller::getLogin(){
    return _login;
}

bdd_USER* Controller::getUser(){
    return _user;
}

int Controller::init(){
    _login->showFullScreen();
    return 0;
}

void Controller::login(QString user, QString pwd){

    qDebug() << user + " , "+ pwd;
}
