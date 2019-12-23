#include "bdd_category.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>

bdd_CATEGORY::bdd_CATEGORY(QString idCategory, QString label): bdd_global(QString("id"), QString("table"))
{
this->_idIdCategory = idCategory;
this->_label = label;
}

bdd_CATEGORY::bdd_CATEGORY(): bdd_global(QString("id"), QString("table")){

}
bdd_CATEGORY::~bdd_CATEGORY(){

}

void bdd_CATEGORY::setIdCategory(QString idCat){
    _idIdCategory = idCat;
}
void bdd_CATEGORY::setLabel(QString lbl){
    _label = lbl;
}

QString bdd_CATEGORY::getIdCategory(){
    return _idIdCategory;
}
QString bdd_CATEGORY::getLabel(){
    return _label;
}

QString bdd_CATEGORY::getId(){
    return "idAddressSupplier";
}
QString bdd_CATEGORY::getTable(){
    return "address_supplier";
}

QMap<QString, QString> bdd_CATEGORY::getDict(){

    QFile file;
    file.setFileName("DATA/jsonCategory.json");
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
