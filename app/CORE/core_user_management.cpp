#include "core_user_management.h"
#include <../app/DB_CLASSES/bdd_user.h>
#include <../app/CORE/api_get_request.h>
#include <../app/CORE/api_post_request.h>
#include <QVector>

core_user_management::core_user_management()
{

}

QVector<bdd_USER> core_user_management::getUsers()

{
    api_get_request *api_get = new api_get_request();

    QVector<bdd_USER> listUser = api_get->parse_file_user();
    qDebug()<<listUser.count();

    return listUser;


}

bool core_user_management::modifyUser(bdd_USER main, bdd_USER modified)
{
    api_post_request *api_post = new api_post_request();
    try {
        //api_post->modifyData()
        return  true;
    } catch (...) {
        return false;
    }

}

bool core_user_management::addUser(bdd_USER u)
{
     api_post_request *api_post = new api_post_request();

    try {
        api_post->pushData();
        return   true;
    } catch (...) {
        return   false;
    }
}
