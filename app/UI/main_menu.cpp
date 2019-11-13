#include "main_menu.h"
#include "ui_main_menu.h"
#include <QDebug>
#include <math.h>
#include <QThread>

Main_Menu::Main_Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Main_Menu)
{
    ui->setupUi(this);
    _menu = new menu_toolbar(this);
}

Main_Menu::Main_Menu(QWidget *parent, menu_toolbar* m) :
    QMainWindow(parent),
    ui(new Ui::Main_Menu)
{
    ui->setupUi(this);
    _menu = m;
    _menu->setParent(this);
    _listButton_quot = new QVector<button_quotation*>;
    _listButton_del = new QVector<button_quotation*>;
    _listLabel_Button = new QVector<QLabel*>;
    _listButton_quot->append(new button_quotation(ui->scrollAreaWidgetContents,0, "DATA_IMG/quot_new.png"));
    _listButton_del->append(new button_quotation(ui->scrollAreaWidgetContents,0, ":/pictures/img/trash_logo.png",true));
    _listLabel_Button->append(new QLabel("New", ui->scrollAreaWidgetContents)); // new icon
    _listButton_quot->append(new button_quotation(ui->scrollAreaWidgetContents,1,"DATA_IMG/quot_ex_1.png"));
    _listButton_del->append(new button_quotation(ui->scrollAreaWidgetContents,1, ":/pictures/img/trash_logo.png",true));
    _listLabel_Button->append(new QLabel("premier", ui->scrollAreaWidgetContents));
    _listButton_quot->append(new button_quotation(ui->scrollAreaWidgetContents,2, "DATA_IMG/quot_ex_2.png"));
    _listButton_del->append(new button_quotation(ui->scrollAreaWidgetContents,2, ":/pictures/img/trash_logo.png",true));
    _listLabel_Button->append(new QLabel("second", ui->scrollAreaWidgetContents));
    _listButton_quot->append(new button_quotation(ui->scrollAreaWidgetContents,3));
    _listButton_del->append(new button_quotation(ui->scrollAreaWidgetContents,3, ":/pictures/img/trash_logo.png",true));
    _listLabel_Button->append(new QLabel("Null", ui->scrollAreaWidgetContents));
    _listButton_quot->append(new button_quotation(ui->scrollAreaWidgetContents,4, "DATA_IMG/quot_ex_1.png"));
    _listButton_del->append(new button_quotation(ui->scrollAreaWidgetContents,4, ":/pictures/img/trash_logo.png",true));
    _listLabel_Button->append(new QLabel("4eme", ui->scrollAreaWidgetContents));
    _listButton_quot->append(new button_quotation(ui->scrollAreaWidgetContents,5, "DATA_IMG/quot_ex_2.png"));
    _listButton_del->append(new button_quotation(ui->scrollAreaWidgetContents,5, ":/pictures/img/trash_logo.png",true));
    _listLabel_Button->append(new QLabel("5eme", ui->scrollAreaWidgetContents));
    ui->scrollArea->setWidgetResizable(false);
    for(int i = 0; i< _listButton_quot->size(); i++){
        _listButton_quot->at(i)->setText("");
        _listButton_quot->at(i)->setStyleSheet("QPushButton {background-color: #00000000; border-radius: 30px; border: 10px solid #7f7f7f;}");
        QObject::connect(_listButton_quot->at(i), &button_quotation::clicked_ID, this, &Main_Menu::getButton_clicked);
        _listButton_del->at(i)->setText("");
        _listButton_del->at(i)->setStyleSheet("QPushButton {background-color: #00000000; border: 0px;}");
        QObject::connect(_listButton_del->at(i), &button_quotation::clicked_ID, this, &Main_Menu::getButtonDel_clicked);
        _listLabel_Button->at(i)->setAlignment(Qt::AlignmentFlag::AlignCenter);
        _listLabel_Button->at(i)->setStyleSheet("QLabel { font: 12pt 'Futura LT';}");
    }
}

Main_Menu::~Main_Menu()
{
    delete ui;
}

bool Main_Menu::event(QEvent * e)
{
    if(e->type() == QEvent::HoverEnter){
        emit Initialized(1);
    }

    return QMainWindow::event(e) ;
}

void Main_Menu::getButton_clicked(int ID){
    qDebug()<< "button clicked : "+ QString::number(ID);
}

void Main_Menu::getButtonDel_clicked(int ID){
    qDebug()<< "button delete clicked : "+ QString::number(ID);
}

void Main_Menu::showFull(){
    qDebug() << "affichage de la menu";
    this->showFullScreen();
    qDebug() << "emited de la menu";
}

void Main_Menu::resizeEvent(QResizeEvent *){
    // format 16:9 only for the moment
    QRect win = this->geometry();

    _width = win.width()/128;
    _height = win.height()/72;
    ui->scrollAreaWidgetContents->setGeometry(0*_width, 0*_height, 128*_width, (1 + _listButton_quot->size()/5) * 20 * _height + 8 * _height);
    ui->scrollArea->setGeometry(0*_width, 0*_height, 128*_width, 60*_height);
    ui->scrollArea->setWidget(ui->scrollAreaWidgetContents);
    ui->background->setGeometry(0*_width, 0*_height, 128*_width, 72*_height);
    ui->background->setPixmap(QPixmap(":/pictures/img/background_1920.png").scaled(128*_width, 72*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    for(int i = 0; i< _listButton_quot->size(); i++){
        int count_w = i%5;
        int count_h = (int)i/5;
        qDebug() << "count_h : " + QString::number(count_h);
        QString urlIcon = _listButton_quot->at(i)->getIconUrl();
        _listButton_quot->at(i)->setGeometry(15*_width + count_w * 20*_width,8*_height + count_h * 20*_height, 12* _width,12*_height);
        _listButton_quot->at(i)->setIcon(QPixmap(urlIcon).scaled(9*_width, 9*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        _listButton_quot->at(i)->setIconSize(QSize(9*_width, 9*_height));
        QString urlIconDel = _listButton_del->at(i)->getIconUrl();
        _listButton_del->at(i)->setGeometry(19*_width + count_w * 20*_width,21*_height + count_h * 20*_height, 4* _width,4*_height);
        _listButton_del->at(i)->setIcon(QPixmap(urlIconDel).scaled(4*_width, 4*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        _listButton_del->at(i)->setIconSize(QSize(4*_width, 4*_height));

        _listLabel_Button->at(i)->setGeometry(15*_width + count_w * 20*_width,6*_height + count_h * 20*_height, 12* _width,2*_height);

    }

    _menu->setGeometry(42*_width, 62*_height, 48*_width, 12*_height);

}