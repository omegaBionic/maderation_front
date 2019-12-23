#ifndef BDD_ATTRIBUT_H
#define BDD_ATTRIBUT_H
#include "bdd_global.h"

class bdd_ATTRIBUT : public bdd_global
{
public:
    bdd_ATTRIBUT(int length, int positionY, int width, int height, int productIdProduct, int orderIdProject, int positionX, int rotationY, int positionZ, int rotationX, int idAttribut);
    bdd_ATTRIBUT();
    virtual ~bdd_ATTRIBUT();

    void setLength(int);
    void setPositionY(int);
    void setWidth(int);
    void setHeight(int);
    void setProductIdProduct(int);
    void setOrderIdProject(int);
    void setPositionX(int);
    void setRotationY(int);
    void setPositionZ(int);
    void setRotationX(int);
    void setIdAttribut(int);

    int getLength();
    int getPositionY();
    int getWidth();
    int getHeight();
    int getProductIdProduct();
    int getOrderIdProject();
    int getPositionX();
    int getRotationY();
    int getPositionZ();
    int getRotationX();
    int getIdAttribut();

    QString getId() override;
    QString getTable() override;
    QMap<QString, QString> getDict() override;

private:

    int _length;
    int _positionY;
    int _width;
    int _height;
    int _productIdProduct;
    int _orderIdProject;
    int _positionX;
    int _rotationY;
    int _positionZ;
    int _rotationX;
    int _idAttribut;
};

#endif // BDD_ATTRIBUT_H
