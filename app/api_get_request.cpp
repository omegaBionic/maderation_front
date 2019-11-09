#include "api_get_request.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDir>
#include <fstream>
#include <QVector>
#include "./database_classes/bdd_status.h"
#include "./database_classes/bdd_user.h"
#include "./database_classes/bdd_client.h"
#include "./database_classes/bdd_address_client.h"
#include "./database_classes/bdd_address_supplier.h"
#include "./database_classes/bdd_category.h"
#include "./database_classes/bdd_chat.h"
#include "./database_classes/bdd_component.h"
#include "./database_classes/bdd_gamme.h"
#include "./database_classes/bdd_invoice_quotation.h"
#include "./database_classes/bdd_message.h"
#include "./database_classes/bdd_product.h"
#include "./database_classes/bdd_project.h"
#include "./database_classes/bdd_promotion_cat.h"
#include "./database_classes/bdd_promotion_comp.h"
#include "./database_classes/bdd_quotation.h"
#include "./database_classes/bdd_role.h"
#include "./database_classes/bdd_shop.h"
#include "./database_classes/bdd_stock.h"
#include "./database_classes/bdd_supplier.h"

api_get_request::api_get_request(QObject *parent) : QObject(parent)
{

}

void api_get_request::get_status(){

    QNetworkAccessManager man;
    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/status?key=179616f1a4cecab2a7eab481b84d076c"));
    QNetworkReply *reply = man.get(request);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();

    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

    QFile::rename("jsonAll.json","data/jsonStatus.json");

    reply->deleteLater();
}

