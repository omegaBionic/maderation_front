#ifndef FORM_TEMPLATE_H
#define FORM_TEMPLATE_H

#include <QWidget>
#include "../DB_CLASSES/bdd_project.h"

namespace Ui {
class Form_template;
}

class Form_template : public QWidget
{
    Q_OBJECT

public:
    explicit Form_template(QWidget *parent = nullptr);
    explicit Form_template(QWidget *parent = nullptr, QString ressource= "./DATA_IMG/quot_default.png");
    ~Form_template();
    void setRessource(QString res);
    void setProject(bdd_PROJECT project);

signals:
    void cancelled();
    void validated(bdd_PROJECT project);

private slots:
    void on_pushButton_cancel_clicked();

    void on_pushButton_validate_clicked();

    void on_comboBox_client_currentIndexChanged(const QString &arg1);

private:
    Ui::Form_template *ui;
    void resizeEvent(QResizeEvent * event);
    int _width;
    int _height;
    QString _res;
    QString _baseProjectID;
    bdd_PROJECT _project;
};

#endif // FORM_TEMPLATE_H
