#include "main_login.h"
#include "ui_main_login.h"
#include "user.h"
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

       if(username != "" && pwd != "")
       {
           QNetworkAccessManager manager;
           QNetworkReply *response = manager.get(QNetworkRequest(QUrl("http://madera-api.maderation.net:8080/api/get/users?key=83c2c07ea1251a1a39ec46d52cbba19c")));
           QEventLoop event;
           connect(response,SIGNAL(finished()),&event,SLOT(quit()));
           event.exec();
           QString html = response->readAll();
           QJsonDocument JsonDoc = QJsonDocument::fromJson(html.toUtf8());
           QJsonObject MyObject = JsonDoc.object();
           QJsonArray jsonArray = MyObject.value("datas")["Items"].toArray();

           User *DataUser = new User;
           DataUser->GetUserData(jsonArray ,username,pwd);



           if(username == MyObject.value("Item")["username"]["S"].toString() && pwd == MyObject.value("Item")["password"]["S"].toString()){
               Dialog_Critical* d = new Dialog_Critical(this,"success", "connexion réussie", "information");
               d->show();
           }
           else
           {
               Dialog_Critical* d = new Dialog_Critical(this,"Error", "connexion ratée", "critical");
               d->show();
           }


       }
       else if(username != "" && pwd == "")
       {
           Dialog_Critical* d = new Dialog_Critical(this,"Error", "Vous devez rentrer votre mot de passe !","critical" );
           d->show();
       }
       else if(username == "" && pwd != "")
       {
           Dialog_Critical* d = new Dialog_Critical(this,"Error","Vous devez rentrer votre identifiant !", "critical");
           d->show();
       }
       else if(username == "" && pwd == "")
       {
           Dialog_Critical* d = new Dialog_Critical(this,"Error", "Vous devez rentrer vos identifiants de connexion !","critical");
           d->show();
       }

}

void Main_Login::on_pushButton_2_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.google.com", QUrl::TolerantMode));
}
