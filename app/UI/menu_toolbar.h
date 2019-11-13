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
    void setWindow(int win);
    bool _isHided;


signals:
    void menu();
    void archive();
    void messages();
    void alerts();
    void logoff();


public slots:
    void on_btn_hide_clicked();

private slots:
    void on_btn_archive_clicked();

    void on_btn_alert_clicked();

    void on_btn_logoff_clicked();

    void on_btn_messages_clicked();

    void on_btn_menu_clicked();

private:
    Ui::menu_toolbar *ui;
    void resizeEvent(QResizeEvent * event);
    void resizeAll();
    int _width;
    int _height;

    /*
     * 0 : main_menu
     *
     */
    int _window;
};

#endif // MENU_TOOLBAR_H
