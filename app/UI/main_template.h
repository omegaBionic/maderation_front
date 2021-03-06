#ifndef MAIN_TEMPLATE_H
#define MAIN_TEMPLATE_H

#include <QMainWindow>
#include <QLabel>
#include "menu_toolbar.h"
#include "../UI/button_quotation.h"
#include "../DB_CLASSES/bdd_project.h"
#include "form_template.h"

namespace Ui {
class main_template;
}

class main_template : public QMainWindow
{
    Q_OBJECT


public:
    explicit main_template(QWidget *parent = nullptr);
    explicit main_template(QWidget *parent = nullptr, menu_toolbar* menu = nullptr, QVector<bdd_PROJECT>* listProject = nullptr, QString user = "");
    ~main_template();
    void showFull();

signals:
    void Initialized(int window);
    void button_clicked(int ID);
    void deleteProject(int ID);
    void openProject(bdd_PROJECT project);

private slots:
    void getButton_clicked(int ID);
    void getButtonDel_clicked(int ID);
    void tplCancelled();
    void tplValidated(bdd_PROJECT project);

    void on_pushButton_power_clicked();

private:
    void resizeEvent(QResizeEvent * event);
    bool event(QEvent *event);
    QVector<button_quotation*>* _listButton_quot;
    QVector<button_quotation*>* _listButton_del;
    QVector<QLabel*>* _listLabel_Button;
    QVector<bdd_PROJECT> _listProject;
    int _width;
    int _height;
    Ui::main_template *ui;
    menu_toolbar* _menu;
    Form_template* _tpl;
    QString _user;


};

#endif // MAIN_TEMPLATE_H
