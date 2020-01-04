#include "bdd_gamme.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>
#include <QJsonArray>

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

    QFile file("DATA/jsonComponent.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QMap<QString, QString> listGamme;

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    int cpt = 0;

    foreach(const QJsonValue &v, itemsArray)
    {
        listGamme.insert(itemsArray.at(cpt).toObject().keys()[cpt], v.toObject().value(v.toObject().keys()[cpt])["S"].toString());
        cpt += 1;
    }

    return listGamme;
}
