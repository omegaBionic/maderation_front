#include "bdd_category.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>
#include <QJsonArray>

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

    QFile file("DATA/jsonCategory.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QMap<QString, QString> listCategory;

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    int cpt = 0;

    foreach(const QJsonValue &v, itemsArray)
    {
        listCategory.insert(itemsArray.at(cpt).toObject().keys()[cpt], v.toObject().value(v.toObject().keys()[cpt])["S"].toString());
        cpt += 1;
    }

    return listCategory;
}
