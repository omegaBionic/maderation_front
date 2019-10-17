#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class tests_UI : public QObject
{
    Q_OBJECT

public:
    tests_UI();
    ~tests_UI();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

tests_UI::tests_UI()
{

}

tests_UI::~tests_UI()
{

}

void tests_UI::initTestCase()
{

}

void tests_UI::cleanupTestCase()
{

}

void tests_UI::test_case1()
{

}

QTEST_MAIN(tests_UI)

#include "tst_tests_ui.moc"
