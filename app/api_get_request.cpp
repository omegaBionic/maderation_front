//#include "api_get_request.h"
//#include <QNetworkAccessManager>
//#include <QNetworkReply>
//#include <QDir>
//#include <fstream>
//#include <user>
//#include <client>
//#include <addressClient>
//#include <addressSupplier>
//#include <category>
//#include <chat>
//#include <component>
//#include <gamme>
//#include <invoiceQuotation>
//#include <message>
//#include <product>
//#include <project>
//#include <promotionCat>
//#include <promotionComp>
//#include <quotation>
//#include <role>
//#include <shop>
//#include <stock>
//#include <supplier>

//api_get_request::api_get_request(QObject *parent) : QObject(parent)
//{

//}

//void api_get_request::get_status(){

//    QNetworkAccessManager man;
//    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/status?key=179616f1a4cecab2a7eab481b84d076c"));
//    QNetworkReply *reply = man.get(request);

//    while (!reply->isFinished())
//    {
//        qApp->processEvents();
//    }

//    QByteArray response_data = reply->readAll();

//    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

//    QFile::rename("jsonAll.json","data/jsonStatus.json");

//    reply->deleteLater();
//}

//void api_get_request::parse_file_status(){

//    QFile file("data/jsonStatus.json");
//    file.open(QIODevice::ReadOnly);
//    QByteArray rawData = file.readAll();

//    // Parse document
//    QJsonDocument doc(QJsonDocument::fromJson(rawData));

//    // Get JSON object
//    QJsonObject json = doc.object();

//    // Access properties

//    Status::status = json["status"].toInt();

//    Status::datas = json["datas"].toString();

//}

//void api_get_request::get_table_user(){

//    QNetworkAccessManager man;
//    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/user?key=83c2c07ea1251a1a39ec46d52cbba19c"));
//    QNetworkReply *reply = man.get(request);

//    while (!reply->isFinished())
//    {
//        qApp->processEvents();
//    }

//    QByteArray response_data = reply->readAll();

//    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

//    QFile::rename("jsonAll.json","data/jsonUser.json");

//    reply->deleteLater();
//}

//void api_get_request::parse_file_user(){

//    QFile file("data/jsonUser.json");
//    file.open(QIODevice::ReadOnly);
//    QByteArray rawData = file.readAll();

//    // Parse document
//    QJsonDocument doc(QJsonDocument::fromJson(rawData));

//    // Get JSON object
//    QJsonObject json = doc.object();

//    // Access properties

//    User::phoneNumber = json["phoneNumber"].toString();

//    User::mail = json["mail"].toBool();

//    User::password = json["password"].toString();

//    User::lastName = json["lastName"].toString();

//    User::mail = json["mail"].toString();

//    User::username = json["username"].toString();

//    User::firstName = json["firstName"].toString();

//    User::addressId = json["addressId"].toInt();

//}

//void api_get_request::get_table_client(){

//    QNetworkAccessManager man;
//    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/client?key=9f15cb387f77c3284bd1bdc364a21eb7"));
//    QNetworkReply *reply = man.get(request);

//    while (!reply->isFinished())
//    {
//        qApp->processEvents();
//    }

//    QByteArray response_data = reply->readAll();

//    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

//    QFile::rename("jsonClient.json","data/jsonClient.json");

//    reply->deleteLater();
//}

//void api_get_request::parse_file_client(){

//    QFile file("data/jsonClient.json");
//    file.open(QIODevice::ReadOnly);
//    QByteArray rawData = file.readAll();

//    // Parse document
//    QJsonDocument doc(QJsonDocument::fromJson(rawData));

//    // Get JSON object
//    QJsonObject json = doc.object();

//    // Access properties

//    Client::phoneNumber = json["phoneNumber"].toString();

//    Client::mail = json["mail"].toBool();

//    Client::password = json["password"].toString();

//    Client::lastName = json["lastName"].toString();

