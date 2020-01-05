#ifndef CORE_LOGIN_H
#define CORE_LOGIN_H
#include <QString>
#include <QNetworkAccessManager>
#include <QFile>
#include <QJsonDocument>
#include <QDir>
#include <fstream>
#include <QObject>
#include <QTextStream>
#include "../DB_CLASSES/bdd_user.h"
#include "../DB_CLASSES/bdd_role.h"

class core_login : public QObject
{
    Q_OBJECT
public:
    core_login();

    bdd_USER getUser(QString username, QString password);
    QVector<bdd_ROLE> getRoles(bdd_USER* user);

};

#endif // CORE_LOGIN_H
