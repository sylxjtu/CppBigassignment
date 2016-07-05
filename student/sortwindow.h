#ifndef SORTWINDOW_H
#define SORTWINDOW_H
#include<QAbstractButton>
#include <QWidget>
#include<QEventLoop>
namespace Ui {
class SortWindow;
}

class SortWindow : public QWidget{
    Q_OBJECT

public:
    explicit SortWindow(QWidget *parent = 0);
    ~SortWindow();
    bool ascending(void);
    void doExec(void);
    static QString compareColumn;
    static void setCompareColumn(QString column);
private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_desc_clicked();
    void on_asc_clicked();
private:
    Ui::SortWindow *ui;
    bool asc;
    bool inLoop;
    QEventLoop loop;
};

#endif // SORTWINDOW_H
