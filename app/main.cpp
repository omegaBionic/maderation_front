#include "./CONTROLLER/controller.h"
#include "./CORE/core_messages.h"
#include "./CORE/api_get_request.h"
#include <QApplication>
#include <QObject>
#include <QtNetwork>
#include "DB_CLASSES/bdd_address_client.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QDir *file = new QDir("./STATUS");
    file->rmdir("./STATUS");
    Controller ct;

    ct.init();


    return a.exec();

}

