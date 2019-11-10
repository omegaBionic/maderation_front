#ifndef BDD_CHAT_H
#define BDD_CHAT_H

#include <QFile>

class bdd_CHAT
{
public:
    bdd_CHAT(QString idChat, QString userUsernameAsReceiver, QString creationDate, QString title);
    bdd_CHAT();
    ~bdd_CHAT();

    void setIdChat(QString);
    void setUserUsernameAsReceiver(QString);
    void setCreationDate(QString);
    void setTitle(QString);

    QString getIdChat();
    QString getUserUsernameAsReceiver();
    QString getCreationDate();
    QString getTitle();

private:

    QString _idChat;
    QString _userUsernameAsReceiver;
    QString _creationDate;
    QString _title;
};

#endif // BDD_CHAT_H
