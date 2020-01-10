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

QString core_template::getLastIDProject()
{

        int result = 0;
        api_get_request *api_get = new api_get_request();

        QVector<bdd_PROJECT> listProj = api_get->parse_file_project();
        bool hasChanged = true;
        while(hasChanged){
            hasChanged = false;
            for(int i = 0; i< listProj.count();i++){
                bdd_PROJECT proj = listProj.at(i);
                if(proj.getIdProject().toInt() == result){
                    result++;
                    hasChanged = true;
                }
            }
        }

        return QString::number(result);

}

QString core_template::getTime()
{

        // recupération de la date et de l'horloge actuelle
            QDate currentDate = QDate::currentDate();
            qDebug()<<currentDate;
            QTime currentTime = QTime::currentTime();
            qDebug()<<currentTime;
        // transformation en QString
            QString currentDateString = currentDate.toString();
            QString currentTimeString = currentTime.toString();
        // concaténation
            QString currentDateTime = currentDateString + " " + currentTimeString;

            qDebug()<<currentDateTime;

            return  currentDateTime;


}

QVector<QString> core_template::getClients()
{

    QVector<QString> result;

    QVector<bdd_CLIENT> listClient = _api->parse_file_client();
    qDebug() << listClient.count();
    for(int i = 0; i< listClient.count(); i++){
        bdd_CLIENT client = listClient.at(i);
        result.append(client.getFirstName());

    }

    return result;


}

QString core_template::getClient(QString name)
{

    QString result;

    QVector<bdd_CLIENT> listClient = _api->parse_file_client();
    qDebug() << listClient.count();
    for(int i = 0; i< listClient.count(); i++){
        bdd_CLIENT client = listClient.at(i);
        if(client.getFirstName() == name){
            result = client.getIdClient();
        }

    }

    return result;


}

QString core_template::getLastAttributID(){
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

void core_template::copyAttributs(QString baseID, QString newID){
    api_get_request* api = new api_get_request();
    QVector<bdd_ATTRIBUT> listAttribut = api->parse_file_attribut();
    for(int i = 0; i<listAttribut.count(); i++){
        bdd_ATTRIBUT attribut = listAttribut.at(i);
        if(attribut.getOrderIdProject() == baseID){
            bdd_ATTRIBUT newAttr = attribut;
            newAttr.setOrderIdProject(newID);
            newAttr.setIdAttribut(this->getLastAttributID());
            api_post_request* post = new api_post_request();
            newAttr.getDict();
            post->modifyData(newAttr, "add");

        }
    }

}
