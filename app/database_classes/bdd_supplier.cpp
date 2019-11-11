#include "bdd_supplier.h"

bdd_SUPPLIER::bdd_SUPPLIER(QString phoneNumber, QString mail, QString description, QString name, QString idSupplier, int addressIdAddress)
{
    this->_phoneNumber = phoneNumber;
    this->_mail = mail;
    this->_description = description;
    this-> _name = name;
    this->_idSupplier = idSupplier;
    this->_addressIdAddres = addressIdAddress;
}
bdd_SUPPLIER::bdd_SUPPLIER(){

}
bdd_SUPPLIER::~bdd_SUPPLIER(){

}
void bdd_SUPPLIER::setPhoneNumber(QString phoneN){
    _phoneNumber = phoneN;
}
void bdd_SUPPLIER::setMail(QString ml){
    _mail = ml;
}
void bdd_SUPPLIER::setDescription(QString desc){
    _description = desc;
}
void bdd_SUPPLIER::setName(QString nm){
    _name = nm;
}
void bdd_SUPPLIER::setIdSupplier(QString idSupp){
    _idSupplier = idSupp;
}
void bdd_SUPPLIER::setAddressIDAddress(int idAdd){
    _addressIdAddres = idAdd;
}

QString bdd_SUPPLIER::getPhoneNumber(){
    return _phoneNumber;
}
QString bdd_SUPPLIER::getMail(){
    return _mail;
}
QString bdd_SUPPLIER::getDescription(){
    return _description;
}
QString bdd_SUPPLIER::getName(){
    return _name;
}
QString bdd_SUPPLIER::getIdSupplier(){
    return _idSupplier;
}
int bdd_SUPPLIER::getAddressIdAddress(){
    return _addressIdAddres;
}
