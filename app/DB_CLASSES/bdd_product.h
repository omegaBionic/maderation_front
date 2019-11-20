#ifndef BDD_PRODUCT_H
#define BDD_PRODUCT_H
#include <QFile>

class bdd_PRODUCT
{
public:
    bdd_PRODUCT(int supplierIdsupplier, QString idProduct, int minWidth, int defaultLength, QString label, QString productCode, int defaultHeight, int defaultWidth, QString material, int minLength, QString type);
    bdd_PRODUCT();
    ~bdd_PRODUCT();

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
    QString _type;
};

#endif // BDD_PRODUCT_H
