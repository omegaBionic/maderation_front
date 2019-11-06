#include <QtTest>
#include <QCoreApplication>
#include <../app/api_get_request.h>

//pour quentin -----------------------------------------
#include <QDesktopServices>
#include <QUrl>
#include <QProcess>
#include <QFile>
#include <QtNetwork>
#include <QJsonObject>
#include <QJsonDocument>
#include <QUrlQuery>
#include <QJsonValue>
#include <QDebug>
#include <sys/stat.h>
#include <QDir>
#include <QMainWindow>
//------------------------------------------------------
#include "../app/main_login.h"



// add necessary includes here



class test_app : public QObject
{
    Q_OBJECT

public:
    test_app();
    ~test_app();
    Main_Login *main;

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();
    void main_login_check_connexion();

//    void api_get_request_test_get_status();
//    void api_get_request_test_get_table_user();
//    void api_get_request_test_get_table_client();
//    void api_get_request_test_get_table_address_client();
//    void api_get_request_test_get_table_address_supplier();
//    void api_get_request_test_get_table_category();
//    void api_get_request_test_get_table_chat();
//    void api_get_request_test_get_table_component();
//    void api_get_request_test_get_table_gamme();
//    void api_get_request_test_get_table_invoice_quotation();
//    void api_get_request_test_get_table_message();
//    void api_get_request_test_get_table_product();
//    void api_get_request_test_get_table_project();
//    void api_get_request_test_get_table_promotion_cat();
//    void api_get_request_test_get_table_promotion_comp();
//    void api_get_request_test_get_table_quotation();
//    void api_get_request_test_get_table_role();
//    void api_get_request_test_get_table_shop();
//    void api_get_request_test_get_table_stock();
//    void api_get_request_test_get_table_supplier();

//    void api_get_request_test_parse_file_status();
//    void api_get_request_test_parse_file_user();
//    void api_get_request_test_parse_file_client();
//    void api_get_request_test_parse_file_address_client();
//    void api_get_request_test_parse_file_address_supplier();
//    void api_get_request_test_parse_file_category();
//    void api_get_request_test_parse_file_chat();
//    void api_get_request_test_parse_file_component();
//    void api_get_request_test_parse_file_gamme();
//    void api_get_request_test_parse_file_invoice_quotation();
//    void api_get_request_test_parse_file_message();
//    void api_get_request_test_parse_file_product();
//    void api_get_request_test_parse_file_project();
//    void api_get_request_test_parse_file_promotion_cat();
//    void api_get_request_test_parse_file_promotion_comp();
//    void api_get_request_test_parse_file_quotation();
//    void api_get_request_test_parse_file_role();
//    void api_get_request_test_parse_file_shop();
//    void api_get_request_test_parse_file_stock();
//    void api_get_request_test_parse_file_supplier();

};

test_app::test_app()
{

}

test_app::~test_app()
{

}

void test_app::initTestCase()
{
    // se lance au tout début
    main = new Main_Login(0);


}


void test_app::cleanupTestCase()
{
    // se lance à la fin
    main = NULL;
}

void test_app::init()
{
    // se lance avant chaque test
    main = new Main_Login(0);
}

void test_app::cleanup()
{
    // se lance après chaque test
    main = NULL;
}

//un exemple de test fonctionnel
void test_app::main_login_check_connexion()
{
    QVERIFY(main->CheckConnexion());
}


//void test_app::api_get_request_test_get_status(){
//    try {
//        api_get_request::get_status();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_get_table_user(){
//    try {
//        api_get_request::get_table_user();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_get_table_client(){
//    try {
//        api_get_request::get_table_client();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_get_table_address_client(){
//    try {
//        api_get_request::get_table_address_client();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_get_table_address_supplier(){
//    try {
//        api_get_request::get_table_address_supplier();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_get_table_category(){
//    try {
//        api_get_request::get_table_category();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_get_table_chat(){
//    try {
//        api_get_request::get_table_chat();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_get_table_component(){
//    try {
//        api_get_request::get_table_component();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_get_table_gamme(){
//    try {
//        api_get_request::get_table_gamme();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_get_table_invoice_quotation(){
//    try {
//        api_get_request::get_table_invoice_quotation();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_get_table_message(){
//    try {
//        api_get_request::get_table_message();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_get_table_product(){
//    try {
//        api_get_request::get_table_product();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_get_table_project(){
//    try {
//        api_get_request::get_table_project();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_get_table_promotion_cat(){
//    try {
//        api_get_request::get_table_promotion_cat();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_get_table_promotion_comp(){
//    try {
//        api_get_request::get_table_promotion_comp();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_get_table_quotation(){
//    try {
//        api_get_request::get_table_quotation();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}
//void test_app::api_get_request_test_get_table_role(){
//    try {
//        api_get_request::get_table_role();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}
//void test_app::api_get_request_test_get_table_shop(){
//    try {
//        api_get_request::get_table_shop();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}
//void test_app::api_get_request_test_get_table_stock(){
//    try {
//        api_get_request::get_table_stock();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}
//void test_app::api_get_request_test_get_table_supplier(){
//    try {
//        api_get_request::get_table_supplier();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_parse_file_status(){
//    try {
//        api_get_request::parse_file_status();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_parse_file_user(){
//    try {
//        api_get_request::parse_file_user();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_parse_file_client(){
//    try {
//        api_get_request::parse_file_client();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_parse_file_address_client(){
//    try {
//        api_get_request::parse_file_address_client();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_parse_file_address_supplier(){
//    try {
//        api_get_request::parse_file_address_supplier();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_parse_file_category(){
//    try {
//        api_get_request::parse_file_category();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_parse_file_chat(){
//    try {
//        api_get_request::parse_file_chat();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_parse_file_component(){
//    try {
//        api_get_request::parse_file_component();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_parse_file_gamme(){
//    try {
//        api_get_request::parse_file_gamme();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_parse_file_invoice_quotation(){
//    try {
//        api_get_request::parse_file_quotation();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_parse_file_message(){
//    try {
//        api_get_request::parse_file_message();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_parse_file_product(){
//    try {
//        api_get_request::parse_file_product();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_parse_file_project(){
//    try {
//        api_get_request::parse_file_project();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_parse_file_promotion_cat(){
//    try {
//        api_get_request::parse_file_promotion_cat();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_parse_file_promotion_comp(){
//    try {
//        api_get_request::parse_file_promotion_comp();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//void test_app::api_get_request_test_parse_file_quotation(){
//    try {
//        api_get_request::parse_file_quotation();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}
//void test_app::api_get_request_test_parse_file_role(){
//    try {
//        api_get_request::parse_file_role();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}
//void test_app::api_get_request_test_parse_file_shop(){
//    try {
//        api_get_request::parse_file_shop();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}
//void test_app::api_get_request_test_parse_file_stock(){
//    try {
//        api_get_request::parse_file_stock();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}
//void test_app::api_get_request_test_parse_file_supplier(){
//    try {
//        api_get_request::parse_file_supplier();
//    }
//    catch (int e) {
//       qDebug()<<e;
//    }

//}

//la définition de test
QTEST_MAIN(test_app)
#include "tst_test_app.moc"
