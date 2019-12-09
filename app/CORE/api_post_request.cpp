#include "api_post_request.h"
#include <QNetworkAccessManager>

api_post_request::api_post_request(){

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
    QByteArray boundary;

    QByteArray datas(QString("--" + boundary + "\r\n").toLatin1());
    datas += "Content-Disposition: form-data; name=\"file\"; filename=\""+file.fileName()+"\"\r\n";
    //here is the http header for manuplate a normal http form and form file object

    datas += "Content-Type: application/json\r\n\r\n"; //file type is here
    datas += line; //and our file is giving to form object
    datas += "\r\n";
    datas += QString("--" + boundary + "\r\n\r\n").toLatin1();
    datas += "Content-Disposition: form-data; name=\"upload\"\r\n\r\n";
    datas += "Uploader\r\n";
    datas += QString("--" + boundary + "--\r\n").toLatin1();

    QNetworkRequest req;
    req.setUrl(QUrl("http://madera-api.maderation.net:8080/api/pushData"));    //my virtual servers' ip address and tiny php page url is here
    req.setRawHeader("Content-Type", "multipart/form-data; boundary=" + boundary);  // we must set the first header like this. its tell the server, current object is a form

    QNetworkAccessManager *manager = new QNetworkAccessManager;     //using qnetwork access manager for post data

    //connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(erroron_filesend(QNetworkReply*)));    //connecting manager object for errors here
    manager->post(req,datas); //send all data


}

void api_post_request::modifyData(QString jsonFile, QString id, QString key, QString modify){
    QFile file("DATA/" + jsonFile);
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();
    file.close();
    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));
    // Get JSON object
    QJsonObject json = doc.object();

    QFile fileModif("DATA/modif.json");
    fileModif.open(QIODevice::ReadWrite);
    QByteArray rawDataModif = fileModif.readAll();
    QJsonDocument docModif(QJsonDocument::fromJson(rawDataModif));
    QJsonObject jsonModif = docModif.object();
    QString modif;
    QTextStream out(&fileModif);

    foreach (key, json.keys()) {
        if(json["id"] == id){
            if(json[key].type() == 1){
                json[key] = key.toInt() - modify.toInt();
            }
            else{
                 json[key] = modify;
            }
        }
    }
    //modif = json[key] + "\r\n\r\n";
    out << modif;
    fileModif.flush();
    fileModif.close();
}
