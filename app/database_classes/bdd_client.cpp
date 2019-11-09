#include "bdd_client.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>

bdd_CLIENT::bdd_CLIENT(QString idClient, QString phoneNumber, bool isActive, QString password, QString lastname, QString mail, QString firstname, int addressIDAdress)
{
    this->_idClient = idClient;
    this->_phoneNumber = phoneNumber;
    this->_isActive = isActive;
    this->_password = password;
    this->_lastname = lastname;
    this->_firstname = firstname;
    this->_mail = mail;
    this->_addressIDAdress = addressIDAdress;
}

bdd_CLIENT::bdd_CLIENT(){

}

bdd_CLIENT::~bdd_CLIENT(){

}

void bdd_CLIENT::setPhoneNumber(QString phoneNb){
    _phoneNumber = phoneNb;
}
void bdd_CLIENT::setIsActive(bool isAct){
    _isActive = isAct;
}
void bdd_CLIENT::setPassword(QString pwd){
    _password = pwd;
}
void bdd_CLIENT::setLastName(QString lastN){
    _lastname = lastN;
}
void bdd_CLIENT::setMail(QString ml){
    _mail = ml;
}
void bdd_CLIENT::setIdClient(QString idCli){
    _idClient = idCli;
}
void bdd_CLIENT::setFirstName(QString firstN){
    _firstname = firstN;
}
void bdd_CLIENT::setAddressIdAddress(int adrId){
    _addressIDAdress = adrId;
}

QString bdd_CLIENT::getPhoneNumber(){
    return _phoneNumber;
}
bool bdd_CLIENT::getIsActive(){
    return _isActive;
}
QString bdd_CLIENT::getPassword(){
    return _password;
}
QString bdd_CLIENT::getLastName(){
    return _lastname;
}
QString bdd_CLIENT::getMail(){
   return _mail;
}
QString bdd_CLIENT::getIdClient(){
    return _idClient;
}
QString bdd_CLIENT::getFirstName(){
   return _firstname;
}
int bdd_CLIENT::getAddressIdAddress(){
    return _addressIDAdress;
}
