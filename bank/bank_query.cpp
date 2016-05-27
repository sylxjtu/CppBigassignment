#include "sqlite3.h"
#include <QtCore>
#include "bank.h"
#include <iostream>

static int callback(void *data, int argc, char **argv, char **azColName){
    *(double*)data = QString(argv[0]).toDouble();
    return 0;
}

double Bank::query(const QString &ID){
    if(!findAccount(ID))
        return -1;
    QString sql = "SELECT money FROM accounts WHERE ID=" + ID;
    QByteArray ba2 = sql.toLatin1();
    char* err;
    double cur;
    if(sqlite3_exec(interface, ba2.data(), callback, &cur, &err) != SQLITE_OK){
        std::cerr << err;
        throw(err);
    }
    return cur;
}
