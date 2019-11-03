#ifndef MAIN_LOGIN_H
#define MAIN_LOGIN_H

#include <QMainWindow>

#include "dialog_critical.h"

namespace Ui {
class Main_Login;
}

class Main_Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Main_Login(QWidget *parent = nullptr);
    ~Main_Login();
    bool CheckConnexion();


private slots:
    void on_pushButton_connect_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Main_Login *ui;

};

#endif // MAIN_LOGIN_H
