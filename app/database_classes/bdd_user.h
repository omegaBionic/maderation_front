#ifndef USER_H
#define USER_H

#include <QFile>

class bdd_USER
{
    public:
        bdd_USER(QString phoneNumber, bool isActive, QString lastname, QString password, QString firstname, int idAddress, QString mail, QString username);
        bdd_USER();

        //destructeur
        ~bdd_USER();

        void setPhoneNumber(QString);
        void setPassword(QString);
        void setLastName(QString);
        void setMail(QString);
        void setUsername(QString);
        void setFirstName(QString);
        void setIsActive(bool);
        void setIdAddress(int);

        QString getPhoneNumber();
        QString getPassword();
        QString getLastName();
        QString getMail();
        QString getUsername();
        QString getFirstName();
        bool getIsActive();
        int getAddressIdAddress();

    private:
        QString _username;
        QString _phoneNumber;
        QString _password;
        QString _firstname;
        QString _lastname;
        QString _mail;
        bool _isActive;
        int _IDAdress;


};





#endif // USER_H
