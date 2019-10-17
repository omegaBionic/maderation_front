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
    explicit Dialog_Critical(QWidget *parent = nullptr);
    ~Dialog_Critical();

private:
    Ui::Dialog_Critical *ui;
};

#endif // DIALOG_CRITICAL_H
