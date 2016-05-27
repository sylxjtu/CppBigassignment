#include "deleteaccount.h"
#include "ui_deleteaccount.h"
#include <QMessageBox>

DeleteAccount::DeleteAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteAccount)
{
    ui->setupUi(this);
    QRegExp re(QString("^[0-9X]+$"));
    ui->accountLineEdit->setValidator(new QRegExpValidator(re,this));
}

DeleteAccount::~DeleteAccount()
{
    delete ui;
}

void DeleteAccount::on_buttonBox_accepted()
{
    QMessageBox message;
    if(!ui->accountLineEdit->hasAcceptableInput()){
        message.setText(QString("输入格式错误"));
        message.exec();
        return;
    }
    int status = b->deleteAccount(ui->accountLineEdit->text());
    message.setText(status?QString("不存在此账号"):QString("删除账号成功"));
    message.exec();
}
