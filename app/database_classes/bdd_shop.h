#ifndef BDD_SHOP_H
#define BDD_SHOP_H
#include <QFile>

class bdd_SHOP
{
public:
    bdd_SHOP(QString city, QString idShop, QString country, int postalCode, QString street);
    bdd_SHOP();
    ~bdd_SHOP();

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

private:

    QString _city;
    QString _idShop;
    QString _country;
    int _postalCode;
    QString _street;
};

#endif // BDD_SHOP_H
