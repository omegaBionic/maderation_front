#include "bdd_role.h"

bdd_ROLE::bdd_ROLE(QString userUsername, QString idRole, QString label)
{
    this->_userUserName =userUsername;
    this->_idRole = idRole;
    this->_label = label;
}
bdd_ROLE::bdd_ROLE(){

}
bdd_ROLE::~bdd_ROLE(){

}
void bdd_ROLE::setUserUsername(QString usrN){
    _userUserName = usrN;
}
void bdd_ROLE::setIdRole(QString idR){
    _idRole = idR;
}
void bdd_ROLE::setLabel(QString lbl){
    _label = lbl;
}

QString bdd_ROLE::getUserUsername(){
    return _userUserName;
}
QString bdd_ROLE::getIdRole(){
    return _idRole;
}
QString bdd_ROLE::getLabel(){
    return _label;
}
