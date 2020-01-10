#include "rect_custom.h"

Rect_Custom::Rect_Custom(QGraphicsRectItem *parent) : QGraphicsRectItem(parent)
{

}

Rect_Custom::Rect_Custom(QGraphicsRectItem *parent, int ID, int X, int Y,int Height, int Length, int Width, QPen pen, QBrush brush) : QGraphicsRectItem(parent)
{
    _ID = ID;
    _Length = Length;
    _Width = Width;
    _Height = Height;
    this->setBrush(brush);
    this->setPen(pen);
    this->setPos(X, Y);
    this->setRect(0,0, _Length, _Width);

}


int Rect_Custom::getLength(){
    return _Length;
}

int Rect_Custom::getHeight(){
    return _Height;
}

int Rect_Custom::getWidth(){
    return _Width;
}

int Rect_Custom::getID(){
    return _ID;
}


void Rect_Custom::setLength(int Length){
    _Length = Length;
}

void Rect_Custom::setWidth(int Width){
    _Width = Width;
}

void Rect_Custom::setHeight(int h){
    _Height = h;
}
