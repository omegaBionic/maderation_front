#include "bdd_role.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>
#include <QJsonArray>

bdd_ROLE::bdd_ROLE(QString userUsername, QString idRole, QString label): bdd_global(QString("idRole"), QString("role"))
{
    this->_userUserName =userUsername;
    this->_idRole = idRole;
    this->_label = label;
}
bdd_ROLE::bdd_ROLE(): bdd_global(QString("idRole"), QString("role")){

}
bdd_ROLE::~bdd_ROLE(){

}
void bdd_ROLE::setUserUsername(QString usrN){
    _userUserName = usrN;
}
void bdd_ROLE::setIdRole(QString idR){
    _idRole = idR;
}
void bdd_ROLE::setLabel(QString lbl){
    _label = lbl;
}

QString bdd_ROLE::getUserUsername(){
    return _userUserName;
}
QString bdd_ROLE::getIdRole(){
    return _idRole;
}
QString bdd_ROLE::getLabel(){
    return _label;
}

QString bdd_ROLE::getId(){
    return "idRole";
}
QString bdd_ROLE::getTable(){
    return "role";
}

void bdd_ROLE::addKey(QString key, QString value){
    bdd_global::addKey(key, value);
    _map.insert(key, value);
}

//bool validation, QString idQuotation, QString creationDate, bool isTemplate, QString userUsername, QString validationDate
QMap<QString, QString> bdd_ROLE::getDict() {
    this->addKey("idRole", "\"S\":\""+ this->_idRole + "\"");
    this->addKey("label", "\"S\":\""+ this->_label + "\"");
    this->addKey("userUsername", "\"S\":\""+ this->_userUserName + "\"");
    bdd_global::getDict();
    return _map;
}
