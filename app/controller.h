#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "main_login.h"
#include "./database_classes/bdd_user.h"
#include "main_menu.h"
#include "menu_toolbar.h"

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
    void login_forgot_password();
    void toolbar_alert();
    void toolbar_logoff();
    void toolbar_messages();
    void toolbar_menu();
    void toolbar_archive();
    void cleanup(int win);

private:
    Main_Login * _login;
    menu_toolbar* _toolbar;
    Main_Menu* _menu;
    bdd_USER* _user;
};

#endif // CONTROLLER_H
