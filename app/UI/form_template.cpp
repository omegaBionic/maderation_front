#include "form_template.h"
#include "ui_form_template.h"

Form_template::Form_template(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_template)
{
    ui->setupUi(this);
}

Form_template::Form_template(QWidget *parent, QString ressource) :
    QWidget(parent),
    ui(new Ui::Form_template)
{
    ui->setupUi(this);
    _res = ressource;

}

Form_template::~Form_template()
{
    delete ui;
}


void Form_template::resizeEvent(QResizeEvent *){
    // format 16:9 only for the moment
    QRect win = this->geometry();
    _width = win.width()/128;
    _height = win.height()/72;
    ui->project_screen->setGeometry(0*_width, 0*_height, 72*_width, 72*_height);
    ui->project_screen->setPixmap(QPixmap(_res).scaled(72*_width, 72*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    ui->pushButton_cancel->setGeometry(QRect(103*_width, 64*_height, 10*_width, 10*_height));
    ui->pushButton_validate->setGeometry(115*_width, 64*_height, 10*_width, 10 *_height);
    ui->comboBox_client->setGeometry(95*_width, 20*_height, 30*_width, 4*_height);
    ui->lineEdit_title->setGeometry(95*_width, 30*_height, 30*_width, 4*_height);

}

void Form_template::on_pushButton_cancel_clicked()
{
    emit cancelled();
}

void Form_template::on_pushButton_validate_clicked()
{
    emit validated();
}

void Form_template::setRessource(QString res)
{
    _res = res;
    ui->project_screen->setPixmap(QPixmap(_res).scaled(72*_width, 72*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

}
