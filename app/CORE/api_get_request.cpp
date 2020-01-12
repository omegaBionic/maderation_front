#include "api_get_request.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDir>
#include <fstream>
#include <QVector>
#include <QTextStream>
#include <QFile>
#include <QtDebug>


api_get_request::api_get_request(QObject *parent) : QObject(parent)
{
    qDebug() << "[api_get_request] id.get_id(): '" << id.get_id() << "'";
}

//int load, int total
void api_get_request::downloadFinished(QNetworkReply* reply){

//    qDebug() << "loading : " + QString::number(load/total) + "%";
    qDebug() << reply->url().toString();
    qDebug("finished");
    QFile *file;
    QString table = reply->url().toString().split("?")[0].split("/")[5];
    table = table[0].toUpper() + table.right(table.length()-1);
    qDebug() << table;
    QString fichier = "";
    if(table != "Status"){
        fichier = "DATA/json"+table+".json";
    }else{
        qDebug() << "status found in table";
        fichier = "STATUS/json"+table+".json";
    }
    if(QFile::exists(fichier)){
        QFile::remove(fichier);
    }

    file = new QFile(fichier);

    QByteArray response_data = reply->readAll();

    file->open(QIODevice::ReadWrite);
    QTextStream out(file);
    out << response_data;
    file->flush();
    file->close();

    reply->deleteLater();
    emit downloadended(table);

}

void api_get_request::get_table(QUrl url){
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    if(manager->networkAccessible() == QNetworkAccessManager::Accessible){
        connect(manager, &QNetworkAccessManager::finished,
                this, &api_get_request::downloadFinished);
        manager->get(QNetworkRequest(url));

    }else if (manager->networkAccessible() == QNetworkAccessManager::NotAccessible || manager->networkAccessible() == QNetworkAccessManager::UnknownAccessibility){
        qDebug()<<"erreur de connexion à internet";
    }
}


void api_get_request::get_status(){

    qDebug() << "start of getting status";
    this->get_table(QUrl("http://madera-api.maderation.net:8080/api/get/status?key=179616f1a4cecab2a7eab481b84d076c&id=" + id.get_id()));

}

QVector<bdd_STATUS> api_get_request::parse_file_status(){

    QFile file("STATUS/jsonStatus.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QVector<bdd_STATUS> listStatus;

    QString status = json.value("status").toString();

    QString datas = json.value("datas").toString();
    listStatus.append(bdd_STATUS(status,datas));

    return listStatus;
}

void api_get_request::get_table_user(){

        qDebug() << "start of getting user";
        this->get_table(QUrl("http://madera-api.maderation.net:8080/api/get/user?key=83c2c07ea1251a1a39ec46d52cbba19c&id=" + id.get_id()));

}

QVector<bdd_USER> api_get_request::parse_file_user(){

    QFile file("DATA/jsonUser.json");
    file.open(QIODevice::ReadOnly);
    QString rawData = (QString) file.readAll();
    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData.toUtf8()));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties
    QVector<bdd_USER> listUser;

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    foreach (const QJsonValue & v, itemsArray)
    {
        bdd_USER* user = new bdd_USER(v.toObject().value("phoneNumber")["S"].toString(), v.toObject().value("isActive")["BOOL"].toBool(), v.toObject().value("lastname")["S"].toString(), v.toObject().value("password")["S"].toString(), v.toObject().value("firstname")["S"].toString(), v.toObject().value("idShop")["N"].toString().toInt(), v.toObject().value("mail")["S"].toString(), v.toObject().value("username")["S"].toString());
        listUser.append(*user);
    }
    return listUser;
}

void api_get_request::get_table_client(){

    qDebug() << "start of getting client";
    this->get_table(QUrl("http://madera-api.maderation.net:8080/api/get/client?key=9f15cb387f77c3284bd1bdc364a21eb7&id=" + id.get_id()));

}

