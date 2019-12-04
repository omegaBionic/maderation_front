#ifndef CORE_MENU_H
#define CORE_MENU_H

#include <QObject>
#include <QVector>
#include "../DB_CLASSES/bdd_project.h"
#include "../DB_CLASSES/bdd_user.h"

#include "../CORE/api_get_request.h"


class core_menu : public QObject
{
    Q_OBJECT
public:
    explicit core_menu(QObject *parent = nullptr);
    QVector<bdd_PROJECT*>* getProject(bdd_USER user);
    void deleteProject(bdd_PROJECT project);

signals:

public slots:

private:
    api_get_request* _api;
};

#endif // CORE_MENU_H
