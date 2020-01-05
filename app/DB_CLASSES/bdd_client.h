#ifndef BDD_CLIENT_H
#define BDD_CLIENT_H

#include "bdd_global.h"
#include <QFile>


class bdd_CLIENT : public bdd_global
{
    public:
        bdd_CLIENT(QString idClient, QString phoneNumber, bool isActive, QString password, QString lastname, QString mail, QString firstname, int addressIDAdress);
        bdd_CLIENT();
        virtual ~bdd_CLIENT();

        void setPhoneNumber(QString);
        void setIdClient(QString);
        void setPassword(QString);
        void setLastName(QString);
        void setMail(QString);
        void setFirstName(QString);
        void setIsActive(bool);
        void setAddressIdAddress(int);

        QString getPhoneNumber();
        QString getPassword();
        QString getLastName();
        QString getMail();
        QString getFirstName();
        bool getIsActive();
        int getAddressIdAddress();
        QString getIdClient();

        QString getId() override;
        QString getTable() override;
        QMap<QString, QString> getDict() override;
        void addKey(QString key, QString value) override;

    private:
        QString _idClient;
        QString _phoneNumber;
        QString _password;
        QString _firstname;
        QString _lastname;
        QString _mail;
        bool _isActive;
        int _addressIDAdress;


};

#endif // BDD_CLIENT_H
