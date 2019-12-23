#include "bdd_promotion_cat.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>

bdd_PROMOTION_CAT::bdd_PROMOTION_CAT(int amount, bool addToExistingProm, QString fromDate, QString idPromotionCat, QString toDate): bdd_global(QString("id"), QString("table"))
{
    this->_amount = amount;
    this->_addToExistingProm =addToExistingProm;
    this->_fromDate = fromDate;
    this->_idPromotionCat = idPromotionCat;
    this->_toDate =toDate;
}
bdd_PROMOTION_CAT::bdd_PROMOTION_CAT(): bdd_global(QString("id"), QString("table")){

}
bdd_PROMOTION_CAT::~bdd_PROMOTION_CAT(){

}
void bdd_PROMOTION_CAT::setAmount(int amnt){
    _amount = amnt;
}
void bdd_PROMOTION_CAT::setAddToExistingProm(bool addExistP){
    _addToExistingProm = addExistP;
}
void bdd_PROMOTION_CAT::setFromDate(QString fromD){
    _fromDate = fromD;
}
void bdd_PROMOTION_CAT::setIdPromotionCat(QString idPromC){
    _idPromotionCat = idPromC;
}
void bdd_PROMOTION_CAT::setToDate(QString toD){
    _toDate = toD;
}

int bdd_PROMOTION_CAT::getAmount(){
    return _amount;
}
bool bdd_PROMOTION_CAT::getAddToExistingProm(){
    return _addToExistingProm;
}
QString bdd_PROMOTION_CAT::getFromDate(){
    return _fromDate;
}
QString bdd_PROMOTION_CAT::getIdPromotionCat(){
    return _idPromotionCat;
}
QString bdd_PROMOTION_CAT::getToDate(){
    return _toDate;
}

QString bdd_PROMOTION_CAT::getId(){
    return "idPromotionCat";
}
QString bdd_PROMOTION_CAT::getTable(){
    return "promotion_cat";
}

QMap<QString, QString> bdd_PROMOTION_CAT::getDict(){

    QFile file;
    file.setFileName("DATA/jsonPromotionCat.json");
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
