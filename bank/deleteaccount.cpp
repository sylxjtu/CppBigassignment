#include "deleteaccount.h"
#include "ui_deleteaccount.h"

DeleteAccount::DeleteAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteAccount)
{
    ui->setupUi(this);
}

DeleteAccount::~DeleteAccount()
{
    delete ui;
}

void DeleteAccount::on_buttonBox_accepted()
{
    b->deleteAccount(ui->accountLineEdit->text());
}
