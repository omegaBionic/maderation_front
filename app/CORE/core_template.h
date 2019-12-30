#ifndef CORE_TEMPLATE_H
#define CORE_TEMPLATE_H
#include <QVector>
#include "../DB_CLASSES/bdd_project.h"
#include "../DB_CLASSES/bdd_client.h"
#include "../CORE/api_get_request.h"
#include <QJsonDocument>


class core_template
{
public:
    core_template();

    QVector<bdd_PROJECT> getTemplates();

    QVector<bdd_CLIENT> getClients();

};

#endif // CORE_TEMPLATE_H
