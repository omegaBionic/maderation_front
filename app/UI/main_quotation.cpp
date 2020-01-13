#include "main_quotation.h"
#include "ui_main_quotation.h"
#include "rect_custom.h"
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include "dialog_critical.h"
#include "../CORE/core_quotation.h"
#include "../CORE/api_post_request.h"
#include "../CORE/core_post_mail_files.h"
#include "form_quotation.h"

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

    _ModifiedBySignal = true;
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
        bdd_PRODUCT product = core->getProductByID(attr.getProductIdProduct());
        Rect_Custom* rect = new Rect_Custom(0, attr.getIdAttribut().toInt(), attr.getPositionX(), attr.getPositionY(), attr.getHeight(), attr.getLength(), attr.getWidth(),QPen(Qt::black), QBrush(QColor(product.getR(), product.getG(), product.getB())));
        rect->setRotation(attr.getRotationX());
        rect->setZValue(attr.getPositionZ());
        _listRectangle->append(rect);


    }


    for(int i = 0; i< _listRectangle->count();i++){
        Rect_Custom * rect = _listRectangle->at(i);

        rect->setFlag(QGraphicsItem::ItemIsMovable);
        rect->setFlag(QGraphicsItem::ItemIsSelectable);
        _scene->addItem(rect);
        _scene->addCustomRect(rect);
        _scene->update();

    }


    ui->background_form->hide();
    ui->grey_screen->hide();

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

    ui->label->setGeometry(1*_widthGroup, 0*_heightGroup,40*_widthGroup, 8*_heightGroup);

    ui->pushButton_new->setGeometry(64*_widthGroup, 1*_heightGroup, 9*_widthGroup, 9*_heightGroup);
    ui->pushButton_firstPlan->setGeometry(54*_widthGroup, 1*_heightGroup, 9*_widthGroup, 9*_heightGroup);
    ui->pushButton_delete->setGeometry(54*_widthGroup, 12*_heightGroup, 9*_widthGroup, 9*_heightGroup);
    ui->comboBox_type->setGeometry(1*_widthGroup, 8*_heightGroup, 40*_widthGroup, 6*_heightGroup);
    ui->pushButton_Copy->setGeometry(64*_widthGroup, 12*_heightGroup, 9*_widthGroup, 9*_heightGroup);
    ui->comboBox_element->setGeometry(1*_widthGroup, 18*_heightGroup, 40*_widthGroup, 6*_heightGroup);

    ui->line_3->setGeometry(0*_widthGroup, 30*_heightGroup, 76*_widthGroup, 2*_heightGroup);

    ui->spinBox_X->setGeometry(2*_widthGroup, 36*_heightGroup, 30*_widthGroup, 6*_heightGroup);
    ui->label_X->setGeometry(2*_widthGroup,32*_heightGroup, 30*_widthGroup, 4*_heightGroup);
    ui->spinBox_Y->setGeometry(42*_widthGroup, 36*_heightGroup, 30*_widthGroup, 6*_heightGroup);
    ui->label_Y->setGeometry(42*_widthGroup, 32*_heightGroup, 30*_widthGroup, 4*_heightGroup);

    ui->spinBox_Z->setGeometry(2*_widthGroup, 48*_heightGroup, 30*_widthGroup, 6*_heightGroup);
    ui->label_Z->setGeometry(2*_widthGroup, 44*_heightGroup, 30*_widthGroup, 4*_heightGroup);
    ui->spinBox_Width->setGeometry(42*_widthGroup, 48*_heightGroup, 30*_widthGroup, 6*_heightGroup);
    ui->label_Width->setGeometry(42*_widthGroup, 44*_heightGroup, 30*_widthGroup, 4*_heightGroup);

    ui->spinBox_Height->setGeometry(2*_widthGroup, 60*_heightGroup, 30*_widthGroup, 6*_heightGroup);
    ui->label_Height->setGeometry(2*_widthGroup, 56*_heightGroup, 30*_widthGroup, 4*_heightGroup);
    ui->spinBox_Length->setGeometry(42*_widthGroup, 60*_heightGroup, 30*_widthGroup, 6*_heightGroup);
    ui->label_Length->setGeometry(42*_widthGroup, 56*_heightGroup, 30*_widthGroup, 4*_heightGroup);

    ui->spinBox_rotation->setGeometry(21*_widthGroup, 72*_heightGroup, 30*_widthGroup, 6*_heightGroup);
    ui->label_rotation->setGeometry(21*_widthGroup, 68*_heightGroup, 30*_widthGroup, 4*_heightGroup);


    ui->pushButton_create->setGeometry(39*_widthGroup, 90*_heightGroup, 18*_widthGroup, 18*_heightGroup);
    ui->pushButton_save->setGeometry(15*_widthGroup, 90*_heightGroup, 18*_widthGroup, 18*_heightGroup);

    ui->pushButton_width->setGeometry(106*_width, 57*_height, 20*_width, 3*_height);
    ui->pushButton_length->setGeometry(120*_width, 41*_height, 6*_width, 20*_height);

    ui->graphicsView->setGeometry(37*_width, 1*_height, 90*_width, 60*_height);
    _scene->setSceneRect(ui->graphicsView->rect());

    ui->pushButton_power->setGeometry(124*_width, 0*_height ,4*_width, 4*_height);
    _menu->setGeometry(42*_width, 62*_height, 48*_width, 12*_height);


    ui->grey_screen->setGeometry(0,0,128*_width, 72*_height);
    ui->background_form->setGeometry(15*_width,5*_height,98*_width, 56*_height);

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
    ui->spinBox_Z->setValue(rect->zValue());
    ui->spinBox_Width->setValue(rect->getWidth());
    ui->spinBox_Length->setValue(rect->getLength());
    ui->spinBox_Height->setValue(rect->getHeight());
    ui->spinBox_rotation->setValue(rect->rotation());
    core_quotation* core = new core_quotation();
    bdd_ATTRIBUT attr = core->getAttributByID(rect->getID());
    bdd_PRODUCT product = core->getProductByID(attr.getProductIdProduct());

    for(int i = 0; i< ui->comboBox_type->count();i++){
        if(ui->comboBox_type->itemText(i) == product.getType()){
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
        Dialog_Critical* c = new Dialog_Critical(this, "ERREUR", "ERREUR : Aucun attribut n'a été sélectionné", "critical");
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
        Dialog_Critical* c = new Dialog_Critical(this, "ERREUR", "ERREUR : Aucun attribut n'a été sélectionné", "critical");
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
        Dialog_Critical* c = new Dialog_Critical(this, "ERREUR", "ERREUR : Aucun attribut n'a été sélectionné", "critical");
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
        Dialog_Critical* c = new Dialog_Critical(this, "ERREUR", "ERREUR : Aucun attribut n'a été sélectionné", "critical");
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
        Dialog_Critical* c = new Dialog_Critical(this, "ERREUR", "ERREUR : Aucun attribut n'a été sélectionné", "critical");
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
        Dialog_Critical* c = new Dialog_Critical(this, "ERREUR", "ERREUR : Aucun attribut n'a été sélectionné", "critical");
        c->show();
    }
}

