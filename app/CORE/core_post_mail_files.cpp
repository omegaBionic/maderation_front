#include "core_post_mail_files.h"
#include <QNetworkAccessManager>
#include <QFile>


core_post_mail_files::core_post_mail_files(QObject* parent): QObject(parent)
{

}
void core_post_mail_files::upload()
{
    QNetworkAccessManager* manager = new QNetworkAccessManager;
    QFile* file = new QFile();
    file->setFileName("test.xml");
    if(!file->open(QFile::ReadOnly|QIODevice::Text)) {
        qDebug()<<"File failed to open - contact system administrator.";

    } else {
        QByteArray boundary = "---------------------------87142694621188";

        QNetworkRequest request( QUrl( "http://localhost/qt/post.php" ) );
        request.setRawHeader( "Referer", "http://localhost/" );
        request.setRawHeader( "Content-Type", "multipart/form-data; boundary=" + boundary ); //<-- seulement 27 tirets

        QFile file( "image.jpg" );
        file.open( QIODevice::ReadOnly );
        QByteArray aadata = "--" + boundary; //<-- mais 29 ici
        aadata += "\r\nContent-Disposition: form-data; name=\"upload\"; filename=\"image.jpg\";\r\n";
        // upload correspondant au nom du champ "file" du formulaire
        aadata += "Content-Type: image/jpeg\r\n\r\n" + file.readAll();
        aadata += "\r\n--" + boundary + "--\r\n"; //<-- et ici

        request.setRawHeader( "Content-Length", QString::number(aadata.size()).toUtf8() );

        QNetworkReply* reply = manager->post( request, aadata );

//        QObject::connect(reply,SIGNAL(finished()),this, SLOT(done())); // reply finished - close file
    }
}
