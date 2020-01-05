#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "../UI/main_login.h"
#include "../UI/main_menu.h"
#include "../UI/menu_toolbar.h"
#include "../UI/main_init.h"
#include "../UI/main_chat.h"
#include "../UI/main_user.h"
#include "../UI/main_template.h"
#include "../UI/main_quotation.h"
#include "../DB_CLASSES/bdd_user.h"
#include "../DB_CLASSES/bdd_role.h"

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
    void toolbar_user_mgt();
    void toolbar_logoff();
    void toolbar_messages();
    void toolbar_menu();
    void toolbar_archive();
    void cleanup(int win);
    void init_folder(int step);
    void delete_project(int ID);
    void open_project_by_ID(int ID);
    void open_project(bdd_PROJECT project);

private:
    Main_Login * _login;
    main_init * _init;
    main_user * _main_user;
    main_chat * _chat;
    menu_toolbar* _toolbar;
    Main_Menu* _menu;
    main_template* _template;
    Main_Quotation* _quotation;
    bdd_USER* _user;
    QVector<bdd_ROLE> _user_roles;
    void launchLogin();
};

#endif // CONTROLLER_H
