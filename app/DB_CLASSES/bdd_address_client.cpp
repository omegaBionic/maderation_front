#include "bdd_address_client.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>

bdd_ADDRESS_CLIENT::bdd_ADDRESS_CLIENT(QString city, QString idAddressClient, QString country, int postalCode, QString street) : bdd_global(QString("id"), QString("table"))
{
    this->_city = city;
    this->_idAddressClient = idAddressClient;
    this->_country = country;
    this->_postalCod = postalCode;
    this->_street = street;
}

bdd_ADDRESS_CLIENT::bdd_ADDRESS_CLIENT() : bdd_global(QString("id"), QString("table"))
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

QMap<QString, QString> bdd_ADDRESS_CLIENT::getDict(){

    QFile file;
    file.setFileName("DATA/jsonAddress_client.json");
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
