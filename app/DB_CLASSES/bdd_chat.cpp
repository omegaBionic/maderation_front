#include "bdd_chat.h"
#include <QFile>

bdd_CHAT::bdd_CHAT(QString idChat, QString userUsernaleAsReceiver,QString userUsernaleAsAutor, QString creationDate, QString title)
{
    this->_idChat = idChat;
    this->_userUsernameAsReceiver = userUsernaleAsReceiver;
    this->_userUsernameAsAutor = userUsernaleAsAutor;
    this->_creationDate = creationDate;
    this->_title = title;
}

bdd_CHAT::bdd_CHAT(){

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