//    Client::mail = json["mail"].toString();

//    Client::username = json["username"].toString();

//    Client::firstName = json["firstName"].toString();

//    Client::addressIdAddress = json["addressIdAddress"].toInt();

//}

//void api_get_request::get_table_address_client(){

//    QNetworkAccessManager man;
//    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/address_client?key=28e60ed41c0a59a442cade866bff3a97"));
//    QNetworkReply *reply = man.get(request);

//    while (!reply->isFinished())
//    {
//        qApp->processEvents();
//    }

//    QByteArray response_data = reply->readAll();

//    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

//    QFile::rename("jsonClient.json","data/jsonAddressClient.json");

//    reply->deleteLater();
//}

//void api_get_request::parse_file_address_client(){

//    QFile file("data/jsonAddressClient.json");
//    file.open(QIODevice::ReadOnly);
//    QByteArray rawData = file.readAll();

//    // Parse document
//    QJsonDocument doc(QJsonDocument::fromJson(rawData));

//    // Get JSON object
//    QJsonObject json = doc.object();

//    // Access properties

//    addressClient::city = json["city"].toString();

//    addressClient::idAddressClient = json["idAddressClient"].toString();

//    addressClient::country = json["country"].toString();

//    addressClient::postalCode = json["postalCode"].toInt();

//    addressClient::street = json["street"].toString();

//}

//void api_get_request::get_table_address_supplier(){

//    QNetworkAccessManager man;
//    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/address_supplier?key=33f85cb0c62fc22f5c2ad0f067c5e83a"));
//    QNetworkReply *reply = man.get(request);

//    while (!reply->isFinished())
//    {
//        qApp->processEvents();
//    }

//    QByteArray response_data = reply->readAll();

//    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

//    QFile::rename("jsonAddressSupplier.json","data/jsonAddressSupplier.json");

//    reply->deleteLater();
//}

//void api_get_request::parse_file_address_supplier(){

//    QFile file("data/jsonAddressSupplier.json");
//    file.open(QIODevice::ReadOnly);
//    QByteArray rawData = file.readAll();

//    // Parse document
//    QJsonDocument doc(QJsonDocument::fromJson(rawData));

//    // Get JSON object
//    QJsonObject json = doc.object();

//    // Access properties

//    addressSupplier::city = json["city"].toString();

//    addressSupplier::idAddressClient = json["idAddressClient"].toString();

//    addressSupplier::country = json["country"].toString();

//    addressSupplier::postalCode = json["postalCode"].toInt();

//    addressSupplier::street = json["street"].toString();

//}

//void api_get_request::get_table_category(){

//    QNetworkAccessManager man;
//    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/category?key=182ea700442885f568585f374423073d"));
//    QNetworkReply *reply = man.get(request);

//    while (!reply->isFinished())
//    {
//        qApp->processEvents();
//    }

//    QByteArray response_data = reply->readAll();

//    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

//    QFile::rename("jsonCategory.json","data/jsonCategory.json");

//    reply->deleteLater();
//}

//void api_get_request::parse_file_category(){

//    QFile file("data/jsonCategory.json");
//    file.open(QIODevice::ReadOnly);
//    QByteArray rawData = file.readAll();

//    // Parse document
//    QJsonDocument doc(QJsonDocument::fromJson(rawData));

//    // Get JSON object
//    QJsonObject json = doc.object();

//    // Access properties

//    category::idCategory = json["idCategory"].toString();

//    category::label = json["label"].toString();

//}

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

//void api_get_request::parse_file_chat(){

//    QFile file("data/jsonChat.json");
//    file.open(QIODevice::ReadOnly);
//    QByteArray rawData = file.readAll();

//    // Parse document
//    QJsonDocument doc(QJsonDocument::fromJson(rawData));

//    // Get JSON object
//    QJsonObject json = doc.object();

//    // Access properties

//    chat::idChat = json["idChat"].toString();

