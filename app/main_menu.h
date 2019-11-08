#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QMainWindow>

namespace Ui {
class Main_Menu;
}

class Main_Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Main_Menu(QWidget *parent = nullptr);
    ~Main_Menu();

private:
    Ui::Main_Menu *ui;
};

#endif // MAIN_MENU_H
