#include "core_user_management.h"
#include "../app/DB_CLASSES/bdd_user.h"
#include "../app/CORE/api_get_request.h"
#include "../app/CORE/api_post_request.h"
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

bool core_user_management::modifyUser(bdd_USER modify)
{
    bdd_USER *myBddUser = new bdd_USER();
    QString newUsername;
    QString newPhoneNumber;
    bool newIsActive;
    QString newLastName;
    QString newPassword;
    QString newFirstname;
    qint32 newIdAdress;
    QString newMail;


    newUsername = modify.getUsername();
    newMail = modify.getMail();
    newIdAdress = modify.getAddressIdAddress();
    newIsActive = modify.getIsActive();
    newLastName = modify.getLastName();
    newPassword = modify.getPassword();
    newPhoneNumber = modify.getPhoneNumber();
    newFirstname = modify.getFirstName();



    api_post_request *api_post = new api_post_request();
    try {
        myBddUser->setUsername(newUsername);
        myBddUser->setMail(newMail);
        myBddUser->setIdAddress(newIdAdress);
        myBddUser->setIsActive(newIsActive);
        myBddUser->setLastName(newLastName);
        myBddUser->setPassword(newPassword);
        myBddUser->setPhoneNumber(newPhoneNumber);
        myBddUser->setFirstName(newFirstname);

//        api_post_request *api_post_request = new api_post_request();
//        api_post_request->modifyData(myBddUser, "mod");

        return  true;
    } catch (...) {
        return false;
    }

}

bool core_user_management::addUser(bdd_USER u)
{
     api_post_request *api_post = new api_post_request();

     bdd_USER myBddUser;
     myBddUser.setMail(u.getMail());
     myBddUser.setIsActive(u.getIsActive());
     myBddUser.setLastName(u.getLastName());
     myBddUser.setPassword(u.getPassword());
     myBddUser.setFirstName(u.getFirstName());
     myBddUser.setIdAddress(u.getAddressIdAddress());
     myBddUser.setPhoneNumber(u.getPhoneNumber());
    try {
//       api_post->modifyData(myBddUser, "add");
        return   true;
    } catch (...) {
        return   false;
    }
}
