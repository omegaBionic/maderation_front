#include "core_post_mail_files.h"
#include <QNetworkAccessManager>
#include <QFile>
#include "utils_id.h"
#include <QImage>
#include <QBuffer>

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

void core_post_mail_files::sendFile(QString pathFile, QString fileName, QString format)
{
    // concatenate json line:
    // {"ToAddresses":"julien.boully721@gmail.com", "CcAddresses":"", "Body1":"This is body 1 :D", "Body1":"Bonjour,<br><br>veuillez trouver ci-joint le document pour votre devis madera : <a href=\"https://maderationpictures.s3-eu-west-1.amazonaws.com/james.jpg\">DevisJames</a><br><br>Cordialement,<br>L'équipe Madera", "Subject":"Test email"}
    QString toSend = "{\"fileName\":\"" + fileName + "\",\"data\":\"data:" ;

    if(format == "png"){
        toSend += "image/png;base64,";
    }else if (format == "html"){
        toSend += "text/html;base64,";
    }else if (format == "pdf"){
        toSend += "application/pdf;base64,";
    }

    QFile file(pathFile);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QByteArray array;
    QString text;
    if(fileName.contains("html")){
        text = in.readAll();
        array = text.toUtf8().toBase64();
    }else if (fileName.contains("pdf")){
        text = in.readAll();
        array = text.toUtf8().toBase64();
    }else if(fileName.contains("png")){
        qDebug() << "CORE_POST_MAIL --> starting to parse png";
        QImage image(pathFile); // 20,20 are the size of the icon
        QByteArray byteArray;
        QBuffer buffer(&byteArray);
        image.save(&buffer, "PNG"); // writes the image in PNG format inside the buffer
        array = byteArray.toBase64(QByteArray::Base64Encoding);
    }

    file.flush();
    file.close();



    toSend += array + "\"}";
    qDebug() << "[core_post_mail_files] toSendFile: '" + text + "'";

    QFile temp("DATA_IMG/temp2.json");
    temp.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream out(&temp);
    out << text;

    temp.flush();
    temp.close();
    QByteArray jsonString = toSend.toUtf8();

    QByteArray postDataSize = QByteArray::number(jsonString.size());
    utils_id id;
    QUrl req("http://madera-api.maderation.net:8080/api/post/post_file?key=c038zoo1a9b638f8e89d897119a1b7bb&id="+id.get_id());

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

void core_post_mail_files::getFile(QString FileName)
{
    // concatenate json line:
    // {"ToAddresses":"julien.boully721@gmail.com", "CcAddresses":"", "Body1":"This is body 1 :D", "Body1":"Bonjour,<br><br>veuillez trouver ci-joint le document pour votre devis madera : <a href=\"https://maderationpictures.s3-eu-west-1.amazonaws.com/james.jpg\">DevisJames</a><br><br>Cordialement,<br>L'équipe Madera", "Subject":"Test email"}

    QUrl req("http://madera-api.maderation.net:8080/api/get/file?key=995bwa38536b6100d3948ea0bd902c88&filename=" + FileName);

    QNetworkRequest request(req);
    _fileName = FileName;

    QNetworkAccessManager test;
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    if(manager->networkAccessible() == QNetworkAccessManager::Accessible){
        connect(manager, &QNetworkAccessManager::finished,
                this, &core_post_mail_files::fileDownloaded);
        manager->get(request);

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

void core_post_mail_files::fileDownloaded(QNetworkReply* reply){

    qDebug() << reply->url().toString();
    qDebug("finished");
    QByteArray response = reply->readAll();
    qDebug() << "response status : " +  response.toBase64();
    if (response.contains("status\":200")){
        qDebug() << "done";
    }
    QFile temp("DATA/" + _fileName);
    temp.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream out(&temp);
    if(_fileName.contains("html")){

        QByteArray data = response.split('"')[5].replace('"', "");
        data = data.replace('}',"");
        out << data.fromBase64(data, QByteArray::Base64Encoding);
    } else if(_fileName.contains("pdf")){

        QByteArray data = response.split('"')[5].replace('"', "");
        data = data.replace('}',"");
        out << data.fromBase64(data, QByteArray::Base64Encoding);
    }else if(_fileName.contains("png")){

        QByteArray data = response.split('"')[5].replace('"', "");
        data = data.replace('}',"");
        QImage image;
        image.loadFromData(QByteArray::fromBase64(data), "PNG");
        image.save("DATA_IMG/" + _fileName);
    }

    temp.flush();
    temp.close();
    reply->deleteLater();

}
