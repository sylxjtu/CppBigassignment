#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include "mobile.h"
#include "basestation.h"

//主窗口类

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void timerEvent(QTimerEvent *event);
    QList<Mobile*> mobiles;
    QList<BaseStation*> stations;
private slots:
    void on_newBase_triggered();
    void on_newPhone_triggered();
    void on_newPDA_triggered();
    void on_newPC_triggered();

private:
    Ui::MainWindow* ui;
    QGraphicsScene* scene;
};

#endif // MAINWINDOW_H
