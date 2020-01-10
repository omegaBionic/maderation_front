#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QMainWindow>
#include <QLabel>
#include "menu_toolbar.h"
#include "../UI/button_quotation.h"
#include "../DB_CLASSES/bdd_project.h"

namespace Ui {
class Main_Menu;
}

class Main_Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Main_Menu(QWidget *parent = nullptr);
    explicit Main_Menu(QWidget *parent = nullptr, menu_toolbar* menu = nullptr, QVector<bdd_PROJECT>* listProject = nullptr);
    ~Main_Menu();
    void showFull();

signals:
    void Initialized(int window);
    void button_clicked(int ID);
    void deleteProject(int ID);

private slots:
    void getButton_clicked(int ID);
    void getButtonDel_clicked(int ID);

    void on_pushButton_power_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_horizontalSlider_valueChanged(int value);

private:
    void resizeEvent(QResizeEvent * event);
    void resizeAll();
    bool event(QEvent *event);
    void wait(int i, int j);
    QVector<button_quotation*>* _listButton_quot;
    QVector<button_quotation*>* _listButton_del;
    QVector<QLabel*>* _listLabel_Button;
    QVector<bdd_PROJECT>* _listProjectUser;
    int _width;
    int _height;
    Ui::Main_Menu *ui;
    menu_toolbar* _menu;
};

#endif // MAIN_MENU_H
