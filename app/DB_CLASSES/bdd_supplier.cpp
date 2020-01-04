#include "bdd_supplier.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>
#include <QJsonArray>

bdd_SUPPLIER::bdd_SUPPLIER(QString phoneNumber, QString mail, QString description, QString name, QString idSupplier, int addressIdAddress): bdd_global(QString("id"), QString("table"))
{
    this->_phoneNumber = phoneNumber;
    this->_mail = mail;
    this->_description = description;
    this-> _name = name;
    this->_idSupplier = idSupplier;
    this->_addressIdAddres = addressIdAddress;
}
bdd_SUPPLIER::bdd_SUPPLIER(): bdd_global(QString("id"), QString("table")){

}
bdd_SUPPLIER::~bdd_SUPPLIER(){

}
void bdd_SUPPLIER::setPhoneNumber(QString phoneN){
    _phoneNumber = phoneN;
}
void bdd_SUPPLIER::setMail(QString ml){
    _mail = ml;
}
void bdd_SUPPLIER::setDescription(QString desc){
    _description = desc;
}
void bdd_SUPPLIER::setName(QString nm){
    _name = nm;
}
void bdd_SUPPLIER::setIdSupplier(QString idSupp){
    _idSupplier = idSupp;
}
void bdd_SUPPLIER::setAddressIDAddress(int idAdd){
    _addressIdAddres = idAdd;
}

QString bdd_SUPPLIER::getPhoneNumber(){
    return _phoneNumber;
}
QString bdd_SUPPLIER::getMail(){
    return _mail;
}
QString bdd_SUPPLIER::getDescription(){
    return _description;
}
QString bdd_SUPPLIER::getName(){
    return _name;
}
QString bdd_SUPPLIER::getIdSupplier(){
    return _idSupplier;
}
int bdd_SUPPLIER::getAddressIdAddress(){
    return _addressIdAddres;
}

QString bdd_SUPPLIER::getId(){
    return "idSupplier";
}
QString bdd_SUPPLIER::getTable(){
    return "supplier";
}

QMap<QString, QString> bdd_SUPPLIER::getDict(){

    QFile file("DATA/jsonSupplier.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QMap<QString, QString> listSupplier;

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    int cpt = 0;

    foreach(const QJsonValue &v, itemsArray)
    {
        listSupplier.insert(itemsArray.at(cpt).toObject().keys()[cpt], v.toObject().value(v.toObject().keys()[cpt])["S"].toString());
        cpt += 1;
    }

    return listSupplier;
}
