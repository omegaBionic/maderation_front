#ifndef MAIN_USER_H
#define MAIN_USER_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include "menu_toolbar.h"
#include "form_users.h"
#include "../DB_CLASSES/bdd_user.h"

namespace Ui {
class main_user;
}

class main_user : public QMainWindow
{
    Q_OBJECT

public:
    explicit main_user(QWidget *parent = nullptr);
    explicit main_user(QWidget *parent = nullptr, menu_toolbar* menu = nullptr, QVector<bdd_USER>* list_user = nullptr);
    ~main_user();


signals:
    void Initialized(int window);


private slots:
    void on_pushButton_power_clicked();

    void on_pushButton_clicked();
    void reloadUsers(int status);
    void reloadTable(QString t);

private:
    QVector<Form_users*>* _listUIUsers;
    QVector<bdd_USER> _listUsers;
    void setUsers();
    Ui::main_user *ui;
    void wait(int time, int interval);
    void resizeEvent(QResizeEvent * event);
    bool event(QEvent *event);
    int _width;
    int _height;
    menu_toolbar* _menu;
};

#endif // MAIN_USER_H
