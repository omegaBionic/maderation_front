#include "core_post_mail_files.h"
#include <QNetworkAccessManager>
#include <QFile>
#include "utils_id.h"

core_post_mail_files::core_post_mail_files()
{

}

void core_post_mail_files::send(QString toAddresses, QString ccAddress, QString subject, QString body1, QString body2)
{
    // concatenate json line:
    // {"ToAddresses":"julien.boully721@gmail.com", "CcAddresses":"", "Body1":"This is body 1 :D", "Body1":"Bonjour,<br><br>veuillez trouver ci-joint le document pour votre devis madera : <a href=\"https://maderationpictures.s3-eu-west-1.amazonaws.com/james.jpg\">DevisJames</a><br><br>Cordialement,<br>L'équipe Madera", "Subject":"Test email"}
    QString toSend = "{\"ToAddresses\":\"" + toAddresses + "\", \"CcAddresses\":\"" + ccAddress + "\", \"Body1\":\"" + body1 + "\", \"Body2\":\"" + body2 + "\", \"Subject\":\"" + subject + "\"}";
    qDebug() << "[core_post_mail_files] toSend: '" + toSend + "'";

    // send json to :
    // http://madera-api.maderation.net:8080/api/post/post_mail?key=bdd5c890be92b02115330360cd77c194

    // TODO: add id.get_id() in id parameter on post request


    QFile temp("DATA_IMG/temp.json");
    temp.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream out(&temp);
    out << toSend;

    temp.flush();
    temp.close();

    QByteArray jsonString = toSend.toUtf8();

    QByteArray postDataSize = QByteArray::number(jsonString.size());
    utils_id id;
    QUrl req("http://madera-api.maderation.net:8080/api/post/post_mail?key=bdd5c890be92b02115330360cd77c194&id="+id.get_id());

    QNetworkRequest request(req);

    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Content-Length", postDataSize);

    QNetworkAccessManager test;
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    if(manager->networkAccessible() == QNetworkAccessManager::Accessible){
        connect(manager, &QNetworkAccessManager::finished,
                this, &core_post_mail_files::downloadFinished);
        manager->post(request, jsonString);

    }else if (manager->networkAccessible() == QNetworkAccessManager::NotAccessible || manager->networkAccessible() == QNetworkAccessManager::UnknownAccessibility){
        qDebug()<<"erreur de connexion à internet";
    }

}


void core_post_mail_files::downloadFinished(QNetworkReply* reply){

    qDebug() << reply->url().toString();
    qDebug("finished");
    QByteArray response = reply->readAll();
    qDebug() << "response status : " +  response;
    if (response.contains("status\":200")){
        qDebug() << "done";
    }

    reply->deleteLater();

}