//    chat::userUsernameAsReceiver = json["userUsernameAsReceiver"].toString();

//    chat::creationDate = json["creationDate"].toString();

//    chat::userUsernameAsAutor = json["userUsernameAsAutor"].toString();

//    chat::title = json["title"].toString();
//}

//void api_get_request::get_table_component(){

//    QNetworkAccessManager man;
//    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/component?key=6400edeffb01785cb7426801619d8535"));
//    QNetworkReply *reply = man.get(request);

//    while (!reply->isFinished())
//    {
//        qApp->processEvents();
//    }

//    QByteArray response_data = reply->readAll();

//    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

//    QFile::rename("jsonComponent.json","data/jsonComponent.json");

//    reply->deleteLater();
//}

//void api_get_request::parse_file_component(){

//    QFile file("data/jsonComponent.json");
//    file.open(QIODevice::ReadOnly);
//    QByteArray rawData = file.readAll();

//    // Parse document
//    QJsonDocument doc(QJsonDocument::fromJson(rawData));

//    // Get JSON object
//    QJsonObject json = doc.object();

//    // Access properties

//    component::supplierIdSupplier = json["supplierIdSupplier"].toInt();

//    component::idComponent = json["idComponent"].toInt();

//    component::categoryIdCategory = json["categoryIdCategory"].toString();

//    component::label = json["label"].toString();
//}

//void api_get_request::get_table_gamme(){

//    QNetworkAccessManager man;
//    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/gamme?key=9af660ef63fbb9e5175d56f064d7a0db"));
//    QNetworkReply *reply = man.get(request);

//    while (!reply->isFinished())
//    {
//        qApp->processEvents();
//    }

//    QByteArray response_data = reply->readAll();

//    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

//    QFile::rename("jsonGamme.json","data/jsonGamme.json");

//    reply->deleteLater();
//}

//void api_get_request::parse_file_gamme(){

//    QFile file("data/jsonGamme.json");
//    file.open(QIODevice::ReadOnly);
//    QByteArray rawData = file.readAll();

//    // Parse document
//    QJsonDocument doc(QJsonDocument::fromJson(rawData));

//    // Get JSON object
//    QJsonObject json = doc.object();

//    // Access properties

//    gamme::idGamme = json["idGamme"].toInt();

//    gamme::productIdProduct = json["productIdProduct"].toInt();

//    gamme::categoryIdCategory = json["categoryIdCategory"].toString();

//    gamme::label = json["label"].toString();
//}

//void api_get_request::get_table_invoice_quotation(){

//    QNetworkAccessManager man;
//    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/invoice_quotation?key=74cc360b19fc2a94ea620ef5803a381b"));
//    QNetworkReply *reply = man.get(request);

//    while (!reply->isFinished())
//    {
//        qApp->processEvents();
//    }

//    QByteArray response_data = reply->readAll();

//    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

//    QFile::rename("jsonInvoiceQuotation.json","data/jsonInvoiceQuotation.json");

//    reply->deleteLater();
//}

//void api_get_request::parse_file_invoice_quotation(){

//    QFile file("data/jsonInvoiceQuotation.json");
//    file.open(QIODevice::ReadOnly);
//    QByteArray rawData = file.readAll();

//    // Parse document
//    QJsonDocument doc(QJsonDocument::fromJson(rawData));

//    // Get JSON object
//    QJsonObject json = doc.object();

//    // Access properties

//    invoiceQuotation::transactionCode = json["transactionCode"].toString();

//    invoiceQuotation::totalAmount = json["totalAmount"].toInt();

//    invoiceQuotation::categoryIdCategory = json["categoryIdCategory"].toString();

//    invoiceQuotation::payingMethod = json["payingMethod"].toString();

//    invoiceQuotation::transactionType = json["transactionType"].toString();

//    invoiceQuotation::taxes = json["taxes"].toInt();
//}

