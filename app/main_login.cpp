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
    QStringList User_username;
    QStringList User_Pwd;
    QStringList User_Email;
    QStringList User_FirstName;

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





           foreach (const QJsonValue & value, jsonArray)
           {
               QJsonObject obj = value.toObject();

               User_username.append(obj.value("username")["S"].toString());             

               User_Pwd.append(obj.value("password")["S"].toString());

               User_Email.append(obj.value("mail")["S"].toString());

               User_FirstName.append(obj.value("firstname")["S"].toString());

           }


           qDebug()<< User_username[0];
           qDebug()<< User_username[1];
           qDebug()<< User_username[2];

           foreach(const QString& var, User_username)
           {
               if(var == username )
               {
                   qDebug("username present!");
               }
               else
               {
                   qDebug("username non present");
               }

           }

           foreach(const QString& var, User_Pwd)
           {
               if(var == pwd )
               {
                   qDebug("mdp present");
               }
               else
               {
                   qDebug("mot de passe non present");
               }
           }



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
