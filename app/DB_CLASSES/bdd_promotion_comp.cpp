#include "bdd_promotion_comp.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>
#include <QJsonArray>

bdd_PROMOTION_COMP::bdd_PROMOTION_COMP(int amount, bool addToExistingProm, QString fromDate, QString idPromotionComp, QString toDate): bdd_global(QString("idPromotionComp"), QString("promotion_comp"))
{
    this->_amount = amount;
    this->_addToExistingProm =addToExistingProm;
    this->_fromDate = fromDate;
    this->_idPromotionComp = idPromotionComp;
    this->_toDate =toDate;
}
bdd_PROMOTION_COMP::bdd_PROMOTION_COMP(): bdd_global(QString("idPromotionComp"), QString("promotion_comp")){

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


void bdd_PROMOTION_COMP::addKey(QString key, QString value){
    bdd_global::addKey(key, value);
    _map.insert(key, value);
}

//int amount, bool addToExistingProm, QString fromDate, QString idPromotionCat, QString toDate
QMap<QString, QString> bdd_PROMOTION_COMP::getDict() {
    this->addKey("amount", "\"N\":\""+ QString::number(this->_amount) + "\"");
    this->addKey("fromDate", "\"S\":\""+ this->_fromDate + "\"");
    this->addKey("toDate", "\"S\":\""+ this->_toDate + "\"");
    this->addKey("idPromotionComp", "\"S\":\""+ this->_idPromotionComp + "\"");
    if(this->_addToExistingProm){
        this->addKey("addToExistingProm", "\"BOOL\":true");
    }else{
        this->addKey("addToExistingProm", "\"BOOL\":false");
    }
    bdd_global::getDict();
    return _map;
}

