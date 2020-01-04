#ifndef CORE_QUOTATION_H
#define CORE_QUOTATION_H

#include "../app/DB_CLASSES/bdd_attribut.h";
#include "../app/DB_CLASSES/bdd_project.h"
#include "../app/DB_CLASSES/bdd_product.h"
#include "../app/CORE/api_get_request.h"


class core_quotation
{
public:
    core_quotation();
    QVector<bdd_ATTRIBUT> getAttributs(bdd_PROJECT project);
    QVector<bdd_PRODUCT> getProduct(QString element, QString type);
    bool setAttribut(bdd_PROJECT project, bdd_ATTRIBUT attribut);
};

#endif // CORE_QUOTATION_H
