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
    void showFull();

signals:
    void check_login(QString user, QString pwd);
    void forgot_password();
    void Initialized(int window);

private slots:
    void on_btn_login_clicked();

    void on_btn_forgot_clicked();

    void on_pushButton_power_clicked();

private:
    void resizeEvent(QResizeEvent * event);
    bool event(QEvent *event);

    Ui::Main_Login *ui;
    int _width;
    int _height;


};

#endif // MAIN_LOGIN_H
