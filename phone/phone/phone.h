#ifndef PHONE_H
#define PHONE_H
#include "mobile.h"
#include <QGraphicsScene>

//手机类（继承移动台类）

class Phone : public Mobile
{
public:
    virtual void trace(const QList<BaseStation*> &);
    Phone(QGraphicsScene* scene, const Keyboard& keyboard, const Screen& screen, const Chip& chip, int ID, const QString& model, double velocity, double frequency);
};

#endif // PHONE_H
