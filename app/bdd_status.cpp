#include "bdd_status.h"

bdd_STATUS::bdd_STATUS(QString status, QString datas)
{
this->_status = status;
this->_datas = datas;
}

void bdd_STATUS::setStatus(QString sta){
    _status = sta;
}
void bdd_STATUS::setDatas(QString dat){
    _datas = dat;
}

QString bdd_STATUS::getStatus(){
    return _status;
}
QString bdd_STATUS::getDatas(){
    return _datas;
}
