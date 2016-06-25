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

static int callback(void *data, int argc, char **argv, char **azColName){
    QTableWidget* obj = (QTableWidget*)data;
    int r = obj->rowCount();
    obj->setRowCount(r+1);
    for(int i=0; i<3; i++){
        obj->setItem(r, i, new QTableWidgetItem(argv[i]));
    }
    return 0;
}

void Trades::on_LineEdit_textChanged(const QString &arg1){
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    QString sql = (arg1.size() != 0 && b->findAccount(arg1))?
                ("SELECT * FROM trades WHERE ID=" + arg1)
               :("SELECT * FROM trades WHERE ID LIKE '%" + arg1 +"%'");
    sqlite3_exec(b->interface,sql.toLatin1().data(), callback, ui->tableWidget, 0);
}
