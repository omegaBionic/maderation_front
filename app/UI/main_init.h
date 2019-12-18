#ifndef MAIN_INIT_H
#define MAIN_INIT_H

#include <QMainWindow>

namespace Ui {
class main_init;
}

class main_init : public QMainWindow
{
    Q_OBJECT

public:
    explicit main_init(QWidget *parent = nullptr);
    ~main_init();
    void Check_folder();
    bool checkConnection();
    void Transfert_Tables();
    void endInit();

signals:
    void Initialized(int window);


private:
    void resize();
    void wait(int time, int interval);
    void wait(int time, int interval, int increment);
    void resizeEvent(QResizeEvent * event);
    bool event(QEvent *event);

    int _width;
    int _height;
    Ui::main_init *ui;
};

#endif // MAIN_INIT_H
