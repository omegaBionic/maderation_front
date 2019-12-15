#ifndef CORE_USER_MANAGEMENT_H
#define CORE_USER_MANAGEMENT_H

#include "../DB_CLASSES/bdd_user.h"

class core_user_management
{
public:
    core_user_management();
    QVector<bdd_USER> getUsers();
    bool modifyUser(bdd_USER modify);
    bool addUser(bdd_USER u);
};

#endif // CORE_USER_MANAGEMENT_H
