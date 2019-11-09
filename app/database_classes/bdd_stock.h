#ifndef BDD_STOCK_H
#define BDD_STOCK_H
#include <QFile>

class bdd_STOCK
{
public:
    bdd_STOCK(int amount, QString idStock, int productIdProduct, int addressIdAddress);
    ~bdd_STOCK();

    void setAmount(int);
    void setIdStock(QString);
    void setProductIdProduct(int);
    void setAddressIdAddress(int);

    int getAmmount();
    QString getIdStock();
    int getProductIdProduct();
    int getAddressIdAddress();

private:

    int _amount;
    QString _idStock;
    int _productIdProduct;
    int _addressIdAddress;
};

#endif // BDD_STOCK_H
