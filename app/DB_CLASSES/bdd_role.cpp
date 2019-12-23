#include "bdd_role.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>

bdd_ROLE::bdd_ROLE(QString userUsername, QString idRole, QString label): bdd_global(QString("id"), QString("table"))
{
    this->_userUserName =userUsername;
    this->_idRole = idRole;
    this->_label = label;
}
bdd_ROLE::bdd_ROLE(): bdd_global(QString("id"), QString("table")){

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

QMap<QString, QString> bdd_ROLE::getDict(){

    QFile file;
    file.setFileName("DATA/jsonRole.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);


    QJsonParseError jsonError;
    QJsonDocument flowerJson = QJsonDocument::fromJson(file.readAll(),&jsonError);
    if (jsonError.error != QJsonParseError::NoError){
    qDebug() << jsonError.errorString();
    }
    QList<QVariant> list = flowerJson.toVariant().toList();
    QMap<QString, QVariant> map = list[0].toMap();
    qDebug() << map["name"].toString();

    //return map;
}
