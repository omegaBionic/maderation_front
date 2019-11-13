#include "main_login.h"
#include "ui_main_login.h"
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
#include <sys/stat.h>
#include <QDir>
#include "Init.h"
#include <QCoreApplication>

//classe des tables
#include "api_get_request.h"

/*#include "../app/database_classes/bdd_address_client.h"
#include "../app/database_classes/bdd_address_supplier.h"
#include "../app/database_classes/bdd_category.h"
#include "../app/database_classes/bdd_chat.h"
#include "../app/database_classes/bdd_client.h"
#include "../app/database_classes/bdd_component.h"
#include "../app/database_classes/bdd_gamme.h"
#include "../app/database_classes/bdd_invoice_quotation.h"
#include "../app/database_classes/bdd_message.h"
#include "../app/database_classes/bdd_product.h"
#include "../app/database_classes/bdd_promotion_cat.h"
#include "../app/database_classes/bdd_promotion_comp.h"
#include "../app/database_classes/bdd_quotation.h"
#include "../app/database_classes/bdd_role.h"
#include "../app/database_classes/bdd_shop.h"
#include "../app/database_classes/bdd_status.h"
#include "../app/database_classes/bdd_stock.h"
#include "../app/database_classes/bdd_supplier.h"
#include "../app/database_classes/bdd_user.h"*/

Init::Init()
{

}

Init::~Init()
{

}

void Init::Check_folder()
{
    // verification de lexistence du dossier DATA

    QDir folder("DATA");
    if(folder.exists())
    {
        //existe
        qDebug("folder exist");
    }
    else if (!folder.exists())
    {
        //existe pas
        folder.mkpath("."); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
        qDebug("created");

    }

};

bool Init::checkConnection()
{
    //connection a l'api
    qDebug("connection a l'api");

    QNetworkAccessManager manager;

    QUrl url("http://madera-api.maderation.net:8080/api/get/status?key=179616f1a4cecab2a7eab481b84d076c");
    QNetworkReply *response = manager.get(QNetworkRequest(url));

    QEventLoop event2;
    QObject::connect(response,SIGNAL(finished()),&event2,SLOT(quit()));
    event2.exec();
    QString html = response->readAll();

    //transformation du json pour lecture

     qDebug("Récuperation du json et transformation");
    //html ="{\"status\":true,\"datas\":\"key: OK, dynamodb: OK\"}";
    QJsonDocument jsonDoc= QJsonDocument::fromJson(html.toUtf8());
    QJsonObject MyObject = jsonDoc.object();
    MyObject.value(QString("status"));
    qDebug()<< MyObject.value(QString("status"));
    QJsonValue statut =  MyObject.value(QString("status"));

     qDebug("Vérification du statut de la  bdd");
     if(MyObject.value(QString("status")) == "true"){
         return true;
     }else {
         return false;
     }
}

