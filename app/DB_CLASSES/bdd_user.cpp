#include "bdd_user.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QJsonArray>

bdd_USER::bdd_USER(QString phoneNumber, bool isActive, QString lastname, QString password, QString firstname, int idAddress, QString mail, QString username): bdd_global(QString("username"), QString("user"))
{
    this->_username = username;
    this->_phoneNumber = phoneNumber;
    this->_isActive = isActive;
    this->_password = password;
    this->_lastname = lastname;
    this->_firstname = firstname;
    this->_mail = mail;
    this->_IDAdress = idAddress;
}
bdd_USER::bdd_USER(): bdd_global(QString("username"), QString("user")){

}
bdd_USER::~bdd_USER(){

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

QString bdd_USER::getId(){
    return "username";
}
QString bdd_USER::getTable(){
    return "user";
}

void bdd_USER::addKey(QString key, QString value){
    bdd_global::addKey(key, value);
    _map.insert(key, value);
}

//QString phoneNumber, bool isActive, QString lastname, QString password, QString firstname, int idAddress, QString mail, QString username
QMap<QString, QString> bdd_USER::getDict() {
    this->addKey("phoneNumber", "\"S\":\""+ this->_phoneNumber + "\"");
    this->addKey("mail", "\"S\":\""+ this->_mail + "\"");
    this->addKey("lastname", "\"S\":\""+ this->_lastname + "\"");
    this->addKey("password", "\"S\":\""+ this->_password + "\"");
    this->addKey("firstname", "\"S\":\""+ this->_firstname + "\"");
    this->addKey("username", "\"S\":\""+ this->_username + "\"");
    this->addKey("idShop", "\"N\":\""+ QString::number(this->_IDAdress) + "\"");
    if(this->_isActive){
        this->addKey("isActive", "\"BOOL\":true");
    }else{
        this->addKey("isActive", "\"BOOL\":false");
    }
    bdd_global::getDict();
    return _map;
}
