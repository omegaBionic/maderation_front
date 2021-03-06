#include "api_post_request.h"
#include <QNetworkAccessManager>
#include <QTextStream>
#include "../DB_CLASSES/bdd_global.h"
#include "utils_id.h"
#include "api_get_request.h"

api_post_request::api_post_request(){
    qDebug() << "[api_post_request] id.get_id(): '" << id.get_id() << "'";
}

void api_post_request::modifyData(bdd_global dataTable, QString modify){

    QFile file("DATA/modif.json");
    int nbItems = 0;
    if(file.open(QIODevice::ReadWrite | QIODevice::Text)){
        QString data = file.readAll();
        QTextStream out(&file);
        if(data.count() < 1){ // pas de données présentes à modifier
            out << "{";
        }else{
            QString jsonFull = data + "}";
            qDebug() << jsonFull;
            QJsonDocument doc(QJsonDocument::fromJson(jsonFull.toUtf8()));

            // Get JSON object
            QJsonObject json = doc.object();

            nbItems = json.count();
        }
        if(nbItems == 0){
            out << "\"" << nbItems << "\":" ;
        }else{
            out << ",\"" << nbItems << "\":" ;
        }
        out << "{";
        out << "\"status\":\"" << modify << "\"," ;
        out << "\"table\":\"madera_" << dataTable.getTable() << "\"," ;
        out << "\"values\":{" ;
        QMap<QString, QString> dictData = dataTable.getDict();
        qDebug() << dictData.count();
        for(int i =0; i< dictData.keys().count(); i++){
            out << "\"" << dictData.keys().at(i) << "\":";
            if(i+1 >= dictData.keys().count()){
                out << "{"<< dictData[dictData.keys().at(i)] << "}";
            }else{
                out << "{" << dictData[dictData.keys().at(i)] << "},";
            }
        }


        out << "}}" ;

    }
    qDebug() << file.readAll();
    file.flush();
    file.close();

    api_post_request::pushData();

}

void api_post_request::addData(bdd_global dataTable, QString modify){

    QFile file("DATA/modif.json");
    int nbItems = 0;
    if(file.open(QIODevice::ReadWrite | QIODevice::Text)){
        QString data = file.readAll();
        QTextStream out(&file);
        if(data.count() < 1){ // pas de données présentes à modifier
            out << "{";
        }else{
            QString jsonFull = data + "}";
            qDebug() << jsonFull;
            QJsonDocument doc(QJsonDocument::fromJson(jsonFull.toUtf8()));

            // Get JSON object
            QJsonObject json = doc.object();

            nbItems = json.count();
        }
        if(nbItems == 0){
            out << "\"" << nbItems << "\":" ;
        }else{
            out << ",\"" << nbItems << "\":" ;
        }
        out << "{";
        out << "\"status\":\"" << modify << "\"," ;
        out << "\"table\":\"madera_" << dataTable.getTable() << "\"," ;
        out << "\"values\":{" ;
        QMap<QString, QString> dictData = dataTable.getDict();
        qDebug() << dictData.count();
        for(int i =0; i< dictData.keys().count(); i++){
            out << "\"" << dictData.keys().at(i) << "\":";
            if(i+1 >= dictData.keys().count()){
                out << "{"<< dictData[dictData.keys().at(i)] << "}";
            }else{
                out << "{" << dictData[dictData.keys().at(i)] << "},";
            }
        }


        out << "}}" ;

    }
    qDebug() << file.readAll();
    file.flush();
    file.close();


}


void api_post_request::pushData(){

    // TODO: add id.get_id() in id parameter on post request


    QFile fileFull("DATA/modif.json");
    fileFull.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray line;   //a qbytearray object for read file line by line
    while (!fileFull.atEnd())
    {
        line.append(fileFull.readLine());
    }
    line.append("}");

    QByteArray jsonString = line;

    fileFull.close();
    QByteArray postDataSize = QByteArray::number(jsonString.size());
    utils_id id;
    QUrl req("http://madera-api.maderation.net:8080/api/post/post_datas?key=993b06009dce6a9962esecf49801d32e&id="+id.get_id());

    QNetworkRequest request(req);

    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Content-Length", postDataSize);

    QNetworkAccessManager test;
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    if(manager->networkAccessible() == QNetworkAccessManager::Accessible){
        connect(manager, &QNetworkAccessManager::finished,
                this, &api_post_request::downloadFinished);
        manager->post(request, jsonString);

    }else if (manager->networkAccessible() == QNetworkAccessManager::NotAccessible || manager->networkAccessible() == QNetworkAccessManager::UnknownAccessibility){
        qDebug()<<"erreur de connexion à internet";
    }

}


void api_post_request::downloadFinished(QNetworkReply* reply){

    qDebug() << reply->url().toString();
    qDebug("finished");
    QByteArray response = reply->readAll();
    qDebug() << "response status : " +  response;
    if (response.contains("status\":200")){
        QFile fileFull("DATA/modif.json");
        fileFull.copy("DATA/temp.json");
        fileFull.remove();
        api_get_request* api = new api_get_request();
        api->get_all_table();
    }

    reply->deleteLater();

}
