#ifndef RECT_CUSTOM_H
#define RECT_CUSTOM_H

#include <QObject>
#include <QWidget>
#include <QGraphicsRectItem>
#include <QPen>

class Rect_Custom : public QGraphicsRectItem
{

public:
    explicit Rect_Custom(QGraphicsRectItem *parent = nullptr);
    explicit Rect_Custom(QGraphicsRectItem *parent = nullptr, int ID = 0, int X = 0, int Y=0, int Length=0, int width=0, QPen pen=QPen(Qt::black), QBrush brush=QBrush(Qt::black));

    int getLength();
    int getWidth();
    void setLength(int length);
    void setWidth(int width);
    int getID();

signals:

public slots:

private :
    int _ID;
    QString _type;
    QString _element;
    int _Length;
    int _Width;
};

#endif // RECT_CUSTOM_H
