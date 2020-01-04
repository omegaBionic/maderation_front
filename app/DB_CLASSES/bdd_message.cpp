#include "bdd_message.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
#include <QFile>
#include <QJsonArray>

bdd_MESSAGE::bdd_MESSAGE(QString creationDate, QString message, QString chatIoChat, QString userUsername, QString idMessage): bdd_global(QString("id"), QString("table"))
{
    this->_creationDate = creationDate;
    this->_message = message;
    this->_chatIoChat = chatIoChat;
    this->_userUsername = userUsername;
    this->_idMessage = idMessage;
}
bdd_MESSAGE::bdd_MESSAGE(): bdd_global(QString("id"), QString("table")){

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

QMap<QString, QString> bdd_MESSAGE::getDict(){

    QFile file("DATA/jsonMessage.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    // Access properties

    QMap<QString, QString> listMessage;

    QJsonValue itemsValues = json.value("datas");
    QJsonArray itemsArray = itemsValues["Items"].toArray();

    int cpt = 0;

    foreach(const QJsonValue &v, itemsArray)
    {
        listMessage.insert(itemsArray.at(cpt).toObject().keys()[cpt], v.toObject().value(v.toObject().keys()[cpt])["S"].toString());
        cpt += 1;
    }

    return listMessage;
}
