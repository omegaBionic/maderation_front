#include "core_login.h"
#include <QJsonObject>
#include "datauser.h"
#include <QMessageBox>

core_login::core_login()
{

}

QVector<dataUser> core_login::getUser(QString username, QString password){
    QMessageBox msgBox;

    if(username == "" || password == ""){
        msgBox.setText("Veuillez remplir les champs obligatoires");
        msgBox.exec();
    }

    QFile fileUser("data/jsonUser.json");
    QFile fileRole("data/jsonRole.json");

    fileUser.open(QIODevice::ReadOnly);
    fileRole.open(QIODevice::ReadOnly);

    QByteArray rawDataUser = fileUser.readAll();
    QByteArray rawDataRole = fileRole.readAll();

    // Parse document
    QJsonDocument docUser(QJsonDocument::fromJson(rawDataUser));
    QJsonDocument docRole(QJsonDocument::fromJson(rawDataRole));

    // Get JSON object
    QJsonObject jsonUser = docUser.object();
    QJsonObject jsonRole = docRole.object();

    QVector<dataUser> myUser;

    foreach (jsonUser["username"], jsonUser.keys()) {
        if(jsonUser["username"] == username && jsonUser["password"] == password){
            foreach(username, jsonRole.keys()){
                if(jsonRole["userUsername"] == username){

                    myUser.append(dataUser(jsonRole["label"].toString(), jsonUser["phoneNumber"].toString(), jsonUser["isActive"].toBool(), jsonUser["lastName"].toString(), jsonUser["password"].toString(), jsonUser["firstName"].toString(), jsonUser["addressId"].toInt(), jsonUser["mail"].toString(), jsonUser["username"].toString()));
                    break;
                }
            }

        }
        else{
            msgBox.setText("Mauvais login ou mot de passe");
            msgBox.exec();
            break;
        }

    }

    return myUser;

}

