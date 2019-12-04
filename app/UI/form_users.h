#ifndef FORM_USERS_H
#define FORM_USERS_H

#include <QWidget>
#include "../DB_CLASSES/bdd_user.h"


namespace Ui {
class Form_users;
}

class Form_users : public QWidget
{
    Q_OBJECT

public:
    explicit Form_users(QWidget *parent = nullptr);
    explicit Form_users(QWidget *parent = nullptr, bdd_USER* user = nullptr);
    ~Form_users();

private:
    Ui::Form_users *ui;
    void resizeEvent(QResizeEvent * event);
    bdd_USER* _user;
    int _width;
    int _height;
};

#endif // FORM_USERS_H
