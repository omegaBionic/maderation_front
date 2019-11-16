#include "./CORE/Init.h"
#include "./CONTROLLER/controller.h"
#include <QApplication>
#include <QObject>

#include <QtNetwork>



int main(int argc, char *argv[])
{

   Init *Initializer = new Init;

   Initializer->Check_folder();
   Initializer->Transfert_Tables();

    QApplication a(argc, argv);
    Controller ct;

    ct.init();

    return a.exec();

}


