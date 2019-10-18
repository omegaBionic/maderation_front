#include "dialog_critical.h"
#include "ui_dialog_critical.h"
#include <QMessageBox>

Dialog_Critical::Dialog_Critical(QWidget *parent, QString title, QString text,QString icon) :
    QDialog(parent),
    ui(new Ui::Dialog_Critical)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    ui->label_title->setText(title);
    ui->label_text->setText(text);
    ui->cancel->hide();
    QIcon icon_button;
    if(icon=="critical")
        icon_button = QIcon(":/pictures/gui_resources/critical.png");
        ui->icon->setIcon(icon_button);
    if(icon=="information")
        icon_button = QIcon(":/pictures/gui_resources/information.png");
        ui->icon->setIcon(icon_button);
    if(icon=="question"){
        icon_button = QIcon(":/pictures/gui_resources/question.ico");
        ui->icon->setIcon(icon_button);
        ui->cancel->show();
    }
    ui->icon->setIconSize(ui->icon->size());

    connect(ui->validate, SIGNAL (clicked()), this, SLOT (on_validate_clicked()));
    connect(ui->cancel, SIGNAL (clicked()), this, SLOT (on_cancel_clicked()));
}

Dialog_Critical::~Dialog_Critical()
{
    delete ui;
}

void Dialog_Critical::on_validate_clicked()
{
    this->accept();
}

void Dialog_Critical::on_cancel_clicked()
{
    this->reject();
}

