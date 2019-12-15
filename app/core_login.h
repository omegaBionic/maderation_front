#ifndef CORE_LOGIN_H
#define CORE_LOGIN_H
#include <QString>
#include "DATA/jsonUser.json"
#include <QNetworkAccessManager>
#include <QFile>
#include <QJsonDocument>
#include <QDir>
#include <fstream>
#include <QVector>
#include <QTextStream>

class core_login
{
public:
    core_login();

    static void getUser(QString username, QString password);
};

#endif // CORE_LOGIN_H
