#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "keyboard.h"
#include "chip.h"
#include "screen.h"

#include "basestation.h"
#include "phone.h"
#include "pda.h"
#include "laptop.h"
#include <QInputDialog>

//计时事件callback函数
void MainWindow::timerEvent(QTimerEvent *event){
    for(QList<Mobile*>::iterator i = mobiles.begin(); i != mobiles.end(); i++){
        (*i)->trace(stations);
        (*i)->draw();
    }
}

//设置时间间隔为10ms
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(0, 0, 450, 450, this);
    ui->graphicsView->setScene(scene);
    this->startTimer(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//建立新基站
void MainWindow::on_newBase_triggered()
{
    double circle = QInputDialog::getDouble(this, "输入半径", "输入半径", 0, 0, 600);
    BaseStation* bs = new BaseStation(scene, 100, QString("Big base"), 233, circle);
    bs->x = QInputDialog::getDouble(this, "输入x坐标", "输入x坐标", 0, 0, 400);
    bs->y = QInputDialog::getDouble(this, "输入y坐标", "输入y坐标", 0, 0, 400);
    bs->drawCircle();
    ((Drawable*)(bs))->draw();
    stations.append(bs);
}

//建立新手机
void MainWindow::on_newPhone_triggered()
{
    Phone *p = new Phone(scene, Keyboard(10, 10, 10, QColor(255, 255, 255)),
          Screen(100, 100, QColor(0, 0, 0), .5, .5, "GOOD SCREEN"),
          Chip("GREAT CHIP", 1, 1, 1e99),
          0, "AWESOME PHONE", 1, 100);
    p->x = QInputDialog::getDouble(this, "输入x坐标", "输入x坐标", 0, 0, 400);
    p->y = QInputDialog::getDouble(this, "输入y坐标", "输入y坐标", 0, 0, 400);
    mobiles.append(p);
}

//建立新pda
void MainWindow::on_newPDA_triggered()
{
    PDA *p = new PDA(scene, Keyboard(10, 10, 10, QColor(255, 255, 255)),
          Screen(100, 100, QColor(0, 0, 0), .5, .5, "GOOD SCREEN"),
          Chip("GREAT CHIP", 1, 1, 1e99),
          0, "AWESOME PHONE", 1, 100);
    p->x = QInputDialog::getDouble(this, "输入x坐标", "输入x坐标", 0, 0, 400);
    p->y = QInputDialog::getDouble(this, "输入y坐标", "输入y坐标", 0, 0, 400);
    mobiles.append(p);
}

//建立新笔记本电脑
void MainWindow::on_newPC_triggered()
{
    Laptop *p = new Laptop(scene, Keyboard(10, 10, 10, QColor(255, 255, 255)),
                        Screen(100, 100, QColor(0, 0, 0), .5, .5, "GOOD SCREEN"),
                        Chip("GREAT CHIP", 1, 1, 1e99),
                        0, "AWESOME PHONE", 1, 100);
    p->x = QInputDialog::getDouble(this, "输入x坐标", "输入x坐标", 0, 0, 400);
    mobiles.append(p);
}
