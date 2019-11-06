#include <QtTest>
#include <QCoreApplication>

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
    void test2();

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

void test_app::test2()
{
    QVERIFY(1==1);
}




//la définition de test
QTEST_MAIN(test_app)
#include "tst_test_app.moc"
