#include "main_login.h"
#include "ui_main_login.h"
#include "ui_menu_toolbar.h"
#include "menu_toolbar.h"
#include "../DB_CLASSES/bdd_user.h"
#include <QDesktopServices>
#include <QUrl>
#include <QProcess>
#include <QMessageBox>
#include <QFile>
#include <QtNetwork>
#include <QJsonObject>
#include <QJsonDocument>
#include <QUrlQuery>
#include <QJsonValue>
#include <QDebug>
#include "../CORE/encryption.h"
#include "dialog_critical.h"

Main_Login::Main_Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Main_Login)
{
    ui->setupUi(this);
//    this->setWindowState(Qt::WindowFullScreen);
}

Main_Login::~Main_Login()
{
    delete ui;
}

bool Main_Login::event(QEvent * e)
{
    if(e->type() == QEvent::HoverEnter){
        emit Initialized(0);
    }

    return QMainWindow::event(e) ;
}

void Main_Login::showFull(){
    qDebug() << "affichage de la login";
    this->showFullScreen();
}

bool Main_Login::CheckConnexion()
{
    //connection a l'api
    qDebug("connection a l'api");

    QNetworkAccessManager manager;

    QUrl url("http://madera-api.maderation.net:8080/api/get/status?key=179616f1a4cecab2a7eab481b84d076c");
    QNetworkReply *response = manager.get(QNetworkRequest(url));

    QEventLoop event2;
    QObject::connect(response,SIGNAL(finished()),&event2,SLOT(quit()));
    event2.exec();
    QString html = response->readAll();

    //transformation du json pour lecture

     qDebug("Récuperation du json et transformation");
    //html ="{\"status\":true,\"datas\":\"key: OK, dynamodb: OK\"}";
    QJsonDocument jsonDoc= QJsonDocument::fromJson(html.toUtf8());
    QJsonObject MyObject = jsonDoc.object();
    MyObject.value(QString("status"));
    qDebug()<< MyObject.value(QString("status"));
    QJsonValue statut =  MyObject.value(QString("status"));

     qDebug("Vérification du statut de la  bdd");
     if(MyObject.value(QString("status")) == "true"){
         return true;
     }else {
         return false;
     }
}


void Main_Login::on_btn_forgot_clicked()
{
    emit forgot_password();
}

void Main_Login::on_btn_login_clicked()
{
    //récupérée par le controleur
    emit check_login(ui->lineEdit_user->text(), ui->lineEdit_pwd->text());



}



/*
 *
 * resize the window to the correct format
 *
 *
 */
void Main_Login::resizeEvent(QResizeEvent *){
    // format 16:9 only for the moment
    QRect win = this->geometry();

    _width = win.width()/128;
    _height = win.height()/72;

    ui->background->setGeometry(0*_width, 0*_height, 128*_width, 72*_height);
    ui->background->setPixmap(QPixmap(":/pictures/img/background_login.png").scaled(128*_width, 72*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    ui->line->setGeometry(102*_width, 50*_height, 20*_width, 5*_height);
    ui->btn_login->setGeometry(100*_width, 45*_height, 24*_width, 3*_height);
    ui->lineEdit_pwd->setGeometry(100*_width, 30*_height, 24*_width, 4*_height);
    ui->lineEdit_user->setGeometry(100*_width, 25*_height, 24*_width, 4*_height);
    ui->label_title->setGeometry(102*_width, 5*_height, 18*_width, 18*_height);
    ui->label_title->setPixmap(QPixmap(":/pictures/img/logo madera.png").scaled(18*_width, 18*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->chk_remember->setGeometry(100*_width, 38*_height, 24*_width, 2*_height);
    ui->btn_forgot->setGeometry(102*_width, 55*_height, 20*_width, 2*_height);
    ui->label_2->setGeometry(0*_width, 0*_height, 95*_width, 72*_height);
    ui->label_2->setPixmap(QPixmap(":/pictures/img/house.jpg").scaled(95*_width, 72*_height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    ui->pushButton_power->setGeometry(124*_width, 0*_height ,4*_width, 4*_height);

}


void Main_Login::on_pushButton_power_clicked()
{
    Dialog_Critical *c = new Dialog_Critical(this,"Exit ?", "êtes vous sûr de vouloir quitter l'application ?", "question");
    int result = c->exec();
    qDebug() << "result du exit : "<< result;
    if(result == QDialog::Accepted){
        this->close();
    }
}
