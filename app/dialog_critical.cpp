#include "dialog_critical.h"
#include "ui_dialog_critical.h"

Dialog_Critical::Dialog_Critical(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Critical)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint);
}

Dialog_Critical::~Dialog_Critical()
{
    delete ui;
}
