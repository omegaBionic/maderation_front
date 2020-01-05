#include "bdd_invoice_quotation.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>
#include <QJsonArray>

bdd_INVOICE_QUOTATION::bdd_INVOICE_QUOTATION(QString transactionCode, QString idInvoiceQuotation, int totalAmount, QString payingMethod, QString transactionType, int taxes): bdd_global(QString("idInvoiceQuotation"), QString("invoice_quotation"))
{
    this->_transactionCode = transactionCode;
    this->_idInvoinceQuotation = idInvoiceQuotation;
    this->_totalAmount = totalAmount;
    this->_payingMethod = payingMethod;
    this->_transactionType = transactionType;
    this->_taxes = taxes;
}
bdd_INVOICE_QUOTATION::bdd_INVOICE_QUOTATION(): bdd_global(QString("idInvoiceQuotation"), QString("invoice_quotation")){

}
bdd_INVOICE_QUOTATION::~bdd_INVOICE_QUOTATION(){

}

void bdd_INVOICE_QUOTATION::setTransactionCode(QString transCod){
    _transactionCode = transCod;
}
void bdd_INVOICE_QUOTATION::setIdInvoiceQuotation(QString invoiceQ){
    _idInvoinceQuotation = invoiceQ;
}
void bdd_INVOICE_QUOTATION::setTotalAmount(int tot){
    _totalAmount = tot;
}
void bdd_INVOICE_QUOTATION::setPayingMethod(QString payMet){
    _payingMethod = payMet;
}
void bdd_INVOICE_QUOTATION::setTransactionType(QString transTyp){
    _transactionType = transTyp;
}
void bdd_INVOICE_QUOTATION::setTaxes(int tax){
    _taxes = tax;
}

QString bdd_INVOICE_QUOTATION::getTransactionCode(){
    return _transactionCode;
}
QString bdd_INVOICE_QUOTATION::getIdInvoiceQuotation(){
    return _idInvoinceQuotation;
}
int bdd_INVOICE_QUOTATION::getTotalAmount(){
    return _totalAmount;
}
QString bdd_INVOICE_QUOTATION::getPayingMethod(){
    return _payingMethod;
}
QString bdd_INVOICE_QUOTATION::getTransactionType(){
    return _transactionType;
}
int bdd_INVOICE_QUOTATION::getTaxes(){
    return _taxes;
}

QString bdd_INVOICE_QUOTATION::getId(){
    return "idInvoiceQuotation";
}
QString bdd_INVOICE_QUOTATION::getTable(){
    return "invoice_quotation";
}

void bdd_INVOICE_QUOTATION::addKey(QString key, QString value){
    bdd_global::addKey(key, value);
    _map.insert(key, value);
}

//QString transactionCode, QString idInvoiceQuotation, int totalAmount, QString payingMethod, QString transactionType, int taxes
QMap<QString, QString> bdd_INVOICE_QUOTATION::getDict() {
    this->addKey("transactionCode", "\"S\":\""+ this->_transactionCode + "\"");
    this->addKey("idInvoiceQuotation", "\"S\":\""+ this->_idInvoinceQuotation + "\"");
    this->addKey("payingMethod", "\"S\":\""+ this->_payingMethod + "\"");
    this->addKey("transactionType", "\"S\":\""+ this->_transactionType + "\"");
    this->addKey("totalAmount", "\"N\":\""+ QString::number(this->_totalAmount) + "\"");
    this->addKey("taxes", "\"N\":\""+ QString::number(this->_taxes) + "\"");
    bdd_global::getDict();
    return _map;
}
