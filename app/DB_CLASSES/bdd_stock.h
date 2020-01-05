#ifndef BDD_STOCK_H
#define BDD_STOCK_H
#include <QFile>
#include "bdd_global.h"

class bdd_STOCK : public bdd_global
{
public:
    bdd_STOCK(int amount, QString idStock, int productIdProduct, int addressIdAddress);
    bdd_STOCK();
    virtual ~bdd_STOCK();

    void setAmount(int);
    void setIdStock(QString);
    void setProductIdProduct(int);
    void setAddressIdAddress(int);

    int getAmmount();
    QString getIdStock();
    int getProductIdProduct();
    int getAddressIdAddress();

    QString getId() override;
    QString getTable() override;
    QMap<QString, QString> getDict() override;
    void addKey(QString key, QString value) override;

private:

    int _amount;
    QString _idStock;
    int _productIdProduct;
    int _addressIdAddress;
};

#endif // BDD_STOCK_H
