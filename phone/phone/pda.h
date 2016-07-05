#ifndef PDA_H
#define PDA_H
#include "mobile.h"
#include <QGraphicsScene>

//PDA类（继承移动台类）

class PDA : public Mobile
{
public:
    virtual void trace(const QList<BaseStation*> &);
    PDA(QGraphicsScene* scene, const Keyboard& keyboard, const Screen& screen, const Chip& chip, int ID, const QString& model, double velocity, double frequency);
};

#endif // PDA_H
