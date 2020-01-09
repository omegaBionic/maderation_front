#include <QtTest>
#include <QCoreApplication>
#include <../app/CORE/api_get_request.h>
#include <../app/CORE/api_post_request.h>
//#include <../app/CORE/core_login.h>

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
#include <../app/CORE/core_user_management.h>
//------------------------------------------------------
#include "../app/UI/main_login.h"
#include "../app/UI/menu_toolbar.h"
#include "../app/CONTROLLER/controller.h"
#include "../app/UI/main_menu.h"
#include "../app/UI/button_quotation.h"
#include "../app/UI/main_chat.h"
#include "../app/UI/form_messages.h"
#include "../app/UI/main_user.h"
#include "../app/UI/form_users.h"
#include "../app/UI/main_template.h"
#include "../app/UI/main_quotation.h"

#include "../app/CORE/core_messages.h"
#include "../app/CORE/core_quotation.h"

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
    void main_login_exist();
    void menu_toolbar_exist();
    void menu_toolbar_hide();
    void menu_toolbar_show();
    void controller_exist();
    void controller_have_login();
    void controller_get_user();
    void main_menu_exist();

    void api_get_request_test_get_status();
    void api_get_request_test_get_table_user();
    void api_get_request_test_get_table_client();
    void api_get_request_test_get_table_address_client();
    void api_get_request_test_get_table_address_supplier();
    void api_get_request_test_get_table_category();
    void api_get_request_test_get_table_chat();
    void api_get_request_test_get_table_component();
    void api_get_request_test_get_table_gamme();
    void api_get_request_test_get_table_invoice_quotation();
    void api_get_request_test_get_table_message();
    void api_get_request_test_get_table_product();
    void api_get_request_test_get_table_project();
    void api_get_request_test_get_table_promotion_cat();
    void api_get_request_test_get_table_promotion_comp();
    void api_get_request_test_get_table_quotation();
    void api_get_request_test_get_table_role();
    void api_get_request_test_get_table_shop();
    void api_get_request_test_get_table_stock();
    void api_get_request_test_get_table_supplier();
    void api_get_request_test_get_table_attribut();

    void api_get_request_test_parse_file_status();
    void api_get_request_test_parse_file_user();
    void api_get_request_test_parse_file_client();
    void api_get_request_test_parse_file_address_client();
    void api_get_request_test_parse_file_address_supplier();
    void api_get_request_test_parse_file_category();
    void api_get_request_test_parse_file_chat();
    void api_get_request_test_parse_file_component();
    void api_get_request_test_parse_file_gamme();
    void api_get_request_test_parse_file_invoice_quotation();
    void api_get_request_test_parse_file_message();
    void api_get_request_test_parse_file_product();
    void api_get_request_test_parse_file_project();
    void api_get_request_test_parse_file_promotion_cat();
    void api_get_request_test_parse_file_promotion_comp();
    void api_get_request_test_parse_file_quotation();
    void api_get_request_test_parse_file_role();
    void api_get_request_test_parse_file_shop();
    void api_get_request_test_parse_file_stock();
    void api_get_request_test_parse_file_supplier();
    void apit_get_request_test_parse_file_attribut();

    void button_quotation_exist();
    void button_quotation_have_ID();

    void main_chat_exist();
    void form_messages_exist();
    void main_template_exist();
    void main_quotation_exist();


    void main_user_exist();
    void form_user_exist();

    void test_Init1();
    void test_Init2();

    void test_coreMessagesGetChats();
    void test_coreMessageGetMessages();
    void test_coreMessageAddMessages();
    void test_coreMessageAddChat();

    void api_post_request_test_pushData();
    void api_post_request_test_modifyData();
    void core_login_get_user();
    void test_core_user_management_add();
    void test_core_user_management_modify();

    void test_core_quotation_getAttribut();
    void test_core_quotation_getProduct();
    void test_core_quotation_setAttribut();


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
void test_app::main_login_exist()
{
    main = new Main_Login(0);
    QVERIFY(main != NULL);
}


