#ifndef BDD_GLOBAL_H
#define BDD_GLOBAL_H
#include <QFile>
#include <QMap>

class bdd_global
{
public:
     explicit bdd_global(QString, QString);
    bdd_global();
    ~bdd_global();

    void setId(QString);
    void setTable(QString);

    QString getId();
    QString getTable();
    QMap<QString, QString> getDict();

private:
    QString _Id;
    QString _Table;
};

#endif // BDD_GLOBAL_H
