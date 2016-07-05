#ifndef CHARTWINDOW_H
#define CHARTWINDOW_H
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QWidget>
#include<QAbstractButton>
#include"students.h"
namespace Ui {
class ChartWindow;
}
QT_CHARTS_USE_NAMESPACE
class ChartWindow : public QWidget{
    Q_OBJECT

public:
    explicit ChartWindow(QWidget *parent = 0);
    ~ChartWindow();
private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
private:
    Ui::ChartWindow *ui;
    QChartView* chartView;
    //QString currentCourse;
};

#endif // CHARTWINDOW_H
