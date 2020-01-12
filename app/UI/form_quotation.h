#ifndef FORM_QUOTATION_H
#define FORM_QUOTATION_H

#include <QWidget>
#include <QGraphicsScene>

namespace Ui {
class Form_quotation;
}

class Form_quotation : public QWidget
{
    Q_OBJECT

public:
    explicit Form_quotation(QWidget *parent = nullptr);
    ~Form_quotation();

private:
    Ui::Form_quotation *ui;
    void refreshScene();
    void resizeEvent(QResizeEvent * event);
    QGraphicsScene* _scene;
    int _width;
    int _height;
};

#endif // FORM_QUOTATION_H
