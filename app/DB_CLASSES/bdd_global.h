#ifndef BDD_GLOBAL_H
#define BDD_GLOBAL_H

#include <QFile>
#include <QMap>

class bdd_global
{
public:
    bdd_global(QString, QString);
    bdd_global();
    virtual ~bdd_global();

    void setId(QString);
    void setTable(QString);

    virtual QString getId();
    virtual QString getTable();
    virtual QMap<QString, QString> getDict();
    virtual void addKey(QString key, QString value);

private:
    QString _Id;
    QString _Table;
protected:
    QMap<QString, QString> _map;
};

#endif // BDD_GLOBAL_H
