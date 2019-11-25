#ifndef FORM_MESSAGES_H
#define FORM_MESSAGES_H

#include <QWidget>
#include <QLabel>
#include "../DB_CLASSES/bdd_message.h"

namespace Ui {
class Form_messages;
}

class Form_messages : public QWidget
{
    Q_OBJECT

public:
    explicit Form_messages(QWidget *parent = nullptr);
    explicit Form_messages(QWidget *parent = nullptr, QVector<bdd_MESSAGE>* listMessage = nullptr, QString title = "this is a title", QString author = "toto");
    ~Form_messages();

private slots:
    void on_plainTextEdit_textChanged();

    void on_pushButton_clicked();

private:
    void resizeAll();
    void resizeEvent(QResizeEvent * event);
    QVector<bdd_MESSAGE>* _listMessage;
    QVector<QLabel*>* _listLabelMessages;
    QVector<QLabel*>* _listLabelAuthor;
    QVector<QLabel*>* _listLabelDate;

    QString _author;
    int _width;
    int _height;
    Ui::Form_messages *ui;
};

#endif // FORM_MESSAGES_H
