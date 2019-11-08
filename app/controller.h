#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "main_login.h"
#include "main_menu.h"
#include "menu_toolbar.h"
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
    void toolbar_alert();
    void toolbar_logoff();
    void toolbar_messages();
    void toolbar_menu();
    void toolbar_archive();

private:
    void cleanup();
    Main_Login * _login;
    menu_toolbar* _toolbar;
    Main_Menu* _menu;
    User* _user;
};

#endif // CONTROLLER_H
