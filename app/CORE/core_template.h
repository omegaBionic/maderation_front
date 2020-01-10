#ifndef CORE_TEMPLATE_H
#define CORE_TEMPLATE_H

#include <QObject>
#include "../DB_CLASSES/bdd_project.h"
#include "../DB_CLASSES/bdd_user.h"

#include "../CORE/api_get_request.h"
#include "../CORE/api_post_request.h"

class core_template : public QObject
{
    Q_OBJECT
public:
    explicit core_template(QObject *parent = nullptr);
    QVector<bdd_PROJECT>* getTemplates();
    QString getLastIDProject();
    QString getTime();
    QVector<QString> getClients();
    QString getClient(QString name);
    void copyAttributs(QString baseID, QString newID);
    QString getLastAttributID();

signals:

public slots:


private:
    api_get_request* _api;
};

#endif // CORE_TEMPLATE_H
