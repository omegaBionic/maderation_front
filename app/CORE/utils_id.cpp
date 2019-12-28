#include "utils_id.h"

utils_id::utils_id()
{
    qDebug() << "[utils_id] generate_id in running.";

    /* check if pathData exist, if not it creates it */
    if (dir.exists(pathData)){
        qDebug() << "[utils_id] pathData found.";
    } else {
        qDebug() << "[utils_id] pathData not found.";

        dir.mkpath(pathData);
        qDebug() << "[utils_id] pathData created.";
    }

    /* check if fileId exist, if not it creates it */
    QFile file(pathData + fileId);
    if(file.exists(pathData + fileId)){
        qDebug() << "[utils_id] fileId found.";
        /* read file */
        if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {

            id = file.readAll();
            qDebug() << "[utils_id] id read: '" << id << "'";
        } else {
            qDebug() << "[utils_id] failed to read file.";
        }
    } else { // gerenerate and write id in file
        qDebug() << "[utils_id] fileId not found.";

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
            qDebug() << "[utils_id] opened file for write.";
            QTextStream out(&file);

            id = QUuid::createUuid().toString();
            out << id;
            qDebug() << "[utils_id] id write in file.";
        } else {
            qDebug() << "[utils_id] failed to open file for write.";
        }
    }
    file.close();
    qDebug() << "[utils_id] file close.";



    qDebug() << "[utils_id] id is: '" << id << "'";
}

utils_id::~utils_id()
{

}

QString utils_id::get_id()
{
    return id;
}
