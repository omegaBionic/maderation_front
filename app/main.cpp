#include "./CONTROLLER/controller.h"
#include "./CORE/core_messages.h"
#include "./CORE/api_get_request.h"
#include <QApplication>
#include <QObject>
#include <QtNetwork>
#include "DB_CLASSES/bdd_address_client.h"
#include "CORE/core_post_mail_files.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QDir *file = new QDir("./STATUS");
    file->rmdir("./STATUS");
    Controller ct;

    /* mail example */
    //core_post_mail_files sender;
    // (QString toAddresses, QString ccAddress, QString subject, QString body1, QString body2)
    //sender.send(QString("julien.boully721@gmail.com"), QString(""), QString("Votre devis madera"), QString("Bonjour,<br><br>veuillez trouver ci-joint le document pour votre devis madera : <a href=\"https://maderationpictures.s3-eu-west-1.amazonaws.com/james.jpg\">DevisJames</a><br><br>Cordialement,<br>L'équipe Madera"), QString("Madera"));

    ct.init();


    return a.exec();

}

