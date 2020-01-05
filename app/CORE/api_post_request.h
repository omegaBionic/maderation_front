#ifndef API_POST_REQUEST_H
#define API_POST_REQUEST_H

#include <QtNetwork>
#include <QObject>
#include "utils_id.h"
#include "../DB_CLASSES/bdd_global.h"


class api_post_request : public QObject
{
    Q_OBJECT
public:
    api_post_request();

    void modifyData(bdd_global dataTable, QString modify);
    void pushData();


public slots:
    void downloadFinished(QNetworkReply* reply);

private:
     utils_id id;
};

#endif // API_POST_REQUEST_H
