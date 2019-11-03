#include "user.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QFile>
#include <QObject>
User::User()
{

}

QString User::GetUserData(QJsonArray MyJsonArray, QString Username, QString Password)
{
    QStringList User_username;
    QStringList User_Pwd;
    QStringList User_Email;
    QStringList User_FirstName;

    foreach (const QJsonValue & value, MyJsonArray)
    {
        QJsonObject obj = value.toObject();

        User_username.append(obj.value("username")["S"].toString());

        User_Pwd.append(obj.value("password")["S"].toString());

        User_Email.append(obj.value("mail")["S"].toString());

        User_FirstName.append(obj.value("firstname")["S"].toString());

    }


    qDebug()<< User_username[0];
    qDebug()<< User_username[1];
    qDebug()<< User_username[2];

    foreach(const QString& var, User_username)
    {
        if(var == Username )
        {
            qDebug("username present!");
        }
        else
        {
            qDebug("username non present");
        }

    }

    foreach(const QString& var, User_Pwd)
    {
        if(var == Password )
        {
            qDebug("mdp present");
        }
        else
        {
            qDebug("mot de passe non present");
        }
    }
    return ("ok");
}
