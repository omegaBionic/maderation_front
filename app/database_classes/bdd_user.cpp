#include "bdd_user.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
bdd_USER::bdd_USER(QString username, QString phoneNumber, bool isActive, QString password, QString lastName, QString firstName, QString mail, int IDAdress)
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
void bdd_USER::setPhoneNumber(QString phoneNb){
    _phoneNumber = phoneNb;
}
void bdd_USER::setIsActive(bool isAct){
    _isActive = isAct;
}
void bdd_USER::setPassword(QString pwd){
    _password = pwd;
}
void bdd_USER::setLastName(QString lastN){
    _lastname = lastN;
}
void bdd_USER::setMail(QString ml){
    _mail = ml;
}
void bdd_USER::setUsername(QString user){
    _username = user;
}
void bdd_USER::setFirstName(QString firstN){
    _firstname = firstN;
}
void bdd_USER::setIdAddress(int adrId){
    _IDAdress = adrId;
}

QString bdd_USER::getPhoneNumber(){
    return _phoneNumber;
}
bool bdd_USER::getIsActive(){
    return _isActive;
}
QString bdd_USER::getPassword(){
    return _password;
}
QString bdd_USER::getLastName(){
    return _lastname;
}
QString bdd_USER::getMail(){
   return _mail;
}
QString bdd_USER::getUsername(){
    return _username;
}
QString bdd_USER::getFirstName(){
   return _firstname;
}
int bdd_USER::getAddressIdAddress(){
    return _IDAdress;
}
