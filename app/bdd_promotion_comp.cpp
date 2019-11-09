#include "bdd_promotion_comp.h"

bdd_PROMOTION_COMP::bdd_PROMOTION_COMP(int amount, bool addToExistingProm, QString fromDate, QString idPromotionComp, QString toDate)
{
    this->_amount = amount;
    this->_addToExistingProm =addToExistingProm;
    this->_fromDate = fromDate;
    this->_idPromotionComp = idPromotionComp;
    this->_toDate =toDate;
}

void bdd_PROMOTION_COMP::setAmount(int amnt){
    _amount = amnt;
}
void bdd_PROMOTION_COMP::setAddToExistingProm(bool addExistP){
    _addToExistingProm = addExistP;
}
void bdd_PROMOTION_COMP::setFromDate(QString fromD){
    _fromDate = fromD;
}
void bdd_PROMOTION_COMP::setIdPromotionComp(QString idPromC){
    _idPromotionComp = idPromC;
}
void bdd_PROMOTION_COMP::setToDate(QString toD){
    _toDate = toD;
}

int bdd_PROMOTION_COMP::getAmount(){
    return _amount;
}
bool bdd_PROMOTION_COMP::getAddToExistingProm(){
    return _addToExistingProm;
}
QString bdd_PROMOTION_COMP::getFromDate(){
    return _fromDate;
}
QString bdd_PROMOTION_COMP::getIdPromotionComp(){
    return _idPromotionComp;
}
QString bdd_PROMOTION_COMP::getToDate(){
    return _toDate;
}