//void api_get_request::get_table_message(){

//    QNetworkAccessManager man;
//    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/message?key=a853ca2949386f7d527bf06117bda9e3"));
//    QNetworkReply *reply = man.get(request);

//    while (!reply->isFinished())
//    {
//        qApp->processEvents();
//    }

//    QByteArray response_data = reply->readAll();

//    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

//    QFile::rename("jsonMessage.json","data/jsonMessage.json");

//    reply->deleteLater();
//}

//void api_get_request::parse_file_message(){

//    QFile file("data/jsonMessage.json");
//    file.open(QIODevice::ReadOnly);
//    QByteArray rawData = file.readAll();

//    // Parse document
//    QJsonDocument doc(QJsonDocument::fromJson(rawData));

//    // Get JSON object
//    QJsonObject json = doc.object();

//    // Access properties

//    message::creationDate = json["creationDate"].toString();

//    message::message = json["message"].toString();

//    message::chatIoChat = json["chatIoChat"].toString();

//    message::userUsername = json["userUsername"].toString();

//    message::idMessage = json["idMessage"].toString();
//}

//void api_get_request::get_table_product(){

//    QNetworkAccessManager man;
//    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/product?key=4789725dd2d8061e7faf00fce9af48e1"));
//    QNetworkReply *reply = man.get(request);

//    while (!reply->isFinished())
//    {
//        qApp->processEvents();
//    }

//    QByteArray response_data = reply->readAll();

//    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

//    QFile::rename("jsonProduct.json","data/jsonProduct.json");

//    reply->deleteLater();
//}

//void api_get_request::parse_file_product(){

//    QFile file("data/jsonProduct.json");
//    file.open(QIODevice::ReadOnly);
//    QByteArray rawData = file.readAll();

//    // Parse document
//    QJsonDocument doc(QJsonDocument::fromJson(rawData));

//    // Get JSON object
//    QJsonObject json = doc.object();

//    // Access properties

//    product::supplierIdSupplier = json["supplierIdSupplier"].toInt();

//    product::idProduct = json["idProduct"].toString();

//    product::minWidth = json["minWidth"].toInt();

//    product::defaultLength = json["defaultLength"].toInt();

//    product::label = json["label"].toString();

//    product::productCode = json["productCode"].toString();

//    product::defaultHeight = json["defaultHeight"].toInt();

//    product::defaultWidth = json["defaultWidth"].toInt();

//    product::material = json["material"].toString();

//    product::minLength = json["minLength"].toInt();

//    product::type = json["type"].toString();
//}

//void api_get_request::get_table_project(){

//    QNetworkAccessManager man;
//    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/project?key=3f61093fa59c13f81fc8648a3d644e0b"));
//    QNetworkReply *reply = man.get(request);

//    while (!reply->isFinished())
//    {
//        qApp->processEvents();
//    }

//    QByteArray response_data = reply->readAll();

//    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

//    QFile::rename("jsonProject.json","data/jsonProject.json");

//    reply->deleteLater();
//}

//void api_get_request::parse_file_project(){

//    QFile file("data/jsonProject.json");
//    file.open(QIODevice::ReadOnly);
//    QByteArray rawData = file.readAll();

//    // Parse document
//    QJsonDocument doc(QJsonDocument::fromJson(rawData));

//    // Get JSON object
//    QJsonObject json = doc.object();

//    // Access properties

//    project::validationDate = json["supplierIdSupplier"].toString();

//    project::validation = json["validation"].toBool();

//    project::creationDate = json["creationDate"].toString();

//    project::isTemplate = json["isTemplate"].toBool();

//    project::idProject = json["idProject"].toString();

//    project::userUsername = json["userUsername"].toString();

//}

//void api_get_request::get_table_promotion_cat(){

//    QNetworkAccessManager man;
//    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/promotion_cat?key=557c0271e30cf474e0f46f93721fd1ba"));
//    QNetworkReply *reply = man.get(request);

