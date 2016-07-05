#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QStringList>
#include<QTableWidget>
#include<QTableWidgetItem>
#include"file.h"
#include"students.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void refresh(QTableWidget *table, QString column = "sid", bool asc = true);
    void order(QString column = "sid", bool asc = false);
private slots:
    void openTriggered(void);
    void saveTriggered(void);
    void exitTriggered(void);
    void importTriggered(void);
    void saveasTriggered(void);
    void updateTriggered(void);
    void addTriggered(void);
    void deleteCTriggered(void);
    void deleteSTriggered(void);
    void sortTriggeredD(void);
    void sortTriggeredA(void);
    void sortKeyTriggered(void);
    void chartTriggered(void);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
