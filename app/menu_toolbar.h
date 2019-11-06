#ifndef MENU_TOOLBAR_H
#define MENU_TOOLBAR_H

#include <QWidget>

namespace Ui {
class menu_toolbar;
}

class menu_toolbar : public QWidget
{
    Q_OBJECT

public:
    explicit menu_toolbar(QWidget *parent = nullptr);
    ~menu_toolbar();

private:
    Ui::menu_toolbar *ui;
    void resizeEvent(QResizeEvent * event);
    int _width;
    int _height;
};

#endif // MENU_TOOLBAR_H
