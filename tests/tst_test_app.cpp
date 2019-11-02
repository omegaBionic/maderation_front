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



class test_app : public QObject
{
    Q_OBJECT

public:
    test_app();
    ~test_app();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();
    void test_case1();

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


}


void test_app::cleanupTestCase()
{
    // se lance à la fin
}

void test_app::init()
{
    // se lance avant chaque test
}

void test_app::cleanup()
{
    // se lance après chaque test
}

//un exemple de test fonctionnel
void test_app::test_case1()
{
    QVERIFY(1==1);
}


//la définition de test
QTEST_MAIN(test_app)
#include "tst_test_app.moc"
