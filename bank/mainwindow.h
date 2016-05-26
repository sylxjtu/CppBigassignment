#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bank.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_newAccountAction_triggered();

    void on_deleteAccountAction_triggered();

    void on_submitPushButton_clicked();

    void on_queryAction_triggered();

private:
    Ui::MainWindow *ui;
    Bank *b;
};

#endif // MAINWINDOW_H
