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
    void setWindow(QString win);
    bool _isHided;
    void setAdmin(bool val);


signals:
    void menu();
    void archive();
    void messages();
    void user_mgt();
    void logoff();


public slots:
    void on_btn_hide_clicked();

private slots:
    void on_btn_archive_clicked();

    void on_btn_logoff_clicked();

    void on_btn_messages_clicked();

    void on_btn_menu_clicked();

    void on_btn_user_clicked();

private:
    Ui::menu_toolbar *ui;
    void resizeEvent(QResizeEvent * event);
    void resizeAll();
    void resizeAllNonAdmin();
    int _width;
    int _height;
    bool _admin;

    /*
     * 0 : main_menu
     *
     */
    int _window;
};

#endif // MENU_TOOLBAR_H
