#ifndef BDD_STATUS_H
#define BDD_STATUS_H

#include <QFile>


class bdd_STATUS
{
    public:
    bdd_STATUS(QString status, QString datas);
    bdd_STATUS();
        ~bdd_STATUS();

        void setStatus(QString);
        void setDatas(QString);

        QString getStatus();
        QString getDatas();

    private:
        QString _status;
        QString _datas;



};

#endif // BDD_STATUS_H
