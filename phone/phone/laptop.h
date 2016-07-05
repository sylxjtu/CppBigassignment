#ifndef LAPTOP_H
#define LAPTOP_H
#include "mobile.h"
#include <QGraphicsScene>

//笔记本电脑类（继承Mobile移动台类）

class Laptop : public Mobile
{
public:
    virtual void trace(const QList<BaseStation*> &);
    Laptop(QGraphicsScene* scene, const Keyboard& keyboard, const Screen& screen, const Chip& chip, int ID, const QString& model, double velocity, double frequency);
};

#endif // LAPTOP_H
