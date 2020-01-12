#include "bdd_component.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>
#include <QJsonArray>

bdd_COMPONENT::bdd_COMPONENT(int supplierIdSupplier, QString idComponent, int categoryIdCategory, QString label, int amount, double price, QString idProduct): bdd_global(QString("idComponent"), QString("component"))
{
    this->_supplierIdSupplier = supplierIdSupplier;
    this->_idComponent = idComponent;
    this->_categoryIdCategory = categoryIdCategory;
    this->_label = label;
    this->_amount = amount;
    this->_price = price;
    this->_idProduct = idProduct;
}
bdd_COMPONENT::bdd_COMPONENT(): bdd_global(QString("idComponent"), QString("component")){

}
bdd_COMPONENT::~bdd_COMPONENT(){

}
void bdd_COMPONENT::setSupplierIdSupplier(int idSupp){
    _supplierIdSupplier = idSupp;
}
void bdd_COMPONENT::setIdComponent(QString idComp){
    _idComponent = idComp;
}
void bdd_COMPONENT::setCategoryIdCategory(int idCateg){
    _categoryIdCategory = idCateg;
}
void bdd_COMPONENT::setLabel(QString lbl){
    _label = lbl;
}

void bdd_COMPONENT::setIDProduct(QString lbl){
    _idProduct = lbl;
}

void bdd_COMPONENT::setPrice(double lbl){
    _price = lbl;
}

void bdd_COMPONENT::setAmount(int lbl){
    _amount = lbl;
}

int bdd_COMPONENT::getSupplierIdSupplier(){
    return _supplierIdSupplier;
}
QString bdd_COMPONENT::getIdComponent(){
    return _idComponent;
}
int bdd_COMPONENT::getCategoryIdCategory(){
    return _categoryIdCategory;
}
QString bdd_COMPONENT::getLabel(){
    return _label;
}


QString bdd_COMPONENT::getIDProduct(){
    return _idProduct;
}


double bdd_COMPONENT::getPrice(){
    return _price;
}


int bdd_COMPONENT::getAmount(){
    return _amount;
}

QString bdd_COMPONENT::getId(){
    return "idComponent";
}
QString bdd_COMPONENT::getTable(){
    return "component";
}

void bdd_COMPONENT::addKey(QString key, QString value){
    bdd_global::addKey(key, value);
    _map.insert(key, value);
}

//int supplierIdSupplier, QString idComponent, int categoryIdCategory, QString label
QMap<QString, QString> bdd_COMPONENT::getDict() {
    this->addKey("idComponent", "\"S\":\""+ this->_idComponent + "\"");
    this->addKey("productIDProduct", "\"S\":\""+ this->_idProduct + "\"");
    this->addKey("label", "\"S\":\""+ this->_label + "\"");
    this->addKey("supplierIdSupplier", "\"N\":\""+ QString::number(this->_supplierIdSupplier) + "\"");
    this->addKey("categoryIdCategory", "\"N\":\""+ QString::number(this->_categoryIdCategory) + "\"");
    this->addKey("amount", "\"N\":\""+ QString::number(this->_amount) + "\"");
    this->addKey("unitairPrice", "\"N\":\""+ QString::number(this->_price) + "\"");
    bdd_global::getDict();
    return _map;
}