//    while (!reply->isFinished())
//    {
//        qApp->processEvents();
//    }

//    QByteArray response_data = reply->readAll();

//    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

//    QFile::rename("jsonPromotionCat.json","data/jsonPromotionCat.json");

//    reply->deleteLater();
//}

//void api_get_request::parse_file_promotion_cat(){

//    QFile file("data/jsonPromotionCat.json");
//    file.open(QIODevice::ReadOnly);
//    QByteArray rawData = file.readAll();

//    // Parse document
//    QJsonDocument doc(QJsonDocument::fromJson(rawData));

//    // Get JSON object
//    QJsonObject json = doc.object();

//    // Access properties

//    promotionCat::amount = json["amount"].toInt();

//    promotionCat::addToExistingProm = json["addToExistingProm"].toBool();

//    promotionCat::fromDate = json["fromDate"].toString();

//    promotionCat::idPromotionCat = json["idPromotionCat"].toString();

//    promotionCat::toDate = json["toDate"].toString();

//}

//void api_get_request::get_table_promotion_comp(){

//    QNetworkAccessManager man;
//    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/promotion_comp?key=2b11565d85da178b3a1942a22d20c624"));
//    QNetworkReply *reply = man.get(request);

//    while (!reply->isFinished())
//    {
//        qApp->processEvents();
//    }

//    QByteArray response_data = reply->readAll();

//    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

//    QFile::rename("jsonPromotionComp.json","data/jsonPromotionComp.json");

//    reply->deleteLater();
//}

//void api_get_request::parse_file_promotion_comp(){

//    QFile file("data/jsonPromotionComp.json");
//    file.open(QIODevice::ReadOnly);
//    QByteArray rawData = file.readAll();

//    // Parse document
//    QJsonDocument doc(QJsonDocument::fromJson(rawData));

//    // Get JSON object
//    QJsonObject json = doc.object();

//    // Access properties

//    promotionComp::amount = json["amount"].toInt();

//    promotionComp::fromDate = json["fromDate"].toString();

//    promotionComp::idPromotionComp = json["idPromotionCat"].toString();

//    promotionComp::toDate = json["toDate"].toString();

//}

//void api_get_request::get_table_quotation(){

//    QNetworkAccessManager man;
//    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/quotation?key=eb307516cffbc5e529cf9c7350ffc299"));
//    QNetworkReply *reply = man.get(request);

//    while (!reply->isFinished())
//    {
//        qApp->processEvents();
//    }

//    QByteArray response_data = reply->readAll();

//    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

//    QFile::rename("jsonQuotation.json","data/jsonQuotation.json");

//    reply->deleteLater();
//}

//void api_get_request::parse_file_quotation(){

//    QFile file("data/jsonQuotation.json");
//    file.open(QIODevice::ReadOnly);
//    QByteArray rawData = file.readAll();

//    // Parse document
//    QJsonDocument doc(QJsonDocument::fromJson(rawData));

//    // Get JSON object
//    QJsonObject json = doc.object();

//    // Access properties

//    quotation::validation = json["validation"].toBool();

//    quotation::idQuotation = json["idQuotation"].toString();

//    quotation::creationDate = json["creationDate"].toString();

//    quotation::isTemplate = json["isTemplate"].toBool();

//    quotation::userUsername = json["userUsername"].toString();

//    quotation::valicationDate = json["valicationDate"].toString();

//}

//void api_get_request::get_table_role(){

//    QNetworkAccessManager man;
//    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/quotation?key=eb307516cffbc5e529cf9c7350ffc299"));
//    QNetworkReply *reply = man.get(request);

//    while (!reply->isFinished())
//    {
//        qApp->processEvents();
//    }

//    QByteArray response_data = reply->readAll();

//    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

//    QFile::rename("jsonRole.json","data/jsonRole.json");

//    reply->deleteLater();
//}

//void api_get_request::parse_file_role(){

