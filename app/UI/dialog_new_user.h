#ifndef DIALOG_NEW_USER_H
#define DIALOG_NEW_USER_H

#include <QDialog>
#include "form_users.h"

namespace Ui {
class Dialog_new_user;
}

class Dialog_new_user : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_new_user(QWidget *parent = nullptr);
    ~Dialog_new_user();

private slots:
    void on_validate_clicked();

    void on_cancel_clicked();

private:
    Ui::Dialog_new_user *ui;
    void resizeEvent(QResizeEvent * event);
    int _width;
    int _height;
    Form_users* _form;
};

#endif // DIALOG_NEW_USER_H
