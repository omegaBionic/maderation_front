#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class Encryption
{
public:
    Encryption();
    QString CypherEncrypt(QString Data,  QString Key[]);
     QString CypherDecrypt(QString Data_to_decrypt,  QString Key[]);
};

#endif // ENCRYPTION_H
