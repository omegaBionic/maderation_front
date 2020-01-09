#ifndef BDD_PROJECT_H
#define BDD_PROJECT_H
#include <QFile>
#include "bdd_global.h"

class bdd_PROJECT : public bdd_global
{
public:
    bdd_PROJECT(QString validationDate, bool validation, QString creationDate, bool isTemplate, QString idProject, QString userUsername, QString Title);
    bdd_PROJECT();
    virtual ~bdd_PROJECT();

    void setValidationDate(QString);
    void setValidation(bool);
    void setCreationDate(QString);
    void setIsTemplate(bool);
    void setIdProject(QString);
    void setuserUseName(QString);
    void setTitle(QString);

    QString getValidationDate();
    bool getValidation();
    QString getCreationDate();
    bool getIsTemplate();
    QString getIdProject();
    QString getUserUserName();

    QString getTitle();

    QString getId() override;
    QString getTable() override;
    QMap<QString, QString> getDict() override;
    void addKey(QString key, QString value) override;

private:

    QString _validationDate;
    bool _validation;
    QString _creationDate;
    bool _isTemplate;
    QString _idProject;
    QString _userUserName;
    QString _Title;
};

#endif // BDD_PROJECT_H
