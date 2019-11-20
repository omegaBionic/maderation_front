#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "../UI/main_login.h"
#include "../UI/main_menu.h"
#include "../UI/menu_toolbar.h"
#include "../UI/main_init.h"
#include "../DB_CLASSES/bdd_user.h"

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
    void init_folder(int step);

private:
    Main_Login * _login;
    main_init * _init;
    menu_toolbar* _toolbar;
    Main_Menu* _menu;
    bdd_USER* _user;
    void launchLogin();
};

#endif // CONTROLLER_H
