#ifndef CORE_POST_MAIL_FILES_H
#define CORE_POST_MAIL_FILES_H

#include <QObject>
#include <QNetworkReply>

class core_post_mail_files : public QObject
{
    Q_OBJECT
public:
    explicit core_post_mail_files();
    void send(QString toAddresses, QString ccAddress, QString subject, QString body1, QString body2);



public slots:
    void downloadFinished(QNetworkReply* reply);
};

#endif // CORE_POST_MAIL_FILES_H
