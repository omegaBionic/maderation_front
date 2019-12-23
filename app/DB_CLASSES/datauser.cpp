#include "datauser.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
dataUser::dataUser(QString role,QString phoneNumber, bool isActive, QString lastname, QString password, QString firstname, int idAddress, QString mail, QString username)
{
    this->_role = role;

    this->_username = username;
    this->_phoneNumber = phoneNumber;
    this->_isActive = isActive;
    this->_password = password;
    this->_lastname = lastname;
    this->_firstname = firstname;
    this->_mail = mail;
    this->_IDAdress = idAddress;

}
dataUser::dataUser(){

}
dataUser::~dataUser(){

}
void dataUser::setRole(QString rl){
    _role = rl;
}
void dataUser::setPhoneNumber(QString phoneNb){
    _phoneNumber = phoneNb;
}
void dataUser::setIsActive(bool isAct){
    _isActive = isAct;
}
void dataUser::setPassword(QString pwd){
    _password = pwd;
}
void dataUser::setLastName(QString lastN){
    _lastname = lastN;
}
void dataUser::setMail(QString ml){
    _mail = ml;
}
void dataUser::setUsername(QString user){
    _username = user;
}
void dataUser::setFirstName(QString firstN){
    _firstname = firstN;
}
void dataUser::setIdAddress(int adrId){
    _IDAdress = adrId;
}


QString dataUser::getRole(){
    return _role;
}

QString dataUser::getPhoneNumber(){
    return _phoneNumber;
}
bool dataUser::getIsActive(){
    return _isActive;
}
QString dataUser::getPassword(){
    return _password;
}
QString dataUser::getLastName(){
    return _lastname;
}
QString dataUser::getMail(){
   return _mail;
}
QString dataUser::getUsername(){
    return _username;
}
QString dataUser::getFirstName(){
   return _firstname;
}
int dataUser::getAddressIdAddress(){
    return _IDAdress;
}
