#ifndef FORM_TEMPLATE_H
#define FORM_TEMPLATE_H

#include <QWidget>

namespace Ui {
class Form_template;
}

class Form_template : public QWidget
{
    Q_OBJECT

public:
    explicit Form_template(QWidget *parent = nullptr);
    explicit Form_template(QWidget *parent = nullptr, QString ressource= "./DATA_IMG/quot_default.png");
    ~Form_template();
    void setRessource(QString res);

signals:
    void cancelled();
    void validated();

private slots:
    void on_pushButton_cancel_clicked();

    void on_pushButton_validate_clicked();

private:
    Ui::Form_template *ui;
    void resizeEvent(QResizeEvent * event);
    int _width;
    int _height;
    QString _res;
};

#endif // FORM_TEMPLATE_H
