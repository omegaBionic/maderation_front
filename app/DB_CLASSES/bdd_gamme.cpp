#include "bdd_gamme.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>

bdd_GAMME::bdd_GAMME(QString idGamme, int productIdProduct, QString label): bdd_global(QString("id"), QString("table"))
{
    this->_idGamme = idGamme;
    this->_productIdProduct = productIdProduct;
    this->_label = label;
}
bdd_GAMME::bdd_GAMME(): bdd_global(QString("id"), QString("table")){

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

QMap<QString, QString> bdd_GAMME::getDict(){

    QFile file;
    file.setFileName("DATA/jsonGamme.json");
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
