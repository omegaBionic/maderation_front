#ifndef BDD_INVOICE_QUOTATION_H
#define BDD_INVOICE_QUOTATION_H
#include <QFile>

class bdd_INVOICE_QUOTATION
{
public:
    bdd_INVOICE_QUOTATION(QString transactionCode, QString idInvoiceQuotation, int totalAmount, QString payingMethod, QString transactionType, int taxes);
    bdd_INVOICE_QUOTATION();
    ~bdd_INVOICE_QUOTATION();

    void setTransactionCode(QString);
    void setIdInvoiceQuotation(QString);
    void setTotalAmount(int);
    void setPayingMethod(QString);
    void setTransactionType(QString);
    void setTaxes(int);

    QString getTransactionCode();
    QString getIdInvoiceQuotation();
    int getTotalAmount();
    QString getPayingMethod();
    QString getTransactionType();
    int getTaxes();

private:

    QString _transactionCode;
    QString _idInvoinceQuotation;
    int _totalAmount;
    QString _payingMethod;
    QString _transactionType;
    int _taxes;
};

#endif // BDD_INVOICE_QUOTATION_H
