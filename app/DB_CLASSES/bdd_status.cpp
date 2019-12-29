#include "bdd_status.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>
#include <QJsonArray>

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

    QFile file("DATA/jsonStatus.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QMap<QString, QString> listStatus;

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    int cpt = 0;

    foreach(const QJsonValue &v, itemsArray)
    {
        listStatus.insert(itemsArray.at(cpt).toObject().keys()[cpt], v.toObject().value(v.toObject().keys()[cpt])["S"].toString());
        cpt += 1;
    }

    return listStatus;
}
