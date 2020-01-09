#include "core_messages.h"
#include "../app/DB_CLASSES/bdd_chat.h"
#include "../app/CORE/api_get_request.h"
#include "../app/CORE/api_post_request.h"
#include "../app/DB_CLASSES/bdd_message.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDir>
#include <fstream>
#include <QVector>
#include <QTextStream>
#include <QFile>
#include <QtDebug>
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrl>
#include <QEventLoop>
#include <QCoreApplication>
#include <QUrlQuery>

core_messages::core_messages(QObject *parent) : QObject(parent)
{

}

QVector<bdd_CHAT> core_messages::getChats(QString u)
{
    qDebug()<<u;
     api_get_request *parseChat = new api_get_request();
    QVector<bdd_CHAT>* result = new QVector<bdd_CHAT>();
    QVector<bdd_CHAT> listChat = parseChat->parse_file_chat();
    qDebug()<<listChat.count();

    QJsonArray myJsonArray;

    QJsonObject myObject;

    for(int i = 0; i < listChat.count(); i++)
    {
        bdd_CHAT chat = listChat.at(i);
        qDebug() << "autor : " + chat.getUserUsernameAsAutor();
        qDebug() << "receiver : " + chat.getUserUsernameAsReceiver();
        if(chat.getUserUsernameAsReceiver() == u || chat.getUserUsernameAsAutor() == u)
        {
            qDebug()<<"adding chat " + chat.getIdChat();
            result->append(chat);
        }
        else
        {
            qDebug("ok");
        }


    }

    return *result;
}

QVector<bdd_MESSAGE> core_messages::getMessages(QString c)
{
    qDebug()<<c;
     api_get_request *parseMessage = new api_get_request();

    QVector<bdd_MESSAGE> listMessage = parseMessage->parse_file_message();
    qDebug()<<listMessage.count();

    QVector<bdd_MESSAGE> result;
    QJsonArray myJsonArray;

    QJsonObject myObject;

    for(int i = 0; i < listMessage.count(); i++)
    {
        bdd_MESSAGE msg = listMessage.at(i);
        if(msg.getChatIoChat() == c)
        {
            result.append(msg);
        }

    }



    return result;

}

QString core_messages::getTime()
{

        // recupération de la date et de l'horloge actuelle
            QDate currentDate = QDate::currentDate();
            qDebug()<<currentDate;
            QTime currentTime = QTime::currentTime();
            qDebug()<<currentTime;
        // transformation en QString
            QString currentDateString = currentDate.toString();
            QString currentTimeString = currentTime.toString();
        // concaténation
            QString currentDateTime = currentDateString + " " + currentTimeString;

            qDebug()<<currentDateTime;

            return  currentDateTime;


}

int core_messages::getIDMsg()
{

        int result = 0;
        api_get_request *api_get = new api_get_request();

        QVector<bdd_MESSAGE> listMsg = api_get->parse_file_message();
        bool hasChanged = true;
        while(hasChanged){
            hasChanged = false;
            for(int i = 0; i< listMsg.count();i++){
                bdd_MESSAGE msg = listMsg.at(i);
                if(msg.getIdMessage().toInt() == result){
                    result++;
                    hasChanged = true;
                }
            }
        }

        return result;

}

QString core_messages::getIDChat()
{

        int result = 0;
        api_get_request *api_get = new api_get_request();

        QVector<bdd_CHAT> listChat = api_get->parse_file_chat();
        bool hasChanged = true;
        while(hasChanged){
            hasChanged = false;
            for(int i = 0; i< listChat.count();i++){
                bdd_CHAT chat = listChat.at(i);
                if(chat.getIdChat().toInt() == result){
                    result++;
                    hasChanged = true;
                }
            }
        }

        return QString::number(result);

}

bool core_messages::addMessage(bdd_USER u, bdd_CHAT c)
{

         QString currentDateTime = getTime();

         bdd_MESSAGE *myBddMessage = new bdd_MESSAGE();
         myBddMessage->setMessage("text");
         myBddMessage->setIdMessage("42");
         myBddMessage->setChatIoChat(c.getIdChat());
         myBddMessage->setCreationDate(currentDateTime);
         myBddMessage->setUserUsername(u.getUsername());



    try {
            api_post_request *api = new api_post_request();

            
            
//            api->modifyData(myBddMessage, "add");
       

        return true;
    } catch (...)
    {
        return false;
    }


}

bool core_messages::addChat(bdd_USER sender, bdd_USER receiver)
{

    QString currentDateTime = getTime();
    bdd_CHAT *myBddChat = new bdd_CHAT();
    myBddChat->setIdChat("1");
    myBddChat->setUserUsernameAsReceiver(receiver.getUsername());
    myBddChat->setCreationDate(currentDateTime);
    myBddChat->setTitle("test");

try {
        api_post_request *api = new api_post_request();



//        api->modifyData(myBddChat, "add");

       return true;
    } catch (...)
    {
       return false;
    }



}