void test_app::api_get_request_test_get_status(){
    try {
        api_get_request* api = new api_get_request();
        api->get_status();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_get_table_user(){
    try {
        api_get_request* api = new api_get_request();
        api->get_table_user();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_get_table_client(){
    try {

        api_get_request* api = new api_get_request();
        api->get_table_client();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_get_table_address_client(){
    try {

        api_get_request* api = new api_get_request();
        api->get_table_address_client();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_get_table_address_supplier(){
    try {

        api_get_request* api = new api_get_request();
        api->get_table_address_supplier();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_get_table_category(){
    try {

        api_get_request* api = new api_get_request();
        api->get_table_category();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_get_table_chat(){
    try {

        api_get_request* api = new api_get_request();
        api->get_table_chat();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_get_table_component(){
    try {

        api_get_request* api = new api_get_request();
        api->get_table_component();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_get_table_gamme(){
    try {

        api_get_request* api = new api_get_request();
        api->get_table_gamme();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_get_table_invoice_quotation(){
    try {

        api_get_request* api = new api_get_request();
        api->get_table_invoice_quotation();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_get_table_message(){
    try {

        api_get_request* api = new api_get_request();
        api->get_table_message();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_get_table_product(){
    try {

        api_get_request* api = new api_get_request();
        api->get_table_product();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_get_table_project(){
    try {

        api_get_request* api = new api_get_request();
        api->get_table_project();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_get_table_promotion_cat(){
    try {

        api_get_request* api = new api_get_request();
        api->get_table_promotion_cat();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_get_table_promotion_comp(){
    try {

        api_get_request* api = new api_get_request();
        api->get_table_promotion_comp();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_get_table_quotation(){
    try {

        api_get_request* api = new api_get_request();
        api->get_table_quotation();
    }
    catch (int e) {
       qDebug()<<e;
    }

}
void test_app::api_get_request_test_get_table_role(){
    try {

        api_get_request* api = new api_get_request();
        api->get_table_role();
    }
    catch (int e) {
       qDebug()<<e;
    }

}
void test_app::api_get_request_test_get_table_shop(){
    try {

        api_get_request* api = new api_get_request();
        api->get_table_shop();
    }
    catch (int e) {
       qDebug()<<e;
    }

}
void test_app::api_get_request_test_get_table_stock(){
    try {

        api_get_request* api = new api_get_request();
        api->get_table_stock();
    }
    catch (int e) {
       qDebug()<<e;
    }

}
void test_app::api_get_request_test_get_table_supplier(){
    try {

        api_get_request* api = new api_get_request();
        api->get_table_supplier();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_get_table_attribut(){
    try {

        api_get_request* api = new api_get_request();
        api->get_table_attribut();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::apit_get_request_test_parse_file_attribut(){
    try {

        api_get_request* api = new api_get_request();
        api->parse_file_attribut();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_parse_file_status(){
    try {

        api_get_request* api = new api_get_request();
        api->parse_file_status();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_parse_file_user(){
    try {

        api_get_request* api = new api_get_request();
        api->parse_file_user();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_parse_file_client(){
    try {

        api_get_request* api = new api_get_request();
        api->parse_file_client();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_parse_file_address_client(){
    try {

        api_get_request* api = new api_get_request();
        api->parse_file_address_client();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_parse_file_address_supplier(){
    try {

        api_get_request* api = new api_get_request();
        api->parse_file_address_supplier();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_parse_file_category(){
    try {

        api_get_request* api = new api_get_request();
        api->parse_file_category();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_parse_file_chat(){
    try {

        api_get_request* api = new api_get_request();
        api->parse_file_chat();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_parse_file_component(){
    try {

        api_get_request* api = new api_get_request();
        api->parse_file_component();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_parse_file_gamme(){
    try {

        api_get_request* api = new api_get_request();
        api->parse_file_gamme();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_parse_file_invoice_quotation(){
    try {

        api_get_request* api = new api_get_request();
        api->parse_file_quotation();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_parse_file_message(){
    try {

        api_get_request* api = new api_get_request();
        api->parse_file_message();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_parse_file_product(){
    try {

        api_get_request* api = new api_get_request();
        api->parse_file_product();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_parse_file_project(){
    try {

        api_get_request* api = new api_get_request();
        api->parse_file_project();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_parse_file_promotion_cat(){
    try {

        api_get_request* api = new api_get_request();
        api->parse_file_promotion_cat();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_parse_file_promotion_comp(){
    try {

        api_get_request* api = new api_get_request();
        api->parse_file_promotion_comp();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::api_get_request_test_parse_file_quotation(){
    try {

        api_get_request* api = new api_get_request();
        api->parse_file_quotation();
    }
    catch (int e) {
       qDebug()<<e;
    }

}
void test_app::api_get_request_test_parse_file_role(){
    try {

        api_get_request* api = new api_get_request();
        api->parse_file_role();
    }
    catch (int e) {
       qDebug()<<e;
    }

}
void test_app::api_get_request_test_parse_file_shop(){
    try {

        api_get_request* api = new api_get_request();
        api->parse_file_shop();
    }
    catch (int e) {
       qDebug()<<e;
    }

}
void test_app::api_get_request_test_parse_file_stock(){
    try {

        api_get_request* api = new api_get_request();
        api->parse_file_stock();
    }
    catch (int e) {
       qDebug()<<e;
    }

}
void test_app::api_get_request_test_parse_file_supplier(){
    try {

        api_get_request* api = new api_get_request();
        api->parse_file_supplier();
    }
    catch (int e) {
       qDebug()<<e;
    }

}

void test_app::menu_toolbar_exist()
{
    menu_toolbar* menu = new menu_toolbar(0);
    QVERIFY(menu != NULL);
}
void test_app::menu_toolbar_hide()
{
    menu_toolbar* menu = new menu_toolbar(0);
    menu->on_btn_hide_clicked();
    QVERIFY(menu->_isHided == true);
}
void test_app::menu_toolbar_show()
{
    menu_toolbar* menu = new menu_toolbar(0);
    QVERIFY(menu->_isHided == false);
    menu->on_btn_hide_clicked();
    QVERIFY(menu->_isHided == true);
    menu->on_btn_hide_clicked();
    QVERIFY(menu->_isHided == false);
    menu->on_btn_hide_clicked();
    QVERIFY(menu->_isHided == true);
}

void test_app::controller_exist()
{
    Controller* ct = new Controller(0);
    QVERIFY(ct != NULL);
}

void test_app::controller_have_login()
{
    Controller* ct = new Controller(0);
    QVERIFY(ct->getLogin() != NULL);
}

void test_app::controller_get_user()
{
    Controller* ct = new Controller(0);
    QVERIFY(ct->getUser() != NULL);
}


void test_app::main_menu_exist(){
    Main_Menu *m = new Main_Menu(0,NULL);
    QVERIFY(m != NULL);
}

void test_app::button_quotation_exist(){
    button_quotation *m = new button_quotation(nullptr, 5);
    QVERIFY(m != NULL);
}

void test_app::main_chat_exist(){
    main_chat *m = new main_chat(0,nullptr,nullptr,"toto");
    QVERIFY(m != NULL);
}

void test_app::form_messages_exist(){
    Form_messages *m = new Form_messages(nullptr, nullptr, "testTitle","author");
    QVERIFY(m != NULL);
}

void test_app::button_quotation_have_ID(){
    button_quotation *m = new button_quotation(nullptr, 5);
    QVERIFY(m->getID() == 5);
}

void test_app::test_Init1()
{
    main_init* m = new main_init();
    m->blockSignals(true);
    m->Check_folder();
    QString path("../app/DATA");
    QDir folder(path);
    QVERIFY((folder.exists()));
}

void test_app::test_Init2()
{
    main_init* m = new main_init();
    m->blockSignals(true);
    m->Check_folder();
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

    QVERIFY((T_jsonUser.exists()));
    QVERIFY((T_jsonClient.exists()));
    QVERIFY((T_jsonAddressClient.exists()));
    QVERIFY((T_jsonCategory.exists()));
    QVERIFY((T_jsonChat.exists()));
    QVERIFY((T_jsonComponent.exists()));
    QVERIFY((T_jsonGamme.exists()));
    QVERIFY((T_jsonInvoiceQuotation.exists()));
    QVERIFY((T_jsonMessage.exists()));
    QVERIFY((T_jsonProduct.exists()));
    QVERIFY((T_jsonProject.exists()));
    QVERIFY((T_jsonPromotionCat.exists()));
    QVERIFY((T_jsonPromotionComp.exists()));
    QVERIFY((T_jsonQuotation.exists()));
    QVERIFY((T_jsonRole.exists()));
    QVERIFY((T_jsonShop.exists()));
    QVERIFY((T_jsonStock.exists()));
    QVERIFY((T_jsonSupplier.exists()));

}

void test_app::test_coreMessagesGetChats()
{
   core_messages* testChats = new core_messages();

   QVERIFY(!testChats->getChats("qcordiero").isEmpty());


}

void test_app::test_coreMessageGetMessages()
{
    core_messages* testChats = new core_messages();

    QVERIFY(!testChats->getMessages("1").isEmpty());

}

void test_app::test_coreMessageAddMessages()
{
    core_messages *testAddMessages = new core_messages();
    bdd_USER u;
    u.setMail("Mail");
    u.setIsActive(false);
    u.setLastName("LastName");
    u.setPassword("PassWord");
    u.setUsername("Username");
    u.setFirstName("Firstname");
    u.setIdAddress(2);
    u.setPhoneNumber("PhoneNumber");


    bdd_CHAT c;
    c.setTitle("testTitle");
    c.setIdChat("testIdChat");
    c.setCreationDate("testCreationDate");
    c.setUserUsernameAsReceiver("testUserUsernameAsReceiver");
    QVERIFY(!testAddMessages->addMessage(u,c) == false);

}

void test_app::test_coreMessageAddChat()
{
    bdd_USER s;
    s.setMail("Mail_s");
    s.setIsActive(false);
    s.setLastName("LastName_s");
    s.setPassword("PassWord_s");
    s.setUsername("Username_s");
    s.setFirstName("Firstname_s");
    s.setIdAddress(2);
    s.setPhoneNumber("PhoneNumber_s");

    bdd_USER r;
    r.setMail("Mail_r");
    r.setIsActive(false);
    r.setLastName("LastName_r");
    r.setPassword("PassWord_r");
    r.setUsername("Username_r");
    r.setFirstName("Firstname_r");
    r.setIdAddress(2);
    r.setPhoneNumber("PhoneNumber_r");

    core_messages *testAddChat = new core_messages();
    QVERIFY(!testAddChat->addChat(s, r)== false);

}

void test_app::main_user_exist(){
    QVector<bdd_USER>* user = new QVector<bdd_USER>();
    user->append(bdd_USER("0606060606",true,"polop","polop", "test",0,"polop@polop.com", "polop"));
    main_user *m = new main_user(0, nullptr, user);
    QVERIFY(m != NULL);
}

void test_app::form_user_exist(){
    Form_users *m = new Form_users(0, bdd_USER("0606060606",true,"polop","polop", "test",0,"polop@polop.com", "polop"));
    QVERIFY(m != NULL);
}

void test_app::main_template_exist(){
    main_template *m = new main_template(0, nullptr, nullptr);
    QVERIFY(m != NULL);
}

void test_app::main_quotation_exist(){
    Main_Quotation *m = new Main_Quotation(nullptr, nullptr);
    QVERIFY(m != NULL);
}



/*void test_app::main_menu_exist(){
    Main_Menu *m = new Main_Menu(0,NULL);
    QVERIFY(m != NULL);
}

void test_app::button_quotation_exist(){
    button_quotation *m = new button_quotation(nullptr, 5);
    QVERIFY(m != NULL);
}

void test_app::button_quotation_have_ID(){
    button_quotation *m = new button_quotation(nullptr, 5);
    QVERIFY(m->getID() == 5);
}*/

bool waitForSignal(QObject *sender, const char *signal, int timeout = 1000) {
    QEventLoop loop;
    QTimer timer;
    timer.setInterval(timeout);
    timer.setSingleShot(true);

    loop.connect(sender, signal, SLOT(quit()));
    loop.connect(&timer, SIGNAL(timeout()), SLOT(quit()));
    timer.start();
    loop.exec();

    return timer.isActive();
}

void test_app::api_post_request_test_pushData(){
     QNetworkAccessManager *nam =  new QNetworkAccessManager(this);
     QUrl url("http://madera-api.maderation.net:8080/api/push");
     QNetworkRequest req(url);

     this->connect(nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(reqFinished(QNetworkReply *)));
     QNetworkReply *rep = nam->get(req);
     QVERIFY(waitForSignal(nam, SIGNAL(finished(QNetworkReply*)), 5000));
}

void test_app::api_post_request_test_modifyData(){
    QString jsonFile = "jsonUser.json";
    QString id = "1";
    QString key = "username";
    QString modify = "jhon";
    try {
//        api_post_request::modifyData(jsonFile, id, key, modify);
    }catch (int e) {
        qDebug()<<e;
     }
}

void test_app::core_login_get_user(){
    try {
        QString username = "jacky";
        QString password = "4l";
        //core_login::getUser(username, password);
    } catch (int e) {
        qDebug()<<e;
    }
}

void test_app::test_core_user_management_add()
{
   bdd_USER u;
   u.setMail("testMail");
   u.setIsActive(true);
   u.setLastName("testLastName");
   u.setPassword("testPassword");
   u.setUsername("testUsername");
   u.setFirstName("testFirstName");
   u.setIdAddress(1);
   u.setPhoneNumber("testPhoneNumber");
   core_user_management *test_core_user_management = new core_user_management();
   QVERIFY(!test_core_user_management->addUser(u) == NULL);

}

void test_app::test_core_user_management_modify()
{
    bdd_USER m;
    m.setMail("testMail");
    m.setIsActive(true);
    m.setLastName("testLastName");
    m.setPassword("testPassword");
    m.setUsername("testUsername");
    m.setFirstName("testFirstName");
    m.setIdAddress(1);
    m.setPhoneNumber("testPhoneNumber");
    core_user_management *test_core_user_management = new core_user_management();
    QVERIFY(!test_core_user_management->modifyUser(m)==NULL);



}

void test_app::test_core_quotation_getAttribut()
{
    bdd_PRODUCT poutre;
    bdd_ATTRIBUT poutreAttribut;

    poutre.setType("Poutre");
    poutre.setLabel("Poutre bois 300/50");
    poutre.setMaterial("bois");
    poutre.setMinWidth(50);
    poutre.setIdProduct("1");
    poutre.setMinLength(100);
    poutre.setProductCode("PB-300-50");
    poutre.setDefaultWidth(50);
    poutre.setDefaultHeight(50);
    poutre.setDefaultLength(300);
    poutre.setSupplierIdSupplier(42);

    poutreAttribut.setLength(500);
    poutreAttribut.setPositionY(240);
    poutreAttribut.setWidth(50);
    poutreAttribut.setHeight(50);
    poutreAttribut.setProductIdProduct(1);
    poutreAttribut.setOrderIdProject(42);
    poutreAttribut.setPositionX(150);
    poutreAttribut.setRotationY(0);
    poutreAttribut.setPositionZ(0);
    poutreAttribut.setRotationX(0);
    poutreAttribut.setIdAttribut(1);

    core_quotation *test_core_quotation = new core_quotation();
//    QVERIFY(!test_core_quotation->getAttributs() == NULL);

}


void test_app::test_core_quotation_getProduct()
{
    bdd_PRODUCT poutre;


    poutre.setType("Poutre");
    poutre.setLabel("Poutre bois 300/50");
    poutre.setMaterial("bois");
    poutre.setMinWidth(50);
    poutre.setIdProduct("1");
    poutre.setMinLength(100);
    poutre.setProductCode("PB-300-50");
    poutre.setDefaultWidth(50);
    poutre.setDefaultHeight(50);
    poutre.setDefaultLength(300);
    poutre.setSupplierIdSupplier(42);


    core_quotation *test_core_quotation = new core_quotation();
    QVector<bdd_PRODUCT> listProduct;
    listProduct = test_core_quotation->getProduct("Poutre", "Type");
    QVERIFY(&listProduct != NULL);

}

void test_app::test_core_quotation_setAttribut()
{
     bdd_ATTRIBUT poutreAttribut;
     bdd_PROJECT Project1;

     poutreAttribut.setLength(500);
     poutreAttribut.setPositionY(240);
     poutreAttribut.setWidth(50);
     poutreAttribut.setHeight(50);
     poutreAttribut.setProductIdProduct(1);
     poutreAttribut.setOrderIdProject(20);
     poutreAttribut.setPositionX(150);
     poutreAttribut.setRotationY(0);
     poutreAttribut.setPositionZ(0);
     poutreAttribut.setRotationX(0);
     poutreAttribut.setIdAttribut(1);

     Project1.setIdProject("42");
     Project1.setIsTemplate(false);
     Project1.setValidation(false);
     Project1.setuserUseName("Projet1 test");
     Project1.setCreationDate("18/12/2019");
     Project1.setValidationDate("00/00/0000");

     core_quotation *test_core_quotation = new core_quotation();
     QVERIFY(test_core_quotation->setAttribut(Project1,poutreAttribut));
//     QVERIFY(Project1.getIdProject() == poutreAttribut.setOrderIdProject(20));

}

//la définition de test
QTEST_MAIN(test_app)
#include "tst_test_app.moc"
