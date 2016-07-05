#ifndef CHIP_H
#define CHIP_H
#include <QString>

//芯片类

class Chip
{
public:
    QString type;
    double width, height, speed;
    Chip(const QString& type, double width, double height, double speed);
};

#endif // CHIP_H
