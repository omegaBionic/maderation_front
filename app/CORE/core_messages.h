#ifndef CORE_MESSAGES_H
#define CORE_MESSAGES_H

#include <QtNetwork>
#include <QObject>
#include <../app/DB_CLASSES/bdd_chat.h>
#include <../app/DB_CLASSES/bdd_message.h>
#include <../app/DB_CLASSES/bdd_user.h>

class core_messages : public QObject
{
    Q_OBJECT
public:
    explicit core_messages(QObject *parent = nullptr);
    QVector<bdd_CHAT> getChats(QString u);
    QVector<bdd_MESSAGE> getMessages(QString c);
    bool addMessage(bdd_USER u, bdd_CHAT c);
    bool addChat(bdd_USER sender, bdd_USER receiver);
    int getIDMsg();
    QString getIDChat();
    QString getTime();
};

#endif // CORE_MESSAGES_H
