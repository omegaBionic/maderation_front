#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QMainWindow>
#include "menu_toolbar.h"

namespace Ui {
class Main_Menu;
}

class Main_Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Main_Menu(QWidget *parent = nullptr);
    explicit Main_Menu(QWidget *parent = nullptr, menu_toolbar* menu = NULL);
    ~Main_Menu();
    void showFull();

signals:
    void Initialized(int window);

private:
    void resizeEvent(QResizeEvent * event);
    bool event(QEvent *event);

    int _width;
    int _height;
    Ui::Main_Menu *ui;
    menu_toolbar* _menu;
};

#endif // MAIN_MENU_H
