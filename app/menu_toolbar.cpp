#include "menu_toolbar.h"
#include "ui_menu_toolbar.h"

menu_toolbar::menu_toolbar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu_toolbar)
{
    ui->setupUi(this);
}

menu_toolbar::~menu_toolbar()
{
    delete ui;
}
