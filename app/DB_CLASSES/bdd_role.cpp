#include "bdd_role.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>
#include <QJsonArray>

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

    QFile file("DATA/jsonRole.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QMap<QString, QString> listRole;

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    int cpt = 0;

    foreach(const QJsonValue &v, itemsArray)
    {
        listRole.insert(itemsArray.at(cpt).toObject().keys()[cpt], v.toObject().value(v.toObject().keys()[cpt])["S"].toString());
        cpt += 1;
    }

    return listRole;
}
