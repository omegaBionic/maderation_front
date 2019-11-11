#ifndef BDD_ADDRESS_SUPPLIER_H
#define BDD_ADDRESS_SUPPLIER_H

#include <QFile>

class bdd_ADDRESS_SUPPLIER
{
public:
    bdd_ADDRESS_SUPPLIER(QString city, QString idAddressClient, QString country, int postalCode, QString street);
    bdd_ADDRESS_SUPPLIER();
    ~bdd_ADDRESS_SUPPLIER();

    void setcity(QString);
    void setidAddressClient(QString);
    void setCountry(QString);
    void setPostalCode(int);
    void setStreet(QString);

    QString getCity();
    QString getIdAddressClient();
    QString getCountry();
    int getPostalCode();
    QString getStreet();

private:

    QString _city;
    QString _idAddressClient;
    QString _country;
    int _postalCod;
    QString _street;
};

#endif // BDD_ADDRESS_SUPPLIER_H
