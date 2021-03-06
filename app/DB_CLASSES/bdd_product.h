#ifndef BDD_PRODUCT_H
#define BDD_PRODUCT_H
#include <QFile>
#include "bdd_global.h"

class bdd_PRODUCT : public bdd_global
{
public:
    bdd_PRODUCT(int supplierIdsupplier, QString idProduct, int minWidth, int defaultLength, QString label, QString productCode, int defaultHeight, int defaultWidth, QString material, int minLength, QString type, int R, int G, int B);
    bdd_PRODUCT();
    virtual ~bdd_PRODUCT();

    void setSupplierIdSupplier(int);
    void setIdProduct(QString);
    void setMinWidth(int);
    void setDefaultLength(int);
    void setLabel(QString);
    void setProductCode(QString);
    void setDefaultHeight(int);
    void setDefaultWidth(int);
    void setMaterial(QString);
    void setMinLength(int);
    void setType(QString);
    void setR(int);
    void setB(int);
    void setG(int);


    int getSupplierIdSupplier();
    QString getIdProduct();
    int getMinWidth();
    int getDefaultLength();
    QString getLabel();
    QString getProductCode();
    int getDefaultHeight();
    int getDefaultWidth();
    QString getMaterial();
    int getMinLength();
    QString getType();
    int getR();
    int getG();
    int getB();

    QString getId() override;
    QString getTable() override;
    QMap<QString, QString> getDict() override;
    void addKey(QString key, QString value) override;

private:
    int _supplierIdSupplier;
    QString _idProduct;
    int _minWidth;
    int _defaultLength;
    QString _label;
    QString _productCode;
    int _defaultHeight;
    int _defaultWidth;
    QString _material;
    int _minLength;
    int _R;
    int _G;
    int _B;
    QString _type;
};

#endif // BDD_PRODUCT_H
