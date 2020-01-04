#include "../UI/main_login.h"
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
#include <sys/stat.h>
#include <QDir>
#include "Init.h"
#include <QCoreApplication>



Init::Init()
{

}

Init::~Init()
{

}

void Init::Check_folder()
{
    // verification de lexistence du dossier DATA

    QDir folder("DATA");
    if(folder.exists())
    {
        //existe
        qDebug("folder exist");
    }
    else if (!folder.exists())
    {
        //existe pas
        folder.mkpath("."); // pour crée d'autre dossier a l'interieur du dossier DATA, garder le point si aucun dossier.
        qDebug("created");

    }

};

void Init::Transfert_Tables()
{

}




