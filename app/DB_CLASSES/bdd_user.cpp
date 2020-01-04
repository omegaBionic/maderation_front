#include "bdd_user.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QJsonArray>

bdd_USER::bdd_USER(QString phoneNumber, bool isActive, QString lastname, QString password, QString firstname, int idAddress, QString mail, QString username): bdd_global(QString("id"), QString("table"))
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
bdd_USER::bdd_USER(): bdd_global(QString("id"), QString("table")){

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

QMap<QString, QString> bdd_USER::getDict(){

    QFile file("DATA/jsonUser.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QMap<QString, QString> listUser;

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    int cpt = 0;

    foreach(const QJsonValue &v, itemsArray)
    {
        listUser.insert(itemsArray.at(cpt).toObject().keys()[cpt], v.toObject().value(v.toObject().keys()[cpt])["S"].toString());
        cpt += 1;
    }

    return listUser;
}
