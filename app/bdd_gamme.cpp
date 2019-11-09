#include "bdd_gamme.h"
#include <QFile>

bdd_GAMME::bdd_GAMME(QString idGamme, int productIdProduct, QString label)
{
    this->_idGamme = idGamme;
    this->_productIdProduct = productIdProduct;
    this->_label = label;
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
