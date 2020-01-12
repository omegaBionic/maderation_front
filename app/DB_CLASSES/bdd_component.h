#ifndef BDD_COMPONENT_H
#define BDD_COMPONENT_H
#include <QFile>
#include "bdd_global.h"

class bdd_COMPONENT : public bdd_global
{
public:
    bdd_COMPONENT(int supplierIdSupplier, QString idComponent, int categoryIdCategory, QString label, int amount, double price, QString idProduct);
    bdd_COMPONENT();
    virtual ~bdd_COMPONENT();

    void setSupplierIdSupplier(int);
    void setIdComponent(QString);
    void setCategoryIdCategory(int);
    void setLabel(QString);
    void setAmount(int);
    void setPrice(double);
    void setIDProduct(QString);

    int getSupplierIdSupplier();
    QString getIdComponent();
    int getCategoryIdCategory();
    double getPrice();
    QString getIDProduct();
    int getAmount();
    QString getLabel();

    QString getId() override;
    QString getTable() override;
    QMap<QString, QString> getDict() override;
    void addKey(QString key, QString value) override;

private:
    int _supplierIdSupplier;
    QString _idComponent;
    int _categoryIdCategory;
    int _amount;
    QString _idProduct;
    double _price;
    QString _label;
};

#endif // BDD_COMPONENT_H
