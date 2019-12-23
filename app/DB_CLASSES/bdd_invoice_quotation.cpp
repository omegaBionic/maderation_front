#include "bdd_invoice_quotation.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>

bdd_INVOICE_QUOTATION::bdd_INVOICE_QUOTATION(QString transactionCode, QString idInvoiceQuotation, int totalAmount, QString payingMethod, QString transactionType, int taxes): bdd_global(QString("id"), QString("table"))
{
    this->_transactionCode = transactionCode;
    this->_idInvoinceQuotation = idInvoiceQuotation;
    this->_totalAmount = totalAmount;
    this->_payingMethod = payingMethod;
    this->_transactionType = transactionType;
    this->_taxes = taxes;
}
bdd_INVOICE_QUOTATION::bdd_INVOICE_QUOTATION(): bdd_global(QString("id"), QString("table")){

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

QMap<QString, QString> bdd_INVOICE_QUOTATION::getDict(){

    QFile file;
    file.setFileName("DATA/jsonInvoiceQuotation.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);


    QJsonParseError jsonError;
    QJsonDocument flowerJson = QJsonDocument::fromJson(file.readAll(),&jsonError);
    if (jsonError.error != QJsonParseError::NoError){
    qDebug() << jsonError.errorString();
    }
    QList<QVariant> list = flowerJson.toVariant().toList();
    QMap<QString, QVariant> map = list[0].toMap();
    qDebug() << map["name"].toString();

    //return map;
}
