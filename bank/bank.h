#ifndef BANK_H
#define BANK_H

#include "sqlite3.h"
#include <QtCore>

class Bank{
    QString dbname;
    void databaseInit();
public:
    sqlite3* interface;
    Bank(const QString& name);
    ~Bank();
    int findAccount(const QString& ID);
    int createAccount(const QString& ID, const QString& password);
    int deleteAccount(const QString& ID);
    int validate(const QString& ID, const QString& password);
    int save(const QString& ID, double Amount);
    int withdraw(const QString& ID, double Amount);
    double query(const QString& ID);
};

#endif // BANK_H
