#include "bdd_component.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>
#include <QJsonArray>

bdd_COMPONENT::bdd_COMPONENT(int supplierIdSupplier, QString idComponent, int categoryIdCategory, QString label): bdd_global(QString("id"), QString("table"))
{
    this->_supplierIdSupplier = supplierIdSupplier;
    this->_idComponent = idComponent;
    this->_categoryIdCategory = categoryIdCategory;
    this->_label = label;
}
bdd_COMPONENT::bdd_COMPONENT(): bdd_global(QString("id"), QString("table")){

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

QString bdd_COMPONENT::getId(){
    return "idComponent";
}
QString bdd_COMPONENT::getTable(){
    return "component";
}

QMap<QString, QString> bdd_COMPONENT::getDict(){

    QFile file("DATA/jsonComponent.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QMap<QString, QString> listComponent;

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    int cpt = 0;

    foreach(const QJsonValue &v, itemsArray)
    {
        listComponent.insert(itemsArray.at(cpt).toObject().keys()[cpt], v.toObject().value(v.toObject().keys()[cpt])["S"].toString());
        cpt += 1;
    }

    return listComponent;
}
