#include "main_quotation.h"
#include "ui_main_quotation.h"
#include "rect_custom.h"
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include "dialog_critical.h"
#include "../CORE/core_quotation.h"

Main_Quotation::Main_Quotation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Main_Quotation)
{
    ui->setupUi(this);
}

Main_Quotation::Main_Quotation(QWidget *parent, menu_toolbar* tool, bdd_PROJECT project) :
    QMainWindow(parent),
    ui(new Ui::Main_Quotation)
{
    ui->setupUi(this);
    _menu = tool;
    _menu->setParent(this);
    _isHided = false;
    _scene = new scene_custom(this);
    _project = project;
    QObject::connect(_scene, &scene_custom::item_Selected, this, &Main_Quotation::Item_Updated);
    ui->graphicsView->setScene(_scene);
    _listRectangle = new QVector<Rect_Custom*>();
    _rectSelected = nullptr;
    core_quotation* core = new core_quotation();

    QVector<bdd_ATTRIBUT> listAttr = core->getAttributs(_project);

    QVector<bdd_PRODUCT> listProduct = core->getAllProducts();

    for(int i = 0; i < listProduct.count();i++){
        bdd_PRODUCT product = listProduct.at(i);
        bool isPresent = false;
        for(int i = 0; i < ui->comboBox_type->count();i++){
            if(ui->comboBox_type->itemText(i) == product.getType()){
                isPresent = true;
            }
        }
        if(!isPresent){
            ui->comboBox_type->addItem(product.getType());
        }

    }


    for(int i = 0; i < listAttr.count(); i++){
        bdd_ATTRIBUT attr = listAttr.at(i);
        _listRectangle->append(new Rect_Custom(0, attr.getIdAttribut().toInt(), attr.getPositionX(), attr.getPositionY(), attr.getHeight(), attr.getLength(), attr.getWidth(),QPen(Qt::black), QBrush(Qt::black)));


    }


    for(int i = 0; i< _listRectangle->count();i++){
        Rect_Custom * rect = _listRectangle->at(i);

        rect->setFlag(QGraphicsItem::ItemIsMovable);
        rect->setFlag(QGraphicsItem::ItemIsSelectable);
        _scene->addItem(rect);
        _scene->addCustomRect(rect);
        _scene->update();

    }
}

Main_Quotation::~Main_Quotation()
{
    delete ui;
}


bool Main_Quotation::event(QEvent * e)
{
    if(e->type() == QEvent::HoverEnter){
        emit Initialized(5);
    }

    return QMainWindow::event(e) ;
}


