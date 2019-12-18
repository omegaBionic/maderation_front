#include "scene_custom.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

scene_custom::scene_custom(QObject* parent): QGraphicsScene(parent)
{
    _SignalToSend = true;
    _timerSending = 0;
    _listRect = new QVector<Rect_Custom*>();
}



void scene_custom::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    _timerSending ++;
    if(_timerSending > 30){
        _SignalToSend = true;
        _timerSending = 0;
    }
    QGraphicsScene::mousePressEvent(event);
    if(event->buttons() == Qt::LeftButton)
    {
        qDebug() << "trying to find something...";
        QGraphicsItem* rect = this->mouseGrabberItem();
        if(rect != NULL){
            Rect_Custom* result = nullptr;
            qDebug() << "got something !";
            for(int i = 0; i<_listRect->count();i++){
                Rect_Custom* r = _listRect->at(i);

                if(r->x() == rect->x() && r->y() == rect->y()){
                    result = r;
                    qDebug() << "got something custom !!!!" << r->getID();
                }
            }
            if(result != nullptr){
                qDebug() << "sending signal...";
                emit this->item_Selected(result);
                _SignalToSend = false;
            }
        }

    }
}

void scene_custom::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){

    QGraphicsScene::mouseReleaseEvent(event);
    qDebug() << "resetting signal...";
    _SignalToSend = true;

}

void scene_custom::mouseMoveEvent(QGraphicsSceneMouseEvent *event){

    _timerSending ++;
    if(_timerSending > 30){
        _SignalToSend = true;
        _timerSending = 0;
    }
    QGraphicsScene::mousePressEvent(event);
    if(event->buttons() == Qt::LeftButton)
    {
        qDebug() << "trying to find something...";
        QGraphicsItem* rect = this->mouseGrabberItem();
        if(rect != NULL){
            Rect_Custom* result = nullptr;
            qDebug() << "got something !";
            for(int i = 0; i<_listRect->count();i++){
                Rect_Custom* r = _listRect->at(i);

                if(r->x() == rect->x() && r->y() == rect->y()){
                    result = r;
                    qDebug() << "got something custom !!!!" << r->getID();
                }
            }
            if(result != nullptr){
                qDebug() << "sending signal...";
                emit this->item_Selected(result);
                _SignalToSend = false;
            }
        }

    }

}

void scene_custom::addCustomRect(Rect_Custom * rect){
    _listRect->append(rect);
}
