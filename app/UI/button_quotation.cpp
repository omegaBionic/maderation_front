#include "button_quotation.h"

button_quotation::button_quotation(QWidget*parent): QPushButton(parent)
{
    QObject::connect(this, &button_quotation::clicked, this, &button_quotation::getClicked);
}

button_quotation::button_quotation(QWidget* parent, int ID, QString url, bool isDelete): QPushButton(parent)
{
    _ID = ID;
    _IconUrl = url;
    QObject::connect(this, &button_quotation::clicked, this, &button_quotation::getClicked);
    if(!isDelete){
        QObject::connect(this, &button_quotation::pressed, this, &button_quotation::isPressed);
        QObject::connect(this, &button_quotation::released, this, &button_quotation::isReleased);
    }
}



button_quotation::~button_quotation()
{
}

void button_quotation::getClicked(){
    emit clicked_ID(_ID);
}

void button_quotation::isPressed(){
    this->setStyleSheet("QPushButton {background-color: #00000000; border-radius: 30px; border: 10px solid #C8C8C8;}");
}

void button_quotation::isReleased(){
    this->setStyleSheet("QPushButton {background-color: #00000000; border-radius: 30px; border: 10px solid #7F7F7F;}");
}

void button_quotation::setID(int ID){
    _ID = ID;
}

int button_quotation::getID(){
    return _ID;
}


void button_quotation::setIconUrl(QString url){
    _IconUrl = url;
}

QString button_quotation::getIconUrl(){
    return _IconUrl;
}
