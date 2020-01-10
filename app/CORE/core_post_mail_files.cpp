#include "core_post_mail_files.h"
#include <QNetworkAccessManager>
#include <QFile>


core_post_mail_files::core_post_mail_files(QObject* parent)
{

}

void core_post_mail_files::send(QString toAddresses, QString body1, QString body2)
{
    // concatenate json line:
    // {"ToAddresses":"guillaume.lefebvre@viacesi.fr", "CcAddresses":"", "Body2":"This is body 2 :D", "Body1":"Bonjour,<br><br>veuillez trouver ci-joint le document pour votre devis madera : <a href=\"https://maderationpictures.s3-eu-west-1.amazonaws.com/james.jpg\">DevisJames</a><br><br>Cordialement,<br>L'équipe Madera", "Subject":"Test email"}
    QString toSend = "{\"ToAddresses\":\"guillaume.lefebvre@viacesi.fr\", \"CcAddresses\":\"\", \"Body2\":\"This is body 2 :D\", \"Body1\":\"Bonjour,<br><br>veuillez trouver ci-joint le document pour votre devis madera : <a href=\"https://maderationpictures.s3-eu-west-1.amazonaws.com/james.jpg\">DevisJames</a><br><br>Cordialement,<br>L'équipe Madera\", \"Subject\":\"Test email\"}";
    qDebug() << "toSend: '" + toSend + "'";

    // send json to :
    // http://madera-api.maderation.net:8080/api/post/post_mail?key=bdd5c890be92b02115330360cd77c194
}
