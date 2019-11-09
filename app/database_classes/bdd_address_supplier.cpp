#include "bdd_address_supplier.h"

bdd_ADDRESS_SUPPLIER::bdd_ADDRESS_SUPPLIER(QString city, QString idAddressClient, QString country, int postalCode, QString street)
{
    this->_city = city;
    this->_idAddressClient = idAddressClient;
    this->_country = country;
    this->_postalCod = postalCode;
    this->_street = street;
}
void bdd_ADDRESS_SUPPLIER::setcity(QString cit){
    _city = cit;
}
void bdd_ADDRESS_SUPPLIER::setidAddressClient(QString idAdCli){
    _idAddressClient = idAdCli;
}
void bdd_ADDRESS_SUPPLIER::setCountry(QString cntry){
    _country = cntry;
}
void bdd_ADDRESS_SUPPLIER::setPostalCode(int pc){
    _postalCod = pc;
}
void bdd_ADDRESS_SUPPLIER::setStreet(QString str){
    _street = str;
}

QString bdd_ADDRESS_SUPPLIER::getCity(){
    return _city;
}
QString bdd_ADDRESS_SUPPLIER::getIdAddressClient(){
    return _idAddressClient;
}
QString bdd_ADDRESS_SUPPLIER::getCountry(){
    return _country;
}
int bdd_ADDRESS_SUPPLIER::getPostalCode(){
    return _postalCod;
}
QString bdd_ADDRESS_SUPPLIER::getStreet(){
   return _street;
}