void Main_Quotation::resizeEvent(QResizeEvent *){
    // format 16:9 only for the moment
    QRect win = this->geometry();

    _width = win.width()/128;
    _height = win.height()/72;
    int _widthGroup = win.width()/256;
    int _heightGroup = win.height()/144;
    ui->background->setGeometry(0*_width, 0*_height, 128*_width, 72*_height);
    ui->background->setPixmap(QPixmap(":/pictures/img/background_1920.png").scaled(128*_width, 72*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    ui->groupBox_data->setGeometry(0*_width, 6*_height, 35*_width, 54*_height);
    ui->groupBox_globale->setGeometry(1*_width, 1*_height, 35*_width, 60*_height);
    ui->pushButton_menu->setGeometry(3*_widthGroup, 3*_heightGroup, 8*_widthGroup, 8*_heightGroup);
    ui->line_globale->setGeometry(0*_widthGroup, 10*_heightGroup, 80*_widthGroup, 1*_heightGroup);

    ui->label->setGeometry(1*_widthGroup, 4*_heightGroup,40*_widthGroup, 8*_heightGroup);

    ui->pushButton_new->setGeometry(64*_widthGroup, 1*_heightGroup, 9*_widthGroup, 9*_heightGroup);
    ui->comboBox_type->setGeometry(1*_widthGroup, 14*_heightGroup, 40*_widthGroup, 6*_heightGroup);
    ui->pushButton_Copy->setGeometry(64*_widthGroup, 12*_heightGroup, 9*_widthGroup, 9*_heightGroup);
    ui->pushButton_create->setGeometry(64*_widthGroup, 104*_heightGroup, 9*_widthGroup, 9*_heightGroup);
    ui->comboBox_element->setGeometry(1*_widthGroup, 24*_heightGroup, 40*_widthGroup, 6*_heightGroup);

    ui->line_3->setGeometry(0*_widthGroup, 42*_heightGroup, 76*_widthGroup, 2*_heightGroup);

    ui->spinBox_X->setGeometry(1*_widthGroup, 48*_heightGroup, 40*_widthGroup, 6*_heightGroup);
    ui->label_X->setGeometry(1*_widthGroup, 44*_heightGroup, 40*_widthGroup, 4*_heightGroup);
    ui->spinBox_Y->setGeometry(1*_widthGroup, 60*_heightGroup, 40*_widthGroup, 6*_heightGroup);
    ui->label_Y->setGeometry(1*_widthGroup, 56*_heightGroup, 40*_widthGroup, 4*_heightGroup);
    ui->spinBox_Z->setGeometry(1*_widthGroup, 72*_heightGroup, 40*_widthGroup, 6*_heightGroup);
    ui->label_Z->setGeometry(1*_widthGroup, 68*_heightGroup, 40*_widthGroup, 4*_heightGroup);

    ui->spinBox_Width->setGeometry(1*_widthGroup, 84*_heightGroup, 40*_widthGroup, 6*_heightGroup);
    ui->label_Width->setGeometry(1*_widthGroup, 80*_heightGroup, 40*_widthGroup, 4*_heightGroup);
    ui->spinBox_Height->setGeometry(1*_widthGroup, 96*_heightGroup, 40*_widthGroup, 6*_heightGroup);
    ui->label_Height->setGeometry(1*_widthGroup, 92*_heightGroup, 40*_widthGroup, 4*_heightGroup);
    ui->spinBox_Length->setGeometry(1*_widthGroup, 108*_heightGroup, 40*_widthGroup, 6*_heightGroup);
    ui->label_Length->setGeometry(1*_widthGroup, 104*_heightGroup, 40*_widthGroup, 4*_heightGroup);

    ui->graphicsView->setGeometry(37*_width, 1*_height, 90*_width, 60*_height);
    _scene->setSceneRect(ui->graphicsView->rect());

    ui->pushButton_power->setGeometry(124*_width, 0*_height ,4*_width, 4*_height);
    _menu->setGeometry(42*_width, 62*_height, 48*_width, 12*_height);

}

void Main_Quotation::on_pushButton_menu_clicked()
{
    _isHided = !_isHided;
    if(_isHided){
        ui->groupBox_data->hide();
        ui->groupBox_globale->hide();
        ui->graphicsView->setGeometry(8*_width, 1*_height, 120*_width, 60*_height);
        _scene->setSceneRect(ui->graphicsView->rect());
    }else{
        ui->groupBox_data->show();
        ui->groupBox_globale->show();
        ui->graphicsView->setGeometry(37*_width, 1*_height, 90*_width, 60*_height);
        _scene->setSceneRect(ui->graphicsView->rect());

    }
}


void Main_Quotation::Item_Updated(Rect_Custom* rect){
    _ModifiedBySignal = true;
    ui->spinBox_X->setValue(rect->x());
    ui->spinBox_Y->setValue(rect->y());
    ui->spinBox_Width->setValue(rect->getWidth());
    ui->spinBox_Length->setValue(rect->getLength());
    core_quotation* core = new core_quotation();
    bdd_ATTRIBUT attr = core->getAttributByID(rect->getID());
    bdd_PRODUCT product = core->getProductByID(attr.getProductIdProduct());

    for(int i = 0; i< ui->comboBox_type->count();i++){
        if(ui->comboBox_type->itemText(i) == product.getLabel()){
            ui->comboBox_type->setCurrentIndex(i);
        }
    }
    this->configureComboBox();
    for(int i = 0; i< ui->comboBox_element->count();i++){
        if(ui->comboBox_element->itemText(i) == product.getMaterial()){
            ui->comboBox_element->setCurrentIndex(i);
        }
    }
    QString text = product.getLabel() + "(" + product.getProductCode() + ")";
    ui->label->setText(text.toUpper());

    _rectSelected = rect;
    _ModifiedBySignal = false;
}

void Main_Quotation::on_pushButton_power_clicked()
{
    Dialog_Critical *c = new Dialog_Critical(this,"Exit ?", "êtes vous sûr de vouloir quitter l'application ?", "question");
    int result = c->exec();
    qDebug() << "result du exit : "<< result;
    if(result == QDialog::Accepted){
        this->close();
    }
}

void Main_Quotation::on_spinBox_Length_valueChanged(int arg1)
{
    if(_ModifiedBySignal){
        return;
    }
    if(_rectSelected != nullptr){
        _rectSelected->setLength(arg1);
        _scene->updateRect(_rectSelected->getID(), arg1, "length");
    }else{
        Dialog_Critical* c = new Dialog_Critical(this, "Error", "Error : No attribut selected", "critical");
        c->show();
    }
}

void Main_Quotation::on_spinBox_Width_valueChanged(int arg1)
{
    if(_ModifiedBySignal){
        return;
    }
    if(_rectSelected != nullptr){
        _rectSelected->setWidth(arg1);
        _scene->updateRect(_rectSelected->getID(), arg1, "width");
    }else{
        Dialog_Critical* c = new Dialog_Critical(this, "Error", "Error : No attribut selected", "critical");
        c->show();
    }
}

void Main_Quotation::on_spinBox_Height_valueChanged(int arg1)
{
    if(_ModifiedBySignal){
        return;
    }
    if(_rectSelected != nullptr){
        _rectSelected->setHeight(arg1);
        _scene->updateRect(_rectSelected->getID(), arg1, "height");
    }else{
        Dialog_Critical* c = new Dialog_Critical(this, "Error", "Error : No attribut selected", "critical");
        c->show();
    }
}

void Main_Quotation::on_spinBox_X_valueChanged(int arg1)
{
    if(_ModifiedBySignal){
        return;
    }
    if(_rectSelected != nullptr){
        _rectSelected->setX(arg1);
        _scene->updateRect(_rectSelected->getID(), arg1, "X");
    }else{
        Dialog_Critical* c = new Dialog_Critical(this, "Error", "Error : No attribut selected", "critical");
        c->show();
    }
}

void Main_Quotation::on_spinBox_Y_valueChanged(int arg1)
{
    if(_ModifiedBySignal){
        return;
    }
    if(_rectSelected != nullptr){
        _rectSelected->setY(arg1);
        _scene->updateRect(_rectSelected->getID(), arg1, "Y");
    }else{
        Dialog_Critical* c = new Dialog_Critical(this, "Error", "Error : No attribut selected", "critical");
        c->show();
    }
}

void Main_Quotation::on_spinBox_Z_valueChanged(int arg1)
{
    if(_ModifiedBySignal){
        return;
    }
    if(_rectSelected != nullptr){
        _rectSelected->setZValue(arg1);
        _scene->updateRect(_rectSelected->getID(), arg1, "Z");
    }else{
        Dialog_Critical* c = new Dialog_Critical(this, "Error", "Error : No attribut selected", "critical");
        c->show();
    }
}

void Main_Quotation::configureComboBox(){
    QString type = ui->comboBox_type->currentText();
    core_quotation* core = new core_quotation();
    QVector<bdd_PRODUCT> listProduct = core->getAllProducts();

    for(int i = 0; i <listProduct.count();i++){
        bdd_PRODUCT prod = listProduct.at(i);
        if(prod.getType() == type){
            bool isPresent = false;
            for(int i = 0; i < ui->comboBox_element->count();i++){
                if(ui->comboBox_element->itemText(i) == prod.getMaterial()){
                    isPresent = true;
                }
            }
            if(!isPresent){
                ui->comboBox_element->addItem(prod.getMaterial());
            }
        }
    }



}
