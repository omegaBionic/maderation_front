#ifndef MAIN_QUOTATION_H
#define MAIN_QUOTATION_H

#include <QMainWindow>
#include "menu_toolbar.h"
#include "../DB_CLASSES/bdd_project.h"
#include "../DB_CLASSES/bdd_attribut.h"
#include "form_template.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "rect_custom.h"
#include "scene_custom.h"

namespace Ui {
class Main_Quotation;
}

class Main_Quotation : public QMainWindow
{
    Q_OBJECT

public:
    explicit Main_Quotation(QWidget *parent = nullptr);
    explicit Main_Quotation(QWidget *parent = nullptr, menu_toolbar* menu = nullptr, bdd_PROJECT proj = bdd_PROJECT());

    ~Main_Quotation();


signals:
    void Initialized(int window);

private slots:
    void on_pushButton_menu_clicked();
    void Item_Updated(Rect_Custom* rect);

    void on_pushButton_power_clicked();

    void on_spinBox_Length_valueChanged(int arg1);

    void on_spinBox_Width_valueChanged(int arg1);

    void on_spinBox_Height_valueChanged(int arg1);

    void on_spinBox_X_valueChanged(int arg1);

    void on_spinBox_Y_valueChanged(int arg1);

    void on_spinBox_Z_valueChanged(int arg1);

    void on_comboBox_element_currentIndexChanged(int index);

    void on_comboBox_type_currentIndexChanged(int index);


    void on_spinBox_rotation_valueChanged(double arg1);

    void on_pushButton_save_clicked();

    void on_spinBox_Length_editingFinished();

    void on_spinBox_rotation_editingFinished();

    void on_spinBox_X_editingFinished();

    void on_spinBox_Height_editingFinished();

    void on_spinBox_Y_editingFinished();

    void on_spinBox_Z_editingFinished();

    void on_spinBox_Width_editingFinished();

    void on_pushButton_new_clicked();

    void on_pushButton_Copy_clicked();

    void on_pushButton_create_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_firstPlan_clicked();

private:
    Ui::Main_Quotation *ui;
    void resizeEvent(QResizeEvent * event);
    void configureComboBox();
    bool event(QEvent *event);
    void saveCurrentAttr();
    int _width;
    int _height;
    bool _isHided;
    bool _ModifiedBySignal;
    menu_toolbar* _menu;
    bdd_PROJECT _project;

    Rect_Custom* _rectSelected;
    scene_custom * _scene;
    QVector<Rect_Custom*>* _listRectangle;
};

#endif // MAIN_QUOTATION_H
