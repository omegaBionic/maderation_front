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

#include "../app/database_classes/bdd_address_client.h"
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
#include "../app/database_classes/bdd_user.h"

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

    api_get_request *getTables = new api_get_request;

    QTextStream outUser(&T_jsonUser);
    QTextStream outClient(&T_jsonClient);
    QTextStream outAdressClient(&T_jsonAddressClient);
    QTextStream outCategory(&T_jsonCategory);
    QTextStream outChat(&T_jsonChat);
    QTextStream outComponent(&T_jsonComponent);
    QTextStream outGamme(&T_jsonGamme);
    QTextStream outInvoiceQuotation(&T_jsonInvoiceQuotation);
    QTextStream outMessage(&T_jsonMessage);
    QTextStream outProduct(&T_jsonProduct);
    QTextStream outProject(&T_jsonProject);
    QTextStream outPromotionCat(&T_jsonPromotionCat);
    QTextStream outPromotionComp(&T_jsonPromotionComp);
    QTextStream outQuotation(&T_jsonQuotation);
    QTextStream outRole(&T_jsonRole);
    QTextStream outShop(&T_jsonShop);
    QTextStream outStock(&T_jsonStock);
    QTextStream outSupplier(&T_jsonSupplier);


    if(!T_jsonUser.open(QIODevice::Append | QIODevice::Text))
        return;

    QTextStream out(&T_jsonUser);

    getTables->get_table_user();
    getTables->get_table_client();
    getTables->get_table_address_client();
    getTables->get_table_category();
    getTables->get_table_chat();
    getTables->get_table_component();
    getTables->get_table_gamme();
    getTables->get_table_invoice_quotation();
    getTables->get_table_message();
    getTables->get_table_product();
    getTables->get_table_project();
    getTables->get_table_promotion_cat();
    getTables->get_table_promotion_comp();
    getTables->get_table_quotation();
    getTables->get_table_role();
    getTables->get_table_shop();
    getTables->get_table_stock();
    getTables->get_table_supplier();
    getTables->get_table_address_supplier();



}




