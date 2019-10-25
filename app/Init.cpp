#include "main_login.h"
#include "ui_main_login.h"
#include <QDesktopServices>
#include <QUrl>
#include <QProcess>
#include <QMessageBox>
#include <QFile>
#include <QtNetwork>
#include <QJsonObject>
#include <QJsonDocument>
#include <QUrlQuery>
#include <QJsonValue>
#include <QDebug>
#include <sys/stat.h>
#include <QDir>
#include <Init.h>
#include <QCoreApplication>





Init::Init()
{

}

Init::~Init()
{

}

void Init::Check_folder()
{
    // verification de lexistence du dossier DATA

    QDir folder("DATA");
    if(folder.exists())
    {
        //existe
        qDebug("folder exist");
    }
    else if (!folder.exists())
    {
        //existe pas
        folder.mkpath("."); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
        qDebug("created");

    }

}

bool Init::Network_Connection()
{
    //connection a l'api
    qDebug("connection a l'api");
    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(QUrl("http://madera-api.maderation.net:8080/api/get/status?key=179616f1a4cecab2a7eab481b84d076c")));
    QEventLoop event;
    QObject::connect(&manager, SIGNAL(finished()), &event, SLOT(quit()));
    event.exec();
    QString html = response->readAll();

    //transformation du json pour lecture

     qDebug("Récuperation du json et transformation");
    //html ="{\"status\":true,\"datas\":\"key: OK, dynamodb: OK\"}";
    QJsonDocument jsonDoc= QJsonDocument::fromJson(html.toUtf8());
    QJsonObject MyObject = jsonDoc.object();
    MyObject.value(QString("status"));
    qDebug()<< MyObject.value(QString("status"));
    QJsonValue statut =  MyObject.value(QString("status"));

     qDebug("Vérification du statut de la  bdd");

    if(statut == true)
    {
           qDebug("connected");
           return true;
    }
    else
    {
           qDebug("not connected");
           return false;
    }
};




