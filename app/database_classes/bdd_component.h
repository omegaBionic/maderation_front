#ifndef BDD_COMPONENT_H
#define BDD_COMPONENT_H
#include <QFile>


class bdd_COMPONENT
{
public:
    bdd_COMPONENT(int supplierIdSupplier, QString idComponent, int categoryIdCategory, QString label);
    ~bdd_COMPONENT();

    void setSupplierIdSupplier(int);
    void setIdComponent(QString);
    void setCategoryIdCategory(int);
    void setLabel(QString);

    int getSupplierIdSupplier();
    QString getIdComponent();
    int getCategoryIdCategory();
    QString getLabel();

private:
    int _supplierIdSupplier;
    QString _idComponent;
    int _categoryIdCategory;
    QString _label;
};

#endif // BDD_COMPONENT_H
