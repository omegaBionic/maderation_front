#include "core_menu.h"

core_menu::core_menu(QObject *parent) : QObject(parent)
{
    _api = new api_get_request();

}


QVector<bdd_PROJECT*>* core_menu::getProject(bdd_USER user){
    QVector<bdd_PROJECT*>* result = new QVector<bdd_PROJECT*>();

    QVector<bdd_PROJECT> listProject = _api->parse_file_project();

    for(int i = 0; i< listProject.count(); i++){
        bdd_PROJECT project = listProject.at(i);
        if(project.getUserUserName() == user.getUsername()){
            result->append(&project);
        }
    }

    return result;
}


void core_menu::deleteProject(bdd_PROJECT project){

}
