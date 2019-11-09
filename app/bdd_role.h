#ifndef BDD_ROLE_H
#define BDD_ROLE_H
#include <QFile>

class bdd_ROLE
{
public:
    bdd_ROLE(QString userUsernqme, QString idRole, QString label);
    ~bdd_ROLE();

    void setUserUsername(QString);
    void setIdRole(QString);
    void setLabel(QString);

    QString getUserUsername();
    QString getIdRole();
    QString getLabel();

private:

    QString _userUserName;
    QString _idRole;
    QString _label;
};

#endif // BDD_ROLE_H
