#include "mobile.h"
#include <QGraphicsScene>

Mobile::Mobile(QGraphicsScene *scene, const QString &filename, const Keyboard &keyboard, const Screen &screen, const Chip &chip, int ID, const QString &model, double velocity, double frequency):
    Drawable(scene, filename, 48, 48),
    keyboard(keyboard),
    screen(screen),
    chip(chip),
    ID(ID),
    model(model),
    frequency(frequency),
    velocity(velocity)
    {}
