#include "bdd_product.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>
#include <QJsonArray>

bdd_PRODUCT::bdd_PRODUCT(int supplierIdsupplier, QString idProduct, int minWidth, int defaultLength, QString label, QString productCode, int defaultHeight, int defaultWidth, QString material, int minLength, QString type): bdd_global(QString("id"), QString("table"))
{
this->_supplierIdSupplier = supplierIdsupplier;
    this->_idProduct = idProduct;
    this->_minWidth = minWidth;
    this->_defaultLength = defaultLength;
    this->_label = label;
    this->_productCode = productCode;
    this->_defaultHeight = defaultHeight;
    this->_defaultWidth = defaultWidth;
    this->_material = material;
    this->_minLength = minLength;
    this->_type = type;
}
bdd_PRODUCT::bdd_PRODUCT(): bdd_global(QString("id"), QString("table")){

}
bdd_PRODUCT::~bdd_PRODUCT(){

}
void bdd_PRODUCT::setSupplierIdSupplier(int idSupp){
    _supplierIdSupplier = idSupp;
}
void bdd_PRODUCT::setIdProduct(QString idProd){
    _idProduct = idProd;
}
void bdd_PRODUCT::setMinWidth(int minWi){
    _minWidth = minWi;
}
void bdd_PRODUCT::setDefaultLength(int defL){
    _defaultLength = defL;
}
void bdd_PRODUCT::setLabel(QString lbl){
    _label = lbl;
}
void bdd_PRODUCT::setProductCode(QString prodC){
    _productCode = prodC;
}
void bdd_PRODUCT::setDefaultHeight(int defH){
    _defaultHeight = defH;
}
void bdd_PRODUCT::setDefaultWidth(int defW){
    _defaultWidth = defW;
}
void bdd_PRODUCT::setMaterial(QString mat){
    _material = mat;
}
void bdd_PRODUCT::setMinLength(int minL){
    _minLength = minL;
}
void bdd_PRODUCT::setType(QString tpe){
    _type = tpe;
}

int bdd_PRODUCT::getSupplierIdSupplier(){
    return _supplierIdSupplier;
}
QString bdd_PRODUCT::getIdProduct(){
    return _idProduct;
}
int bdd_PRODUCT::getMinWidth(){
    return _minWidth;
}
int bdd_PRODUCT::getDefaultLength(){
    return _defaultLength;
}
QString bdd_PRODUCT::getLabel(){
    return _label;
}
QString bdd_PRODUCT::getProductCode(){
    return _productCode;
}
int bdd_PRODUCT::getDefaultHeight(){
    return _defaultHeight;
}
int bdd_PRODUCT::getDefaultWidth(){
    return _defaultWidth;
}
QString bdd_PRODUCT::getMaterial(){
    return _material;
}
int bdd_PRODUCT::getMinLength(){
    return _minLength;
}
QString bdd_PRODUCT::getType(){
    return _type;
}

QString bdd_PRODUCT::getId(){
    return "idProduct";
}
QString bdd_PRODUCT::getTable(){
    return "product";
}

QMap<QString, QString> bdd_PRODUCT::getDict(){

    QFile file("DATA/jsonProduct.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QMap<QString, QString> listProduct;

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    int cpt = 0;

    foreach(const QJsonValue &v, itemsArray)
    {
        listProduct.insert(itemsArray.at(cpt).toObject().keys()[cpt], v.toObject().value(v.toObject().keys()[cpt])["S"].toString());
        cpt += 1;
    }

    return listProduct;
}
