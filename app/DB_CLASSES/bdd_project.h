#ifndef BDD_PROJECT_H
#define BDD_PROJECT_H
#include <QFile>
#include "bdd_global.h"

class bdd_PROJECT : public bdd_global
{
public:
    bdd_PROJECT(QString validationDate, bool validation, QString creationDate, bool isTemplate, QString idProject, QString userUsername);
    bdd_PROJECT();
    virtual ~bdd_PROJECT();

    void setValidationDate(QString);
    void setValidation(bool);
    void setCreationDate(QString);
    void setIsTemplate(bool);
    void setIdProject(QString);
    void setuserUseName(QString);

    QString getValidationDate();
    bool getValidation();
    QString getCreationDate();
    bool getIsTemplate();
    QString getIdProject();
    QString getUserUserName();

    QString getId() override;
    QString getTable() override;
    QMap<QString, QString> getDict() override;

private:

    QString _validationDate;
    bool _validation;
    QString _creationDate;
    bool _isTemplate;
    QString _idProject;
    QString _userUserName;
};

#endif // BDD_PROJECT_H
