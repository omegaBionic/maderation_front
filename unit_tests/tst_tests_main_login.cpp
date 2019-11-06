#include <QtTest>
#include <QCoreApplication>
#include "../app/main_login.h"

// add necessary includes here

class tests_main_login : public QObject
{
    Q_OBJECT

public:
    tests_main_login();
    ~tests_main_login();

private slots:
    void test_case1();

};

tests_main_login::tests_main_login()
{

}

tests_main_login::~tests_main_login()
{

}

void tests_main_login::test_case1()
{
    Main_Login *main;
    main = new Main_Login(0);
    QVERIFY(main->CheckConnexion());
}

QTEST_MAIN(tests_main_login)

#include "tst_tests_main_login.moc"
