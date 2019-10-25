#include "main_login.h"
#include "ui_main_login.h"
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

Main_Login::Main_Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Main_Login)
{
    ui->setupUi(this);

    this->setMinimumSize(640,360);




//    ui->menuBar->hide();
//    ui->progressBar->hide();
}

Main_Login::~Main_Login()
{
    delete ui;
}

void Main_Login::on_pushButton_connect_clicked()
{
    QString username= ui->lineEdit_user->text();
       QString pwd= ui->lineEdit_pwd->text();
       if(username != "" && pwd != ""){
           QNetworkAccessManager manager;
           QNetworkReply *response = manager.get(QNetworkRequest(QUrl("http://madera-api.maderation.net:8080/API/getUser?username="+username+"&password="+pwd)));
           QEventLoop event;
           connect(response,SIGNAL(finished()),&event,SLOT(quit()));
           event.exec();
           QString html = response->readAll();
           QJsonObject jsonObject= QJsonDocument::fromJson(html.toUtf8()).object();
           if(username == jsonObject.value("Item")["username"]["S"].toString() && pwd == jsonObject.value("Item")["password"]["S"].toString()){
               Dialog_Critical* d = new Dialog_Critical(this,"success", "connexion réussie", "information");
               d->show();
           }else{
               Dialog_Critical* d = new Dialog_Critical(this,"Error", "connexion ratée", "critical");
               d->show();
           }
       }
}

void Main_Login::on_pushButton_2_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.google.com", QUrl::TolerantMode));
}



