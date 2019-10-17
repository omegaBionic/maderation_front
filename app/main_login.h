#ifndef MAIN_LOGIN_H
#define MAIN_LOGIN_H

#include <QMainWindow>

namespace Ui {
class Main_login;
}

class Main_login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Main_login(QWidget *parent = nullptr);
    ~Main_login();

private:
    Ui::Main_login *ui;
};

#endif // MAIN_LOGIN_H
