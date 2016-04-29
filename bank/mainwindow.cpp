#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "userlogin.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_UserLoginOrLogout_triggered()
{
    UserLogin* UserLoginWidget = new UserLogin(this);
    setCentralWidget(UserLoginWidget);
}
