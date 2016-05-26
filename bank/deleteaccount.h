#ifndef DELETEACCOUNT_H
#define DELETEACCOUNT_H

#include <QDialog>
#include "bank.h"

namespace Ui {
class DeleteAccount;
}

class DeleteAccount : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteAccount(QWidget *parent = 0);
    ~DeleteAccount();
    Bank* b;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DeleteAccount *ui;
};

#endif // DELETEACCOUNT_H
