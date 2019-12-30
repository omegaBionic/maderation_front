#include "core_template.h"
#include <QJsonObject>

core_template::core_template()
{

}

QVector<bdd_PROJECT> core_template::getTemplates(){

   api_get_request *get = new api_get_request();

   QVector <bdd_QUOTATION> vQuotation;
   QVector <bdd_PROJECT> vProject;

   vQuotation = get->parse_file_quotation();

   for (int i = 0; i < vQuotation.size(); ++i) {
       if (vQuotation.indexOf("isTemplate") == true){

       }

   }

}