QVector<bdd_CLIENT> api_get_request::parse_file_client(){

    QFile file("DATA/jsonClient.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QVector<bdd_CLIENT> listClient;

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    foreach (const QJsonValue & v, itemsArray)
    {
        listClient.append(bdd_CLIENT(v.toObject().value("idClient")["S"].toString(), v.toObject().value("phoneNumber")["S"].toString(), v.toObject().value("isActive")["BOOL"].toBool(), v.toObject().value("password")["S"].toString(), v.toObject().value("lastName")["S"].toString(), v.toObject().value("mail")["S"].toString(), v.toObject().value("firstName")["S"].toString(), v.toObject().value("addressId")["N"].toString().toInt()));
    }
    return listClient;
}

void api_get_request::get_table_address_client(){

    qDebug() << "start of getting address client";
    this->get_table(QUrl("http://madera-api.maderation.net:8080/api/get/address_client?key=28e60ed41c0a59a442cade866bff3a97&id=" + id.get_id()));

}


QVector<bdd_ADDRESS_CLIENT> api_get_request::parse_file_address_client(){

    QFile file("data/jsonAddress_client.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QVector<bdd_ADDRESS_CLIENT> listAddressClient;

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    foreach (const QJsonValue & v, itemsArray)
    {
        listAddressClient.append(bdd_ADDRESS_CLIENT(v.toObject().value("city")["S"].toString(), v.toObject().value("idAddressClient")["S"].toString(), v.toObject().value("country")["S"].toString(), v.toObject().value("postalCode")["N"].toString().toInt(), v.toObject().value("street")["S"].toString()));
    }
    return listAddressClient;

}

void api_get_request::get_table_address_supplier(){

      qDebug() << "start of getting address supplier";
    this->get_table(QUrl("http://madera-api.maderation.net:8080/api/get/address_supplier?key=33f85cb0c62fc22f5c2ad0f067c5e83a&id=" + id.get_id()));

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

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    foreach (const QJsonValue & v, itemsArray)
    {
        listAddressSupplier.append(bdd_ADDRESS_SUPPLIER(v.toObject().value("city")["S"].toString(), v.toObject().value("idAddressClient")["S"].toString(), v.toObject().value("country")["S"].toString(), v.toObject().value("postalCode")["N"].toString().toInt(), v.toObject().value("street")["S"].toString()));
    }
    return listAddressSupplier;
}

void api_get_request::get_table_category(){

    qDebug() << "start of getting category";
    this->get_table(QUrl("http://madera-api.maderation.net:8080/api/get/category?key=182ea700442885f568585f374423073d&id=" + id.get_id()));

}

QVector<bdd_CATEGORY> api_get_request::parse_file_category(){

    QFile file("DATA/jsonCategory.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QVector<bdd_CATEGORY> listCategory;

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    foreach (const QJsonValue & v, itemsArray)
    {
        listCategory.append(bdd_CATEGORY(v.toObject().value("idCategory")["S"].toString(), v.toObject().value("label")["S"].toString()));
    }
    return listCategory;

}

void api_get_request::get_table_chat(){

    qDebug() << "start of getting chat";
    this->get_table(QUrl("http://madera-api.maderation.net:8080/api/get/chat?key=80aacfbde81d03d20788f370417651cc&id=" + id.get_id()));

}

QVector<bdd_CHAT> api_get_request::parse_file_chat(){

    QFile file("data/jsonChat.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

//    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

//    // Get JSON object
    QJsonObject json = doc.object();

//    // Access properties
    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    QVector<bdd_CHAT> listChat;


    foreach (const QJsonValue & v, itemsArray)
    {
        listChat.append(bdd_CHAT(v.toObject().value("idChat")["S"].toString(), v.toObject().value("userUsernameAsReceiver")["S"].toString(), v.toObject().value("userUsernameAsAutor")["S"].toString(), v.toObject().value("creationDate")["S"].toString(), v.toObject().value("title")["S"].toString()));
    }
    return listChat;
}

void api_get_request::get_table_component(){

    qDebug() << "start of getting component";
    this->get_table(QUrl("http://madera-api.maderation.net:8080/api/get/component?key=6400edeffb01785cb7426801619d8535&id=" + id.get_id()));

}

QVector<bdd_COMPONENT> api_get_request::parse_file_component(){

    QFile file("data/jsonComponent.json");
    file.open(QIODevice::ReadOnly);
    QTextStream lines(&file);
    lines.setCodec(QTextCodec::codecForName("UTF-8"));
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties


    QVector<bdd_COMPONENT> listComponent;

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    foreach (const QJsonValue & v, itemsArray)
    {
        listComponent.append(bdd_COMPONENT(v.toObject().value("supplierIdSupplier")["N"].toString().toInt(), v.toObject().value("idComponent")["S"].toString(), v.toObject().value("categoryIdCategory")["N"].toString().toInt(), v.toObject().value("label")["S"].toString(), v.toObject().value("amount")["N"].toString().toInt(), v.toObject().value("unitairPrice")["N"].toString().toDouble(), v.toObject().value("productIDProduct")["S"].toString()));
    }
    return listComponent;
}

void api_get_request::get_table_gamme(){

    qDebug() << "start of getting gamme";
    this->get_table(QUrl("http://madera-api.maderation.net:8080/api/get/gamme?key=9af660ef63fbb9e5175d56f064d7a0db&id=" + id.get_id()));

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

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    foreach (const QJsonValue & v, itemsArray)
    {
        listGamme.append(bdd_GAMME(v.toObject().value("idGamme")["S"].toString(), v.toObject().value("productIdProduct")["N"].toString().toInt(), v.toObject().value("label")["S"].toString()));
    }
    return listGamme;
}

void api_get_request::get_table_invoice_quotation(){

    qDebug() << "start of getting invoice quotation";
    this->get_table(QUrl("http://madera-api.maderation.net:8080/api/get/invoice_quotation?key=74cc360b19fc2a94ea620ef5803a381b&id=" + id.get_id()));

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

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    foreach (const QJsonValue & v, itemsArray)
    {
        listInvoiceQuotation.append(bdd_INVOICE_QUOTATION(v.toObject().value("transactionCode")["S"].toString(), v.toObject().value("idInvoiceQuotation")["S"].toString(), v.toObject().value("totalAmount")["N"].toString().toInt(), v.toObject().value("payingMethod")["S"].toString(), v.toObject().value("transactionType")["S"].toString(), v.toObject().value("taxes")["N"].toString().toInt()));
    }
    return listInvoiceQuotation;
}

void api_get_request::get_table_message(){

    qDebug() << "start of getting message";
    this->get_table(QUrl("http://madera-api.maderation.net:8080/api/get/message?key=a853ca2949386f7d527bf06117bda9e3&id=" + id.get_id()));

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

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    QVector<bdd_MESSAGE> listMessage;

    foreach (const QJsonValue & v, itemsArray)
    {
        listMessage.append(bdd_MESSAGE(v.toObject().value("creationDate")["S"].toString(), v.toObject().value("message")["S"].toString(), v.toObject().value("chatIoChat")["S"].toString(), v.toObject().value("userUsername")["S"].toString(), v.toObject().value("idMessage")["S"].toString()));
    }
    return listMessage;
}

void api_get_request::get_table_product(){

    qDebug() << "start of getting product";
    this->get_table(QUrl("http://madera-api.maderation.net:8080/api/get/product?key=4789725dd2d8061e7faf00fce9af48e1&id=" + id.get_id()));

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

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    foreach (const QJsonValue & v, itemsArray)
    {
        listProduct.append(bdd_PRODUCT(v.toObject().value("supplierIdSupplier")["N"].toString().toInt(), v.toObject().value("idProduct")["S"].toString(), v.toObject().value("minWidth").toString().toInt(), v.toObject().value("defaultLength")["N"].toString().toInt(), v.toObject().value("label")["S"].toString(), v.toObject().value("productCode")["S"].toString(), v.toObject().value("defaultHeight")["N"].toString().toInt(), v.toObject().value("defaultWidth")["N"].toString().toInt(), v.toObject().value("material")["S"].toString(), v.toObject().value("minLength")["N"].toString().toInt(), v.toObject().value("type")["S"].toString(), v.toObject().value("R")["N"].toString().toInt(), v.toObject().value("G")["N"].toString().toInt(), v.toObject().value("B")["N"].toString().toInt()));
    }
    return listProduct;
}

void api_get_request::get_table_project(){

    qDebug() << "start of getting project";
    this->get_table(QUrl("http://madera-api.maderation.net:8080/api/get/project?key=3f61093fa59c13f81fc8648a3d644e0b&id=" + id.get_id()));

}

QVector<bdd_PROJECT> api_get_request::parse_file_project(){

    QFile file("data/jsonProject.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();
    // Access properties

    QVector<bdd_PROJECT> listProject;

    foreach (const QJsonValue & v, itemsArray)
    {
        listProject.append(bdd_PROJECT(v.toObject().value("supplierIdSupplier")["S"].toString(), v.toObject().value("validation")["BOOL"].toBool(), v.toObject().value("creationDate")["S"].toString(), v.toObject().value("isTemplate")["BOOL"].toBool(), v.toObject().value("idProject")["S"].toString(), v.toObject().value("userUsername")["S"].toString(), v.toObject().value("Title")["S"].toString(), v.toObject().value("IDClient")["S"].toString()));
    }
    return listProject;

}

void api_get_request::get_table_promotion_cat(){

    qDebug() << "start of getting promotion category";
    this->get_table(QUrl("http://madera-api.maderation.net:8080/api/get/promotion_cat?key=557c0271e30cf474e0f46f93721fd1ba&id=" + id.get_id()));

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

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    foreach (const QJsonValue & v, itemsArray)
    {
        listPromotionCat.append(bdd_PROMOTION_CAT(v.toObject().value("amount")["N"].toString().toInt(), v.toObject().value("addToExistingProm")["BOOL"].toBool(), v.toObject().value("fromDate")["S"].toString(), v.toObject().value("idPromotionCat")["S"].toString(), v.toObject().value("toDate")["S"].toString()));
    }
    return listPromotionCat;

}

void api_get_request::get_table_promotion_comp(){

    qDebug() << "start of getting promotion component";
    this->get_table(QUrl("http://madera-api.maderation.net:8080/api/get/promotion_comp?key=2b11565d85da178b3a1942a22d20c624&id=" + id.get_id()));

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

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    foreach (const QJsonValue & v, itemsArray)
    {
        listPromotionComp.append(bdd_PROMOTION_COMP(v.toObject().value("amount")["N"].toString().toInt(), v.toObject().value("addToExistingProm")["BOOL"].toBool(), v.toObject().value("fromDate")["S"].toString(), v.toObject().value("idPromotionComp")["S"].toString(), v.toObject().value("toDate")["S"].toString()));
    }
    return listPromotionComp;
}

void api_get_request::get_table_quotation(){

    qDebug() << "start of getting quotation";
    this->get_table(QUrl("http://madera-api.maderation.net:8080/api/get/quotation?key=eb307516cffbc5e529cf9c7350ffc299&id=" + id.get_id()));

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

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    foreach (const QJsonValue & v, itemsArray)
    {
        listQuotation.append(bdd_QUOTATION(v.toObject().value("validation")["BOOL"].toBool(), v.toObject().value("idQuotation")["S"].toString(), v.toObject().value("creationDate")["S"].toString(), v.toObject().value("isTemplate")["BOOL"].toBool(), v.toObject().value("userUsername")["S"].toString(), v.toObject().value("valicationDate")["S"].toString()));
    }
    return listQuotation;

}

void api_get_request::get_table_role(){

    qDebug() << "start of getting role";
    this->get_table(QUrl("http://madera-api.maderation.net:8080/api/get/role?key=33f85cb0c62f522f5c2ad09067c5e83a&id=" + id.get_id()));

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

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    foreach (const QJsonValue & v, itemsArray)
    {
        listRole.append(bdd_ROLE(v.toObject().value("userUsername")["S"].toString(), v.toObject().value("idRole")["S"].toString(), v.toObject().value("label")["S"].toString()));
    }
    return listRole;

}

void api_get_request::get_table_shop(){

    qDebug() << "start of getting shop";
    this->get_table(QUrl("http://madera-api.maderation.net:8080/api/get/shop?key=p3f85cbdc62fc22f5c2ad0f067m5eldlda&id=" + id.get_id()));

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

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    foreach (const QJsonValue & v, itemsArray)
    {
        qDebug() << v.toObject().value("postalCode")["N"].toString().toInt();
        listShop.append(bdd_SHOP(v.toObject().value("city")["S"].toString(), v.toObject().value("idShop")["S"].toString(), v.toObject().value("country")["S"].toString(), v.toObject().value("postalCode")["N"].toString().toInt(), v.toObject().value("street")["S"].toString()));
    }
    return listShop;
}

void api_get_request::get_table_stock(){

    qDebug() << "start of getting stock";
    this->get_table(QUrl("http://madera-api.maderation.net:8080/api/get/stock?key=93f85cb0cc2fc22f5c2ad0f067c5e95116&id=" + id.get_id()));

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

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    foreach (const QJsonValue & v, itemsArray)
    {
        listStock.append(bdd_STOCK(v.toObject().value("amount")["N"].toInt(), v.toObject().value("idStock")["S"].toString(), v.toObject().value("productIdProduct")["N"].toInt(), v.toObject().value("addressIdAddress")["N"].toInt()));
    }
    return listStock;
}

void api_get_request::get_table_supplier(){

    qDebug() << "start of getting supplier";
    this->get_table(QUrl("http://madera-api.maderation.net:8080/api/get/supplier?key=3ff85cb0c62fc22z5c2adff067c5e83a&id=" + id.get_id()));

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

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    foreach (const QJsonValue & v, itemsArray)
    {
        listSupplier.append(bdd_SUPPLIER(v.toObject().value("phoneNumber")["S"].toString(), v.toObject().value("mail")["N"].toString(), v.toObject().value("description")["S"].toString(), v.toObject().value("name")["S"].toString(), v.toObject().value("isSupplier")["S"].toString(), v.toObject().value("addressIdAddress")["N"].toInt()));
    }
    return listSupplier;
}

void api_get_request::get_table_attribut(){

        qDebug() << "start of getting attribut";
        this->get_table(QUrl("http://madera-api.maderation.net:8080/api/get/attribut?key=86ad7be9d92e838132c9c182554531e9&id=" + id.get_id()));

}

QVector<bdd_ATTRIBUT> api_get_request::parse_file_attribut(){

    QFile file("DATA/jsonAttribut.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QVector<bdd_ATTRIBUT> listAttribut;

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    foreach (const QJsonValue & v, itemsArray)
    {
        listAttribut.append(bdd_ATTRIBUT(v.toObject().value("length")["N"].toString().toInt(),v.toObject().value("positionY")["N"].toString().toInt(),v.toObject().value("width")["N"].toString().toInt(),v.toObject().value("height")["N"].toString().toInt(),v.toObject().value("productIdProduct")["N"].toString().toInt(),v.toObject().value("orderIdOrder")["N"].toString().toInt(),v.toObject().value("positionX")["N"].toString().toInt(),v.toObject().value("rotationY")["N"].toString().toInt(),v.toObject().value("positionZ")["N"].toString().toInt(),v.toObject().value("rotationX")["N"].toString().toInt(),v.toObject().value("idAttribut")["S"].toString()));
    }
    return listAttribut;
}

void api_get_request::get_all_table(){
    qDebug() << "------------------get all !!";
    this->get_table_chat();
    this->get_table_role();
    this->get_table_shop();
    this->get_table_user();
    this->get_table_gamme();
    this->get_table_stock();
    this->get_table_client();
    this->get_table_message();
    this->get_table_product();
    this->get_table_project();
    this->get_table_attribut();
    this->get_table_category();
    this->get_table_supplier();
    this->get_table_component();
    this->get_table_quotation();
    this->get_table_promotion_cat();
    this->get_table_address_client();
    this->get_table_promotion_comp();
    this->get_table_address_supplier();
    this->get_table_invoice_quotation();
}

