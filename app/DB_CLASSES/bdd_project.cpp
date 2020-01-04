#include "bdd_project.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>
#include <QJsonArray>

bdd_PROJECT::bdd_PROJECT(QString validationDate, bool validation, QString creationDate, bool isTemplate, QString idProject, QString userUsername): bdd_global(QString("id"), QString("table"))
{
    this->_validationDate = validationDate;
    this->_validation = validation;
    this->_creationDate = creationDate;
    this->_isTemplate = isTemplate;
    this->_idProject = idProject;
    this->_userUserName = userUsername;
}
bdd_PROJECT::bdd_PROJECT(): bdd_global(QString("id"), QString("table")){

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

QString bdd_PROJECT::getId(){
    return "idProject";
}
QString bdd_PROJECT::getTable(){
    return "project";
}

QMap<QString, QString> bdd_PROJECT::getDict(){

    QFile file("DATA/jsonProject.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QMap<QString, QString> listProject;

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    int cpt = 0;

    foreach(const QJsonValue &v, itemsArray)
    {
        listProject.insert(itemsArray.at(cpt).toObject().keys()[cpt], v.toObject().value(v.toObject().keys()[cpt])["S"].toString());
        cpt += 1;
    }

    return listProject;
}
