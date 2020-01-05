#include "bdd_address_client.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QDebug>
#include <QFile>
#include <QObject>

bdd_ADDRESS_CLIENT::bdd_ADDRESS_CLIENT(QString city, QString idAddressClient, QString country, int postalCode, QString street) : bdd_global(QString("idAddressClient"), QString("address_client"))
{
    this->_city = city;
    this->_idAddressClient = idAddressClient;
    this->_country = country;
    this->_postalCod = postalCode;
    this->_street = street;
}

bdd_ADDRESS_CLIENT::bdd_ADDRESS_CLIENT() : bdd_global(QString("idAddressClient"), QString("address_client"))
{

}

bdd_ADDRESS_CLIENT::~bdd_ADDRESS_CLIENT()
{

}

void bdd_ADDRESS_CLIENT::setcity(QString cit){
    _city = cit;
}

void bdd_ADDRESS_CLIENT::setidAddressClient(QString idAdCli){
    _idAddressClient = idAdCli;
}

void bdd_ADDRESS_CLIENT::setCountry(QString cntry){
    _country = cntry;
}

void bdd_ADDRESS_CLIENT::setPostalCode(int pc){
    _postalCod = pc;
}

void bdd_ADDRESS_CLIENT::setStreet(QString str){
    _street = str;
}

QString bdd_ADDRESS_CLIENT::getCity(){
    return _city;
}

QString bdd_ADDRESS_CLIENT::getIdAddressClient(){
    return _idAddressClient;
}
QString bdd_ADDRESS_CLIENT::getCountry(){
    return _country;
}

int bdd_ADDRESS_CLIENT::getPostalCode(){
    return _postalCod;
}

QString bdd_ADDRESS_CLIENT::getStreet(){
   return _street;
}

QString bdd_ADDRESS_CLIENT::getId(){
    return "idAddressClient";
}
QString bdd_ADDRESS_CLIENT::getTable(){
    return "address_client";
}

void bdd_ADDRESS_CLIENT::addKey(QString key, QString value){
    bdd_global::addKey(key, value);
    _map.insert(key, value);
}


QMap<QString, QString> bdd_ADDRESS_CLIENT::getDict() {
    this->addKey("city", "\"S\":\""+ this->_city + "\"");
    this->addKey("street", "\"S\":\""+ this->_street + "\"");
    this->addKey("country", "\"S\":\""+ this->_country + "\"");
    this->addKey("postalCode", "\"N\":\""+ QString::number(this->_postalCod) + "\"");
    this->addKey("idAddressClient", "\"S\":\""+ this->_idAddressClient + "\"");

    bdd_global::getDict();
    return _map;
}

