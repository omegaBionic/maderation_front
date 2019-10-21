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
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <QFile>
#include <sys/stat.h>
#include <QtNetwork>
#include <QJsonObject>
#include <QJsonDocument>
#include <QUrlQuery>
#include <QJsonValue>
#include <QDebug>

using namespace std;

void Check_folder()
{
    // verification de lexistance du dossier DATA

    int access (const char *path, int mode);
    ofstream objecfichier;

    char* folder = "DATA";
    if(mkdir(folder) == -1)
    {
        //existe pas
        cout<<"created"<<endl;
    }
    else
    {
        //existe
        cout<<"folder exist"<<endl;
    }

}

void Network_Connection()
{
    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(QUrl("http://http://madera-api.maderation.net:8080/API/get/status?key=179616f1a4cecab2a7eab481b84d076c")));
    QString html = response->readAll();
    QJsonObject jsonObject= QJsonDocument::fromJson(html.toUtf8()).object();

}
