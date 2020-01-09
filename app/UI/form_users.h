#ifndef FORM_USERS_H
#define FORM_USERS_H

#include <QWidget>
#include "../DB_CLASSES/bdd_user.h"
#include "../DB_CLASSES/bdd_role.h"


namespace Ui {
class Form_users;
}

class Form_users : public QWidget
{
    Q_OBJECT

public:
    explicit Form_users(QWidget *parent = nullptr);
    explicit Form_users(QWidget *parent = nullptr, bdd_USER user = bdd_USER());
    explicit Form_users(QWidget *parent = nullptr, QString mode = "new");
    ~Form_users();
    bdd_USER getUser();
    void addUser();

signals:

    void UsersUpdated(int i);

private slots:
    void on_pushButton_validate_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_reset_clicked();

    void on_comboBox_shop_currentTextChanged(const QString &arg1);

    void on_lineEdit_firstname_textChanged(const QString &arg1);

    void on_lineEdit_lastname_textChanged(const QString &arg1);

    void on_lineEdit_email_textChanged(const QString &arg1);

    void on_lineEdit_phone_textChanged(const QString &arg1);

    void on_checkBox_active_stateChanged(int arg1);

    void on_lineEdit_username_textChanged(const QString &arg1);

private:
    Ui::Form_users *ui;
    void resizeEvent(QResizeEvent * event);
    void setAttributs();
    bdd_USER _user;
    bdd_USER _baseUser;
    QVector<bdd_ROLE> _user_roles;
    int _width;
    int _height;
    QString _mode;
};

#endif // FORM_USERS_H
