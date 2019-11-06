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
//------------------------------------------------------



// add necessary includes here



class test_main_login : public QObject
{
    Q_OBJECT

public:
    test_main_login();
    ~test_main_login();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();
    void test_case1();

};

test_main_login::test_main_login()
{

}

test_main_login::~test_main_login()
{

}

void test_main_login::initTestCase()
{
    // se lance au tout début


}


void test_main_login::cleanupTestCase()
{
    // se lance à la fin
}

void test_main_login::init()
{
    // se lance avant chaque test
}

void test_main_login::cleanup()
{
    // se lance après chaque test
}

//un exemple de test fonctionnel
void test_main_login::test_case1()
{
    QVERIFY(1==1);
}


//la définition de test
QTEST_MAIN(test_main_login)
#include "test_main_login.moc"
