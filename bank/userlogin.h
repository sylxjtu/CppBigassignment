#ifndef USERLOGIN_H
#define USERLOGIN_H

#include <QWidget>

namespace Ui {
class UserLogin;
}

class UserLogin : public QWidget
{
    Q_OBJECT

public:
    explicit UserLogin(QWidget *parent = 0);
    ~UserLogin();

private:
    Ui::UserLogin *ui;
};

#endif // USERLOGIN_H
