#include "sortwindow.h"
#include "ui_sortwindow.h"
#include<QStringList>
#include"course.h"
#include"students.h"

QString SortWindow::compareColumn;

SortWindow::SortWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SortWindow){
    ui->setupUi(this);
    this->setWindowTitle(tr("排序"));
    ui->comboBox->addItem("学号");
    ui->comboBox->addItems(QStringList(Course::courses()));
    asc = false;
    inLoop = false;
}

SortWindow::~SortWindow(){
    delete ui;
}

bool SortWindow::ascending(void){
    return asc;
}

void SortWindow::doExec(void){
    inLoop = true;
    this->show();
    loop.exec();
}

void SortWindow::on_buttonBox_clicked(QAbstractButton *button){
    if(ui->buttonBox->standardButton(button) == QDialogButtonBox::Cancel){
        if(inLoop){
            inLoop = false;
            loop.quit();
        }
        this->close();
    }else{
        QString column = ui->comboBox->currentText();
        if((ui->comboBox->currentIndex()) == 0)
            column = "sid";
        setCompareColumn(column);
        if(inLoop){
            inLoop = false;
            loop.quit();
        }
        this->close();
    }
}

void SortWindow::setCompareColumn(QString column){
    compareColumn = column;
}

void SortWindow::on_desc_clicked(){
    asc = false;
}

void SortWindow::on_asc_clicked(){
    asc = true;
}
