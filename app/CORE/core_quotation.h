#ifndef CORE_QUOTATION_H
#define CORE_QUOTATION_H

#include "../app/DB_CLASSES/bdd_attribut.h";
#include "../app/DB_CLASSES/bdd_project.h"
#include "../app/DB_CLASSES/bdd_product.h"
#include "../app/CORE/api_get_request.h"
#include <QMap>


class core_quotation
{
public:
    core_quotation();
    QVector<bdd_ATTRIBUT> getAttributs(bdd_PROJECT project);
    bdd_ATTRIBUT getAttributByID(int ID);
    bdd_PRODUCT getProductByID(int ID);
    bdd_PRODUCT getProduct(QString element, QString type);
    QVector<bdd_PRODUCT> getAllProducts();
    bool setAttribut(bdd_PROJECT project, bdd_ATTRIBUT attribut);
    QString getLastAttributID();
    QString getClientName(int ID);
    QString getClientAddress(int ID);
    QString getClientCity(int ID);
    QString getClientPhone(int ID);
    QString getClientMail(int ID);
    QString getUserMail(QString username);
    QVector<bdd_COMPONENT> getComponents(bdd_PRODUCT);

};

#endif // CORE_QUOTATION_H
