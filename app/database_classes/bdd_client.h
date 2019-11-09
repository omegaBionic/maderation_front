#ifndef BDD_CLIENT_H
#define BDD_CLIENT_H

#include <QFile>


class bdd_CLIENT
{
    public:
        bdd_CLIENT(QString phoneNumber,QString idCLient, bool isActive, QString password, QString lastName, QString firstName, QString mail, int addressIdAddress);
        ~bdd_CLIENT();

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
