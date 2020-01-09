#ifndef CORE_USER_MANAGEMENT_H
#define CORE_USER_MANAGEMENT_H

#include "../DB_CLASSES/bdd_user.h"
#include "../DB_CLASSES/bdd_shop.h"
#include "../DB_CLASSES/bdd_role.h"

class core_user_management
{
public:
    core_user_management();
    QVector<bdd_USER> getUsers();
    QVector<bdd_ROLE> getUserRole(bdd_USER u);
    QVector<bdd_SHOP> getUserShop();
    bool modifyUser(bdd_USER modify);
    int getLastIDRole();
    bool addUser(bdd_USER u);
};

#endif // CORE_USER_MANAGEMENT_H
