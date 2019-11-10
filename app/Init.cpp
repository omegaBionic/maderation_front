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
    QDir T_jsonUser("../app/DATA/jsonUser.json");
    QDir T_jsonClient("../app/DATA/jsonClient.json");
    QDir T_jsonAddressClient("../app/DATA/jsonAddressClient.json");
    QDir T_jsonCategory("../app/DATA/jsonCategory.json");
    QDir T_jsonChat("../app/DATA/jsonChat.json");
    QDir T_jsonComponent("../app/DATA/jsonComponent.json");
    QDir T_jsonGamme("../app/DATA/jsonGamme.json");
    QDir T_jsonInvoiceQuotation("../app/DATA/jsonInvoiceQuotation.json");
    QDir T_jsonMessage("../app/DATA/jsonMessage.json");
    QDir T_jsonProduct("../app/DATA/jsonProduct.json");
    QDir T_jsonProject("../app/DATA/jsonProject.json");
    QDir T_jsonPromotionCat("../app/DATA/jsonPromotionCat.json");
    QDir T_jsonPromotionComp("../app/DATA/jsonPromotionComp.json");
    QDir T_jsonQuotation("../app/DATA/jsonQuotation.json");
    QDir T_jsonRole("../app/DATA/jsonRole.json");
    QDir T_jsonShop("../app/DATA/jsonShop.json");
    QDir T_jsonStock("../app/DATA/jsonStock.json");
    QDir T_jsonSupplier("../app/DATA/jsonSupplier.json");

}




