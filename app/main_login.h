#ifndef MAIN_LOGIN_H
#define MAIN_LOGIN_H

#include <QMainWindow>

#include "dialog_critical.h"
#include "menu_toolbar.h"

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
    void on_btn_login_clicked();

private:
    Ui::Main_Login *ui;
    void resizeEvent(QResizeEvent * event);
    int _width;
    int _height;

};

#endif // MAIN_LOGIN_H
