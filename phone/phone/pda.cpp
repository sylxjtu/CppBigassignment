#include "pda.h"
#include "basepath.h"
#include <cmath>
#include <QGraphicsScene>
#include "basestation.h"
#include <QList>

//运动轨迹为抛物线

void PDA::trace(const QList<BaseStation*>& l){
    x += velocity*2;
    y += y*velocity/100 + velocity;
    x = fmod(x, 400);
    y = fmod(y, 400);
    int flag = 0;
    for(QList<BaseStation*>::const_iterator i = l.begin(); i != l.end(); i++){
        if(sqrt(((*i)->x - x)*((*i)->x - x) + ((*i)->y - y)*((*i)->y - y)) < (*i)->circle){
            flag = 1;
            break;
        }
    }
    if(flag) color = QColor(0, 0, 0, 0); else color = QColor(255, 0, 0, 0);
}

PDA::PDA(QGraphicsScene* scene, const Keyboard &keyboard, const Screen &screen, const Chip &chip, int ID, const QString &model, double velocity, double frequency)
    :Mobile(scene, BASEPATH"pda.png", keyboard, screen, chip, ID, model, velocity, frequency){}
