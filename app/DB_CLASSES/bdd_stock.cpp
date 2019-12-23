#include "bdd_stock.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>

bdd_STOCK::bdd_STOCK(int amount, QString idStock, int productIdProduct, int addressIdAddress): bdd_global(QString("id"), QString("table"))
{
    this->_amount = amount;
    this->_idStock = idStock;
    this->_productIdProduct = productIdProduct;
    this->_addressIdAddress = addressIdAddress;
}
bdd_STOCK::bdd_STOCK(): bdd_global(QString("id"), QString("table")){

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

QMap<QString, QString> bdd_STOCK::getDict(){

    QFile file;
    file.setFileName("DATA/jsonStock.json");
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
