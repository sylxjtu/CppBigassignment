#include "cardlist.h"
#include "ui_cardlist.h"
#include "sqlite3.h"
#include "bank.h"
#include <iostream>

static int callback(void *data, int argc, char **argv, char **azColName){
    ((QListWidget*)data)->addItem(QString(argv[0]));
    return 0;
}

CardList::CardList(QWidget *parent, Bank *b) :
    QDialog(parent),
    b(b),
    ui(new Ui::CardList)
{
    ui->setupUi(this);
    sqlite3_exec(b->interface,"SELECT * FROM accounts", callback, ui->listWidget, 0);
}

CardList::~CardList()
{
    delete ui;
}
