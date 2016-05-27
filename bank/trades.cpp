#include "trades.h"
#include "ui_trades.h"

Trades::Trades(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Trades)
{
    ui->setupUi(this);
}

Trades::~Trades()
{
    delete ui;
}
