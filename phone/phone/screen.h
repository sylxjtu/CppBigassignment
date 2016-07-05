#ifndef SCREEN_H
#define SCREEN_H
#include <QString>
#include <QColor>

//屏幕类

class Screen
{
public:
    double width, height;
    QColor color;
    double resx, resy;
    QString type;
    Screen(double width, double height, const QColor& color, double resx, double resy, const QString& type);
};

#endif // SCREEN_H
