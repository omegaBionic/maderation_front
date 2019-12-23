#include "bdd_promotion_comp.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>

bdd_PROMOTION_COMP::bdd_PROMOTION_COMP(int amount, bool addToExistingProm, QString fromDate, QString idPromotionComp, QString toDate): bdd_global(QString("id"), QString("table"))
{
    this->_amount = amount;
    this->_addToExistingProm =addToExistingProm;
    this->_fromDate = fromDate;
    this->_idPromotionComp = idPromotionComp;
    this->_toDate =toDate;
}
bdd_PROMOTION_COMP::bdd_PROMOTION_COMP(): bdd_global(QString("id"), QString("table")){

}
bdd_PROMOTION_COMP::~bdd_PROMOTION_COMP(){

}
void bdd_PROMOTION_COMP::setAmount(int amnt){
    _amount = amnt;
}
void bdd_PROMOTION_COMP::setAddToExistingProm(bool addExistP){
    _addToExistingProm = addExistP;
}
void bdd_PROMOTION_COMP::setFromDate(QString fromD){
    _fromDate = fromD;
}
void bdd_PROMOTION_COMP::setIdPromotionComp(QString idPromC){
    _idPromotionComp = idPromC;
}
void bdd_PROMOTION_COMP::setToDate(QString toD){
    _toDate = toD;
}

int bdd_PROMOTION_COMP::getAmount(){
    return _amount;
}
bool bdd_PROMOTION_COMP::getAddToExistingProm(){
    return _addToExistingProm;
}
QString bdd_PROMOTION_COMP::getFromDate(){
    return _fromDate;
}
QString bdd_PROMOTION_COMP::getIdPromotionComp(){
    return _idPromotionComp;
}
QString bdd_PROMOTION_COMP::getToDate(){
    return _toDate;
}

QString bdd_PROMOTION_COMP::getId(){
    return "idPromotionComp";
}
QString bdd_PROMOTION_COMP::getTable(){
    return "promotion_comp";
}

QMap<QString, QString> bdd_PROMOTION_COMP::getDict(){

    QFile file;
    file.setFileName("DATA/jsonPromotionComp.json");
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
