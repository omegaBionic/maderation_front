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
    void sendFile(QString PathFile, QString FileName, QString format);
    void getFile(QString filename);



public slots:
    void downloadFinished(QNetworkReply* reply);
    void fileDownloaded(QNetworkReply* reply);
private:
    QString _fileName;
};

#endif // CORE_POST_MAIL_FILES_H
