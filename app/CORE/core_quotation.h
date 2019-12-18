#ifndef CORE_QUOTATION_H
#define CORE_QUOTATION_H

#include "../app/DB_CLASSES/bdd_attribut";
#include "../app/DB_CLASSES/bdd_project.h"
#include "../app/DB_CLASSES/bdd_product.h"


class core_quotation
{
public:
    core_quotation();
    QVector<bdd_ATTRIBUT> getAttributs(bdd_PROJECT project);
    QVector<bdd_PRODUCT> getProduct(QString type);
};

#endif // CORE_QUOTATION_H
