#ifndef API_GET_REQUEST_H
#define API_GET_REQUEST_H
#include <QtNetwork>
#include <QObject>


class api_get_request : public QObject
{
    Q_OBJECT
public:
    explicit api_get_request(QObject *parent = nullptr);
    static void get_tables();


signals:

public slots:

};

#endif // API_GET_REQUEST_H
