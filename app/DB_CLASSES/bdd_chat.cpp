#include "bdd_chat.h"
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QJsonArray>

bdd_CHAT::bdd_CHAT(QString idChat, QString userUsernaleAsReceiver, QString userUsernaleAsAutor, QString creationDate, QString title): bdd_global(QString("id"), QString("table"))
{
    this->_idChat = idChat;
    this->_userUsernameAsReceiver = userUsernaleAsReceiver;
    this->_userUsernameAsAutor = userUsernaleAsAutor;
    this->_creationDate = creationDate;
    this->_title = title;
}

bdd_CHAT::bdd_CHAT(): bdd_global(QString("id"), QString("table")){

}
bdd_CHAT::~bdd_CHAT(){

}

void bdd_CHAT::setIdChat(QString idCh){
    _idChat = idCh;
}
void bdd_CHAT::setUserUsernameAsReceiver(QString userAsRecei){
    _userUsernameAsReceiver = userAsRecei;
}
void bdd_CHAT::setUserUsernameAsAutor(QString userAsRecei){
    _userUsernameAsAutor = userAsRecei;
}

void bdd_CHAT::setCreationDate(QString crDat){
    _creationDate = crDat;
}
void bdd_CHAT::setTitle(QString tle){
    _title = tle;
}

QString bdd_CHAT::getIdChat(){
    return _idChat;
}
QString bdd_CHAT::getUserUsernameAsReceiver(){
    return _userUsernameAsReceiver;
}
QString bdd_CHAT::getUserUsernameAsAutor(){
    return _userUsernameAsAutor;
}
QString bdd_CHAT::getCreationDate(){
    return _creationDate;
}
QString bdd_CHAT::getTitle(){
    return _title;
}

QString bdd_CHAT::getId(){
    return "idChat";
}
QString bdd_CHAT::getTable(){
    return "chat";
}

QMap<QString, QString> bdd_CHAT::getDict(){

    QFile file("DATA/jsonChat.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QMap<QString, QString> listChat;

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    int cpt = 0;

    foreach(const QJsonValue &v, itemsArray)
    {
        listChat.insert(itemsArray.at(cpt).toObject().keys()[cpt], v.toObject().value(v.toObject().keys()[cpt])["S"].toString());
        cpt += 1;
    }

    return listChat;
}
