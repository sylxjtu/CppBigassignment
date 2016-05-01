#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "account.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Account* user;

private slots:
    void on_UserLoginOrLogout_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