void Main_Quotation::configureComboBox(){
    QString type = ui->comboBox_type->currentText();
    core_quotation* core = new core_quotation();
    QVector<bdd_PRODUCT> listProduct = core->getAllProducts();

    for(int i = 0; i < ui->comboBox_element->count();i++){
        ui->comboBox_element->removeItem(0);
    }
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

void Main_Quotation::on_comboBox_element_currentIndexChanged(int index)
{
    if(_ModifiedBySignal){
        return;
    }
    bdd_PRODUCT newProduct;
    core_quotation* core  = new core_quotation();
    newProduct = core->getProduct(ui->comboBox_element->currentText(), ui->comboBox_type->currentText());


    if(_rectSelected != nullptr){
        _rectSelected->setPen(QPen(Qt::black));
        _rectSelected->setBrush(QBrush(QColor(QColor(newProduct.getR(), newProduct.getG(), newProduct.getB()))));
    }else{
        Dialog_Critical* c = new Dialog_Critical(this, "ERREUR", "ERREUR : Aucun attribut n'a été sélectionné", "critical");
        c->show();
    }

    this->saveCurrentAttr();
}

void Main_Quotation::on_comboBox_type_currentIndexChanged(int index)
{
    if(_ModifiedBySignal){
        return;
    }
    this->configureComboBox();
    bdd_PRODUCT newProduct;
    core_quotation* core  = new core_quotation();
    newProduct = core->getProduct(ui->comboBox_element->currentText(), ui->comboBox_type->currentText());


    if(_rectSelected != nullptr){
        _rectSelected->setWidth(newProduct.getDefaultWidth());
        _rectSelected->setLength(newProduct.getDefaultLength());
        _rectSelected->setPen(QPen(Qt::black));
        _rectSelected->setBrush(QBrush(QColor(QColor(newProduct.getR(), newProduct.getG(), newProduct.getB()))));
        _scene->updateRect(_rectSelected->getID(), newProduct.getDefaultWidth(), "width");
        _scene->updateRect(_rectSelected->getID(), newProduct.getDefaultLength(), "length");
        ui->spinBox_Width->setValue(newProduct.getDefaultWidth());
        ui->spinBox_Length->setValue(newProduct.getDefaultLength());
    }else{
        Dialog_Critical* c = new Dialog_Critical(this, "ERREUR", "ERREUR : Aucun attribut n'a été sélectionné", "critical");
        c->show();
    }
    this->saveCurrentAttr();
}


void Main_Quotation::saveCurrentAttr(){
    bdd_ATTRIBUT current;
    bdd_PRODUCT newProduct;
    core_quotation* core  = new core_quotation();
    current = core->getAttributByID(_rectSelected->getID());
    newProduct = core->getProduct(ui->comboBox_element->currentText(), ui->comboBox_type->currentText());
    current.setProductIdProduct(newProduct.getIdProduct().toInt());
    current.setWidth(_rectSelected->getWidth());
    current.setHeight(_rectSelected->getHeight());
    current.setLength(ui->spinBox_Length->value());
    current.setPositionX(ui->spinBox_X->value());
    current.setPositionY(ui->spinBox_Y->value());
    current.setPositionZ(ui->spinBox_Z->value());
    current.setRotationX(ui->spinBox_rotation->value());
    QString text = newProduct.getLabel() + "(" + newProduct.getProductCode() + ")";
    ui->label->setText(text.toUpper());
    current.getDict();
    api_post_request* api = new api_post_request();
    api->modifyData(current, "modify");
}

void Main_Quotation::on_spinBox_rotation_valueChanged(double arg1)
{
    if(_ModifiedBySignal){
        return;
    }
    if(_rectSelected != nullptr){
        _rectSelected->setRotation(arg1);
        _scene->updateRect(_rectSelected->getID(), arg1, "rotation");
    }else{
        Dialog_Critical* c = new Dialog_Critical(this, "ERREUR", "ERREUR : Aucun attribut n'a été sélectionné", "critical");
        c->show();
    }
}

void Main_Quotation::on_pushButton_save_clicked()
{
    core_quotation* core = new core_quotation();
    api_post_request* api = new api_post_request();
    QVector<Rect_Custom*>* listRect = _scene->getRect();
    _listRectangle = listRect;
    for(int i = 0; i < this->_listRectangle->count(); i++){
        Rect_Custom* rect = _listRectangle->at(i);
        bdd_ATTRIBUT attr = core->getAttributByID(rect->getID());
        attr = core->getAttributByID(rect->getID());
        attr.setWidth(rect->getWidth());
        attr.setLength(rect->getLength());
        attr.setPositionX(rect->x());
        attr.setPositionY(rect->y());
        attr.setRotationX(rect->rotation());
        attr.getDict();
        api->addData(attr, "modify");


    }
    QPixmap image = ui->graphicsView->grab(ui->graphicsView->sceneRect().toRect());
    QString filename = _project.getTitle().replace(" ","") + ".png";
    image.save("DATA_IMG/" + filename);
    core_post_mail_files* core_file = new core_post_mail_files();

    core_file->sendFile("DATA_IMG/" + filename, filename, "png");
    api->pushData();
}

void Main_Quotation::on_spinBox_Length_editingFinished()
{
    this->saveCurrentAttr();
}

void Main_Quotation::on_spinBox_rotation_editingFinished()
{
    this->saveCurrentAttr();
}

void Main_Quotation::on_spinBox_X_editingFinished()
{
    this->saveCurrentAttr();
}

void Main_Quotation::on_spinBox_Height_editingFinished()
{
    this->saveCurrentAttr();
}

void Main_Quotation::on_spinBox_Y_editingFinished()
{
    this->saveCurrentAttr();
}

void Main_Quotation::on_spinBox_Z_editingFinished()
{
    this->saveCurrentAttr();
}

void Main_Quotation::on_spinBox_Width_editingFinished()
{
    this->saveCurrentAttr();
}

void Main_Quotation::on_pushButton_new_clicked()
{
    bdd_ATTRIBUT current;
    bdd_PRODUCT newProduct;
    core_quotation* core  = new core_quotation();
    current.setIdAttribut(core->getLastAttributID());
    newProduct = core->getProduct(ui->comboBox_element->currentText(), ui->comboBox_type->currentText());
    current.setProductIdProduct(newProduct.getIdProduct().toInt());
    current.setOrderIdProject(_project.getIdProject());
    current.setWidth(newProduct.getDefaultWidth());
    current.setHeight(newProduct.getDefaultHeight());
    current.setLength(newProduct.getDefaultLength());
    current.setPositionX(5);
    current.setPositionY(5);
    current.setPositionZ(0);
    current.setRotationX(0);
    QString text = newProduct.getLabel() + "(" + newProduct.getProductCode() + ")";
    ui->label->setText(text.toUpper());
    current.getDict();
    api_post_request* api = new api_post_request();
    api->modifyData(current, "add");

    bdd_PRODUCT product = core->getProductByID(current.getProductIdProduct());
    Rect_Custom * rect = new Rect_Custom(0, current.getIdAttribut().toInt(), current.getPositionX() + 10, current.getPositionY() + 10, current.getHeight(), current.getLength(), current.getWidth(),QPen(Qt::black), QBrush(QColor(product.getR(), product.getG(), product.getB())));
    rect->setRotation(current.getRotationX());

    rect->setZValue(current.getPositionZ());
    _listRectangle->append(rect);
    rect->setFlag(QGraphicsItem::ItemIsMovable);
    rect->setFlag(QGraphicsItem::ItemIsSelectable);
    _scene->addItem(rect);
    _scene->addCustomRect(rect);
    _scene->update();
}

void Main_Quotation::on_pushButton_Copy_clicked()
{
    bdd_ATTRIBUT current;
    bdd_PRODUCT newProduct;
    core_quotation* core  = new core_quotation();
    current.setIdAttribut(core->getLastAttributID());
    newProduct = core->getProduct(ui->comboBox_element->currentText(), ui->comboBox_type->currentText());
    current.setProductIdProduct(newProduct.getIdProduct().toInt());
    current.setOrderIdProject(_project.getIdProject());
    current.setWidth(_rectSelected->getWidth());
    current.setHeight(_rectSelected->getHeight());
    current.setLength(ui->spinBox_Length->value());
    current.setPositionX(ui->spinBox_X->value());
    current.setPositionY(ui->spinBox_Y->value());
    current.setPositionZ(ui->spinBox_Z->value());
    current.setRotationX(ui->spinBox_rotation->value());
    QString text = newProduct.getLabel() + "(" + newProduct.getProductCode() + ")";
    ui->label->setText(text.toUpper());
    current.getDict();
    api_post_request* api = new api_post_request();
    api->modifyData(current, "add");


    bdd_PRODUCT product = core->getProductByID(current.getProductIdProduct());
    Rect_Custom * rect = new Rect_Custom(0, current.getIdAttribut().toInt(), current.getPositionX() + 10, current.getPositionY() + 10, current.getHeight(), current.getLength(), current.getWidth(),QPen(Qt::black), QBrush(QColor(product.getR(), product.getG(), product.getB())));
    rect->setRotation(current.getRotationX());
    rect->setZValue(current.getPositionZ());
    _listRectangle->append(rect);
    rect->setFlag(QGraphicsItem::ItemIsMovable);
    rect->setFlag(QGraphicsItem::ItemIsSelectable);
    _scene->addItem(rect);
    _scene->addCustomRect(rect);
    _scene->update();
}

void Main_Quotation::on_pushButton_create_clicked()
{
    ui->grey_screen->show();
    ui->background_form->show();

    Form_quotation* form = new Form_quotation(this, _project);
    QObject::connect(form, &Form_quotation::cancelled, this, &Main_Quotation::form_cancelled);
    form->setGeometry(17*_width,7*_height,94*_width, 52*_height);
    form->show();

}

void Main_Quotation::on_pushButton_delete_clicked()
{
    if(_rectSelected != nullptr){
        _scene->deleteRect(_rectSelected->getID());
        for(int i = 0; i < _listRectangle->count(); i++){
            Rect_Custom* rect = _listRectangle->at(i);
            if(rect->getID() == rect->getID()){
                _listRectangle->removeAt(i);
            }
        }
        bdd_ATTRIBUT current;
        core_quotation* core  = new core_quotation();
        current = core->getAttributByID(_rectSelected->getID());

        current.getDict();
        api_post_request* api = new api_post_request();
        api->modifyData(current, "delete");

        _rectSelected = nullptr;
    }else{
        Dialog_Critical* c = new Dialog_Critical(this, "Error", "Error : No attribut selected", "critical");
        c->show();
    }
}

void Main_Quotation::on_pushButton_firstPlan_clicked()
{

    qreal maxZ = _rectSelected->zValue();

    for(int i = 0; i < _listRectangle->count(); i++){
        Rect_Custom* rect = _listRectangle->at(i);
        if(rect->zValue() > maxZ){
            maxZ = rect->zValue();
        }
    }

    _rectSelected->setZValue(maxZ + 1);

    _scene->updateRect(_rectSelected->getID(), maxZ+1, "Z");

    bdd_ATTRIBUT current;
    core_quotation* core  = new core_quotation();
    current = core->getAttributByID(_rectSelected->getID());
    current.setPositionZ(maxZ+1);
    ui->spinBox_Z->setValue(maxZ+1);
    current.getDict();
    api_post_request* api = new api_post_request();
    api->modifyData(current, "modify");

}


void Main_Quotation::form_cancelled(){

    ui->grey_screen->hide();
    ui->background_form->hide();
}
