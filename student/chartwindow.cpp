#include "chartwindow.h"
#include "ui_chartwindow.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE
ChartWindow::ChartWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChartWindow){
    ui->setupUi(this);
    ui->comboBox->addItem("GPA");
    QStringList columns(Course::courses());
    ui->comboBox->addItems(columns);
    this->setWindowTitle("统计图");
}

ChartWindow::~ChartWindow(){
    delete ui;
}

void ChartWindow::on_buttonBox_clicked(QAbstractButton *button){
    if(ui->buttonBox->standardButton(button) == QDialogButtonBox::Ok){
        int columnIndex = ui->comboBox->currentIndex();
        QString columnName = ui->comboBox->currentText();
        QList<int> res;
        if(columnIndex == 0)
            res = Students::calculate("gpa");
        else
            res = Students::calculate(columnName);
        QPieSeries *series = new QPieSeries();
        series->append("优", qreal(res[0]));
        series->append("良", qreal(res[1]));
        series->append("中", qreal(res[2]));
        series->append("及格",qreal(res[3]));
        series->append("不及格",qreal(res[4]));
        QChart* chart = new QChart();
        chart->addSeries(series);
        if(!(ui->container->isEmpty()))
            ui->container->removeWidget(chartView);
        chartView = new QChartView(chart);
        ui->container->addWidget(chartView);
    }
}
