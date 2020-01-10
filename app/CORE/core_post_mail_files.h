#ifndef CORE_POST_MAIL_FILES_H
#define CORE_POST_MAIL_FILES_H

#include <QObject>


class core_post_mail_files
{
    Q_OBJECT
public:
    explicit core_post_mail_files();
    void send(QString toAddresses, QString body1, QString body2);
};

#endif // CORE_POST_MAIL_FILES_H
