#include "core_template.h"

core_template::core_template(QObject *parent) : QObject(parent)
{

}

QVector<bdd_PROJECT>* core_template::getTemplates(){
    QVector<bdd_PROJECT>* result = new QVector<bdd_PROJECT>();

    QVector<bdd_PROJECT> listProject = _api->parse_file_project();
    qDebug() << listProject.count();
    for(int i = 0; i< listProject.count(); i++){
        bdd_PROJECT project = listProject.at(i);
        if(project.getIsTemplate() == true){

            result->append(project);
        }
    }

    return result;
}
