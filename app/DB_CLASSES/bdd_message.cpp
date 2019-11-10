#include "bdd_message.h"
#include <QFile>

bdd_MESSAGE::bdd_MESSAGE(QString creationDate, QString message, QString chatIoChat, QString userUsername, QString idMessage)
{
    this->_creationDate = creationDate;
    this->_message = message;
    this->_chatIoChat = chatIoChat;
    this->_userUsername = userUsername;
    this->_idMessage = idMessage;
}
bdd_MESSAGE::bdd_MESSAGE(){

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
