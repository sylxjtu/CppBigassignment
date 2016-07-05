#ifndef MOBILE_H
#define MOBILE_H
#include "keyboard.h"
#include "screen.h"
#include "chip.h"
#include "drawable.h"
#include <QList>
#include "basestation.h"
#include <QString>

//移动台类

class Mobile : public Drawable
{
    Keyboard keyboard;
    Screen screen;
    Chip chip;
    int ID;
    QString model;
    double frequency;
public:
    double velocity; //vx
    Mobile(QGraphicsScene *scene, const QString &filename, const Keyboard &keyboard, const Screen &screen, const Chip &chip, int ID, const QString &model, double velocity, double frequency);
    virtual void trace(const QList<BaseStation*> &) = 0;
};

#endif // MOBILE_H
