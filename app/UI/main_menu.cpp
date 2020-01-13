#include "main_menu.h"
#include "ui_main_menu.h"
#include <QDebug>
#include <math.h>
#include <QThread>
#include "dialog_critical.h"
#include <QScrollArea>
#include "../CORE/api_get_request.h"

Main_Menu::Main_Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Main_Menu)
{
    ui->setupUi(this);
    _menu = new menu_toolbar(this);
}

Main_Menu::Main_Menu(QWidget *parent, menu_toolbar* m, QVector<bdd_PROJECT>* listProject) :
    QMainWindow(parent),
    ui(new Ui::Main_Menu)
{


    ui->setupUi(this);
    _menu = m;
    _menu->setParent(this);
    _listButton_quot = new QVector<button_quotation*>;
    _listButton_del = new QVector<button_quotation*>;
    _listLabel_Button = new QVector<QLabel*>;
    _listProjectUser = listProject;


    _listButton_quot->append(new button_quotation(ui->scrollAreaWidgetContents,-1, "DATA_IMG/quot_new.png"));
    button_quotation* btn = new button_quotation(ui->scrollAreaWidgetContents,-1, ":/pictures/img/trash_logo.png",true);
    btn->hide();
    _listButton_del->append(btn);
    _listLabel_Button->append(new QLabel("New", ui->scrollAreaWidgetContents)); // new icon
    for(int i = 0; i<listProject->count(); i++){
        bdd_PROJECT project = listProject->at(i);
        qDebug() << "buttons added : ";
        qDebug() << project.getIdProject();
        int ID = project.getIdProject().toInt();
        _listButton_quot->append(new button_quotation(ui->scrollAreaWidgetContents,ID, "./DATA_IMG/" + project.getTitle().replace(" ","") +  ".png"));
        _listButton_del->append(new button_quotation(ui->scrollAreaWidgetContents,project.getIdProject().toInt(), ":/pictures/img/trash_logo.png",true));
        qDebug() << "buttons added : " << project.getIdProject().toInt();
        _listLabel_Button->append(new QLabel(project.getTitle(), ui->scrollAreaWidgetContents)); // new icon
        qDebug() << "buttons added : " << project.getIdProject().toInt();

    }

    ui->scrollArea->setWidgetResizable(false);
    for(int i = 0; i< _listButton_quot->size(); i++){
        _listButton_quot->at(i)->setText("");
        _listButton_quot->at(i)->setStyleSheet("QPushButton {background-color: #00000000; border-radius: 30px; border: 10px solid #7f7f7f;}");
        _listButton_quot->at(i)->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QObject::connect(_listButton_quot->at(i), &button_quotation::clicked_ID, this, &Main_Menu::getButton_clicked);
        _listButton_del->at(i)->setText("");
        _listButton_del->at(i)->setStyleSheet("QPushButton {background-color: #00000000; border: 0px;}");
        _listButton_del->at(i)->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QObject::connect(_listButton_del->at(i), &button_quotation::clicked_ID, this, &Main_Menu::getButtonDel_clicked);
        _listLabel_Button->at(i)->setAlignment(Qt::AlignmentFlag::AlignCenter);
        _listLabel_Button->at(i)->setStyleSheet("QLabel { font: 12pt 'Futura LT';}");
    }

    if(!_menu->isAdmin()){
        ui->label->setVisible(false);
        ui->horizontalSlider->setVisible(false);
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
    emit button_clicked(ID);
}

void Main_Menu::getButtonDel_clicked(int ID){

    qDebug()<< "button delete clicked : "+ QString::number(ID);
    Dialog_Critical* c = new Dialog_Critical(this, "SUPPRESSION ?", "Etes-vous sûr de vouloir supprimer ce projet ?", "question");
    int result = c->exec();
    if(result == QDialog::Accepted){
        for(int i = 0; i < _listButton_del->count();i++){
            if( _listButton_del->at(i)->getID() == ID){
                _listButton_del->removeAt(i);
                _listLabel_Button->removeAt(i);
                _listButton_quot->removeAt(i);


            }

        }

        for(int i = 0; i< _listProjectUser->count(); i++){
            bdd_PROJECT proj = _listProjectUser->at(i);
            if(proj.getIdProject().toInt() == ID){
                _listProjectUser->removeAt(i);
            }
        }

        emit deleteProject(ID);
        this->wait(500,500);
        this->on_horizontalSlider_valueChanged(0);
    }


}

void Main_Menu::showFull(){
    qDebug() << "affichage de la menu";
    this->showFullScreen();
    qDebug() << "emited de la menu";
}

void Main_Menu::resizeAll(){
    QRect win = this->geometry();

    _width = win.width()/128;
    _height = win.height()/72;
    ui->scrollAreaWidgetContents->update();
    ui->scrollAreaWidgetContents->setGeometry(0*_width, 0*_height, 128*_width, (1 + _listButton_quot->size()/5) * 20 * _height + 8 * _height);
    ui->scrollArea->setGeometry(0*_width, 0*_height, 128*_width, 60*_height);
    ui->scrollArea->setWidget(ui->scrollAreaWidgetContents);
    ui->background->setGeometry(0*_width, 0*_height, 128*_width, 72*_height);
    ui->background->setPixmap(QPixmap(":/pictures/img/background_1920.png").scaled(128*_width, 72*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    for(int i = 0; i< _listButton_quot->size(); i++){
        int count_w = i%5;
        int count_h = (int)i/5;
        qDebug() << "count_h : " + QString::number(count_h);
        qDebug() << "pos X du bouton : " << i << " -> " << 15*_width + count_w * 20*_width;
        QString urlIcon = _listButton_quot->at(i)->getIconUrl();
        _listButton_quot->at(i)->setGeometry(15*_width + count_w * 20*_width,8*_height + count_h * 20*_height, 12* _width,12*_height);
        _listButton_quot->at(i)->setIcon(QPixmap(urlIcon).scaled(9*_width, 9*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        _listButton_quot->at(i)->setIconSize(QSize(9*_width, 9*_height));
        QString urlIconDel = _listButton_del->at(i)->getIconUrl();
        _listButton_del->at(i)->setGeometry(19*_width + count_w * 20*_width,21*_height + count_h * 20*_height, 4* _width,4*_height);
        _listButton_del->at(i)->setIcon(QPixmap(urlIconDel).scaled(4*_width, 4*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        _listButton_del->at(i)->setIconSize(QSize(4*_width, 4*_height));

        _listLabel_Button->at(i)->setGeometry(15*_width + count_w * 20*_width,6*_height + count_h * 20*_height, 12* _width,2*_height);

        qDebug() << "real pos X du bouton : " << i << " -> " << _listButton_quot->at(i)->geometry().x();
    }
    ui->label->setGeometry(122*_width,4*_height, 8* _width,2*_height);
    ui->horizontalSlider->setGeometry(122*_width,6*_height, 4* _width,2*_height);
    ui->pushButton_power->setGeometry(124*_width, 0*_height ,4*_width, 4*_height);
    _menu->setGeometry(42*_width, 62*_height, 48*_width, 12*_height);
    this->update();
    ui->scrollAreaWidgetContents->update();
}

void Main_Menu::resizeEvent(QResizeEvent *){
    // format 16:9 only for the moment
    this->resizeAll();
}

void Main_Menu::on_pushButton_power_clicked()
{
    Dialog_Critical *c = new Dialog_Critical(this,"Exit ?", "êtes vous sûr de vouloir quitter l'application ?", "question");
    int result = c->exec();
    qDebug() << "result du exit : "<< result;
    if(result == QDialog::Accepted){
        this->close();
    }
}

void Main_Menu::on_horizontalSlider_sliderMoved(int position)
{

}

void Main_Menu::on_horizontalSlider_valueChanged(int value)
{
    qDebug() << "changed slider" << value;
    QVector<bdd_PROJECT> listProject;
    if(value == 1 ){
        api_get_request* api = new api_get_request();
        listProject = api->parse_file_project();
    }else {
        listProject = *_listProjectUser;
    }



    _listButton_quot = nullptr;
    _listButton_quot = new QVector<button_quotation*>;
    _listButton_del = nullptr;
    _listButton_del = new QVector<button_quotation*>;
    _listLabel_Button = nullptr;
    _listLabel_Button = new QVector<QLabel*>;

    ui->scrollAreaWidgetContents = new QWidget(ui->scrollArea);

    _listButton_quot->append(new button_quotation(ui->scrollAreaWidgetContents,-1, "DATA_IMG/quot_new.png"));
    button_quotation* btn = new button_quotation(ui->scrollAreaWidgetContents,-1, ":/pictures/img/trash_logo.png",true);
    btn->hide();
    _listButton_del->append(btn);
    _listLabel_Button->append(new QLabel("New", ui->scrollAreaWidgetContents)); // new icon
    for(int i = 0; i<listProject.count(); i++){
        bdd_PROJECT project = listProject.at(i);
        int ID = project.getIdProject().toInt();
        qDebug() << "adding project : " + project.getTitle();
        _listButton_quot->append(new button_quotation(ui->scrollAreaWidgetContents,ID, "./DATA_IMG/" + project.getTitle().replace(" ","") +  ".png"));
        _listButton_del->append(new button_quotation(ui->scrollAreaWidgetContents,project.getIdProject().toInt(), ":/pictures/img/trash_logo.png",true));
        qDebug() << "buttons added : " << project.getTitle();
        if(value == 1){
            _listLabel_Button->append(new QLabel(project.getTitle() + "(" + project.getUserUserName() + ")", ui->scrollAreaWidgetContents)); // new icon

        }else{
            _listLabel_Button->append(new QLabel(project.getTitle(), ui->scrollAreaWidgetContents)); // new icon

        }

    }
    for(int i = 0; i< _listButton_quot->size(); i++){
        _listButton_quot->at(i)->setText("");
        _listButton_quot->at(i)->setStyleSheet("QPushButton {background-color: #00000000; border-radius: 30px; border: 10px solid #7f7f7f;}");
        _listButton_quot->at(i)->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QObject::connect(_listButton_quot->at(i), &button_quotation::clicked_ID, this, &Main_Menu::getButton_clicked);
        _listButton_del->at(i)->setText("");
        _listButton_del->at(i)->setStyleSheet("QPushButton {background-color: #00000000; border: 0px;}");
        _listButton_del->at(i)->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        QObject::connect(_listButton_del->at(i), &button_quotation::clicked_ID, this, &Main_Menu::getButtonDel_clicked);
        _listLabel_Button->at(i)->setAlignment(Qt::AlignmentFlag::AlignCenter);
        _listLabel_Button->at(i)->setStyleSheet("QLabel { font: 12pt 'Futura LT';}");
    }

    this->resizeAll();
    this->update();
}


void Main_Menu::wait(int time, int interval){
    qDebug() << "waiting...";
    int timer = clock() + time;
    qDebug()<<clock();
    qDebug()<<timer;
    bool hasUpgrade = false;
    while(timer > clock()){
        qApp->processEvents();
        if(clock()%interval == 0){
            if(!hasUpgrade){
                hasUpgrade = true;
            }
        }else{
            hasUpgrade = false;
        }
    }
    qDebug() << "end of wait...";
}
