#include "bdd_promotion_cat.h"

bdd_PROMOTION_CAT::bdd_PROMOTION_CAT(int amount, bool addToExistingProm, QString fromDate, QString idPromotionCat, QString toDate)
{
    this->_amount = amount;
    this->_addToExistingProm =addToExistingProm;
    this->_fromDate = fromDate;
    this->_idPromotionCat = idPromotionCat;
    this->_toDate =toDate;
}
bdd_PROMOTION_CAT::bdd_PROMOTION_CAT(){

}
bdd_PROMOTION_CAT::~bdd_PROMOTION_CAT(){

}
void bdd_PROMOTION_CAT::setAmount(int amnt){
    _amount = amnt;
}
void bdd_PROMOTION_CAT::setAddToExistingProm(bool addExistP){
    _addToExistingProm = addExistP;
}
void bdd_PROMOTION_CAT::setFromDate(QString fromD){
    _fromDate = fromD;
}
void bdd_PROMOTION_CAT::setIdPromotionCat(QString idPromC){
    _idPromotionCat = idPromC;
}
void bdd_PROMOTION_CAT::setToDate(QString toD){
    _toDate = toD;
}

int bdd_PROMOTION_CAT::getAmount(){
    return _amount;
}
bool bdd_PROMOTION_CAT::getAddToExistingProm(){
    return _addToExistingProm;
}
QString bdd_PROMOTION_CAT::getFromDate(){
    return _fromDate;
}
QString bdd_PROMOTION_CAT::getIdPromotionCat(){
    return _idPromotionCat;
}
QString bdd_PROMOTION_CAT::getToDate(){
    return _toDate;
}
