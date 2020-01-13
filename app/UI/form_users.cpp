#include "form_users.h"
#include "ui_form_users.h"
#include "../CORE/core_user_management.h"
#include "../CORE/api_post_request.h"
#include "dialog_critical.h"

Form_users::Form_users(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_users)
{
    ui->setupUi(this);

    ui->pushButton_reset->setVisible(false);
    ui->pushButton_delete->setVisible(false);
    ui->pushButton_validate->setVisible(false);
    ui->pushButton_reset_pwd->setVisible(false);
}

Form_users::Form_users(QWidget *parent, QString mode) :
    QWidget(parent),
    ui(new Ui::Form_users)
{
    ui->setupUi(this);

    ui->pushButton_reset->setVisible(false);
    ui->pushButton_delete->setVisible(false);
    ui->pushButton_validate->setVisible(false);
    ui->pushButton_reset_pwd->setVisible(false);
    _mode = mode;
    this->setAttributs();
}

Form_users::Form_users(QWidget *parent, bdd_USER user) :
    QWidget(parent),
    ui(new Ui::Form_users)
{
    ui->setupUi(this);
    _user = user;
    _baseUser = user;
    ui->lineEdit_username->setVisible(false);
    _mode = "edit";
    this->setAttributs();

}



Form_users::~Form_users()
{
    delete ui;
}

void Form_users::setAttributs(){

    ui->lineEdit_email->setText(_user.getMail());
    ui->lineEdit_phone->setText(_user.getPhoneNumber());
    ui->lineEdit_lastname->setText(_user.getLastName());
    ui->lineEdit_firstname->setText(_user.getFirstName());




    if(_user.getIsActive()){
        ui->checkBox_active->setChecked(true);
    }
    core_user_management* core = new core_user_management();
    QVector<bdd_ROLE> roles = core->getUserRole(_user);
    _user_roles = roles;

    ui->checkBox_user->setChecked(false);
    ui->checkBox_admin->setChecked(false);
    ui->checkBox_super_admin->setChecked(false);
    for(int i = 0; i<roles.count(); i++){
        bdd_ROLE role = roles.at(i);
        if(role.getLabel() == "user"){
            ui->checkBox_user->setChecked(true);
        }

        if(role.getLabel() == "admin"){
            ui->checkBox_admin->setChecked(true);
        }

        if(role.getLabel() == "superAdmin"){
            ui->checkBox_super_admin->setChecked(true);
        }
    }

    QVector<bdd_SHOP> shops = core->getUserShop();

    for(int i = 0; i< shops.count();i++){
        bdd_SHOP shop = shops.at(i);
        ui->comboBox_shop->addItem(shop.getCity() + "(" + shop.getStreet() + "," + QString::number(shop.getPostalCode()) + ")");
        if(shop.getIdShop() == QString::number(_user.getAddressIdAddress())){
            ui->comboBox_shop->setCurrentIndex(ui->comboBox_shop->count()-1);
        }
    }

}

