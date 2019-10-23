#ifndef API_CONNECT_H
#define API_CONNECT_H

#include <QObject>

class api_connect : public QObject
{
    Q_OBJECT
public:
    explicit api_connect(QObject *parent = nullptr);

signals:

public slots:
};

#endif // API_CONNECT_H
