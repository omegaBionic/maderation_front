#include "widget_custom.h"
#include "ui_widget_custom.h"
#include <QPainter>
#include <QPaintEvent>

widget_custom::widget_custom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget_custom)
{
    ui->setupUi(this);
}

widget_custom::~widget_custom()
{
    delete ui;
}

void widget_custom::paintEvent(QPaintEvent *event){
        QPainter paint(this);
        paint.setRenderHint(QPainter::Antialiasing);
        paint.fillRect(event->rect(), QBrush(Qt::white));

}
