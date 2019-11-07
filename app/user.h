#ifndef USER_H
#define USER_H

#include <QFile>

class User
{
    public:
        User(QString username, QString phoneNumber, bool isActive, QString password, QString lastName, QString firstName, QString mail, int IDAdress);
        ~User();

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
