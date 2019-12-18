#ifndef MAIN_QUOTATION_H
#define MAIN_QUOTATION_H

#include <QMainWindow>
#include "menu_toolbar.h"
#include "../DB_CLASSES/bdd_project.h"
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
    explicit Main_Quotation(QWidget *parent = nullptr, menu_toolbar* menu = nullptr);

    ~Main_Quotation();


signals:
    void Initialized(int window);

private slots:
    void on_pushButton_menu_clicked();
    void Item_Updated(Rect_Custom* rect);

private:
    Ui::Main_Quotation *ui;
    void resizeEvent(QResizeEvent * event);
    bool event(QEvent *event);
    int _width;
    int _height;
    bool _isHided;
    menu_toolbar* _menu;


    scene_custom * _scene;
    QVector<Rect_Custom*>* _listRectangle;
};

#endif // MAIN_QUOTATION_H
