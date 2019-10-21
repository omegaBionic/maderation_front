#include "main_login.h"
#include "Init.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Check_folder();
    Network_Connection();
    QApplication a(argc, argv);
    Main_Login w;
    w.showFullScreen();
    return a.exec();
}
