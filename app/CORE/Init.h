#ifndef INIT_H
#define INIT_H

#include <QObject>
#include <QNetworkAccessManager>
#include "../UI/dialog_critical.h"


namespace Ui {
class Init;
}
class Init: public QObject
{
    Q_OBJECT
    //
 public :
    Init();
    void Check_folder();
    void Transfert_Tables();

    ~Init();

};





#endif // INIT_H
