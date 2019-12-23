#include "bdd_address_supplier.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>

bdd_ADDRESS_SUPPLIER::bdd_ADDRESS_SUPPLIER(QString city, QString idAddressSupplier, QString country, int postalCode, QString street): bdd_global(QString("id"), QString("table"))
{
    this->_city = city;
    this->_idAddressSupplier = idAddressSupplier;
    this->_country = country;
    this->_postalCod = postalCode;
    this->_street = street;
}
bdd_ADDRESS_SUPPLIER::bdd_ADDRESS_SUPPLIER(): bdd_global(QString("id"), QString("table")){

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

QMap<QString, QString> bdd_ADDRESS_SUPPLIER::getDict(){

    QFile file;
    file.setFileName("DATA/jsonAddress_Supplier.json");
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
