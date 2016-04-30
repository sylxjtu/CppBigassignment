#include "userlogin.h"
#include "ui_userlogin.h"

#include <QMessageBox>
#include "mainwindow.h"

UserLogin::UserLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserLogin)
{
    ui->setupUi(this);
}

UserLogin::~UserLogin()
{
    delete ui;
}

void UserLogin::on_pushButton_clicked()
{
    Account* r = new Account;
    Status s = r.login(ui->PasswordInput->text(), ui->CertInput->text(), ui->CertTypeInput->currentIndex());
    if(s == 0){
        Ui::MainWindow*(parentWidget())->user = r;
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("错误");
        msgBox.setInformativeText("");
        msgBox.exec();
    }
}
