#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "main_login.h"
#include "user.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    int init();
    Main_Login* getLogin();
    User* getUser();

private slots:
    void login(QString user, QString pwd);

private:
    Main_Login * _login;
    User* _user;
};

#endif // CONTROLLER_H
