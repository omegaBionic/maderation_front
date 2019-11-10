#ifndef BDD_CATEGORY_H
#define BDD_CATEGORY_H

#include <QFile>

class bdd_CATEGORY
{
public:
    bdd_CATEGORY(QString idCategory, QString label);
    bdd_CATEGORY();
    ~bdd_CATEGORY();

    void setIdCategory(QString);
    void setLabel(QString);

    QString getIdCategory();
    QString getLabel();

private:
    QString _idIdCategory;
    QString _Label;
};

#endif // BDD_CATEGORY_H
