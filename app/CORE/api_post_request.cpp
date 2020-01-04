#include "api_post_request.h"
#include <QNetworkAccessManager>

api_post_request::api_post_request(){

    }

void api_post_request::modifyData(QString jsonFile,QString idKey, QString id, QString key, QString modify){

}

void api_post_request::pushData(){

    QFile file("DATA/modif.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "file open failure";
    }
    QByteArray line;   //a qbytearray object for read file line by line
    while (!file.atEnd())
    {
        line.append(file.readLine());
    }

    file.close();

    QByteArray jsonString = line;

    QByteArray postDataSize = QByteArray::number(jsonString.size());

    QUrl req("http://madera-api.maderation.net:8080/api/post/");

    QNetworkRequest request(req);

    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Content-Length", postDataSize);

    QNetworkAccessManager test;

    QEventLoop loop;
    connect(&test, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));
    QNetworkReply * reply = test.post(request, jsonString);
    //connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onError(QNetworkReply::NetworkError)));
    loop.exec();

    QByteArray response = reply->readAll();
    qDebug() << response;


}
