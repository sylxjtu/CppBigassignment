#include "screen.h"

Screen::Screen(double width, double height, const QColor &color, double resx, double resy, const QString &type):
    width(width),
    height(height),
    color(color),
    resx(resx),
    resy(resy),
    type(type){}
