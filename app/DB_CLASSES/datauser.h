#ifndef DATAUSER_H
#define DATAUSER_H
#include <QFile>

class dataUser
{
    public:
        dataUser(QString role,QString phoneNumber, bool isActive, QString lastname, QString password, QString firstname, int idAddress, QString mail, QString username);
        dataUser();

        //destructeur
        ~dataUser();

        void setRole(QString);

        void setPhoneNumber(QString);
        void setPassword(QString);
        void setLastName(QString);
        void setMail(QString);
        void setUsername(QString);
        void setFirstName(QString);
        void setIsActive(bool);
        void setIdAddress(int);

        QString getRole();

        QString getPhoneNumber();
        QString getPassword();
        QString getLastName();
        QString getMail();
        QString getUsername();
        QString getFirstName();
        bool getIsActive();
        int getAddressIdAddress();

    private:

        QString _role;
        QString _username;
        QString _phoneNumber;
        QString _password;
        QString _firstname;
        QString _lastname;
        QString _mail;
        bool _isActive;
        int _IDAdress;


};

#endif // DATAUSER_H
