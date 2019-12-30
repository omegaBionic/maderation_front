#include "core_template.h"
#include <QJsonObject>

core_template::core_template()
{

}

QVector<bdd_PROJECT> core_template::getTemplates(){

   api_get_request *get = new api_get_request();

   QVector <bdd_QUOTATION> quot;

   quot = get->parse_file_quotation();

   for (int i = 0; i < quot.size(); ++i) {
       if (quot.indexOf("isTemplate") == true){

       }

   }

}
