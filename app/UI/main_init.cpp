#include "main_init.h"
#include "ui_main_init.h"
#include "../CORE/api_get_request.h"
#include <QDesktopServices>
#include <QUrl>
#include <QProcess>
#include <QMessageBox>
#include <QFile>
#include <QtNetwork>
#include <QJsonObject>
#include <QJsonDocument>
#include <QUrlQuery>
#include <QJsonValue>
#include <QDebug>
#include <QCoreApplication>
#include <QDir>

main_init::main_init(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::main_init)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);

}

main_init::~main_init()
{
    delete ui;
}

void main_init::resize(){
    QRect win = this->geometry();
    _width = win.width()/128;
    _height = win.height()/72;
    QDir dir = QDir("./DATA_IMG");
    if(!dir.exists()){
        dir.mkpath(".");
        dir.mkpath("./loading_img");
    }


    QPixmap p = QPixmap(":/pictures/img/loading_leaf_grey.png");
    p = p.scaled(42*_width, 8*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    bool test = p.save("DATA_IMG/loading_img/loading_leaf_grey.png", "png");
    p = QPixmap(":/pictures/img/loading_leaf.png");
    p = p.scaled(42*_width, 8*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    p.save("DATA_IMG/loading_img/loading_leaf.png", "png");


    ui->label->setGeometry(0*_width, 0*_height, 128*_width, 72*_height);
    ui->label->setPixmap(QPixmap(":/pictures/img/background_login.png").scaled(128*_width, 72*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    ui->label_titre->setGeometry(45*_width, 5*_height, 32*_width, 6*_height);
    ui->label_info->setGeometry(40*_width, 40*_height, 42*_width, 6*_height);
    ui->progressBar->setGeometry(40*_width, 30*_height, 42*_width, 8*_height);
    ui->progressBar->setStyleSheet("QProgressBar:horizontal { border: 1px solid gray; border-radius: 3px;background:#00000000;background-image: url(./DATA_IMG/loading_img/loading_leaf_grey.png);}QProgressBar::chunk:horizontal {background:#00000000;background-image: url(./DATA_IMG/loading_img/loading_leaf.png);}");


}

void main_init::resizeEvent(QResizeEvent *){
    // format 16:9 only for the moment
    this->resize();

}

bool main_init::event(QEvent * e)
{
    if(e->type() == QEvent::HoverEnter){
        emit Initialized(0);
    }

    return QMainWindow::event(e) ;
}

void main_init::wait(int time, int interval){
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
                ui->progressBar->setValue(ui->progressBar->value() + 1);
                this->update();
            }
        }else{
            hasUpgrade = false;
        }
    }
    qDebug() << "end of wait...";
}

void main_init::wait(int time, int interval, int increment){
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
                ui->progressBar->setValue(ui->progressBar->value() + increment);
                this->update();
            }
        }else{
            hasUpgrade = false;
        }
    }
    qDebug() << "end of wait...";
}

bool main_init::checkConnection()
{
    //connection a l'api
    try
    {
        ui->label_info->setText("Vérification de la connexion");
        QNetworkAccessManager *manager = new QNetworkAccessManager(this);
        if(manager->networkAccessible() == QNetworkAccessManager::Accessible){
            api_get_request* api = new api_get_request(this);
            api->get_status();
            int timer = clock() + 6000;
            bool hasUpgrade = false;
            while(timer > clock()){
                qApp->processEvents();
                if(clock()%120 == 0){
                    if(!hasUpgrade){
                        if(QFile::exists("./STATUS/jsonStatus.json")){
                            qDebug() << "file exist";
                            break;
                        }
                        qDebug() << clock();
                        hasUpgrade = true;
                        ui->progressBar->setValue(ui->progressBar->value() + 1);
                    }
                }else{
                    hasUpgrade = false;
                }
            }
            this->wait(500,10);
            if(QFile::exists("./STATUS/jsonStatus.json")){
            bdd_STATUS status = api->parse_file_status().first();
            qDebug() << "data : "+status.getDatas();
                if(status.getDatas() == "OK"){
                    return true;
                }
            }else{
                qDebug() << "no data";
                return false;
            }


        }else{
            qDebug() << "error during connexion";
            ui->progressBar->setValue(ui->progressBar->value() + 1);
            return false;
        }
    }
    catch(QUrl url)
    {
        qDebug("Connexion a l'api echoué");
        return false;
    }

    return false;
}



void main_init::Check_folder()
{
    // verification de lexistence du dossier DATA
    ui->label_info->setText("Vérification de la présence du dosier de donnée");
    QDir stat("./STATUS");
    if(!stat.exists()){
        stat.mkpath(".");
    }
    QDir folder("./DATA");
    if(folder.exists())
    {
        //existe

        this->wait(1000,20);

        emit Initialized(1);
        qDebug("folder exist");
    }
    else if (!folder.exists())
    {
        //existe pas
        folder.mkpath("."); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.

        this->wait(1000,20);
        if(this->checkConnection()){
            this->Transfert_Tables();
        }else{
            ui->progressBar->setValue(100);
        }
        qDebug("created");
        emit Initialized(2); // end of initialisation

    }
}


