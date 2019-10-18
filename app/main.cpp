#include "main_login.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Main_Login w;
    w.showFullScreen();
    return a.exec();
}
