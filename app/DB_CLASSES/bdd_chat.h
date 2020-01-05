#ifndef BDD_CHAT_H
#define BDD_CHAT_H

#include "bdd_global.h"
#include <QFile>

class bdd_CHAT : public bdd_global
{
public:
    bdd_CHAT(QString idChat, QString userUsernameAsReceiver, QString userUsernameAsAutor, QString creationDate, QString title);
    bdd_CHAT();
    virtual ~bdd_CHAT();

    void setIdChat(QString);
    void setUserUsernameAsReceiver(QString);
    void setUserUsernameAsAutor(QString);
    void setCreationDate(QString);
    void setTitle(QString);

    QString getIdChat();
    QString getUserUsernameAsReceiver();
    QString getUserUsernameAsAutor();
    QString getCreationDate();
    QString getTitle();

    QString getId() override;
    QString getTable() override;
    QMap<QString, QString> getDict() override;
    void addKey(QString key, QString value) override;

private:

    QString _idChat;
    QString _userUsernameAsReceiver;
    QString _userUsernameAsAutor;
    QString _creationDate;
    QString _title;
};

#endif // BDD_CHAT_H
