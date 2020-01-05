#ifndef BDD_ADDRESS_SUPPLIER_H
#define BDD_ADDRESS_SUPPLIER_H

#include "bdd_global.h"
#include <QFile>

class bdd_ADDRESS_SUPPLIER : public bdd_global
{
public:
    bdd_ADDRESS_SUPPLIER(QString city, QString idAddressSupplier, QString country, int postalCode, QString street);
    bdd_ADDRESS_SUPPLIER();
    virtual ~bdd_ADDRESS_SUPPLIER();

    void setcity(QString);
    void setidAddressSupplier(QString);
    void setCountry(QString);
    void setPostalCode(int);
    void setStreet(QString);

    QString getCity();
    QString getIdAddressSupplier();
    QString getCountry();
    int getPostalCode();
    QString getStreet();

    QString getId() override;
    QString getTable() override;
    QMap<QString, QString> getDict() override;
    void addKey(QString key, QString value) override;

private:

    QString _city;
    QString _idAddressSupplier;
    QString _country;
    int _postalCod;
    QString _street;
};

#endif // BDD_ADDRESS_SUPPLIER_H
