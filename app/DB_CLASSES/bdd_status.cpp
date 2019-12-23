#include "bdd_status.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>

bdd_STATUS::bdd_STATUS(QString status, QString datas): bdd_global(QString("id"), QString("table"))
{
this->_status = status;
this->_datas = datas;
}

bdd_STATUS::bdd_STATUS(): bdd_global(QString("id"), QString("table"))
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

QMap<QString, QString> bdd_STATUS::getDict(){

    QFile file;
    file.setFileName("DATA/jsonStatus.json");
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
