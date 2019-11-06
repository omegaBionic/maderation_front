#include "api_get_request.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDir>
#include <fstream>


api_get_request::api_get_request(QObject *parent) : QObject(parent)
{
    if(!QDir("data").exists()){
        QDir().mkdir("data");
    }
}



//Retourne toutes les données
void get_tables(){

    QNetworkAccessManager man;
    //Requête get
    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/API/get/all"));
    QNetworkReply *reply = man.get(request);

    // On attend la réponse de l'api
    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    // On enregistre la réponse
    QByteArray response_data = reply->readAll();

    //On change le format en json
    QJsonDocument jsonAll = QJsonDocument::fromJson(response_data);

    QFile::rename("jsonAll.json","data/jsonAll.json");

    //Clean the reply object
    reply->deleteLater();
}



void get_table_user(){

    QNetworkAccessManager man;
    QNetworkRequest request(QUrl("http://madera-api.maderation.net:8080/API/get/user"));
    QNetworkReply *reply = man.get(request);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray response_data = reply->readAll();

    QJsonDocument jsonUser = QJsonDocument::fromJson(response_data);

    QFile::rename("jsonAll.json","data/jsonUser.json");

    reply->deleteLater();
}



void parse_file_user(){

    QFile file("data/jsonUser.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties
    //qDebug() << json["something"].toString();

    QString phoneNumber = json["phoneNumber"].toString();
    bool isActive = json["mail"].toBool();
    QString password = json["password"].toString();
    QString lastName = json["lastName"].toString();
    QString mail = json["mail"].toString();
    QString idUser = json["idUser"].toString();
    QString firstName = json["firstName"].toString();
    QString addressIdAddress = json["addressIdAddress"].toString();

}



