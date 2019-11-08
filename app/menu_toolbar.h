#ifndef MENU_TOOLBAR_H
#define MENU_TOOLBAR_H

#include <QWidget>

namespace Ui {
class menu_toolbar;
}

// pos de la toolbar en général :
//    _menu->setGeometry(40*_width, 63*_height, 48*_width, 12*_height);

class menu_toolbar : public QWidget
{
    Q_OBJECT

public:
    explicit menu_toolbar(QWidget *parent = nullptr);
    ~menu_toolbar();
    bool _isHided;

public slots:
    void on_btn_hide_clicked();

private:
    Ui::menu_toolbar *ui;
    void resizeEvent(QResizeEvent * event);
    int _width;
    int _height;
};

#endif // MENU_TOOLBAR_H
