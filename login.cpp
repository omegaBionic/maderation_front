#include "login.h"
#include "ui_login.h"
#include <QDebug>

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    qDebug() << "test";
}

Login::~Login()
{
    delete ui;
}

