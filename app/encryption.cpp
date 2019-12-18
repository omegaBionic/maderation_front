#include "encryption.h"
#include "QObject"
#include <QDebug>

Encryption::Encryption()
{


}

 QString Encryption::CypherEncrypt(QString Data, QString Key[])
{

    QByteArray XorString = Data.toUtf8();
    QByteArray Encryption;

    for (qint32 i = 0; i < XorString.size(); i++)
    {

        Encryption += XorString[i] ^ (qint64(Key) + 1) %20;
    }
    qDebug()<< Encryption << endl;
    return Encryption;


}


QString Encryption::CypherDecrypt(QString Data_to_decrypt, QString Key[])
{
    QByteArray String_before_decrypt = Data_to_decrypt.toUtf8();
    QByteArray Decryption;

    for(qint32 i = 0; i < Data_to_decrypt.size(); i++ )
    {
        Decryption += String_before_decrypt[i] ^ (qint64(Key) +1) %20;

    }

    qDebug()<< Decryption << endl;
    return Decryption;
}


