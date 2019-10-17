#include <QtTest>
#include <QCoreApplication>

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

}

void test_app::cleanupTestCase()
{

}

void test_app::test_case1()
{

}

QTEST_MAIN(test_app)

#include "tst_test_app.moc"
