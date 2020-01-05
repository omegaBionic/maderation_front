#ifndef BDD_STATUS_H
#define BDD_STATUS_H

#include <QFile>
#include "bdd_global.h"

class bdd_STATUS : public bdd_global
{
    public:
    bdd_STATUS(QString status, QString datas);
    bdd_STATUS();
    virtual ~bdd_STATUS();

    void setStatus(QString);
    void setDatas(QString);

    QString getStatus();
    QString getDatas();

    QString getId() override;
    QString getTable() override;
    QMap<QString, QString> getDict() override;
    void addKey(QString key, QString value) override;

private:
    QString _status;
    QString _datas;



};

#endif // BDD_STATUS_H
