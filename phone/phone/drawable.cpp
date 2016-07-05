#include "drawable.h"
#include <QPixmap>
#include <QPainter>
#include <QGraphicsScene>

//Drawable接口初始化
Drawable::Drawable(QGraphicsScene *scene, QString filename, double width, double height):
    scene(scene), filename(filename), width(width), height(height), color(QColor(0, 0, 0, 0)){
    item = new QGraphicsPixmapItem;
    draw();
    scene->addItem(item);
}

//Drawable接口draw函数
//作用 更新图像对象
//1. 改变图像对象坐标
//2. 改变图像对象颜色
void Drawable::draw(){
    QPixmap img(filename);
    img = img.scaled(QSize(width, height));
    QPainter p(&img);
    p.setCompositionMode(QPainter::CompositionMode_SourceIn);
    p.fillRect(img.rect(), color.rgb());
    p.end();
    item->setPixmap(img);
    item->setPos(x, y);
}
