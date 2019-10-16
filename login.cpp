#include "login.h"
#include "ui_login.h"
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

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_validate_clicked()
{
    QString username= ui->lineEdit_user->text();
    QString pwd= ui->lineEdit_pwd->text();
    if(username != "" && pwd != ""){
        QNetworkAccessManager manager;
        QNetworkReply *response = manager.get(QNetworkRequest(QUrl("http://15.188.130.85:8080/API/get/User?username="+username+"&password="+pwd)));
        QEventLoop event;
        connect(response,SIGNAL(finished()),&event,SLOT(quit()));
        event.exec();
        QString html = response->readAll();
        QJsonObject jsonObject= QJsonDocument::fromJson(html.toUtf8()).object();
        if(username == jsonObject.value("Item")["username"]["S"].toString() && pwd == jsonObject.value("Item")["password"]["S"].toString()){
            QMessageBox::information(this,"Success", "Connexion réussie");
        }else{
            QMessageBox::critical(this,"Wrong password", "Wrong password or username, please retry");
        }
    }
}

void Login::on_pushButton_2_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.google.com", QUrl::TolerantMode));
}



