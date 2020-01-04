#include "bdd_shop.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>
#include <QJsonArray>

bdd_SHOP::bdd_SHOP(QString city, QString idShop, QString country, int postalCode, QString street): bdd_global(QString("id"), QString("table"))
{
    this->_city = city;
    this->_idShop = idShop;
    this->_country = country;
    this-> _postalCode = postalCode;
    this->_street = street;

}
bdd_SHOP::bdd_SHOP(): bdd_global(QString("id"), QString("table")){

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
    return "idRole";
}
QString bdd_SHOP::getTable(){
    return "role";
}

QMap<QString, QString> bdd_SHOP::getDict(){

    QFile file("DATA/jsonShop.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QMap<QString, QString> listShop;

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    int cpt = 0;

    foreach(const QJsonValue &v, itemsArray)
    {
        listShop.insert(itemsArray.at(cpt).toObject().keys()[cpt], v.toObject().value(v.toObject().keys()[cpt])["S"].toString());
        cpt += 1;
    }

    return listShop;
}
