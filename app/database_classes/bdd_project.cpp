#include "bdd_project.h"

bdd_PROJECT::bdd_PROJECT(QString validationDate, bool validation, QString creationDate, bool isTemplate, QString idProject, QString userUsername)
{
    this->_validationDate = validationDate;
    this->_validation = validation;
    this->_creationDate = creationDate;
    this->_isTemplate = isTemplate;
    this->_idProject = idProject;
    this->_userUserName = userUsername;
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