void Init::Transfert_Tables()
{
    //creation des object table de type qfile et de leur chemin
    QFile T_jsonUser("../app/DATA/jsonUser.json");
    QFile T_jsonClient("../app/DATA/jsonClient.json");
    QFile T_jsonAddressClient("../app/DATA/jsonAddressClient.json");
    QFile T_jsonCategory("../app/DATA/jsonCategory.json");
    QFile T_jsonChat("../app/DATA/jsonChat.json");
    QFile T_jsonComponent("../app/DATA/jsonComponent.json");
    QFile T_jsonGamme("../app/DATA/jsonGamme.json");
    QFile T_jsonInvoiceQuotation("../app/DATA/jsonInvoiceQuotation.json");
    QFile T_jsonMessage("../app/DATA/jsonMessage.json");
    QFile T_jsonProduct("../app/DATA/jsonProduct.json");
    QFile T_jsonProject("../app/DATA/jsonProject.json");
    QFile T_jsonPromotionCat("../app/DATA/jsonPromotionCat.json");
    QFile T_jsonPromotionComp("../app/DATA/jsonPromotionComp.json");
    QFile T_jsonQuotation("../app/DATA/jsonQuotation.json");

    QFile T_jsonRole("../app/DATA/jsonRole.json");
    QFile T_jsonShop("../app/DATA/jsonShop.json");
    QFile T_jsonStock("../app/DATA/jsonStock.json");
    QFile T_jsonSupplier("../app/DATA/jsonSupplier.json");
     QFile T_jsonAdressSupplier("../app/DATA/jsonAddressSupplier.json");

    api_get_request *getTables = new api_get_request;

    //varification de leur existance dans le dossier
    if(T_jsonUser.exists())
    {
        //existe
        qDebug("table T_jsonUser exist");
    }
    else if (!T_jsonUser.exists())
    {
        //existe pas
         getTables->get_table_user(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
        qDebug("created");
    }
    //---
    if(T_jsonClient.exists())
    {
        //existe
        qDebug("table T_jsonClient exist");
    }
    else if (!T_jsonClient.exists())
    {
        //existe pas
        getTables->get_table_client(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
        qDebug("created");
    }
    //---
    if(T_jsonAddressClient.exists())
    {
        //existe
        qDebug("table T_jsonAddressClient exist");
    }
    else if (!T_jsonAddressClient.exists())
    {
        //existe pas
       getTables->get_table_address_client(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
        qDebug("created");
    }
    //---
    if(T_jsonCategory.exists())
    {
        //existe
        qDebug("table T_jsonCategory  exist");
    }
    else if (!T_jsonCategory.exists())
    {
        //existe pas
       getTables->get_table_category(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
        qDebug("created");
    }
    //---
    if(T_jsonChat.exists())
    {
        //existe
        qDebug("table T_jsonChat exist");
    }
    else if (!T_jsonChat.exists())
    {
        //existe pas
      getTables->get_table_chat(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
        qDebug("created");
    }
    //---
    if(T_jsonComponent.exists())
    {
        //existe
        qDebug("table T_jsonComponent exist");
    }
    else if (!T_jsonComponent.exists())
    {
        //existe pas
      getTables->get_table_component(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
        qDebug("created");
    }
    //---
    if(T_jsonGamme.exists())
    {
        //existe
        qDebug("table T_jsonGamme exist");
    }
    else if (!T_jsonGamme.exists())
    {
        //existe pas
      getTables->get_table_gamme(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
        qDebug("created");
    }
    //---
    if(T_jsonInvoiceQuotation.exists())
    {
        //existe
        qDebug("table T_jsonInvoiceQuotation exist");
    }
    else if (!T_jsonInvoiceQuotation.exists())
    {
        //existe pas
       getTables->get_table_invoice_quotation(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
        qDebug("created");
    }
    //---
    if(T_jsonMessage.exists())
    {
        //existe
        qDebug("table T_jsonMessage exist");
    }
    else if (!T_jsonMessage.exists())
    {
        //existe pas
       getTables->get_table_message(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
        qDebug("created");
    }
    //---
    if(T_jsonProduct.exists())
    {
        //existe
        qDebug("table T_jsonProduct exist");
    }
    else if (!T_jsonProduct.exists())
    {
        //existe pas
       getTables->get_table_product(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
        qDebug("created");
    }
    //---
    if(T_jsonProject.exists())
    {
        //existe
        qDebug("table T_jsonProject exist");
    }
    else if (!T_jsonProject.exists())
    {
        //existe pas
        getTables->get_table_project(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
        qDebug("created");
    }
    //---
    if(T_jsonPromotionCat.exists())
    {
        //existe
        qDebug("table T_jsonPromotionCat exist");
    }
    else if (!T_jsonPromotionCat.exists())
    {
        //existe pas
        getTables->get_table_promotion_cat(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
        qDebug("created");
    }
    //---
    if(T_jsonPromotionComp.exists())
    {
        //existe
        qDebug("table T_jsonPromotionComp exist");
    }
    else if (!T_jsonPromotionComp.exists())
    {
        //existe pas
         getTables->get_table_promotion_comp(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
        qDebug("created");
    }
    //---
    if(T_jsonQuotation.exists())
    {
        //existe
        qDebug("table T_jsonQuotation exist");
    }
    else if (!T_jsonQuotation.exists())
    {
        //existe pas
          getTables->get_table_quotation(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
        qDebug("created");
    }
    //---
    if(T_jsonRole.exists())
    {
        //existe
        qDebug("table T_jsonRole exist");
    }
    else if (!T_jsonRole.exists())
    {
        //existe pas
          getTables->get_table_role(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
        qDebug("created");
    }
    //---
    if(T_jsonShop.exists())
    {
        //existe
        qDebug("table T_jsonShop exist");
    }
    else if (!T_jsonShop.exists())
    {
        //existe pas
           getTables->get_table_shop(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
        qDebug("created");
    }
    //---
    if(T_jsonStock.exists())
    {
        //existe
        qDebug("table T_jsonStock exist");
    }
    else if (!T_jsonStock.exists())
    {
        //existe pas
           getTables->get_table_stock(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
        qDebug("created");
    }
    //---
    if(T_jsonSupplier.exists())
    {
        //existe
        qDebug("table T_jsonSupplier exist");
    }
    else if (!T_jsonSupplier.exists())
    {
        //existe pas
           getTables->get_table_supplier(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
        qDebug("created");
    }
    //---
    if(T_jsonAdressSupplier.exists())
    {
        //existe
        qDebug("table T_jsonAdressSupplier exist");
    }
    else if (!T_jsonAdressSupplier.exists())
    {
        //existe pas
           getTables->get_table_address_supplier(); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
        qDebug("created");
    }
    //---





}




