#include "bank.h"

int Bank::save(const QString &ID, double Amount){
    return withdraw(ID, -Amount);
}
