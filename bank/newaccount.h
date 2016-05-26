#ifndef NEWACCOUNT_H
#define NEWACCOUNT_H

#include <QDialog>
#include "bank.h"

namespace Ui {
class NewAccount;
}

class NewAccount : public QDialog
{
    Q_OBJECT

public:
    explicit NewAccount(QWidget *parent = 0);
    ~NewAccount();
    Bank* b;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::NewAccount *ui;

};

#endif // NEWACCOUNT_H
