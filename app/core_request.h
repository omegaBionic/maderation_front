#ifndef CORE_REQUEST_H
#define CORE_REQUEST_H

#include <QObject>
#include "user.h"

class core_request
{
public:
    core_request();
    QVector<QString> getRequest(User u);
    bool addRequest(QString title, QString message, User u);

};

#endif // CORE_REQUEST_H
