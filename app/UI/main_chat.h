#ifndef MAIN_CHAT_H
#define MAIN_CHAT_H

#include <QMainWindow>
#include "menu_toolbar.h"
#include "../DB_CLASSES/bdd_chat.h"

namespace Ui {
class main_chat;
}

class main_chat : public QMainWindow
{
    Q_OBJECT

public:
    explicit main_chat(QWidget *parent = nullptr);
    explicit main_chat(QWidget *parent = nullptr, menu_toolbar *m = nullptr, QVector<bdd_CHAT>* listChat = nullptr, QString username = "toto");
    ~main_chat();

signals:
    void Initialized(int window);


private slots:
    void on_pushButton_power_clicked();

private:
    void resizeEvent(QResizeEvent * event);
    bool event(QEvent *event);

    QString _user;
    Ui::main_chat *ui;
    int _width;
    int _height;
    menu_toolbar* _menu;
};

#endif // MAIN_CHAT_H