//    QFile file("data/jsonRole.json");
//    file.open(QIODevice::ReadOnly);
//    QByteArray rawData = file.readAll();

//    // Parse document
//    QJsonDocument doc(QJsonDocument::fromJson(rawData));

//    // Get JSON object
//    QJsonObject json = doc.object();

//    // Access properties

//    role::userUsername = json["userUsername"].toString();

//    role::idRole = json["idRole"].toString();

//    role::label = json["label"].toString();

//}

//void api_get_request::get_table_shop(){

//    QNetworkAccessManager man;
//    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/shop?key=p3f85cbdc62fc22f5c2ad0f067m5eldlda"));
//    QNetworkReply *reply = man.get(request);

//    while (!reply->isFinished())
//    {
//        qApp->processEvents();
//    }

//    QByteArray response_data = reply->readAll();

//    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

//    QFile::rename("jsonShop.json","data/jsonShop.json");

//    reply->deleteLater();
//}

//void api_get_request::parse_file_shop(){

//    QFile file("data/jsonShop.json");
//    file.open(QIODevice::ReadOnly);
//    QByteArray rawData = file.readAll();

//    // Parse document
//    QJsonDocument doc(QJsonDocument::fromJson(rawData));

//    // Get JSON object
//    QJsonObject json = doc.object();

//    // Access properties

//    shop::city = json["city"].toString();

//    shop::idShop = json["idShop"].toString();

//    shop::country = json["country"].toString();

//    shop::postalCode = json["postalCode"].toInt();

//    shop::street = json["street"].toString();

//}

//void api_get_request::get_table_stock(){

//    QNetworkAccessManager man;
//    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/stock?key=93f85cb0cc2fc22f5c2ad0f067c5e95116"));
//    QNetworkReply *reply = man.get(request);

//    while (!reply->isFinished())
//    {
//        qApp->processEvents();
//    }

//    QByteArray response_data = reply->readAll();

//    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

//    QFile::rename("jsonStock.json","data/jsonStock.json");

//    reply->deleteLater();
//}

//void api_get_request::parse_file_stock(){

//    QFile file("data/jsonStock.json");
//    file.open(QIODevice::ReadOnly);
//    QByteArray rawData = file.readAll();

//    // Parse document
//    QJsonDocument doc(QJsonDocument::fromJson(rawData));

//    // Get JSON object
//    QJsonObject json = doc.object();

//    // Access properties

//    stock::amount = json["amount"].toInt();

//    stock::idStock = json["idStock"].toString();

//    stock::productIdProduct = json["productIdProduct"].toInt();

//    stock::addressIdAddress = json["addressIdAddress"].toInt();

//}

//void api_get_request::get_table_supplier(){

//    QNetworkAccessManager man;
//    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/api/get/supplier?key=3ff85cb0c62fc22z5c2adff067c5e83a"));
//    QNetworkReply *reply = man.get(request);

//    while (!reply->isFinished())
//    {
//        qApp->processEvents();
//    }

//    QByteArray response_data = reply->readAll();

//    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

//    QFile::rename("jsonSupplier.json","data/jsonSupplier.json");

//    reply->deleteLater();
//}

//void api_get_request::parse_file_supplier(){

//    QFile file("data/jsonSupplier.json");
//    file.open(QIODevice::ReadOnly);
//    QByteArray rawData = file.readAll();

//    // Parse document
//    QJsonDocument doc(QJsonDocument::fromJson(rawData));

//    // Get JSON object
//    QJsonObject json = doc.object();

//    // Access properties

//    supplier::phoneNumber = json["phoneNumber"].toString();

//    supplier::mail = json["mail"].toString();

//    supplier::description = json["description"].toString();

//    supplier::name = json["name"].toString();

//    supplier::isSupplier = json["isSupplier"].toString();

//    supplier::addressIdAddress = json["addressIdAddress"].toInt();

//}
