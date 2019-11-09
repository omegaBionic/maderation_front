#include "bdd_stock.h"

bdd_STOCK::bdd_STOCK(int amount, QString idStock, int productIdProduct, int addressIdAddress)
{
    this->_amount = amount;
    this->_idStock = idStock;
    this->_productIdProduct = productIdProduct;
    this->_addressIdAddress = addressIdAddress;
}

void bdd_STOCK::setAmount(int amnt){
    _amount = amnt;
}
void bdd_STOCK::setIdStock(QString idS){
    _idStock = idS;
}
void bdd_STOCK::setProductIdProduct(int idProd){
    _productIdProduct = idProd;
}
void bdd_STOCK::setAddressIdAddress(int idAdd){
    _addressIdAddress =idAdd;
}

int bdd_STOCK::getAmmount(){
return _amount;
}
QString bdd_STOCK::getIdStock(){
return _idStock;
}
int bdd_STOCK::getProductIdProduct(){
return _productIdProduct;
}
int bdd_STOCK::getAddressIdAddress(){
return _addressIdAddress;
}
