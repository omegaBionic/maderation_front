#ifndef BDD_ADDRESS_CLIENT_H
#define BDD_ADDRESS_CLIENT_H

#include <QFile>

class bdd_ADDRESS_CLIENT
{
public:
    bdd_ADDRESS_CLIENT(QString city, QString idAddressClient, QString country, int postalCode, QString street);
    bdd_ADDRESS_CLIENT();
    ~bdd_ADDRESS_CLIENT();

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

#endif // BDD_ADDRESS_CLIENT_H
