#include "bdd_gamme.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>
#include <QJsonArray>

bdd_GAMME::bdd_GAMME(QString idGamme, int productIdProduct, QString label): bdd_global(QString("idGamme"), QString("gamme"))
{
    this->_idGamme = idGamme;
    this->_productIdProduct = productIdProduct;
    this->_label = label;
}
bdd_GAMME::bdd_GAMME(): bdd_global(QString("idGamme"), QString("gamme")){

}
bdd_GAMME::~bdd_GAMME(){

}

void bdd_GAMME::setIdGamme(QString idGam){
    _idGamme = idGam;
}
void bdd_GAMME::setproductIdProduct(int idProduct){
    _productIdProduct = idProduct;
}
void bdd_GAMME::setLabel(QString lbl){
    _label = lbl;
}

QString bdd_GAMME::getIdGamme(){
    return _idGamme;
}
int bdd_GAMME::getProductIdProduct(){
    return _productIdProduct;
}
QString bdd_GAMME::getLabel(){
    return _label;
}

QString bdd_GAMME::getId(){
    return "idGamme";
}
QString bdd_GAMME::getTable(){
    return "gamme";
}

void bdd_GAMME::addKey(QString key, QString value){
    bdd_global::addKey(key, value);
    _map.insert(key, value);
}

//QString idGamme, int productIdProduct, QString label
QMap<QString, QString> bdd_GAMME::getDict() {
    this->addKey("idComponent", "\"S\":\""+ this->_idGamme + "\"");
    this->addKey("label", "\"S\":\""+ this->_label + "\"");
    this->addKey("productIdProduct", "\"N\":\""+ QString::number(this->_productIdProduct) + "\"");
    bdd_global::getDict();
    return _map;
}
