#include "bdd_chat.h"
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>

bdd_CHAT::bdd_CHAT(QString idChat, QString userUsernaleAsReceiver, QString creationDate, QString title): bdd_global(QString("id"), QString("table"))
{
    this->_idChat = idChat;
    this->_userUsernameAsReceiver = userUsernaleAsReceiver;
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

    QFile file;
    file.setFileName("DATA/jsonChat.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);


    QJsonParseError jsonError;
    QJsonDocument flowerJson = QJsonDocument::fromJson(file.readAll(),&jsonError);
    if (jsonError.error != QJsonParseError::NoError){
    qDebug() << jsonError.errorString();
    }
    QList<QVariant> list = flowerJson.toVariant().toList();
    QMap<QString, QVariant> map = list[0].toMap();
    qDebug() << map["name"].toString();

    //return map;
}
