#include "main_template.h"
#include "ui_main_template.h"
#include <QDebug>
#include <math.h>
#include <QThread>
#include "dialog_critical.h"

main_template::main_template(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::main_template)
{
    ui->setupUi(this);
    _menu = new menu_toolbar(this);
}

main_template::main_template(QWidget *parent, menu_toolbar* m, QVector<bdd_PROJECT>* listProject) :
    QMainWindow(parent),
    ui(new Ui::main_template)
{
    ui->setupUi(this);

    ui->background_form->hide();
    ui->grey_screen->hide();

    _tpl = new Form_template(this, "");
    _tpl->hide();
    QObject::connect(_tpl, &Form_template::cancelled, this, &main_template::tplCancelled);
    QObject::connect(_tpl, &Form_template::validated, this, &main_template::tplValidated);

    _menu = m;
    _menu->setParent(this);
    _listButton_quot = new QVector<button_quotation*>;
    _listButton_del = new QVector<button_quotation*>;
    _listLabel_Button = new QVector<QLabel*>;


    _listButton_quot->append(new button_quotation(ui->scrollAreaWidgetContents,-1, "DATA_IMG/quot_new.png"));
    button_quotation* btn = new button_quotation(ui->scrollAreaWidgetContents,-1, ":/pictures/img/trash_logo.png",true);
    btn->hide();
    _listButton_del->append(btn);
    _listLabel_Button->append(new QLabel("New Empty Project", ui->scrollAreaWidgetContents)); // new icon
    for(int i = 0; i<listProject->count(); i++){
        bdd_PROJECT project = listProject->at(i);
        qDebug() << "buttons added : ";
        qDebug() << project.getIdProject();
        int ID = project.getIdProject().toInt();
        _listButton_quot->append(new button_quotation(ui->scrollAreaWidgetContents,ID, "./DATA_IMG/quot_ex_1.png"));
        _listButton_del->append(new button_quotation(ui->scrollAreaWidgetContents,project.getIdProject().toInt(), ":/pictures/img/trash_logo.png",true));
        qDebug() << "buttons added : " << project.getIdProject().toInt();
        _listLabel_Button->append(new QLabel(project.getUserUserName(), ui->scrollAreaWidgetContents)); // new icon
        qDebug() << "buttons added : " << project.getIdProject().toInt();

    }

    ui->scrollArea->setWidgetResizable(false);
    for(int i = 0; i< _listButton_quot->size(); i++){
        _listButton_quot->at(i)->setText("");
        _listButton_quot->at(i)->setStyleSheet("QPushButton {background-color: #00000000; border-radius: 30px; border: 10px solid #7f7f7f;}");
        QObject::connect(_listButton_quot->at(i), &button_quotation::clicked_ID, this, &main_template::getButton_clicked);
        _listButton_del->at(i)->setText("");
        _listButton_del->at(i)->setStyleSheet("QPushButton {background-color: #00000000; border: 0px;}");
        QObject::connect(_listButton_del->at(i), &button_quotation::clicked_ID, this, &main_template::getButtonDel_clicked);
        _listLabel_Button->at(i)->setAlignment(Qt::AlignmentFlag::AlignCenter);
        _listLabel_Button->at(i)->setStyleSheet("QLabel { font: 12pt 'Futura LT';}");
    }
}

main_template::~main_template()
{
    delete ui;
}

bool main_template::event(QEvent * e)
{
    if(e->type() == QEvent::HoverEnter){
        emit Initialized(4);
    }

    return QMainWindow::event(e) ;
}

void main_template::getButton_clicked(int ID){
    qDebug()<< "button clicked : "+ QString::number(ID);
    ui->grey_screen->show();
    ui->background_form->show();
    _tpl->setRessource("./DATA_IMG/quot_default.png");
    _tpl->setGeometry(17*_width,7*_height,94*_width, 52*_height);
    _tpl->show();
}

void main_template::getButtonDel_clicked(int ID){
    qDebug()<< "button delete clicked : "+ QString::number(ID);
    emit deleteProject(ID);

}

void main_template::showFull(){
    qDebug() << "affichage de la menu";
    this->showFullScreen();
    qDebug() << "emited de la menu";
}

void main_template::resizeEvent(QResizeEvent *){
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

    ui->pushButton_power->setGeometry(124*_width, 0*_height ,4*_width, 4*_height);
    ui->grey_screen->setGeometry(0,0,128*_width, 72*_height);
    ui->background_form->setGeometry(15*_width,5*_height,98*_width, 56*_height);

    _menu->setGeometry(42*_width, 62*_height, 48*_width, 12*_height);

}

void main_template::tplCancelled(){
    _tpl->hide();
    ui->background_form->hide();
    ui->grey_screen->hide();

}

void main_template::tplValidated(){
    _tpl->hide();
    ui->background_form->hide();
    ui->grey_screen->hide();

    emit openProject(bdd_PROJECT("Tue Dec  2 00:00:00 PST 2014", "true", "Tue Dec  2 00:00:00 PST 2014", "true", "0", "omega"));
}

void main_template::on_pushButton_power_clicked()
{
    Dialog_Critical *c = new Dialog_Critical(this,"Exit ?", "êtes vous sûr de vouloir quitter l'application ?", "question");
    int result = c->exec();
    qDebug() << "result du exit : "<< result;
    if(result == QDialog::Accepted){
        this->close();
    }
}
