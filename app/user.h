#ifndef USER_H
#define USER_H

#include <QFile>

class User
{
    public:
        User();
        QString GetUserData(QJsonArray MyJsonArray[], QString Username, QString Password);



};

#endif // USER_H
