#include "bdd_component.h"
#include <QFile>

bdd_COMPONENT::bdd_COMPONENT(int supplierIdSupplier, QString idComponent, int categoryIdCategory, QString label)
{
    this->_supplierIdSupplier = supplierIdSupplier;
    this->_idComponent = idComponent;
    this->_categoryIdCategory = categoryIdCategory;
    this->_label = label;
}
bdd_COMPONENT::bdd_COMPONENT(){

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
