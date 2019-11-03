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

bool Main_Login::CheckConnexion(){

    return true;
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

       if(username != "" && pwd != ""){

           QNetworkAccessManager manager;
           QNetworkReply *response = manager.get(QNetworkRequest(QUrl("http://madera-api.maderation.net:8080/API/getUser?username="+username+"&password="+pwd)));
           QEventLoop event;
           connect(response,SIGNAL(finished()),&event,SLOT(quit()));
           event.exec();
           QString html = response->readAll();
           QJsonObject jsonObject= QJsonDocument::fromJson(html.toUtf8()).object();

           //Chiffrement pwd du json
           QString pwd_json = jsonObject.value("Item")["password"]["S"].toString();
           QString Pwd_Json_Encrypted  = (Chiffrement->CypherEncrypt(pwd_json, &key));
           QString pwd_Json_Decrypted = (Chiffrement->CypherDecrypt(Pwd_Json_Encrypted, &key));
            //------------------

           //comparaison des deux mdp chiffré
           if(pwd_Json_Decrypted == Pwd_Json_Encrypted)
           {
               qDebug("identique");
           }
           else
           {
               qDebug("Differents");
           }

           if(username == jsonObject.value("Item")["username"]["S"].toString() && pwd == jsonObject.value("Item")["password"]["S"].toString()){
               Dialog_Critical* d = new Dialog_Critical(this,"success", "connexion réussie", "information");
               d->show();
           }else{
               Dialog_Critical* d = new Dialog_Critical(this,"Error", "connexion ratée", "critical");
               d->show();
           }

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
