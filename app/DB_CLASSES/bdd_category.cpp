#include "bdd_category.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>
#include <QJsonArray>

bdd_CATEGORY::bdd_CATEGORY(QString idCategory, QString label): bdd_global(QString("idCategory"), QString("category"))
{
this->_idIdCategory = idCategory;
this->_label = label;
}

bdd_CATEGORY::bdd_CATEGORY(): bdd_global(QString("idCategory"), QString("category")){

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
    return "idCategory";
}
QString bdd_CATEGORY::getTable(){
    return "category";
}

void bdd_CATEGORY::addKey(QString key, QString value){
    bdd_global::addKey(key, value);
    _map.insert(key, value);
}


QMap<QString, QString> bdd_CATEGORY::getDict() {
    this->addKey("idCategory", "\"S\":\""+ this->_idIdCategory + "\"");
    this->addKey("label", "\"S\":\""+ this->_label + "\"");

    bdd_global::getDict();
    return _map;
}
