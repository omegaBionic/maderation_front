#include "core_quotation.h"
#include <QDebug>
#include "api_post_request.h"
#include "api_get_request.h"

core_quotation::core_quotation()
{
}

QVector<bdd_ATTRIBUT> core_quotation::getAttributs(bdd_PROJECT project)
{
        QVector<bdd_ATTRIBUT> result;

       api_get_request* api = new api_get_request();
        QVector<bdd_ATTRIBUT> listAttr = api->parse_file_attribut();
        qDebug() << listAttr.count();
        for(int i = 0; i< listAttr.count(); i++){
            bdd_ATTRIBUT attr = listAttr.at(i);
            if(attr.getOrderIdProject() == project.getIdProject()){

                result.append(attr);
            }
        }

        return result;
}

bdd_ATTRIBUT core_quotation::getAttributByID(int ID)
{
        bdd_ATTRIBUT result;

       api_get_request* api = new api_get_request();
        QVector<bdd_ATTRIBUT> listAttr = api->parse_file_attribut();
        qDebug() << listAttr.count();
        for(int i = 0; i< listAttr.count(); i++){
            bdd_ATTRIBUT attr = listAttr.at(i);
            if(attr.getIdAttribut().toInt() == ID){

                result = attr;
            }
        }

        return result;
}

bdd_PRODUCT core_quotation::getProductByID(int ID)
{
        bdd_PRODUCT result;

       api_get_request* api = new api_get_request();
        QVector<bdd_PRODUCT> listProd = api->parse_file_product();
        qDebug() << listProd.count();
        for(int i = 0; i< listProd.count(); i++){
            bdd_PRODUCT prod = listProd.at(i);
            if(prod.getIdProduct().toInt() == ID){

                result = prod;
            }
        }

        return result;
}


 QVector<bdd_PRODUCT> core_quotation::getAllProducts(){
     QVector<bdd_PRODUCT> result;

    api_get_request* api = new api_get_request();
     result = api->parse_file_product();

     return result;

 }

bdd_PRODUCT core_quotation::getProduct(QString element, QString type)
{
    bdd_PRODUCT result;

   api_get_request* api = new api_get_request();
    QVector<bdd_PRODUCT> listProd = api->parse_file_product();
    qDebug() << listProd.count();
    for(int i = 0; i< listProd.count(); i++){
        bdd_PRODUCT prod = listProd.at(i);
        if(prod.getMaterial() == element && prod.getType() == type){

            result = prod;
        }
    }

    return result;


}

bool core_quotation::setAttribut(bdd_PROJECT project, bdd_ATTRIBUT attribut)
{
    api_get_request *parseProject = new api_get_request();
    try
    {
        attribut.setOrderIdProject(project.getIdProject());
         return true;
    }

     catch (...)
    {
      return false;
    }
}

QString core_quotation::getLastAttributID(){
    int result = 0;
    api_get_request *api_get = new api_get_request();

    QVector<bdd_ATTRIBUT> listAttr = api_get->parse_file_attribut();
    bool hasChanged = true;
    while(hasChanged){
        hasChanged = false;
        for(int i = 0; i< listAttr.count();i++){
            bdd_ATTRIBUT attr = listAttr.at(i);
            if(attr.getIdAttribut().toInt() == result){
                result++;
                hasChanged = true;
            }
        }
    }

    return QString::number(result);

}
