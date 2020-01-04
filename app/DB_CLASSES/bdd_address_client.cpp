#include "bdd_address_client.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
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

    QFile file("data/jsonAddress_client.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QMap<QString, QString> listAddressClient;

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    int cpt = 0;

    foreach(const QJsonValue &v, itemsArray)
    {
        listAddressClient.insert(itemsArray.at(cpt).toObject().keys()[cpt], v.toObject().value(v.toObject().keys()[cpt])["S"].toString());
        cpt += 1;
    }

    return listAddressClient;

}



