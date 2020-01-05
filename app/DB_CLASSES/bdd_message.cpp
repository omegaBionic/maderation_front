#include "bdd_message.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>
#include <QJsonArray>

bdd_MESSAGE::bdd_MESSAGE(QString creationDate, QString message, QString chatIoChat, QString userUsername, QString idMessage): bdd_global(QString("idMessage"), QString("message"))
{
    this->_creationDate = creationDate;
    this->_message = message;
    this->_chatIoChat = chatIoChat;
    this->_userUsername = userUsername;
    this->_idMessage = idMessage;
}
bdd_MESSAGE::bdd_MESSAGE(): bdd_global(QString("idMessage"), QString("message")){

}
bdd_MESSAGE::~bdd_MESSAGE(){

}
void bdd_MESSAGE::setCreationDate(QString creaDat){
    _creationDate = creaDat;
}
void bdd_MESSAGE::setMessage(QString msg){
    _message = msg;
}
void bdd_MESSAGE::setChatIoChat(QString chatIo){
    _chatIoChat = chatIo;
}
void bdd_MESSAGE::setUserUsername(QString usrN){
    _userUsername = usrN;
}
void bdd_MESSAGE::setIdMessage(QString idMsg){
    _idMessage = idMsg;
}

QString bdd_MESSAGE::getCreationDate(){
    return _creationDate;
}
QString bdd_MESSAGE::getMessage(){
    return _message;
}
QString bdd_MESSAGE::getChatIoChat(){
    return _chatIoChat;
}
QString bdd_MESSAGE::getUserUsername(){
    return _userUsername;
}
QString bdd_MESSAGE::getIdMessage(){
    return _idMessage;
}

QString bdd_MESSAGE::getId(){
    return "idMessage";
}
QString bdd_MESSAGE::getTable(){
    return "message";
}

void bdd_MESSAGE::addKey(QString key, QString value){
    bdd_global::addKey(key, value);
    _map.insert(key, value);
}

//QString creationDate, QString message, QString chatIoChat, QString userUsername, QString idMessage
QMap<QString, QString> bdd_MESSAGE::getDict() {
    this->addKey("creationDate", "\"S\":\""+ this->_creationDate + "\"");
    this->addKey("message", "\"S\":\""+ this->_message + "\"");
    this->addKey("chatIoChat", "\"S\":\""+ this->_chatIoChat + "\"");
    this->addKey("userUsername", "\"S\":\""+ this->_userUsername + "\"");
    this->addKey("idMessage", "\"S\":\""+ this->_idMessage + "\"");
    bdd_global::getDict();
    return _map;
}
