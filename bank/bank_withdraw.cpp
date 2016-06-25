#include "sqlite3.h"
#include <QtCore>
#include "bank.h"
#include <iostream>

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    return 0;
}

int Bank::withdraw(const QString &ID, double Amount){
    double cur = query(ID);
    if(cur < 0)
        return 1;
    if(cur < Amount)
        return 2;
    QString sql = QString("UPDATE accounts SET money=")+QString::number(cur-Amount,'f',2)+" WHERE ID="+ID;
    QByteArray ba = sql.toLatin1();
    char* err;
    if(sqlite3_exec(interface, ba.data(), callback, 0, &err) != SQLITE_OK){
        std::cerr << err;
        throw(err);
    }
    sql = QString("INSERT INTO trades (ID, money, endmoney) VALUES (")+ID+
            ","+QString::number(-Amount,'f',2)+
            ","+QString::number(cur-Amount,'f',2)+
            ")";
    ba = sql.toLatin1();
    if(sqlite3_exec(interface, ba.data(), callback, 0, &err) != SQLITE_OK){
        std::cerr << err;
        throw(err);
    }
    return 0;
}
