#ifndef BDD_SHOP_H
#define BDD_SHOP_H
#include <QFile>
#include "bdd_global.h"

class bdd_SHOP : public bdd_global
{
public:
    bdd_SHOP(QString city, QString idShop, QString country, int postalCode, QString street);
    bdd_SHOP();
    virtual ~bdd_SHOP();

    void setCity(QString);
    void setIdShop(QString);
    void setCountry(QString);
    void setPostalCode(int);
    void setStreet(QString);

    QString getCity();
    QString getIdShop();
    QString getCountry();
    int getPostalCode();
    QString getStreet();

    QString getId() override;
    QString getTable() override;
    QMap<QString, QString> getDict() override;
    void addKey(QString key, QString value) override;

private:

    QString _city;
    QString _idShop;
    QString _country;
    int _postalCode;
    QString _street;
};

#endif // BDD_SHOP_H
