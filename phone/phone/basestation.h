#ifndef BASESTATION_H
#define BASESTATION_H
#include <QString>
#include <QWidget>
#include <QGraphicsScene>
#include "drawable.h"

//基站类

class BaseStation : public Drawable
{
    QWidget* parent;
    double height;
    QString type;
    double datarate;
public:
    double circle;
    BaseStation(QGraphicsScene* parent, double height, const QString& type, double datarate, double circle);
    void drawCircle();
};

#endif // BASESTATION_H
