#ifndef WIDGET_CUSTOM_H
#define WIDGET_CUSTOM_H

#include <QWidget>

namespace Ui {
class widget_custom;
}

class widget_custom : public QWidget
{
    Q_OBJECT

public:
    explicit widget_custom(QWidget *parent = nullptr);
    ~widget_custom();

private:
    Ui::widget_custom *ui;
    void paintEvent(QPaintEvent *event);
};

#endif // WIDGET_CUSTOM_H
