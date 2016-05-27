#include "sqlite3.h"
#include "bank.h"
#include <QtCore>
#include <iostream>

static int callback(void *ret, int argc, char **argv, char **azColName){
    *(int*)ret = 1;
    return 0;
}

int Bank::findAccount(const QString &ID){
    QString sql = "SELECT * FROM accounts WHERE ID=" + ID;
    QByteArray ba = sql.toLatin1();
    char* err;
    int found = 0;
    if(sqlite3_exec(interface, ba.data(), callback, &found, &err) != SQLITE_OK){
        std::cerr << err;
        throw(err);
    }
    if(found)
        return 1;
    return 0;
}
