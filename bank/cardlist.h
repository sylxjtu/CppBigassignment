#ifndef CARDLIST_H
#define CARDLIST_H

#include <QDialog>
#include "bank.h"

namespace Ui {
class CardList;
}

class CardList : public QDialog
{
    Q_OBJECT

public:
    Bank* b;
    explicit CardList(QWidget *parent, Bank* b);
    ~CardList();

private:
    Ui::CardList *ui;
};

#endif // CARDLIST_H
