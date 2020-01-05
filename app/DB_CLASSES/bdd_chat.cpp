#include "bdd_chat.h"
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QJsonArray>

bdd_CHAT::bdd_CHAT(QString idChat, QString userUsernaleAsReceiver, QString userUsernaleAsAutor, QString creationDate, QString title): bdd_global(QString("idChat"), QString("chat"))
{
    this->_idChat = idChat;
    this->_userUsernameAsReceiver = userUsernaleAsReceiver;
    this->_userUsernameAsAutor = userUsernaleAsAutor;
    this->_creationDate = creationDate;
    this->_title = title;
}

bdd_CHAT::bdd_CHAT(): bdd_global(QString("idChat"), QString("chat")){

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

void bdd_CHAT::addKey(QString key, QString value){
    bdd_global::addKey(key, value);
    _map.insert(key, value);
}

QMap<QString, QString> bdd_CHAT::getDict() {
    this->addKey("idChat", "\"S\":\""+ this->_idChat + "\"");
    this->addKey("userUsernameAsAutor", "\"S\":\""+ this->_userUsernameAsAutor + "\"");
    this->addKey("userUsernameAsReceiver", "\"S\":\""+ this->_userUsernameAsReceiver + "\"");
    this->addKey("creationDate", "\"S\":\""+ this->_creationDate + "\"");
    this->addKey("title", "\"S\":\""+ this->_title + "\"");

    bdd_global::getDict();
    return _map;
}
