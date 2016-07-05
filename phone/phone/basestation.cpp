#include "basestation.h"
#include "basepath.h"

BaseStation::BaseStation(QGraphicsScene* scene, double height, const QString &type, double datarate, double circle):
    Drawable(scene, BASEPATH"base.png", 48, 48), height(height), type(type), datarate(datarate), circle(circle){}

//画出基站范围
void BaseStation::drawCircle(){
    scene->addEllipse(x - circle, y - circle, circle * 2, circle * 2, QPen(QColor(255, 0, 0)));
}
