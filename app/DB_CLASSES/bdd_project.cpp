#include "bdd_project.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>
#include <QJsonArray>

bdd_PROJECT::bdd_PROJECT(QString validationDate, bool validation, QString creationDate, bool isTemplate, QString idProject, QString userUsername, QString Title, QString IDClient): bdd_global(QString("idProject"), QString("project"))
{
    this->_validationDate = validationDate;
    this->_validation = validation;
    this->_creationDate = creationDate;
    this->_isTemplate = isTemplate;
    this->_idProject = idProject;
    this->_userUserName = userUsername;
    this->_Title = Title;
    this->_IDClient = IDClient;
    this->addKey("validationDate", "\"S\":\""+ this->_validationDate + "\"");
    if(this->_validation){
        this->addKey("validation", "\"BOOL\":\"true\"");
    }else{
        this->addKey("validation", "\"BOOL\":\"false\"");
    }

    if(this->_isTemplate){
        this->addKey("isTemplate", "\"BOOL\":\"true\"");
    }else{
        this->addKey("isTemplate", "\"BOOL\":\"false\"");
    }
    this->addKey("idProject", "\"S\":\""+ this->_idProject + "\"");
    this->addKey("creationDate", "\"S\":\""+ this->_creationDate + "\"");
    this->addKey("userUsername", "\"S\":\""+ this->_userUserName + "\"");
    this->addKey("Title", "\"S\":\""+ this->_Title + "\"");
    this->addKey("IDClient", "\"S\":\""+ this->_IDClient + "\"");


}
bdd_PROJECT::bdd_PROJECT(): bdd_global(QString("idProject"), QString("project")){

}

bdd_PROJECT::~bdd_PROJECT(){

}

void bdd_PROJECT::setValidationDate(QString validD){
    _validationDate = validD;
}

void bdd_PROJECT::setValidation(bool valid){
    _validation = valid;
}

void bdd_PROJECT::setCreationDate(QString creaDat){
    _creationDate = creaDat;
}

void bdd_PROJECT::setIsTemplate(bool temp){
    _isTemplate = temp;
}

void bdd_PROJECT::setIdProject(QString idPro){
    _idProject =idPro;
}

void bdd_PROJECT::setuserUseName(QString usrN){
    _userUserName = usrN;
}

void bdd_PROJECT::setIDClient(QString id){
    _IDClient = id;
}

void bdd_PROJECT::setTitle(QString title){
    _Title = title;
}

QString bdd_PROJECT::getTitle(){
   return _Title;
}

QString bdd_PROJECT::getValidationDate(){
   return _validationDate;
}

bool bdd_PROJECT::getValidation(){
    return _validation;
}

QString bdd_PROJECT::getCreationDate(){
    return _creationDate;
}

bool bdd_PROJECT::getIsTemplate(){
    return _isTemplate;
}

QString bdd_PROJECT::getIdProject(){
    return _idProject;
}

QString bdd_PROJECT::getUserUserName(){
    return _userUserName;
}

QString bdd_PROJECT::getIDClient(){
    return _IDClient;
}

QString bdd_PROJECT::getId(){
    return "idProject";
}

QString bdd_PROJECT::getTable(){
    return "project";
}

void bdd_PROJECT::addKey(QString key, QString value){
    bdd_global::addKey(key, value);
    _map.insert(key, value);
}

QMap<QString, QString> bdd_PROJECT::getDict() {
    this->addKey("validationDate", "\"S\":\""+ this->_validationDate + "\"");
    if(this->_validation){
        this->addKey("validation", "\"BOOL\":true");
    }else{
        this->addKey("validation", "\"BOOL\":false");
    }

    if(this->_isTemplate){
        this->addKey("isTemplate", "\"BOOL\":true");
    }else{
        this->addKey("isTemplate", "\"BOOL\":false");
    }
    this->addKey("idProject", "\"S\":\""+ this->_idProject + "\"");
    this->addKey("creationDate", "\"S\":\""+ this->_creationDate + "\"");
    this->addKey("userUsername", "\"S\":\""+ this->_userUserName + "\"");
    this->addKey("Title", "\"S\":\""+ this->_Title + "\"");
    this->addKey("IDClient", "\"S\":\""+ this->_IDClient + "\"");

    bdd_global::getDict();
    return _map;
}
