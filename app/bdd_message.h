#ifndef BDD_MESSAGE_H
#define BDD_MESSAGE_H
#include <QFile>

class bdd_MESSAGE
{
public:
    bdd_MESSAGE(QString creationDate, QString message, QString chatIoChat, QString userUsername, QString idMessage);
    ~bdd_MESSAGE();

    void setCreationDate(QString);
    void setMessage(QString);
    void setChatIoChat(QString);
    void setUserUsername(QString);
    void setIdMessage(QString);

    QString getCreationDate();
    QString getMessage();
    QString getChatIoChat();
    QString getUserUsername();
    QString getIdMessage();

    QString _creationDate;
    QString _message;
    QString _chatIoChat;
    QString _userUsername;
    QString _idMessage;
};

#endif // BDD_MESSAGE_H
