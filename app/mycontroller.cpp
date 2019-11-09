#include "mycontroller.h"
#include <QDesktopServices>
#include <api_get_request.h>

myController::myController(QWidget *parent) : QMainWindow(parent),ui(new Ui::myController)
{
    ui->setupUi(this);
    QPixmap pix(":img/house.jpg");
    ui->lbl_pic->setPixmap(pix);
}

void myController::authentificationVerify(){
    QString username= ui->lineEdit_user->text();
    QString pwd= ui->lineEdit_pwd->text();
}
