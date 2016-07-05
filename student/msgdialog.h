#ifndef MSGDIALOG_H
#define MSGDIALOG_H

#include <QWidget>
#include<QAbstractButton>
#include<QEventLoop>
namespace Ui {
class MsgDialog;
}

class MsgDialog : public QWidget{
    Q_OBJECT

public:
    enum method{add, update, removeCourse, removeStudent};
    explicit MsgDialog(method me, QWidget *parent = 0);
    ~MsgDialog();
    void doExec(void);
private:
    Ui::MsgDialog *ui;
    method m;
    bool inLoop;
    QEventLoop loop;
private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
};

#endif // MSGDIALOG_H
