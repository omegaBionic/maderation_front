#include "user.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
User::User(QString username, QString phoneNumber, bool isActive, QString password, QString lastName, QString firstName, QString mail, int IDAdress)
{
    this->_username = username;
    this->_phoneNumber = phoneNumber;
    this->_isActive = isActive;
    this->_password = password;
    this->_lastname = lastName;
    this->_firstname = firstName;
    this->_mail = mail;
    this->_IDAdress = IDAdress;
}
void User::setPhoneNumber(QString phoneNb){
    _phoneNumber = phoneNb;
}
void User::setIsActive(bool isAct){
    _isActive = isAct;
}
void User::setPassword(QString pwd){
    _password = pwd;
}
void User::setLastName(QString lastN){
    _lastname = lastN;
}
void User::setMail(QString ml){
    _mail = ml;
}
void User::setUsername(QString user){
    _username = user;
}
void User::setFirstName(QString firstN){
    _firstname = firstN;
}
void User::setIdAddress(int adrId){
    _IDAdress = adrId;
}

QString User::getPhoneNumber(){
    return _phoneNumber;
}
bool User::getIsActive(){
    return _isActive;
}
QString User::getPassword(){
    return _password;
}
QString User::getLastName(){
    return _lastname;
}
QString User::getMail(){
   return _mail;
}
QString User::getUsername(){
    return _username;
}
QString User::getFirstName(){
   return _firstname;
}
int User::getAddressIdAddress(){
    return _IDAdress;
}
