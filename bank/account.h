#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QtCore>

typedef QString ID_t;

enum UserCertType {
    IDCard,
    UndefinedType
};

enum Status {
    OperationSuccessful,
    CardIDInvalid,
    UserNotFound,
    PasswordNotMatch,
    CashAmountInvalid,
    BalanceNotEnough,
    CardFrozen,
    TransferAmountRestricted,
    TransferTimesRestricted,
    TargetCardIDInvalid,
    TargetCardAnduserNotMatch,
    ReapplyTimeOut,
    UserIDInvalid,
    UserNotLogIn,
    NoAvaliableNetworkConnection,
    UndefinedError
};

class Account
{
public:
    Account();
    ~Account();
    Status login(QString password, ID_t userCert, UserCertType userCertType = IDCard);
};

#endif // ACCOUNT_H
