#ifndef DIALOG_CHAT_H
#define DIALOG_CHAT_H

#include <QDialog>

namespace Ui {
class Dialog_chat;
}

class Dialog_chat : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_chat(QWidget *parent = nullptr, QString user = "");
    ~Dialog_chat();

private slots:
    void on_cancel_clicked();

    void on_validate_clicked();

private:
    Ui::Dialog_chat *ui;
    void resizeEvent(QResizeEvent * event);
    int _width;
    int _height;
    QString _author;
};

#endif // DIALOG_CHAT_H
