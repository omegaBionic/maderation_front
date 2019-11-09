#include "bdd_category.h"

#include <QFile>

bdd_CATEGORY::bdd_CATEGORY(QString idCategory, QString label)
{
this->_idIdCategory = idCategory;
this->_Label = label;
}

void bdd_CATEGORY::setIdCategory(QString idCat){
    _idIdCategory = idCat;
}
void bdd_CATEGORY::setLabel(QString lbl){
    _Label = lbl;
}

QString bdd_CATEGORY::getIdCategory(){
    return _idIdCategory;
}
QString bdd_CATEGORY::getLabel(){
    return _Label;
}
