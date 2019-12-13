#include "bdd_global.h"

bdd_global::bdd_global(QString id, QString table)
{
    _Id = id;
    _Table = table;
}

bdd_global::bdd_global()
{

}

bdd_global::~bdd_global()
{

}

void bdd_global::setId(QString Id){
    _Id = Id;
}

QString bdd_global::getTable() {
    return _Table;
}

QString bdd_global::getId(){
    return _Id;
}

QMap<QString, QString> bdd_global::getDict(){
    QMap<QString, QString> map;
    map.insert("key", "value");
    return map;
}
