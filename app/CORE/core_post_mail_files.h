#ifndef CORE_POST_MAIL_FILES_H
#define CORE_POST_MAIL_FILES_H

#include <QObject>

class core_post_mail_files: public QObject
{
    Q_OBJECT
public:
    explicit core_post_mail_files(QObject* parent = nullptr);
    void upload();
};

#endif // CORE_POST_MAIL_FILES_H
