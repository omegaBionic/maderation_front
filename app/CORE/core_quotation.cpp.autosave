#include "core_quotation.h"
#include <QDebug>

core_quotation::core_quotation()
{
}

 QVector<bdd_ATTRIBUT> core_quotation::getAttributs(bdd_PROJECT project)
 {
     qDebug()<<project.getIdProject();
      api_get_request *parseAttribut = new api_get_request();

     QVector<bdd_ATTRIBUT> listAttribut = parseAttribut->parse_file_attribut();
     qDebug()<<listAttribut.count();

     QJsonArray myJsonArray;

     QJsonObject myObject;

     for(int i ; i < listAttribut.count(); i++)
     {
         //qDebug()<<listAttribut.value(i).getIDProject();


         if(listAttribut.value(i).getOrderIdProject() != project.getIDProject)
         {
             qDebug()<<"pas ok";
             listAttribut.remove(i);
             i = 0;
         }
         else
         {
             qDebug("ok");
         }


     }

     return listAttribut;
 }

QVector<bdd_PRODUCT> core_quotation::getProduct(QString element, QString type)
{

   int choixInt;

   if(type == "type")
   {
       choixInt = 1;
   }
   else if(type == "material")
   {
       choixInt = 2;
   }
   else if (type == "typeEtMaterial")
   {
       choixInt = 3;
   }

   api_get_request *parseProduct = new api_get_request();
   QVector<bdd_PRODUCT> listProduct = parseProduct->parse_file_product();
   qDebug()<<element;
   qDebug()<<listProduct.count();

   for(int i ; i < listProduct.count(); i++)
   {
       switch(choixInt)
       {
            case 1:


                  if(listProduct.value(i).getType() != element)
                  {
                      qDebug()<<"pas ok";
                      listProduct.remove(i);
                      i = 0;
                  }
                  else
                  {
                      qDebug("ok");
                  }
                  return listProduct;
            break;
            case 2:
                  if(listProduct.value(i).getMaterial() != element)
                  {
                      qDebug()<<"pas ok";
                      listProduct.remove(i);
                      i = 0;
                  }
                  else
                  {
                      qDebug("ok");
                  }
                  return listProduct;
            break;
            case 3:
                  if(listProduct.value(i).getMaterial() != element && listProduct.value(i).getMaterial() != type)
                  {
                      qDebug()<<"pas ok";
                      listProduct.remove(i);
                      i = 0;
                  }
                  else
                  {
                      qDebug("ok");
                  }
                  return listProduct;
            break;

            default:
                  qDebug()<<"erreur de type rentre : soit type, soit material, soit typeEtMaterial";

       }
   }


}

bool core_quotation::setAttribut(bdd_PROJECT project, bdd_ATTRIBUT attribut)
{
    api_get_request *parseProject = new api_get_request();
    try
    {
        attribut.setOrderIdProject == project.getIdProject();
         return true;
    }

     catch (...)
    {
      return false;
    }
}

