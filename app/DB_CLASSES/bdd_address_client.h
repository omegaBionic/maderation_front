#ifndef BDD_ADDRESS_CLIENT_H
#define BDD_ADDRESS_CLIENT_H

#include "bdd_global.h"
#include <QFile>

class bdd_ADDRESS_CLIENT : public bdd_global
{
public:
    bdd_ADDRESS_CLIENT(QString city, QString idAddressClient, QString country, int postalCode, QString street);
    bdd_ADDRESS_CLIENT();
    virtual ~bdd_ADDRESS_CLIENT();

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

    QString getId() override;
    QString getTable() override;
    QMap<QString, QString> getDict() override;

    QMap<QStringList, QString> TestDict();

private:

    QString _city;
    QString _idAddressClient;
    QString _country;
    int _postalCod;
    QString _street;
};

#endif // BDD_ADDRESS_CLIENT_H
