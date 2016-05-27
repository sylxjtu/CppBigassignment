#ifndef TRADES_H
#define TRADES_H

#include <QDialog>

namespace Ui {
class Trades;
}

class Trades : public QDialog
{
    Q_OBJECT

public:
    explicit Trades(QWidget *parent = 0);
    ~Trades();

private:
    Ui::Trades *ui;
};

#endif // TRADES_H
