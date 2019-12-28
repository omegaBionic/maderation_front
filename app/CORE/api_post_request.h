#ifndef API_POST_REQUEST_H
#define API_POST_REQUEST_H
#include <QtNetwork>
#include <QObject>
#include "utils_id.h"


class api_post_request : public QObject
{
    Q_OBJECT
public:
    api_post_request();

    static void modifyData(QString jsonFile, QString idKey, QString id, QString key, QString modify);
    static void pushData();


};

#endif // API_POST_REQUEST_H
