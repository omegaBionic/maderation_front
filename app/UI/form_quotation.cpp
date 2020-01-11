#include "form_quotation.h"
#include "ui_form_quotation.h"
#include <QPdfWriter>
#include <QPainter>
#include <QPageSize>

Form_quotation::Form_quotation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_quotation)
{
    ui->setupUi(this);

    QString fileName("DATA_IMG/test.pdf");
    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    QPainter painter(&pdfWriter);

    for (int i=0; i<3; ++i) {
        painter.drawPixmap(QRect(0,0,pdfWriter.logicalDpiX()*8.3,pdfWriter.logicalDpiY()*11.7), QPixmap("DATA_IMG/quot_new.png"));
        pdfWriter.newPage();
    }

}

Form_quotation::~Form_quotation()
{
    delete ui;
}
