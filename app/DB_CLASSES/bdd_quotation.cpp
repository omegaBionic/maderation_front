#include "bdd_quotation.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>
#include <QJsonArray>

bdd_QUOTATION::bdd_QUOTATION(bool validation, QString idQuotation, QString creationDate, bool isTemplate, QString userUsername, QString validationDate ): bdd_global(QString("idQuotation"), QString("quotation"))
{
    this->_validationDate = validationDate;
    this->_validation = validation;
    this->_creationDate = creationDate;
    this->_isTemplate = isTemplate;
    this->_idQuotation = idQuotation;
    this->_userUserName = userUsername;
}
bdd_QUOTATION::bdd_QUOTATION(): bdd_global(QString("idQuotation"), QString("quotation")){

}
bdd_QUOTATION::~bdd_QUOTATION(){

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

QString bdd_QUOTATION::getId(){
    return "idQuotation";
}
QString bdd_QUOTATION::getTable(){
    return "quotation";
}


void bdd_QUOTATION::addKey(QString key, QString value){
    bdd_global::addKey(key, value);
    _map.insert(key, value);
}

//bool validation, QString idQuotation, QString creationDate, bool isTemplate, QString userUsername, QString validationDate
QMap<QString, QString> bdd_QUOTATION::getDict() {
    this->addKey("idQuotation", "\"S\":\""+ this->_idQuotation + "\"");
    this->addKey("creationDate", "\"S\":\""+ this->_creationDate + "\"");
    this->addKey("userUserName", "\"S\":\""+ this->_userUserName + "\"");
    this->addKey("validationDate", "\"S\":\""+ this->_validationDate + "\"");
    if(this->_validation){
        this->addKey("validation", "\"B\":\"true\"");
    }else{
        this->addKey("validation", "\"B\":\"false\"");
    }
    if(this->_isTemplate){
        this->addKey("isTemplate", "\"B\":\"true\"");
    }else{
        this->addKey("isTemplate", "\"B\":\"false\"");
    }
    bdd_global::getDict();
    return _map;
}

