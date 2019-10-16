#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_validate_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
