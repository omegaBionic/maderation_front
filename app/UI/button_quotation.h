#ifndef BUTTON_QUOTATION_H
#define BUTTON_QUOTATION_H

#include <QPushButton>

class button_quotation : public QPushButton
{
    Q_OBJECT

public:
    explicit button_quotation(QWidget* parent = nullptr);
    explicit button_quotation(QWidget* parent = nullptr , int ID = 0, QString url = "DATA_IMG/quot_default.png",bool isDelete = false);
    ~button_quotation();
    void setIconUrl(QString url);
    void setID(int ID);
    int getID();
    QString getIconUrl();
signals:
    void clicked_ID(int id);

private slots:
    void getClicked();
    void isPressed();
    void isReleased();

private:
    int _ID;
    QString _IconUrl;
};

#endif // BUTTON_QUOTATION_H