void Form_users::resizeEvent(QResizeEvent *){
    // format 16:9 only for the moment
    QRect win = this->geometry();
    _width = win.width()/128;
    _height = win.height()/72;
    if(_mode =="new"){
        ui->groupBox_roles->setGeometry(92*_width, 10*_height, 30*_width, 30*_height);
        ui->comboBox_shop->setGeometry(40*_width, 10*_height, 45*_width, 6*_height);
    }else{
        ui->groupBox_roles->setGeometry(90*_width, 10*_height, 20*_width, 40*_height);
        ui->comboBox_shop->setGeometry(40*_width, 10*_height, 20*_width, 6*_height);
    }
//    ui->verticalLayout->setGeometry(QRect(0*_width, 0*_height, 20*_width, 40*_height));
    ui->lineEdit_username->setGeometry(3*_width, 0*_height, 30*_width, 6*_height);
    ui->lineEdit_firstname->setGeometry(3*_width, 10*_height, 30*_width, 6*_height);
    ui->lineEdit_lastname->setGeometry(3*_width, 20*_height, 30*_width, 6*_height);
    ui->lineEdit_email->setGeometry(3*_width, 30*_height, 30*_width, 6*_height);
    ui->lineEdit_phone->setGeometry(3*_width, 40*_height, 30*_width, 6*_height);
    ui->checkBox_active->setGeometry(3*_width, 50*_height, 30*_width, 4*_height);
    ui->pushButton_reset->setGeometry(86*_width, 60*_height, 10*_width, 10*_height);

    ui->pushButton_delete->setGeometry(98*_width, 60*_height, 10*_width, 10*_height);

    ui->pushButton_validate->setGeometry(110*_width, 60*_height, 10*_width, 10*_height);

    ui->pushButton_reset_pwd->setGeometry(122*_width, 60*_height, 10*_width, 10*_height);

    ui->checkBox_user->setGeometry(0*_width, 5*_height, 30*_width, 4*_height);
    ui->checkBox_admin->setGeometry(0*_width, 15*_height, 30*_width, 4*_height);
    ui->checkBox_super_admin->setGeometry(0*_width, 25 * _height, 30*_width, 4*_height);


}

void Form_users::on_pushButton_validate_clicked()
{

    api_post_request* api = new api_post_request();
    _user.getDict();
    api->modifyData(_user, "modify");
    core_user_management* core = new core_user_management();
    QVector<bdd_ROLE> roles = core->getUserRole(_user);

    if(ui->checkBox_user->isChecked()){
        bool roleExists = false;
        for(int i = 0; i<roles.count();i++){
            bdd_ROLE role = roles.at(i);
            if(role.getLabel() == "user"){
                roleExists = true;
            }
        }
        if(!roleExists){
            bdd_ROLE role = bdd_ROLE(_user.getUsername(), QString::number(core->getLastIDRole()), "user");
            role.getDict();
            api->modifyData(role, "add");
        }
    }else{
        for(int i = 0; i<roles.count();i++){
            bdd_ROLE role = roles.at(i);
            if(role.getLabel() == "user"){
                role.getDict();
                api->modifyData(role, "delete");
            }
        }
    }
    if(ui->checkBox_admin->isChecked()){
        bool roleExists = false;
        for(int i = 0; i<roles.count();i++){
            bdd_ROLE role = roles.at(i);
            if(role.getLabel() == "admin"){
                roleExists = true;
            }
        }
        if(!roleExists){
            bdd_ROLE role = bdd_ROLE(_user.getUsername(), QString::number(core->getLastIDRole()), "admin");
            role.getDict();
            api->modifyData(role, "add");
        }
    }else{
        for(int i = 0; i<roles.count();i++){
            bdd_ROLE role = roles.at(i);
            if(role.getLabel() == "admin"){
                role.getDict();
                api->modifyData(role, "delete");
            }
        }
    }
    if(ui->checkBox_super_admin->isChecked()){
        bool roleExists = false;
        for(int i = 0; i<roles.count();i++){
            bdd_ROLE role = roles.at(i);
            if(role.getLabel() == "superAdmin"){
                roleExists = true;
            }
        }
        if(!roleExists){
            bdd_ROLE role = bdd_ROLE(_user.getUsername(), QString::number(core->getLastIDRole()), "superAdmin");
            role.getDict();
            api->modifyData(role, "add");
        }
    }else{
        for(int i = 0; i<roles.count();i++){
            bdd_ROLE role = roles.at(i);
            if(role.getLabel() == "superAdmin"){
                role.getDict();
                api->modifyData(role, "delete");
            }
        }
    }

    emit UsersUpdated(2);

}

void Form_users::on_pushButton_delete_clicked()
{
    api_post_request* api = new api_post_request();
    _user.getDict();
    api->modifyData(_user, "delete");
    core_user_management* core = new core_user_management();
    QVector<bdd_ROLE> roles = core->getUserRole(_user);

    for(int i = 0; i<roles.count();i++){
        bdd_ROLE role = roles.at(i);
        if(role.getLabel() == "user"){
            role.getDict();
            api->modifyData(role, "delete");
        }

    }

    emit UsersUpdated(1);

}

