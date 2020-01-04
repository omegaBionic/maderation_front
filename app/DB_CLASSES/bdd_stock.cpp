#include "bdd_stock.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>
#include <QJsonArray>

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

    QFile file("DATA/jsonStock.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QMap<QString, QString> listStock;

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    int cpt = 0;

    foreach(const QJsonValue &v, itemsArray)
    {
        listStock.insert(itemsArray.at(cpt).toObject().keys()[cpt], v.toObject().value(v.toObject().keys()[cpt])["S"].toString());
        cpt += 1;
    }

    return listStock;
}
