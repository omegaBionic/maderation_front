#ifndef BDD_QUOTATION_H
#define BDD_QUOTATION_H
#include <QFile>

class bdd_QUOTATION
{
public:
    bdd_QUOTATION(bool validation, QString idQuotation, QString creationDate, bool isTemplate, QString userUsername, QString validationDate);
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

private:

    QString _validationDate;
    bool _validation;
    QString _creationDate;
    bool _isTemplate;
    QString _idQuotation;
    QString _userUserName;
};

#endif // BDD_QUOTATION_H
