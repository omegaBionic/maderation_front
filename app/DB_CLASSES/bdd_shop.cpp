#include "bdd_shop.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>
#include <QJsonArray>

bdd_SHOP::bdd_SHOP(QString city, QString idShop, QString country, int postalCode, QString street): bdd_global(QString("idShop"), QString("shop"))
{
    this->_city = city;
    this->_idShop = idShop;
    this->_country = country;
    this-> _postalCode = postalCode;
    this->_street = street;

}
bdd_SHOP::bdd_SHOP(): bdd_global(QString("idShop"), QString("shop")){

}
bdd_SHOP::~bdd_SHOP(){

}
void bdd_SHOP::setCity(QString cty){
    _city = cty;
}
void bdd_SHOP::setIdShop(QString idS){
    _idShop = idS;
}
void bdd_SHOP::setCountry(QString cntry){
    _country = cntry;
}
void bdd_SHOP::setPostalCode(int postC){
    _postalCode = postC;
}
void bdd_SHOP::setStreet(QString strt){
    _street = strt;
}

QString bdd_SHOP::getCity(){
return _city;
}
QString bdd_SHOP::getIdShop(){
return _idShop;
}
QString bdd_SHOP::getCountry(){
return _country;
}
int bdd_SHOP::getPostalCode(){
return _postalCode;
}
QString bdd_SHOP::getStreet(){
return _street;
}

QString bdd_SHOP::getId(){
    return "idShop";
}
QString bdd_SHOP::getTable(){
    return "shop";
}

void bdd_SHOP::addKey(QString key, QString value){
    bdd_global::addKey(key, value);
    _map.insert(key, value);
}

//QString city, QString idShop, QString country, int postalCode, QString street
QMap<QString, QString> bdd_SHOP::getDict() {
    this->addKey("city", "\"S\":\""+ this->_city + "\"");
    this->addKey("idShop", "\"S\":\""+ this->_idShop + "\"");
    this->addKey("country", "\"S\":\""+ this->_country + "\"");
    this->addKey("street", "\"S\":\""+ this->_street + "\"");
    this->addKey("postalCode", "\"N\":\""+ QString::number(this->_postalCode) + "\"");
    bdd_global::getDict();
    return _map;
}

