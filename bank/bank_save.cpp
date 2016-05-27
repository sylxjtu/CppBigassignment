#include "bank.h"

int Bank::save(const QString &ID, double Amount){
    withdraw(ID, -Amount);
}
