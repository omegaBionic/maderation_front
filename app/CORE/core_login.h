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
#include "datauser.h"

class core_login : public QObject
{
    Q_OBJECT
public:
    core_login();

    static QVector<dataUser>getUser(QString username, QString password);

};

#endif // CORE_LOGIN_H
