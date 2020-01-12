#include "form_quotation.h"
#include "ui_form_quotation.h"
#include <QPdfWriter>
#include <QPainter>
#include <QPageSize>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "widget_custom.h"
#include <QtPrintSupport/QtPrintSupport>

#include <QPrinter>




Form_quotation::Form_quotation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_quotation)
{
    ui->setupUi(this);

    QString fileName("DATA_IMG/test.pdf");
    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));

    QPainter painter(&pdfWriter);
    _scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(_scene);


    painter.drawPixmap(QRect(20,20,pdfWriter.logicalDpiX()*1.3,pdfWriter.logicalDpiY()*1.3), QPixmap(":/pictures/img/logo accueil.png").scaled(pdfWriter.logicalDpiX()*1.3,pdfWriter.logicalDpiY()*1.3, Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    painter.drawText(20,pdfWriter.logicalDpiY()*1.4, "MADERA");

    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap(":/pictures/img/logo accueil.png").scaled(100,100, Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    item->setPos(20,20);

    QGraphicsTextItem* text = new QGraphicsTextItem("MADERA");
    text->setPos(20,140);
    _scene->addItem(item);
    _scene->addItem(text);
    this->refreshScene();


    QString html =
    "<div align=right>"
       "City, 11/11/2015"
    "</div>"
    "<div align=left>"
       "Sender Name<br>"
       "street 34/56A<br>"
       "121-43 city"
    "</div>"
    "<h1 align=center>DOCUMENT TITLE</h1>"
    "<p align=justify>"
       "document content document content document content document content document content document content document content document content document content document content "
       "document content document content document content document content document content document content document content document content document content document content "
    "</p>"
    "<div align=right>sincerly</div>";

    QTextDocument document;
    document.setHtml(html);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName("DATA_IMG/testhtml.pdf");
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    document.print(&printer);



}

Form_quotation::~Form_quotation()
{
    delete ui;
}

void Form_quotation::refreshScene(){
    int height = 0;
    if(ui->graphicsView->height() > _scene->height()){
        height = ui->graphicsView->height();
    }else{
        height = _scene->height();
    }
    ui->graphicsView->setSceneRect(0,0,ui->graphicsView->width(), height);

}

void Form_quotation::resizeEvent(QResizeEvent *){
    // format 16:9 only for the moment
    QRect win = this->geometry();
    _width = win.width()/128;
    _height = win.height()/72;
    ui->graphicsView->setGeometry(0*_width, 0*_height, 90*_width, 74*_height);
    this->refreshScene();
}
