#include "bdd_address_supplier.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QJsonArray>

bdd_ADDRESS_SUPPLIER::bdd_ADDRESS_SUPPLIER(QString city, QString idAddressSupplier, QString country, int postalCode, QString street): bdd_global(QString("idAddressSupplier"), QString("address_supplier"))
{
    this->_city = city;
    this->_idAddressSupplier = idAddressSupplier;
    this->_country = country;
    this->_postalCod = postalCode;
    this->_street = street;
}
bdd_ADDRESS_SUPPLIER::bdd_ADDRESS_SUPPLIER(): bdd_global(QString("idAddressSupplier"), QString("address_supplier")){

}
bdd_ADDRESS_SUPPLIER::~bdd_ADDRESS_SUPPLIER(){

}
void bdd_ADDRESS_SUPPLIER::setcity(QString cit){
    _city = cit;
}
void bdd_ADDRESS_SUPPLIER::setidAddressSupplier(QString idAdCli){
    _idAddressSupplier = idAdCli;
}
void bdd_ADDRESS_SUPPLIER::setCountry(QString cntry){
    _country = cntry;
}
void bdd_ADDRESS_SUPPLIER::setPostalCode(int pc){
    _postalCod = pc;
}
void bdd_ADDRESS_SUPPLIER::setStreet(QString str){
    _street = str;
}

QString bdd_ADDRESS_SUPPLIER::getCity(){
    return _city;
}
QString bdd_ADDRESS_SUPPLIER::getIdAddressSupplier(){
    return _idAddressSupplier;
}
QString bdd_ADDRESS_SUPPLIER::getCountry(){
    return _country;
}
int bdd_ADDRESS_SUPPLIER::getPostalCode(){
    return _postalCod;
}
QString bdd_ADDRESS_SUPPLIER::getStreet(){
   return _street;
}

QString bdd_ADDRESS_SUPPLIER::getId(){
    return "idAddressSupplier";
}
QString bdd_ADDRESS_SUPPLIER::getTable(){
    return "address_supplier";
}

void bdd_ADDRESS_SUPPLIER::addKey(QString key, QString value){
    bdd_global::addKey(key, value);
    _map.insert(key, value);
}


QMap<QString, QString> bdd_ADDRESS_SUPPLIER::getDict() {
    this->addKey("city", "\"S\":\""+ this->_city + "\"");
    this->addKey("street", "\"S\":\""+ this->_street + "\"");
    this->addKey("country", "\"S\":\""+ this->_country + "\"");
    this->addKey("postalCode", "\"N\":\""+ QString::number(this->_postalCod) + "\"");
    this->addKey("idAddressSupplier", "\"S\":\""+ this->_idAddressSupplier + "\"");

    bdd_global::getDict();
    return _map;
}

