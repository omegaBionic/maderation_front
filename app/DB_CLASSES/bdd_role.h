#ifndef BDD_ROLE_H
#define BDD_ROLE_H
#include <QFile>
#include "bdd_global.h"

class bdd_ROLE : public bdd_global
{
public:
    bdd_ROLE(QString userUsernqme, QString idRole, QString label);
    bdd_ROLE();
    virtual ~bdd_ROLE();

    void setUserUsername(QString);
    void setIdRole(QString);
    void setLabel(QString);

    QString getUserUsername();
    QString getIdRole();
    QString getLabel();

    QString getId() override;
    QString getTable() override;
    QMap<QString, QString> getDict() override;
    void addKey(QString key, QString value) override;

private:

    QString _userUserName;
    QString _idRole;
    QString _label;
};

#endif // BDD_ROLE_H
