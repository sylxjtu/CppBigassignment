#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newaccount.h"
#include "deleteaccount.h"
#include "bank.h"
#include "cardlist.h"

#include <QMessageBox>
#include <QRegExpValidator>
#include <QRegExp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    b = new Bank(QString("bank.db"));
    QRegExp re(QString("^[0-9X]+$"));
    ui->cardIDLineEdit->setValidator(new QRegExpValidator(re,this));
    QRegExp re2(QString("^([0-9]){6}$"));
    ui->passwordLineEdit->setValidator(new QRegExpValidator(re2,this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newAccountAction_triggered()
{
    NewAccount w;
    w.b = b;
    w.exec();
}

void MainWindow::on_deleteAccountAction_triggered()
{
    DeleteAccount w;
    w.b = b;
    w.exec();
}

void MainWindow::on_submitPushButton_clicked()
{
    QMessageBox message;
    if(!ui->cardIDLineEdit->hasAcceptableInput() || !ui->passwordLineEdit->hasAcceptableInput()){
        message.setText(QString("输入格式错误"));
        message.exec();
        return;
    }
    int va = b->validate(ui->cardIDLineEdit->text(),ui->passwordLineEdit->text());
    if(va==2) {
        message.setText(QString("密码错误"));
    }
    else if(va==1){
        message.setText(QString("账号不存在"));
    }
    else {
        if(ui->operationComboBox->currentIndex()==0){
            b->save(ui->cardIDLineEdit->text(),ui->amountDoubleSpinBox->value());
            message.setText(QString("存款成功"));
        }
        else if(ui->operationComboBox->currentIndex()==1){
            int r = b->withdraw(ui->cardIDLineEdit->text(),ui->amountDoubleSpinBox->value());
            message.setText(r==0?QString("取款成功"):QString("余额不足"));
        }
        else{
            double d = b->query(ui->cardIDLineEdit->text());
            message.setText(QString("余额:")+QString::number(d,'f',2));
        }
    }
    message.exec();
}

void MainWindow::on_accountListAction_triggered()
{
    CardList c(this,b);
    c.exec();
}

void MainWindow::on_queryAction_triggered()
{

}
