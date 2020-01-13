#include "form_template.h"
#include "ui_form_template.h"
#include "../CORE/core_template.h"
#include "dialog_critical.h"

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


    core_template* tpl = new core_template();
    QVector<QString> listClient = tpl->getClients();

    for(int i = 0; i<listClient.count(); i++){
        QString client = listClient.at(i);
        ui->comboBox_client->addItem(client);
    }

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
    if(ui->lineEdit_title->text() == ""){
        Dialog_Critical* d = new Dialog_Critical(this, "ERREUR", "Veuillez saisir un titre", "critical");
        d->show();
        return;
    }
    core_template* tpl = new core_template();
    _project.setTitle(ui->lineEdit_title->text());
    _project.setIsTemplate(false);
    _project.setValidation(false);
    _project.setCreationDate(tpl->getTime());
    _project.setValidationDate("not yet validated");
    _project.getDict();
    tpl->copyAttributs(_baseProjectID, _project.getIdProject());
    api_post_request* api = new api_post_request();

    api->modifyData(_project, "add");

    emit validated(_project);
}

void Form_template::setRessource(QString res)
{
    _res = res;
    ui->project_screen->setPixmap(QPixmap(_res).scaled(72*_width, 72*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

}
void Form_template::setProject(bdd_PROJECT project)
{
    _project = project;
    _baseProjectID = project.getIdProject();
    core_template* tpl = new core_template();
    _project.setIDClient(tpl->getClient(ui->comboBox_client->currentText()));
    _project.setIdProject(tpl->getLastIDProject());

}

void Form_template::on_comboBox_client_currentIndexChanged(const QString &arg1)
{

    core_template* tpl = new core_template();
    _project.setIDClient(tpl->getClient(ui->comboBox_client->currentText()));
}