void Form_users::on_pushButton_reset_clicked()
{
    _user =_baseUser;
    this->setAttributs();
}

void Form_users::on_comboBox_shop_currentTextChanged(const QString &arg1)
{
    core_user_management* core = new core_user_management();
    QVector<bdd_SHOP> shops = core->getUserShop();
    for(int i =0; i< shops.count(); i++){
        bdd_SHOP shop = shops.at(i);
        if(shop.getCity() + "(" + shop.getStreet() + "," + QString::number(shop.getPostalCode()) + ")" == arg1){
            _user.setIdAddress(shop.getId().toInt());
        }
    }
}

void Form_users::on_lineEdit_firstname_textChanged(const QString &arg1)
{
    _user.setFirstName(arg1);
}

void Form_users::on_lineEdit_lastname_textChanged(const QString &arg1)
{
    _user.setLastName(arg1);
}

void Form_users::on_lineEdit_email_textChanged(const QString &arg1)
{
    _user.setMail(arg1);
}

void Form_users::on_lineEdit_phone_textChanged(const QString &arg1)
{
    _user.setPhoneNumber(arg1);
}

void Form_users::on_checkBox_active_stateChanged(int arg1)
{
    _user.setIsActive(ui->checkBox_active->isChecked());
}

bdd_USER Form_users::getUser(){
    return _user;
}

void Form_users::addUser(){
    _user.setPassword("admin");
    if(ui->lineEdit_username->text() == ""){
        return;
    }
    api_post_request* api = new api_post_request();
    _user.getDict();
    api->modifyData(_user, "add");
    core_user_management* core = new core_user_management();
    QVector<bdd_ROLE> roles = core->getUserRole(_user);

    if(ui->checkBox_user->isChecked()){
        bool roleExists = false;
        for(int i = 0; i<roles.count();i++){
            bdd_ROLE role = roles.at(i);
            if(role.getLabel() == "user"){
                roleExists = true;
            }
        }
        if(!roleExists){
            bdd_ROLE role = bdd_ROLE(_user.getUsername(), QString::number(core->getLastIDRole()), "user");
            role.getDict();
            api->modifyData(role, "add");
        }
    }else{
        for(int i = 0; i<roles.count();i++){
            bdd_ROLE role = roles.at(i);
            if(role.getLabel() == "user"){
                role.getDict();
                api->modifyData(role, "delete");
            }
        }
    }
    if(ui->checkBox_admin->isChecked()){
        bool roleExists = false;
        for(int i = 0; i<roles.count();i++){
            bdd_ROLE role = roles.at(i);
            if(role.getLabel() == "admin"){
                roleExists = true;
            }
        }
        if(!roleExists){
            bdd_ROLE role = bdd_ROLE(_user.getUsername(), QString::number(core->getLastIDRole()), "admin");
            role.getDict();
            api->modifyData(role, "add");
        }
    }else{
        for(int i = 0; i<roles.count();i++){
            bdd_ROLE role = roles.at(i);
            if(role.getLabel() == "admin"){
                role.getDict();
                api->modifyData(role, "delete");
            }
        }
    }
    if(ui->checkBox_super_admin->isChecked()){
        bool roleExists = false;
        for(int i = 0; i<roles.count();i++){
            bdd_ROLE role = roles.at(i);
            if(role.getLabel() == "superAdmin"){
                roleExists = true;
            }
        }
        if(!roleExists){
            bdd_ROLE role = bdd_ROLE(_user.getUsername(), QString::number(core->getLastIDRole()), "superAdmin");
            role.getDict();
            api->modifyData(role, "add");
        }
    }else{
        for(int i = 0; i<roles.count();i++){
            bdd_ROLE role = roles.at(i);
            if(role.getLabel() == "superAdmin"){
                role.getDict();
                api->modifyData(role, "delete");
            }
        }
    }
    emit UsersUpdated(0);

}

void Form_users::on_lineEdit_username_textChanged(const QString &arg1)
{
    _user.setUsername(arg1);
}
