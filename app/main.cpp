#include "main_login.h"
#include "Init.h"
#include "menu_toolbar.h"
#include "encryption.h"
#include <QApplication>
#include <QObject>

#include <QtNetwork>



int main(int argc, char *argv[])
{



   Init *Initializer = new Init;

   Initializer->Check_folder();

  //  Initializer->Network_Connection();

    //Network_Connection();
    QApplication a(argc, argv);
    Main_Login w;


    w.showFullScreen();

    return a.exec();

}


