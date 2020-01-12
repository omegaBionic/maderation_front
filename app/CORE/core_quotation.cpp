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

QString core_quotation::getClientName(int ID){
    QString result = "";
    api_get_request *api_get = new api_get_request();

    QVector<bdd_CLIENT> listClient = api_get->parse_file_client();
        for(int i = 0; i< listClient.count();i++){
            bdd_CLIENT client = listClient.at(i);
            if(client.getIdClient().toInt() == ID){
                result = client.getFirstName() + " " + client.getLastName();

        }
    }

    return result;

}


QString core_quotation::getClientCity(int ID){
    QString result = "";
    api_get_request *api_get = new api_get_request();

    QVector<bdd_CLIENT> listClient = api_get->parse_file_client();
        for(int i = 0; i< listClient.count();i++){
            bdd_CLIENT client = listClient.at(i);
            if(client.getIdClient().toInt() == ID){
                QVector<bdd_ADDRESS_CLIENT> listAddress = api_get->parse_file_address_client();
                    for(int i = 0; i< listAddress.count();i++){
                        bdd_ADDRESS_CLIENT address = listAddress.at(i);
                        if(client.getAddressIdAddress() == address.getIdAddressClient().toInt()){
                            result =  QString::number(address.getPostalCode()) + " " + address.getCity() + ", " + address.getCountry();

                    }
                }

        }
    }

    return result;

}


QString core_quotation::getClientAddress(int ID){
    QString result = "";
    api_get_request *api_get = new api_get_request();

    QVector<bdd_CLIENT> listClient = api_get->parse_file_client();
        for(int i = 0; i< listClient.count();i++){
            bdd_CLIENT client = listClient.at(i);
            if(client.getIdClient().toInt() == ID){
                QVector<bdd_ADDRESS_CLIENT> listAddress = api_get->parse_file_address_client();
                    for(int i = 0; i< listAddress.count();i++){
                        bdd_ADDRESS_CLIENT address = listAddress.at(i);
                        if(client.getAddressIdAddress() == address.getIdAddressClient().toInt()){
                            result =address.getStreet() ;

                    }
                }

        }
    }

    return result;

}


QString core_quotation::getClientPhone(int ID){
    QString result = "";
    api_get_request *api_get = new api_get_request();

    QVector<bdd_CLIENT> listClient = api_get->parse_file_client();
        for(int i = 0; i< listClient.count();i++){
            bdd_CLIENT client = listClient.at(i);
            if(client.getIdClient().toInt() == ID){
                result = client.getPhoneNumber();

        }
    }

    return result;

}

QVector<bdd_COMPONENT> core_quotation::getComponents(bdd_PRODUCT prod){

    QVector<bdd_COMPONENT> result;

   api_get_request* api = new api_get_request();
    QVector<bdd_COMPONENT> listComp = api->parse_file_component();
    for(int i = 0; i< listComp.count(); i++){
        bdd_COMPONENT comp = listComp.at(i);
        if(comp.getIDProduct() == prod.getIdProduct()){

            result.append(comp);
        }
    }

    return result;

}

QString core_quotation::getClientMail(int ID){
    QString result = "";
    api_get_request *api_get = new api_get_request();

    QVector<bdd_CLIENT> listClient = api_get->parse_file_client();
        for(int i = 0; i< listClient.count();i++){
            bdd_CLIENT client = listClient.at(i);
            if(client.getIdClient().toInt() == ID){
                result = client.getMail();

        }
    }

    return result;

}


QString core_quotation::getUserMail(QString username){
    QString result = "";
    api_get_request *api_get = new api_get_request();

    QVector<bdd_USER> listUser = api_get->parse_file_user();
        for(int i = 0; i< listUser.count();i++){
            bdd_USER user = listUser.at(i);
            if(user.getUsername() == username){
                result = user.getMail();

        }
    }

    return result;

}
