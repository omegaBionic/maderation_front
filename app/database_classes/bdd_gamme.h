#ifndef BDD_GAMME_H
#define BDD_GAMME_H
#include <QFile>

class bdd_GAMME
{
public:
    bdd_GAMME(QString idGamme, int productIdProduct, QString label);
    ~bdd_GAMME();

    void setIdGamme(QString);
    void setproductIdProduct(int);
    void setLabel(QString);

    QString getIdGamme();
    int getProductIdProduct();
    QString getLabel();

private:
    QString _idGamme;
    int _productIdProduct;
    QString _label;
};

#endif // BDD_GAMME_H
