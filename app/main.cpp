#include "./CONTROLLER/controller.h"
#include <QApplication>
#include <QObject>
#include <QtNetwork>
#include "DB_CLASSES/bdd_address_client.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDir *file = new QDir("STATUS");
    file->rmdir("STATUS");

    bdd_ADDRESS_CLIENT *t = new bdd_ADDRESS_CLIENT();

    QMap<QString, QString> test;

    test = t->TestDict();

    Controller ct;

    ct.init();

    return a.exec();

}


