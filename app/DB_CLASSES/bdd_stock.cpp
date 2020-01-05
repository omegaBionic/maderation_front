#include "bdd_stock.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>
#include <QJsonArray>

bdd_STOCK::bdd_STOCK(int amount, QString idStock, int productIdProduct, int addressIdAddress): bdd_global(QString("idStock"), QString("stock"))
{
    this->_amount = amount;
    this->_idStock = idStock;
    this->_productIdProduct = productIdProduct;
    this->_addressIdAddress = addressIdAddress;
}
bdd_STOCK::bdd_STOCK(): bdd_global(QString("idStock"), QString("stock")){

}
bdd_STOCK::~bdd_STOCK(){

}
void bdd_STOCK::setAmount(int amnt){
    _amount = amnt;
}
void bdd_STOCK::setIdStock(QString idS){
    _idStock = idS;
}
void bdd_STOCK::setProductIdProduct(int idProd){
    _productIdProduct = idProd;
}
void bdd_STOCK::setAddressIdAddress(int idAdd){
    _addressIdAddress =idAdd;
}

int bdd_STOCK::getAmmount(){
return _amount;
}
QString bdd_STOCK::getIdStock(){
return _idStock;
}
int bdd_STOCK::getProductIdProduct(){
return _productIdProduct;
}
int bdd_STOCK::getAddressIdAddress(){
return _addressIdAddress;
}

QString bdd_STOCK::getId(){
    return "idStock";
}
QString bdd_STOCK::getTable(){
    return "stock";
}

void bdd_STOCK::addKey(QString key, QString value){
    bdd_global::addKey(key, value);
    _map.insert(key, value);
}

//int amount, QString idStock, int productIdProduct, int addressIdAddress
QMap<QString, QString> bdd_STOCK::getDict() {
    this->addKey("idStock", "\"S\":\""+ this->_idStock + "\"");
    this->addKey("amount", "\"N\":\""+ QString::number(this->_amount) + "\"");
    this->addKey("productIdProduct", "\"N\":\""+ QString::number(this->_productIdProduct) + "\"");
    this->addKey("addressIdAddress", "\"N\":\""+ QString::number(this->_addressIdAddress) + "\"");
    bdd_global::getDict();
    return _map;
}


