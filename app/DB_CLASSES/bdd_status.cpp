#include "bdd_status.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>
#include <QJsonArray>

bdd_STATUS::bdd_STATUS(QString status, QString datas): bdd_global(QString("status"), QString("status"))
{
this->_status = status;
this->_datas = datas;
}

bdd_STATUS::bdd_STATUS(): bdd_global(QString("status"), QString("status"))
{
}

bdd_STATUS::~bdd_STATUS()
{
}

void bdd_STATUS::setStatus(QString sta){
    _status = sta;
}
void bdd_STATUS::setDatas(QString dat){
    _datas = dat;
}

QString bdd_STATUS::getStatus(){
    return _status;
}
QString bdd_STATUS::getDatas(){
    return _datas;
}

QString bdd_STATUS::getId(){
    return "status";
}
QString bdd_STATUS::getTable(){
    return "status";
}

void bdd_STATUS::addKey(QString key, QString value){
    bdd_global::addKey(key, value);
    _map.insert(key, value);
}

//QString city, QString idShop, QString country, int postalCode, QString street
QMap<QString, QString> bdd_STATUS::getDict() {
    this->addKey("status", "\"S\":\""+ this->_status + "\"");
    this->addKey("datas", "\"S\":\""+ this->_datas + "\"");
    bdd_global::getDict();
    return _map;
}

