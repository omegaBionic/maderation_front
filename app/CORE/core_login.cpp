#include "core_login.h"
#include <QJsonObject>
#include "../CORE/api_get_request.h"
#include <QMessageBox>

core_login::core_login()
{

}

bdd_USER core_login::getUser(QString username, QString password){
    bdd_USER result;
    api_get_request* api = new api_get_request(nullptr);
    QVector<bdd_USER> listUsers = api->parse_file_user();

    for(int i = 0; i< listUsers.count();i++){
        bdd_USER user = listUsers.at(i);
        if(user.getPassword() == password && user.getUsername()==username){
            result = user;

        }
    }
    return result;
}


QVector<bdd_ROLE> core_login::getRoles(bdd_USER* user){
    QVector<bdd_ROLE> result;
    api_get_request* api = new api_get_request(nullptr);
    QVector<bdd_ROLE> roles = api->parse_file_role();

    for(int i = 0; i< roles.count();i++){
        bdd_ROLE role = roles.at(i);
        if(role.getUserUsername() == user->getUsername()){
            result.append(role);
        }
    }

    return result;
}
