#include "bdd_attribut.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>

bdd_ATTRIBUT::bdd_ATTRIBUT(int length, int positionY, int width, int height, int productIdProduct, int orderIdProject, int positionX, int rotationY, int positionZ, int rotationX, int idAttribut) : bdd_global(QString("id"), QString("table"))
{
    this->_length = length;
    this->_positionY = positionY;
    this->_width = width;
    this->_height = height;
    this->_productIdProduct = productIdProduct;
    this->_orderIdProject = orderIdProject;
    this->_positionX = positionX;
    this->_rotationY = rotationY;
    this->_positionZ = positionZ;
    this->_rotationX = rotationX;
    this->_idAttribut = idAttribut;
}

bdd_ATTRIBUT::bdd_ATTRIBUT(): bdd_global(QString("id"), QString("table")){

}
bdd_ATTRIBUT::~bdd_ATTRIBUT(){

}

void bdd_ATTRIBUT::setLength(int lgth){
    _length = lgth;
}
void bdd_ATTRIBUT::setPositionY(int posY){
    _positionY = posY;
}
void bdd_ATTRIBUT::setWidth(int wdth){
    _width = wdth;
}
void bdd_ATTRIBUT::setHeight(int lgth){
    _length = lgth;
}
void bdd_ATTRIBUT::setProductIdProduct(int idProd){
    _productIdProduct = idProd;
}
void bdd_ATTRIBUT::setOrderIdProject(int idOrd){
    _orderIdProject = idOrd;
}
void bdd_ATTRIBUT::setPositionX(int posX){
    _positionX = posX;
}
void bdd_ATTRIBUT::setRotationY(int rotY){
    _rotationY = rotY;
}
void bdd_ATTRIBUT::setPositionZ(int posZ){
    _positionZ = posZ;
}
void bdd_ATTRIBUT::setRotationX(int rotX){
    _rotationX = rotX;
}
void bdd_ATTRIBUT::setIdAttribut(int idAtt){
    _idAttribut = idAtt;
}

int bdd_ATTRIBUT::getLength(){
    return _length;
}
int bdd_ATTRIBUT::getPositionY(){
    return _positionY;
}
int bdd_ATTRIBUT::getWidth(){
   return _width;
}
int bdd_ATTRIBUT::getHeight(){
   return _length;
}
int bdd_ATTRIBUT::getProductIdProduct(){
   return _productIdProduct;
}
int bdd_ATTRIBUT::getOrderIdProject(){
   return _orderIdProject;
}
int bdd_ATTRIBUT::getPositionX(){
   return _positionX;
}
int bdd_ATTRIBUT::getRotationY(){
   return _rotationY;
}
int bdd_ATTRIBUT::getPositionZ(){
   return _positionZ;
}
int bdd_ATTRIBUT::getRotationX(){
   return _rotationX;
}
int bdd_ATTRIBUT::getIdAttribut(){
   return _idAttribut;
}

QString bdd_ATTRIBUT::getId(){
    return "idAttribut";
}
QString bdd_ATTRIBUT::getTable(){
    return "attribut";
}

QMap<QString, QString> bdd_ATTRIBUT::getDict(){

}
