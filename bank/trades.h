#ifndef TRADES_H
#define TRADES_H

#include <QDialog>
#include "bank.h"

namespace Ui {
class Trades;
}

class Trades : public QDialog
{
    Q_OBJECT

public:
    Bank* b;
    int cnt;
    explicit Trades(QWidget *parent = 0);
    ~Trades();

private slots:
    void on_LineEdit_textChanged(const QString &arg1);

private:
    Ui::Trades *ui;

};

#endif // TRADES_H
