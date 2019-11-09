#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "main_login.h"
#include "./database_classes/bdd_user.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    int init();
    Main_Login* getLogin();
    bdd_USER* getUser();

private slots:
    void login(QString user, QString pwd);

private:
    Main_Login * _login;
    bdd_USER* _user;
};

#endif // CONTROLLER_H
