#include "bdd_quotation.h"

bdd_QUOTATION::bdd_QUOTATION(bool validation, QString creationDate, bool isTemplate, QString idQuotation, QString userUsername, QString validationDate )
{
    this->_validationDate = validationDate;
    this->_validation = validation;
    this->_creationDate = creationDate;
    this->_isTemplate = isTemplate;
    this->_idQuotation = idQuotation;
    this->_userUserName = userUsername;
}

void bdd_QUOTATION::setValidationDate(QString validD){
    _validationDate = validD;
}
void bdd_QUOTATION::setValidation(bool valid){
    _validation = valid;
}
void bdd_QUOTATION::setCreationDate(QString creaDat){
    _creationDate = creaDat;
}
void bdd_QUOTATION::setIsTemplate(bool temp){
    _isTemplate = temp;
}
void bdd_QUOTATION::setIdQuotation(QString idQuo){
    _idQuotation =idQuo;
}
void bdd_QUOTATION::setuserUseName(QString usrN){
    _userUserName = usrN;
}

QString bdd_QUOTATION::getValidationDate(){
   return _validationDate;
}
bool bdd_QUOTATION::getValidation(){
    return _validation;
}
QString bdd_QUOTATION::getCreationDate(){
    return _creationDate;
}
bool bdd_QUOTATION::getIsTemplate(){
    return _isTemplate;
}
QString bdd_QUOTATION::getIdQuotation(){
    return _idQuotation;
}
QString bdd_QUOTATION::getUserUserName(){
    return _userUserName;
}