QVector<bdd_STATUS> api_get_request::parse_file_status(){

    QFile file("data/jsonStatus.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QVector<bdd_STATUS> listStatus;

    listStatus.append(bdd_STATUS(json["status"].toString(),json["datas"].toString()));

    return listStatus;
}

void api_get_request::get_table_user(){

    QNetworkAccessManager man;
    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/user?key=83c2c07ea1251a1a39ec46d52cbba19c"));
    QNetworkReply *reply = man.get(request);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();

    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

    QFile::rename("jsonAll.json","data/jsonUser.json");

    reply->deleteLater();
}

QVector<bdd_USER> api_get_request::parse_file_user(){

    QFile file("data/jsonUser.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QVector<bdd_USER> listUser;

    listUser.append(bdd_USER(json["phoneNumber"].toString(), json["isActive"].toBool(), json["lastName"].toString(), json["password"].toString(), json["firstName"].toString(), json["addressId"].toInt(), json["mail"].toString(), json["username"].toString()));

    return listUser;
}

void api_get_request::get_table_client(){

    QNetworkAccessManager man;
    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/client?key=9f15cb387f77c3284bd1bdc364a21eb7"));
    QNetworkReply *reply = man.get(request);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();

    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

    QFile::rename("jsonClient.json","data/jsonClient.json");

    reply->deleteLater();
}

QVector<bdd_CLIENT> api_get_request::parse_file_client(){

    QFile file("data/jsonClient.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QVector<bdd_CLIENT> listClient;

    listClient.append(bdd_CLIENT(json["username"].toString(), json["phoneNumber"].toString(), json["isActive"].toBool(), json["password"].toString(), json["lastName"].toString(), json["firstName"].toString(), json["mail"].toString(), json["addressId"].toInt()));

    return listClient;
}

void api_get_request::get_table_address_client(){

    QNetworkAccessManager man;
    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/address_client?key=28e60ed41c0a59a442cade866bff3a97"));
    QNetworkReply *reply = man.get(request);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();

    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

    QFile::rename("jsonClient.json","data/jsonAddressClient.json");

    reply->deleteLater();
}

QVector<bdd_ADDRESS_CLIENT> api_get_request::parse_file_address_client(){

    QFile file("data/jsonAddressClient.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QVector<bdd_ADDRESS_CLIENT> listAddressClient;

    listAddressClient.append(bdd_ADDRESS_CLIENT(json["city"].toString(), json["idAddressClient"].toString(), json["country"].toString(), json["postalCode"].toInt(), json["street"].toString()));

    return listAddressClient;

}

void api_get_request::get_table_address_supplier(){

    QNetworkAccessManager man;
    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/address_supplier?key=33f85cb0c62fc22f5c2ad0f067c5e83a"));
    QNetworkReply *reply = man.get(request);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();

    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

    QFile::rename("jsonAddressSupplier.json","data/jsonAddressSupplier.json");

    reply->deleteLater();
}

QVector<bdd_ADDRESS_SUPPLIER> api_get_request::parse_file_address_supplier(){

    QFile file("data/jsonAddressSupplier.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QVector<bdd_ADDRESS_SUPPLIER> listAddressSupplier;

    listAddressSupplier.append(bdd_ADDRESS_SUPPLIER(json["city"].toString(), json["idAddressClient"].toString(), json["country"].toString(), json["postalCode"].toInt(), json["street"].toString()));

    return listAddressSupplier;
}

void api_get_request::get_table_category(){

    QNetworkAccessManager man;
    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/category?key=182ea700442885f568585f374423073d"));
    QNetworkReply *reply = man.get(request);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();

    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

    QFile::rename("jsonCategory.json","data/jsonCategory.json");

    reply->deleteLater();
}

QVector<bdd_CATEGORY> api_get_request::parse_file_category(){

    QFile file("data/jsonCategory.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QVector<bdd_CATEGORY> listCategory;

    listCategory.append(bdd_CATEGORY(json["idCategory"].toString(), json["label"].toString()));

    return listCategory;

}

//void api_get_request::get_table_chat(){

//    QNetworkAccessManager man;
//    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/chat?key=80aacfbde81d03d20788f370417651cc"));
//    QNetworkReply *reply = man.get(request);

//    while (!reply->isFinished())
//    {
//        qApp->processEvents();
//    }

//    QByteArray response_data = reply->readAll();

//    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

//    QFile::rename("jsonChat.json","data/jsonChat.json");

//    reply->deleteLater();
//}

QVector<bdd_CHAT> api_get_request::parse_file_chat(){

//    QFile file("data/jsonChat.json");
//    file.open(QIODevice::ReadOnly);
//    QByteArray rawData = file.readAll();

//    // Parse document
//    QJsonDocument doc(QJsonDocument::fromJson(rawData));

//    // Get JSON object
//    QJsonObject json = doc.object();

//    // Access properties

    QVector<bdd_CHAT> listChat;

    listChat.append(bdd_CHAT(json["idChat"].toString(), json["userUsernameAsReceiver"].toString(), json["creationDate"].toString(), json["title"].toString()));

    return listChat;
}

void api_get_request::get_table_component(){

    QNetworkAccessManager man;
    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/component?key=6400edeffb01785cb7426801619d8535"));
    QNetworkReply *reply = man.get(request);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();

    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

    QFile::rename("jsonComponent.json","data/jsonComponent.json");

    reply->deleteLater();
}

QVector<bdd_COMPONENT> api_get_request::parse_file_component(){

    QFile file("data/jsonComponent.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties


    QVector<bdd_COMPONENT> listComponent;

    listComponent.append(bdd_COMPONENT(json["supplierIdSupplier"].toInt(), json["idComponent"].toString(), json["categoryIdCategory"].toInt(), json["label"].toString()));

    return listComponent;
}

void api_get_request::get_table_gamme(){

    QNetworkAccessManager man;
    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/gamme?key=9af660ef63fbb9e5175d56f064d7a0db"));
    QNetworkReply *reply = man.get(request);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();

    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

    QFile::rename("jsonGamme.json","data/jsonGamme.json");

    reply->deleteLater();
}

QVector<bdd_GAMME> api_get_request::parse_file_gamme(){

    QFile file("data/jsonGamme.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QVector<bdd_GAMME> listGamme;

    listGamme.append(bdd_GAMME(json["idGamme"].toString(), json["productIdProduct"].toInt(), json["label"].toString()));

    return listGamme;
}

void api_get_request::get_table_invoice_quotation(){

    QNetworkAccessManager man;
    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/invoice_quotation?key=74cc360b19fc2a94ea620ef5803a381b"));
    QNetworkReply *reply = man.get(request);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();

    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

    QFile::rename("jsonInvoiceQuotation.json","data/jsonInvoiceQuotation.json");

    reply->deleteLater();
}

QVector<bdd_INVOICE_QUOTATION> api_get_request::parse_file_invoice_quotation(){

    QFile file("data/jsonInvoiceQuotation.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties


    QVector<bdd_INVOICE_QUOTATION> listInvoiceQuotation;
    listInvoiceQuotation.append(bdd_INVOICE_QUOTATION(json["transactionCode"].toString(), json["idInvoiceQuotation"].toString(), json["totalAmount"].toInt(), json["payingMethod"].toString(), json["transactionType"].toString(), json["taxes"].toInt()));

    return listInvoiceQuotation;
}

void api_get_request::get_table_message(){

    QNetworkAccessManager man;
    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/message?key=a853ca2949386f7d527bf06117bda9e3"));
    QNetworkReply *reply = man.get(request);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();

    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

    QFile::rename("jsonMessage.json","data/jsonMessage.json");

    reply->deleteLater();
}

QVector<bdd_MESSAGE> api_get_request::parse_file_message(){

    QFile file("data/jsonMessage.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QVector<bdd_MESSAGE> listMessage;

    listMessage.append(bdd_MESSAGE(json["creationDate"].toString(), json["message"].toString(), json["chatIoChat"].toString(), json["userUsername"].toString(), json["idMessage"].toString()));

    return listMessage;
}

void api_get_request::get_table_product(){

    QNetworkAccessManager man;
    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/product?key=4789725dd2d8061e7faf00fce9af48e1"));
    QNetworkReply *reply = man.get(request);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();

    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

    QFile::rename("jsonProduct.json","data/jsonProduct.json");

    reply->deleteLater();
}

QVector<bdd_PRODUCT> api_get_request::parse_file_product(){

    QFile file("data/jsonProduct.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QVector<bdd_PRODUCT> listProduct;
    listProduct.append(bdd_PRODUCT(json["supplierIdSupplier"].toInt(), json["idProduct"].toString(), json["minWidth"].toInt(), json["defaultLength"].toInt(), json["label"].toString(), json["productCode"].toString(), json["defaultHeight"].toInt(), json["defaultWidth"].toInt(), json["material"].toString(), json["minLength"].toInt(), json["type"].toString()));

    return listProduct;
}

void api_get_request::get_table_project(){

    QNetworkAccessManager man;
    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/project?key=3f61093fa59c13f81fc8648a3d644e0b"));
    QNetworkReply *reply = man.get(request);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();

    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

    QFile::rename("jsonProject.json","data/jsonProject.json");

    reply->deleteLater();
}

QVector<bdd_PROJECT> api_get_request::parse_file_project(){

    QFile file("data/jsonProject.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QVector<bdd_PROJECT> listProject;

    listProject.append(bdd_PROJECT(json["supplierIdSupplier"].toString(), json["validation"].toBool(), json["creationDate"].toString(), json["isTemplate"].toBool(), json["idProject"].toString(), json["userUsername"].toString()));

    return listProject;

}

void api_get_request::get_table_promotion_cat(){

    QNetworkAccessManager man;
    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/promotion_cat?key=557c0271e30cf474e0f46f93721fd1ba"));
    QNetworkReply *reply = man.get(request);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();

    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

    QFile::rename("jsonPromotionCat.json","data/jsonPromotionCat.json");

    reply->deleteLater();
}

QVector<bdd_PROMOTION_CAT> api_get_request::parse_file_promotion_cat(){

    QFile file("data/jsonPromotionCat.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QVector<bdd_PROMOTION_CAT> listPromotionCat;

    listPromotionCat.append(bdd_PROMOTION_CAT(json["amount"].toInt(), json["addToExistingProm"].toBool(), json["fromDate"].toString(), json["idPromotionCat"].toString(), json["toDate"].toString()));

    return listPromotionCat;

}

void api_get_request::get_table_promotion_comp(){

    QNetworkAccessManager man;
    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/promotion_comp?key=2b11565d85da178b3a1942a22d20c624"));
    QNetworkReply *reply = man.get(request);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();

    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

    QFile::rename("jsonPromotionComp.json","data/jsonPromotionComp.json");

    reply->deleteLater();
}

QVector<bdd_PROMOTION_COMP> api_get_request::parse_file_promotion_comp(){

    QFile file("data/jsonPromotionComp.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QVector<bdd_PROMOTION_COMP> listPromotionComp;

    listPromotionComp.append(bdd_PROMOTION_COMP(json["amount"].toInt(), json["addToExistingProm"].toBool(), json["fromDate"].toString(), json["idPromotionComp"].toString(), json["toDate"].toString()));

    return listPromotionComp;
}

void api_get_request::get_table_quotation(){

    QNetworkAccessManager man;
    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/quotation?key=eb307516cffbc5e529cf9c7350ffc299"));
    QNetworkReply *reply = man.get(request);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();

    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

    QFile::rename("jsonQuotation.json","data/jsonQuotation.json");

    reply->deleteLater();
}

QVector<bdd_QUOTATION> api_get_request::parse_file_quotation(){

    QFile file("data/jsonQuotation.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QVector<bdd_QUOTATION> listQuotation;

    listQuotation.append(bdd_QUOTATION(json["validation"].toBool(), json["idQuotation"].toString(), json["creationDate"].toString(), json["isTemplate"].toBool(), json["userUsername"].toString(), json["valicationDate"].toString()));

    return listQuotation;

}

void api_get_request::get_table_role(){

    QNetworkAccessManager man;
    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/quotation?key=eb307516cffbc5e529cf9c7350ffc299"));
    QNetworkReply *reply = man.get(request);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();

    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

    QFile::rename("jsonRole.json","data/jsonRole.json");

    reply->deleteLater();
}

QVector<bdd_ROLE> api_get_request::parse_file_role(){

    QFile file("data/jsonRole.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QVector<bdd_ROLE> listRole;

    listRole.append(bdd_ROLE(json["userUsername"].toString(), json["idRole"].toString(), json["label"].toString()));

    return listRole;

}

void api_get_request::get_table_shop(){

    QNetworkAccessManager man;
    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/shop?key=p3f85cbdc62fc22f5c2ad0f067m5eldlda"));
    QNetworkReply *reply = man.get(request);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();

    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

    QFile::rename("jsonShop.json","data/jsonShop.json");

    reply->deleteLater();
}

QVector<bdd_SHOP> api_get_request::parse_file_shop(){

    QFile file("data/jsonShop.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QVector<bdd_SHOP> listShop;

    listShop.append(bdd_SHOP(json["city"].toString(), json["idShop"].toString(), json["country"].toString(), json["postalCode"].toInt(), json["street"].toString()));

    return listShop;
}

void api_get_request::get_table_stock(){

    QNetworkAccessManager man;
    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/stock?key=93f85cb0cc2fc22f5c2ad0f067c5e95116"));
    QNetworkReply *reply = man.get(request);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();

    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

    QFile::rename("jsonStock.json","data/jsonStock.json");

    reply->deleteLater();
}

QVector<bdd_STOCK>api_get_request::parse_file_stock(){

    QFile file("data/jsonStock.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QVector<bdd_STOCK> listStock;

    listStock.append(bdd_STOCK(json["amount"].toInt(), json["idStock"].toString(), json["productIdProduct"].toInt(), json["addressIdAddress"].toInt()));

    return listStock;
}

void api_get_request::get_table_supplier(){

    QNetworkAccessManager man;
    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/supplier?key=3ff85cb0c62fc22z5c2adff067c5e83a"));
    QNetworkReply *reply = man.get(request);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();

    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

    QFile::rename("jsonSupplier.json","data/jsonSupplier.json");

    reply->deleteLater();
}

QVector<bdd_SUPPLIER> api_get_request::parse_file_supplier(){

    QFile file("data/jsonSupplier.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QVector<bdd_SUPPLIER> listSupplier;

    listSupplier.append(bdd_SUPPLIER(json["phoneNumber"].toString(), json["mail"].toString(), json["description"].toString(), json["name"].toString(), json["isSupplier"].toString(), json["addressIdAddress"].toInt()));

    return listSupplier;
}

