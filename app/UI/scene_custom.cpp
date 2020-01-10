#include "scene_custom.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>

scene_custom::scene_custom(QObject* parent): QGraphicsScene(parent)
{
    _SignalToSend = true;
    _timerSending = 0;
    _listRect = new QVector<Rect_Custom*>();

}



void scene_custom::mousePressEvent(QGraphicsSceneMouseEvent *event) {
   //QMessageBox::information(0, "data", "X  : " + QString::number(event->scenePos().x()) + ", Y : " + QString::number(event->scenePos().y()));

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
        if(rect != nullptr){
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
                    int diffX =(r->pos().x()) -  event->scenePos().x();
                    int diffY =(r->pos().y()) -  event->scenePos().y();
//                    QMessageBox::information(0, "data", "diffX : " + QString::number(diffX));
                    r->setPos(event->scenePos().x() + diffX, event->scenePos().y()  + diffY );
//                    r->setY(event->scenePos().y());
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


void scene_custom::updateRect(int IDRect, int value, QString param){
    for(int i = 0; i < _listRect->count(); i++){
        Rect_Custom* rect = _listRect->at(i);
        if(rect->getID() == IDRect){
            if(param == "width"){
                rect->setWidth(value);
                rect->setRect(0,0, value, rect->getHeight());
            }else if (param =="height"){

                rect->setHeight(value);
                rect->setRect(0,0, rect->getWidth(),value);
            }else if (param == "length"){

                rect->setLength(value);
            }else if (param == "X"){

                rect->setX(value);
            }else if (param == "Y"){

                rect->setY(value);
            }else if (param == "Z"){

                rect->setZValue(value);
            }
        }
    }
}
