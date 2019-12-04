#include "core_login.h"
#include <QJsonObject>
#include "../DB_CLASSES/bdd_user.h"

core_login::core_login()
{

}

void core_login::getUser(QString username, QString password){

    QFile file("data/jsonUser.json");
    file.open(QIODevice::ReadOnly);
    QByteArray rawData = file.readAll();

    // Parse document
    QJsonDocument doc(QJsonDocument::fromJson(rawData));

    // Get JSON object
    QJsonObject json = doc.object();

    QVector<bdd_USER> listUser;

    foreach (username, json.keys()) {
        if(json["username"] == username && json["password"] == password){

            listUser.append(bdd_USER(json["phoneNumber"].toString(), json["isActive"].toBool(), json["lastName"].toString(), json["password"].toString(), json["firstName"].toString(), json["addressId"].toInt(), json["mail"].toString(), json["username"].toString()));

        }

    }

}
