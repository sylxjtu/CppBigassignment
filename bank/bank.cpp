#include "sqlite3.h"
#include <QtCore>
#include "bank.h"
#include <iostream>
#include "fileexists.h"
static int InitCallback(void *NotUsed, int argc, char **argv, char **azColName){
    return 0;
}

struct Validate_S{
    char* password;
    int ok;
};

static int ValidateCallback(void *data, int argc, char **argv, char **azColName){
    Validate_S* vs = (Validate_S*)data;
    if(QString(vs->password) == QString(argv[0]))
        vs->ok = 0;
    return 0;
}

Bank::Bank(const QString &name){
    dbname = name;
    QByteArray ba = name.toLatin1();
    int needinit = 0;
    if(!fileExists(ba.data()))
        needinit = 1;
    sqlite3_open(ba.data(),&interface);
    if(needinit)
        databaseInit();
}

Bank::~Bank(){
    sqlite3_close(interface);
}

int Bank::createAccount(const QString &ID, const QString &password){
    QString sql;
    char* err;
    QByteArray ba;

    if(findAccount(ID))
        return 1;

    sql = "INSERT INTO accounts (ID, password, money) VALUES (";
    sql = sql + ID;
    sql = sql + ",";
    sql = sql + password;
    sql = sql + ",0)";
    ba = sql.toLatin1();
    if(sqlite3_exec(interface, ba.data(), InitCallback, 0, &err) != SQLITE_OK){
        std::cerr << err;
        throw(err);
    }
    else
        return 0;
}

int Bank::deleteAccount(const QString &ID){
    QString sql;
    char* err;
    QByteArray ba;

    if(!findAccount(ID))
        return 1;

    sql = "DELETE FROM accounts WHERE ID=" + ID;
    ba = sql.toLatin1();
    sqlite3_exec(interface, ba.data(), InitCallback, 0, &err);
    sql = "DELETE FROM trades WHERE ID=" + ID;
    sqlite3_exec(interface, sql.toLatin1().data(), InitCallback, 0, &err);
    return 0;
}

int Bank::validate(const QString &ID, const QString &password){
    if(!findAccount(ID))
        return 1;
    Validate_S vs;
    QByteArray ba = password.toLatin1();
    vs.password = ba.data();
    vs.ok = 2;
    QString sql = "SELECT password FROM accounts WHERE ID=" + ID;
    QByteArray ba2 = sql.toLatin1();
    char* err;
    if(sqlite3_exec(interface, ba2.data(), ValidateCallback, &vs, &err) != SQLITE_OK){
        std::cerr << err;
        throw(err);
    }
    return vs.ok;
}
