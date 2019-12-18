#ifndef SCENE_CUSTOM_H
#define SCENE_CUSTOM_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include "rect_custom.h"

class scene_custom : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit scene_custom(QObject *parent = nullptr);
    void addCustomRect(Rect_Custom*);

signals:
    void item_Selected(Rect_Custom* rect);

private:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    bool _SignalToSend;
    int _timerSending;
    QVector<Rect_Custom*>* _listRect;
};

#endif // SCENE_CUSTOM_H
