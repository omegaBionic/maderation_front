#ifndef DIALOG_CRITICAL_H
#define DIALOG_CRITICAL_H

#include <QDialog>

namespace Ui {
class Dialog_Critical;
}

class Dialog_Critical : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Critical(QWidget *parent,QString title, QString text,QString icon);
    ~Dialog_Critical();

private slots:
    void on_validate_clicked();

    void on_cancel_clicked();

private:
    Ui::Dialog_Critical *ui;
};

#endif // DIALOG_CRITICAL_H
