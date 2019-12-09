#include "bdd_global.h"

bdd_global::bdd_global(QString id, QString table)
{
    _Id = id;
    _Table = table;
}

void bdd_global::setId(QString Id){
    _Id = Id;
}

QString bdd_global::getId(){
    return _Id;
}

QMap<QString, QString> bdd_global::getDict(){
    QMap<QString, QString> map;
    map.insert("key", "value");
    return map;
}
