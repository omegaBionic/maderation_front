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
#include "encryption.h"

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

void Main_Login::on_btn_login_clicked()
{
    QString key = "23";
    Encryption *Chiffrement = new Encryption;// convertir le texte a chiffrer en QbyteArray avec : QString MonText = "test"; ---->  QByteArray MonText_converti = MonText.toUtf8(); avant .

    if(!CheckConnexion()==true)
    {
        qDebug("not connected");
    }
    else
    {
        qDebug("connected");
    }

       QString username= ui->lineEdit_user->text();
       QString pwd= ui->lineEdit_pwd->text();
       QString Pwd_encrypted;
       QString Pwd_Json_Encrypted;

       QString pwd_decrypted;
       QString pwd_Json_Decrypted;
       if(username != "" && pwd != ""){

           //Chiffrement pwd de la form

           Pwd_encrypted  = (Chiffrement->CypherEncrypt(pwd, &key)); //chiffrement
           //pwd_decrypted = (Chiffrement->CypherDecrypt(Pwd_encrypted, &key));//dechiffrement
            //------------------

           QNetworkAccessManager manager;
           QNetworkReply *response = manager.get(QNetworkRequest(QUrl("http://madera-api.maderation.net:8080/api/get/users?key=83c2c07ea1251a1a39ec46d52cbba19c")));
           QEventLoop event;
           connect(response,SIGNAL(finished()),&event,SLOT(quit()));
           event.exec();
           QString html = response->readAll();
           QJsonObject jsonObject= QJsonDocument::fromJson(html.toUtf8()).object();

           //Chiffrement pwd du json
           QString pwd_json = jsonObject.value("datas")["Items"]["password"]["S"].toString();
           Pwd_Json_Encrypted  = (Chiffrement->CypherEncrypt(pwd_json, &key));
          // pwd_Json_Decrypted = (Chiffrement->CypherDecrypt(Pwd_Json_Encrypted, &key));
            //------------------

           //comparaison des deux mdp chiffré
           if(Pwd_encrypted == Pwd_Json_Encrypted)
           {
               qDebug("identique");
           }
           else
           {
               qDebug("Differents");
           }
           if(username == jsonObject.value("datas")["Items"][0]["username"]["S"].toString() && pwd == jsonObject.value("datas")["Items"][0]["password"]["S"].toString()){
               Dialog_Critical* d = new Dialog_Critical(this,"success", "connexion réussie", "information");
               d->show();
           }else{
               Dialog_Critical* d = new Dialog_Critical(this,"Error", "connexion ratée, pwd is : " + pwd + "json is : "+jsonObject.value("datas")["Items"]["password"]["S"].toString(), "critical");
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

void Main_Login::on_lbl_pwd_linkActivated(const QString &link)
{
    QDesktopServices::openUrl(QUrl("https://www.google.com", QUrl::TolerantMode));
}

void Main_Login::on_lbl_create_account_linkActivated(const QString &link)
{
    QDesktopServices::openUrl(QUrl("https://www.google.com", QUrl::TolerantMode));
}

