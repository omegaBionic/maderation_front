#ifndef BDD_QUOTATION_H
#define BDD_QUOTATION_H
#include <QFile>
#include "bdd_global.h"

class bdd_QUOTATION : public bdd_global
{
public:
    bdd_QUOTATION(bool validation, QString idQuotation, QString creationDate, bool isTemplate, QString userUsername, QString validationDate);
    bdd_QUOTATION();
    ~bdd_QUOTATION();

    void setValidationDate(QString);
    void setValidation(bool);
    void setCreationDate(QString);
    void setIsTemplate(bool);
    void setIdQuotation(QString);
    void setuserUseName(QString);

    QString getValidationDate();
    bool getValidation();
    QString getCreationDate();
    bool getIsTemplate();
    QString getIdQuotation();
    QString getUserUserName();

    QString getId() override;
    QString getTable() override;
    QMap<QString, QString> getDict() override;
    void addKey(QString key, QString value) override;

private:

    QString _validationDate;
    bool _validation;
    QString _creationDate;
    bool _isTemplate;
    QString _idQuotation;
    QString _userUserName;
};

#endif // BDD_QUOTATION_H
