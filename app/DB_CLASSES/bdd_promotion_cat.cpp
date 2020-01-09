#include "bdd_promotion_cat.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>
#include <QJsonArray>

bdd_PROMOTION_CAT::bdd_PROMOTION_CAT(int amount, bool addToExistingProm, QString fromDate, QString idPromotionCat, QString toDate): bdd_global(QString("idPromotionCat"), QString("promotion_cat"))
{
    this->_amount = amount;
    this->_addToExistingProm =addToExistingProm;
    this->_fromDate = fromDate;
    this->_idPromotionCat = idPromotionCat;
    this->_toDate =toDate;
}
bdd_PROMOTION_CAT::bdd_PROMOTION_CAT(): bdd_global(QString("idPromotionCat"), QString("promotion_cat")){

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

void bdd_PROMOTION_CAT::addKey(QString key, QString value){
    bdd_global::addKey(key, value);
    _map.insert(key, value);
}

//int amount, bool addToExistingProm, QString fromDate, QString idPromotionCat, QString toDate
QMap<QString, QString> bdd_PROMOTION_CAT::getDict() {
    this->addKey("amount", "\"N\":\""+ QString::number(this->_amount) + "\"");
    this->addKey("fromDate", "\"S\":\""+ this->_fromDate + "\"");
    this->addKey("toDate", "\"S\":\""+ this->_toDate + "\"");
    this->addKey("idPromotionCat", "\"S\":\""+ this->_idPromotionCat + "\"");
    if(this->_addToExistingProm){
        this->addKey("addToExistingProm", "\"BOOL\":true");
    }else{
        this->addKey("addToExistingProm", "\"BOOL\":false");
    }
    bdd_global::getDict();
    return _map;
}

