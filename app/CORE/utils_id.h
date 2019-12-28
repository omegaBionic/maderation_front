#ifndef UTILS_ID_H
#define UTILS_ID_H

#include <QtDebug>
#include <QString>
#include <QUuid>
#include <QDir>


class utils_id
{
public:
    utils_id();
    ~utils_id();

    QString get_id();

private:
    QString id = "None";

    QDir dir;
    QFile file;
    QString pathData = "DATA/";
    QString fileId = "id.txt";
};

#endif // UTILS_ID_H
