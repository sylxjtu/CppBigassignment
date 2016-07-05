#ifndef DRAWABLE_H
#define DRAWABLE_H
#include <QWidget>
#include <QLabel>
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QColor>

//重要特性 Drawable接口
//实现该接口的类会有draw()函数

class Drawable
{
public:
    QGraphicsScene* scene;
    QGraphicsPixmapItem* item;
    QString filename;
    int width, height;
    double x, y;
    QColor color;
    void draw();
    Drawable(QGraphicsScene *scene, QString filename, double width, double height);
};

#endif // DRAWABLE_H
