#ifndef BDD_CATEGORY_H
#define BDD_CATEGORY_H

#include "bdd_global.h"
#include <QFile>

class bdd_CATEGORY : public bdd_global
{
public:
    bdd_CATEGORY(QString idCategory, QString label);
    bdd_CATEGORY();
    virtual ~bdd_CATEGORY();

    void setIdCategory(QString);
    void setLabel(QString);

    QString getIdCategory();
    QString getLabel();

    QString getId() override;
    QString getTable() override;
    QMap<QString, QString> getDict() override;

private:
    QString _idIdCategory;
    QString _label;
};

#endif // BDD_CATEGORY_H
