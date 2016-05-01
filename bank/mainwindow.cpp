#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "userlogin.h"
#include "account.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    user(NULL)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_UserLoginOrLogout_triggered()
{
    if(!user){
        UserLogin* UserLoginWidget = new UserLogin(this);
        setCentralWidget(UserLoginWidget);
    }
}
