#include "bank.h"
#include "sqlite3.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    return 0;
}

void Bank::databaseInit(){
    sqlite3_exec(interface, "CREATE TABLE accounts (ID TEXT, password TEXT, money REAL)", callback, 0, 0);
    sqlite3_exec(interface, "CREATE TABLE trades (ID TEXT, money REAL, endmoney REAL)", callback, 0, 0);
}
