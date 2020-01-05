#ifndef BDD_SUPPLIER_H
#define BDD_SUPPLIER_H
#include <QFile>
#include "bdd_global.h"

class bdd_SUPPLIER : public bdd_global
{
public:
    bdd_SUPPLIER(QString phoneNumber, QString mail, QString description, QString name, QString idSupplier, int addressIdAddress);
    bdd_SUPPLIER();
    virtual ~bdd_SUPPLIER();

    void setPhoneNumber(QString);
    void setMail(QString);
    void setDescription(QString);
    void setName(QString);
    void setIdSupplier(QString);
    void setAddressIDAddress(int);

    QString getPhoneNumber();
    QString getMail();
    QString getDescription();
    QString getName();
    QString getIdSupplier();
    int getAddressIdAddress();

    QString getId() override;
    QString getTable() override;
    QMap<QString, QString> getDict() override;
    void addKey(QString key, QString value) override;

private:
    QString _phoneNumber;
    QString _mail;
    QString _description;
    QString _name;
    QString _idSupplier;
    int _addressIdAddres;
};

#endif // BDD_SUPPLIER_H
