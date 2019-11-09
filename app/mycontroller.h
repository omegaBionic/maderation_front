#ifndef MYCONTROLLER_H
#define MYCONTROLLER_H

#include <QDesktopServices>
#include <QMainWindow>

namespace Ui {
class myController;
}

class myController : public QMainWindow
{
    Q_OBJECT

public:
    explicit myController(QWidget *parent = nullptr);
    void authentificationVerify();

private:
    Ui::myController *ui;
};

#endif // MYCONTROLLER_H