void main_init::Transfert_Tables()
{

    ui->label_info->setText("téléchargement des données");
    //creation des object table de type qfile et de leur chemin
    QFile T_jsonUser("./DATA/jsonUser.json");
    QFile T_jsonClient("./DATA/jsonClient.json");
    QFile T_jsonAddressClient("./DATA/jsonAddressClient.json");
    QFile T_jsonCategory("./DATA/jsonCategory.json");
    QFile T_jsonChat("./DATA/jsonChat.json");
    QFile T_jsonComponent("./DATA/jsonComponent.json");
    QFile T_jsonGamme("./DATA/jsonGamme.json");
    QFile T_jsonInvoiceQuotation("./DATA/jsonInvoiceQuotation.json");
    QFile T_jsonMessage("./DATA/jsonMessage.json");
    QFile T_jsonProduct("./DATA/jsonProduct.json");
    QFile T_jsonProject("./DATA/jsonProject.json");
    QFile T_jsonPromotionCat("./DATA/jsonPromotionCat.json");
    QFile T_jsonPromotionComp("./DATA/jsonPromotionComp.json");
    QFile T_jsonQuotation("./DATA/jsonQuotation.json");

    QFile T_jsonRole("./DATA/jsonRole.json");
    QFile T_jsonShop("./DATA/jsonShop.json");
    QFile T_jsonStock("./DATA/jsonStock.json");
    QFile T_jsonSupplier("./DATA/jsonSupplier.json");
    QFile T_jsonAdressSupplier("./DATA/jsonAddressSupplier.json");

    //timeOut Variable


    api_get_request *getTables = new api_get_request;


        //debut du timer
        //vérification de leur existance dans le dossier
        if(T_jsonUser.exists())
        {
            //existe

            this->wait(500,10);
            qDebug("table T_jsonUser exist");
        }
        else if (!T_jsonUser.exists())
        {
            //existe pas

            ui->label_info->setText("téléchargement du fichier user");

            this->wait(1200,20);
            getTables->get_table_user(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
            qDebug("created");
        }
        //---
        if(T_jsonClient.exists())
        {
            //existe

            this->wait(500,10);
            qDebug("table T_jsonClient exist");
        }
        else if (!T_jsonClient.exists())
        {
            //existe pas
            ui->label_info->setText("téléchargement du fichier client");

            this->wait(1200,20);
            getTables->get_table_client(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
            qDebug("created");
        }
        //---
        if(T_jsonAddressClient.exists())
        {
            //existe

            this->wait(500,10);
            qDebug("table T_jsonAddressClient exist");
        }
        else if (!T_jsonAddressClient.exists())
        {
            //existe pas
            ui->label_info->setText("téléchargement du fichier address client");

            this->wait(1200,20);
           getTables->get_table_address_client(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
            qDebug("created");
        }
        //---
        if(T_jsonCategory.exists())
        {
            //existe

            this->wait(500,10);
            qDebug("table T_jsonCategory  exist");
        }
        else if (!T_jsonCategory.exists())
        {
            //existe pas
            ui->label_info->setText("téléchargement du fichier category");

            this->wait(1200,20);
           getTables->get_table_category(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
            qDebug("created");
        }
        //---
        if(T_jsonChat.exists())
        {
            //existe

            this->wait(500,10);
            qDebug("table T_jsonChat exist");
        }
        else if (!T_jsonChat.exists())
        {
            //existe pas
            ui->label_info->setText("téléchargement du fichier chat");

            this->wait(1200,20);
          getTables->get_table_chat(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
            qDebug("created");
        }
        //---
        if(T_jsonComponent.exists())
        {
            //existe

            this->wait(500,10);
            qDebug("table T_jsonComponent exist");
        }
        else if (!T_jsonComponent.exists())
        {
            //existe pas
            ui->label_info->setText("téléchargement du fichier component");

            this->wait(1200,20);
          getTables->get_table_component(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
            qDebug("created");
        }
        //---
        if(T_jsonGamme.exists())
        {
            //existe

            this->wait(500,10);
            qDebug("table T_jsonGamme exist");
        }
        else if (!T_jsonGamme.exists())
        {
            //existe pas
            ui->label_info->setText("téléchargement du fichier gamme");

            this->wait(1200,20);
          getTables->get_table_gamme(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
            qDebug("created");
        }
        //---
        if(T_jsonInvoiceQuotation.exists())
        {
            //existe

            this->wait(500,10);
            qDebug("table T_jsonInvoiceQuotation exist");
        }
        else if (!T_jsonInvoiceQuotation.exists())
        {
            //existe pas
            ui->label_info->setText("téléchargement du fichier invoice quotation");

            this->wait(1200,20);
           getTables->get_table_invoice_quotation(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
            qDebug("created");
        }
        //---
        if(T_jsonMessage.exists())
        {
            //existe

            this->wait(500,10);
            qDebug("table T_jsonMessage exist");
        }
        else if (!T_jsonMessage.exists())
        {
            //existe pas
            ui->label_info->setText("téléchargement du fichier message");

            this->wait(1200,20);
           getTables->get_table_message(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
            qDebug("created");
        }
        //---
        if(T_jsonProduct.exists())
        {
            //existe

            this->wait(500,10);
            qDebug("table T_jsonProduct exist");
        }
        else if (!T_jsonProduct.exists())
        {
            //existe pas
            ui->label_info->setText("téléchargement du fichier product");

            this->wait(1200,20);
           getTables->get_table_product(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
            qDebug("created");
        }
        //---
        if(T_jsonProject.exists())
        {
            //existe

            this->wait(500,10);
            qDebug("table T_jsonProject exist");
        }
        else if (!T_jsonProject.exists())
        {
            //existe pas
            ui->label_info->setText("téléchargement du fichier project");

            this->wait(1200,20);
            getTables->get_table_project(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
            qDebug("created");
        }
        //---
        if(T_jsonPromotionCat.exists())
        {
            //existe

            this->wait(500,10);
            qDebug("table T_jsonPromotionCat exist");
        }
        else if (!T_jsonPromotionCat.exists())
        {
            //existe pas
            ui->label_info->setText("téléchargement du fichier promotion category");

            this->wait(1200,20);
            getTables->get_table_promotion_cat(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
            qDebug("created");
        }
        //---
        if(T_jsonPromotionComp.exists())
        {
            //existe

            this->wait(500,10);
            qDebug("table T_jsonPromotionComp exist");
        }
        else if (!T_jsonPromotionComp.exists())
        {
            //existe pas
            ui->label_info->setText("téléchargement du fichier promotion component");

            this->wait(1200,20);
             getTables->get_table_promotion_comp(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
            qDebug("created");
        }
        //---
        if(T_jsonQuotation.exists())
        {
            //existe

            this->wait(500,10);
            qDebug("table T_jsonQuotation exist");
        }
        else if (!T_jsonQuotation.exists())
        {
            //existe pas
            ui->label_info->setText("téléchargement du fichier quotation");

            this->wait(1200,20);
              getTables->get_table_quotation(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
            qDebug("created");
        }
        //---
        if(T_jsonRole.exists())
        {
            //existe

            this->wait(500,10);
            qDebug("table T_jsonRole exist");
        }
        else if (!T_jsonRole.exists())
        {
            //existe pas
            ui->label_info->setText("téléchargement du fichier role");

            this->wait(1200,20);
              getTables->get_table_role(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
            qDebug("created");
        }
        //---
        if(T_jsonShop.exists())
        {
            //existe

            this->wait(500,10);
            qDebug("table T_jsonShop exist");
        }
        else if (!T_jsonShop.exists())
        {
            //existe pas
            ui->label_info->setText("téléchargement du fichier shop");

            this->wait(1200,20);
               getTables->get_table_shop(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
            qDebug("created");
        }
        //---
        if(T_jsonStock.exists())
        {
            //existe

            this->wait(500,10);
            qDebug("table T_jsonStock exist");
        }
        else if (!T_jsonStock.exists())
        {
            //existe pas
            ui->label_info->setText("téléchargement du fichier stock");

            this->wait(1200,20);
               getTables->get_table_stock(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
            qDebug("created");
        }
        //---
        if(T_jsonSupplier.exists())
        {
            //existe

            this->wait(500,10);
            qDebug("table T_jsonSupplier exist");
        }
        else if (!T_jsonSupplier.exists())
        {
            //existe pas
            ui->label_info->setText("téléchargement du fichier supplier");

            this->wait(1200,20);
               getTables->get_table_supplier(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
            qDebug("created");
        }
        //---
        if(T_jsonAdressSupplier.exists())
        {
            //existe

            this->wait(500,10);
            qDebug("table T_jsonAdressSupplier exist");
        }
        else if (!T_jsonAdressSupplier.exists())
        {
            //existe pas
            ui->label_info->setText("téléchargement du fichier address supplier");

            this->wait(1200,20);
               getTables->get_table_address_supplier(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
            qDebug("created");
        }
        //---
        emit Initialized(2);







}


void main_init::endInit(){
    ui->label_info->setText("Finalisation...");
    int increment = (2000 - ui->progressBar->value()) / 60;


    this->wait(3000,50, increment);
    emit Initialized(3);
}
