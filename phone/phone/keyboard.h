#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <QColor>

//键盘类

class Keyboard
{
public:
    int KeyNum;
    double width;
    double height;
    QColor color;
    Keyboard(int KeyNum, double width, double height, const QColor& color);
};

#endif // KEYBOARD_H
