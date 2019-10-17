#include "main_login.h"
#include "ui_main_login.h"

Main_login::Main_login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Main_login)
{
    ui->setupUi(this);
}

Main_login::~Main_login()
{
    delete ui;
}
