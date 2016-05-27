#include "newaccount.h"
#include "ui_newaccount.h"
#include <QMessageBox>

NewAccount::NewAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewAccount)
{
    ui->setupUi(this);
    QRegExp re(QString("^[0-9X]+$"));
    ui->accountLineEdit->setValidator(new QRegExpValidator(re,this));
    QRegExp re2(QString("^([0-9]){6}$"));
    ui->passwordLineEdit->setValidator(new QRegExpValidator(re2,this));
}

NewAccount::~NewAccount()
{
    delete ui;
}

void NewAccount::on_buttonBox_accepted()
{
    QMessageBox message;
    if(!ui->accountLineEdit->hasAcceptableInput() || !ui->passwordLineEdit->hasAcceptableInput()){
        message.setText(QString("输入格式错误"));
        message.exec();
        return;
    }
    b->createAccount(ui->accountLineEdit->text(),ui->passwordLineEdit->text());
    message.setText(QString("创建账号成功"));
    message.exec();
}
