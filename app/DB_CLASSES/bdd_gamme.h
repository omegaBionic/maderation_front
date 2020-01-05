#ifndef BDD_GAMME_H
#define BDD_GAMME_H
#include <QFile>
#include "bdd_global.h"

class bdd_GAMME : public bdd_global
{
public:
    bdd_GAMME(QString idGamme, int productIdProduct, QString label);
    bdd_GAMME();
    virtual ~bdd_GAMME();

    void setIdGamme(QString);
    void setproductIdProduct(int);
    void setLabel(QString);

    QString getIdGamme();
    int getProductIdProduct();
    QString getLabel();

    QString getId() override;
    QString getTable() override;
    QMap<QString, QString> getDict() override;
    void addKey(QString key, QString value) override;

private:
    QString _idGamme;
    int _productIdProduct;
    QString _label;
};

#endif // BDD_GAMME_H
